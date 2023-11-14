#ifndef _LOG_H_
#define _LOG_H_

#ifdef LOG
#define LOG_TRACE(fmt, ...) LOG(LOG_LVL_TRACE, fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...) LOG(LOG_LVL_DEBUG, fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...) LOG(LOG_LVL_INFO, fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...) LOG(LOG_LVL_WARN, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) LOG(LOG_LVL_ERROR, fmt, ##__VA_ARGS__)
#define LOG_FATAL(fmt, ...) LOG(LOG_LVL_FATAL, fmt, ##__VA_ARGS__)
#else
#define LOG(...)
#define LOG_TRACE(...)
#define LOG_DEBUG(...)
#define LOG_INFO(...)
#define LOG_WARN(...)
#define LOG_ERROR(...)
#define LOG_FATAL(...)
#endif

//~ add additional debug functions (test point hooks, entry/exit hooks etc)
//~ consider preproc project (add hooks to functions based on some test def file)

#include <stdio.h>
#define LOG_LVL_TRACE_NAME 'T'
#define LOG_LVL_DEBUG_NAME 'D'
#define LOG_LVL_INFO_NAME 'I'
#define LOG_LVL_WARN_NAME 'W'
#define LOG_LVL_ERROR_NAME 'E'
#define LOG_LVL_FATAL_NAME 'F'
#define LOG_LVL_NEVER_NAME 'N'

#define LOG_LVL_TRACE 0
#define LOG_LVL_DEBUG 1
#define LOG_LVL_INFO 2
#define LOG_LVL_WARN 3
#define LOG_LVL_ERROR 4
#define LOG_LVL_FATAL 5
#define LOG_LVL_NEVER 6

//~ nicer timestamps / formatting
#define LOG_INTERNAL1(time, tid, fac, lvl, fmt, ...) printf("%013lld %p %s %c\t" fmt "\n", time, tid, fac, lvl, ##__VA_ARGS__)

#include <stdlib.h>

#ifndef _WIN32
#include <pthread.h>
#define LOG_INTERNAL(fac, lvl, ...)                                                             \
    do                                                                                          \
    {                                                                                           \
        if (fac <= lvl)                                                                         \
        {                                                                                       \
            struct timespec tv;                                                                 \
            clock_gettime(CLOCK_REALTIME, &tv);                                                 \
            i64 time = tv.tv_sec % 1000 * 1000000000 + tv.tv_nsec;                              \
            LOG_INTERNAL1(time, (void*) pthread_self(), fac##_NAME, lvl##_NAME, ##__VA_ARGS__); \
            fflush(stdout);                                                                     \
        }                                                                                       \
    } while (0)
#else
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <profileapi.h>
#include <processthreadsapi.h>

static __declspec(thread) void* this_tid = (void*) (LONGLONG) -1;
static void* getTid()
{
    return this_tid != (void*) (LONGLONG) -1 ? this_tid : (this_tid=(void*) (LONGLONG) GetCurrentThreadId());
}

#define LOG_INTERNAL(fac,lvl, ...)                                                          \
    do {                                                                                    \
        if (fac <= lvl)                                                                     \
        {                                                                                   \
            LARGE_INTEGER time;                                                             \
            QueryPerformanceCounter(&time);                                                 \
            LOG_INTERNAL1(time.QuadPart, getTid(), fac##_NAME, lvl##_NAME, ##__VA_ARGS__);  \
        }                                                                                   \
    } while(0)
#endif

#endif // _LOG_H_
