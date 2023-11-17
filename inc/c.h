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

typedef const i8 ci8;   // [−128, 127]
typedef const i16 ci16; // [−32768, 32767]
typedef const i32 ci32; // [−2147483648, 2147483647]
typedef const i64 ci64; // [−9223372036854775808, 9223372036854775807]
typedef const u8 cu8;   // [0, 255]
typedef const u16 cu16; // [0, 65535]
typedef const u32 cu32; // [0, 4294967295]
typedef const u64 cu64; // [0, 18446744073709551615]

typedef size_t sz;

#define VOID_MASK 0xFF00000000000000
#define VOID_SHIFT 56

typedef char ch;
typedef const char cc;

// OS independent return types, <0 error, 0 OK, >0 application defined.
// Underlying values not restricted above may change & should not be relied on
typedef i8 r8;
typedef i16 r16;
typedef i32 r32;
typedef i64 r64;
// typedef u64 ru64 //~ could reserve only N high values for errors, rather than entire -ve range.
#define RET_OK 0
#define RET_FALSE -1  // Not really an error, just returning false.
#define RET_ERR -2    // Generic error
#define RET_MEM -3    // Out of memory
#define RET_NYI -4    // Not yet implemented
#define RET_UNSUP -5  // Unsupported argument
#define RET_INVAL -6  // Invalid argument         //~ Consider a range of these (RET_INVAL_2)
#define RET_TO -7     // Timeout
#define RET_CONN -8   // Connection error
#define RET_PERM -9   // Permission error
#define RET_AGAIN -10 // Resource temporarily unavailable (EAGAIN / EWOULDBLOCK)

#ifdef _WIN32
typedef struct HINSTANCE__ inst;
typedef struct HDC__ hdc;
typedef struct tagRECT rect;
typedef struct tagMSG msg;
#endif

typedef struct _iobuf file;

#endif // _C_H_