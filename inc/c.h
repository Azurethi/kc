#ifndef _C_H_
#define _C_H_

#include <stdint.h>

//~ fast ints?
// long long instead of int64_t for windows compat.

typedef int8_t i8;     // [−128, 127]
typedef int16_t i16;   // [−32768, 32767]
typedef int32_t i32;   // [−2147483648, 2147483647]
typedef long long i64; // [−9223372036854775808, 9223372036854775807]
typedef uint8_t u8;    // [0, 255]
typedef uint16_t u16;  // [0, 65535]
typedef uint32_t u32;  // [0, 4294967295]
typedef uint64_t u64;  // [0, 18446744073709551615]

#define VOID_MASK 0xFF00000000000001
#define VOID_SHIFT 56

typedef char ch;
typedef const char cc;

// OS independent return types, <0 error, 0 OK, >0 application defined.
typedef i8 r8;
typedef i16 r16;
typedef i32 r32;
typedef i64 r64;
// typedef u64 ru64 //~ could reserve only N high values for errors, rather than entire -ve range.
#define RET_OK 0
#define RET_ERR -1
#define RET_MEM -2

#ifdef _WIN32
typedef struct HINSTANCE__ inst;
typedef struct HDC__ hdc;
typedef struct tagRECT rect;
#endif

typedef struct _iobuf file;

#endif // _C_H_