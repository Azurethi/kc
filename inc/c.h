#ifndef _C_H_
#define _C_H_

#include <stdint.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef long long i64;  //~ for windows compat.
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef char ch;
typedef const char cc;

#ifdef _WIN32
typedef struct HINSTANCE__ inst;
typedef struct HDC__ hdc;
typedef struct tagRECT rect;
#endif

#endif // _C_H_