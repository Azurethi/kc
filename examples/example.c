#ifndef LOG_FAC_EXAMPLE
#define LOG_FAC_EXAMPLE LOG_LVL_TRACE
#endif
#define LOG_FAC_EXAMPLE_NAME "exmp"
#define LOG(...) LOG_INTERNAL(LOG_FAC_EXAMPLE, ##__VA_ARGS__)
#include "log.h"

#include "c.h"

file *LOG_FILE_HANDLE = 0;
i32 __stdcall WinMain(inst *cur, inst *prev, ch *cmdl, i32 show)
{
    LOG_FILE_HANDLE = fopen("example.log", "a+");

    LOG_INFO("Starting example application.");

    msg msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        LOG_TRACE("Processing message!");
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    fclose(LOG_FILE_HANDLE);

    return msg.wParam;
}