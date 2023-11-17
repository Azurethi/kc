// Rework / extension of k.h from https://github.com/KxSystems/kdb/blob/c7a64a6d07db40622a534196389cb5885159bd35/c/c/k.h
#ifndef _KC_H_
#define _KC_H_

#include "c.h"

#define KXVER 3

// k.h typedefs
typedef char*S,C;
typedef unsigned char G;
typedef short H;
typedef int I;
typedef long long J;
typedef float E;
typedef double F;
typedef void V;
typedef unsigned long long UJ;

#ifdef __cplusplus
extern"C"{
#endif
#if !defined(KXVER)
// Asof 2023.03.30, default to 3. For kdb+2.x or standalone c-api before 2011-04-20 used KXVER=2
#define KXVER 3
#endif
#if KXVER>=3
typedef struct k0{signed char m,a,t;C u;I r;union{G g;H h;I i;J j;E e;F f;S s;struct k0*k;struct{J n;G G0[];};};}*K;
typedef struct{G g[16];}U;
#define kU(x) ((U*)kG(x))
#define xU ((U*)xG)
extern K ku(U),knt(J,K),ktn(I,J),kpn(S,J);
extern I setm(I),ver();
#define DO(n,x)	{J i=0,_i=(n);for(;i<_i;++i){x;}}
#else
typedef struct k0{I r;H t,u;union{G g;H h;I i;J j;E e;F f;S s;struct k0*k;struct{I n;G G0[];};};}*K;
extern K ktn(I,I),kpn(S,I);
#define DO(n,x)	{I i=0,_i=(n);for(;i<_i;++i){x;}}
#endif
#ifdef __cplusplus
}
#endif

// vector accessors, e.g. kF(x)[i] for float&datetime
#define kG(x)	((x)->G0)
#define kC(x)	kG(x)
#define kH(x)	((H*)kG(x))
#define kI(x)	((I*)kG(x))
#define kJ(x)	((J*)kG(x))
#define kE(x)	((E*)kG(x))
#define kF(x)	((F*)kG(x))
#define kS(x)	((S*)kG(x))
#define kK(x)	((K*)kG(x))

//      type bytes qtype     ctype  accessor
#define K0 0  // - gen list  -      kK
#define KB 1  // 1 boolean   char   kG
#define UU 2  // 16 guid     U      kU
#define KG 4  // 1 byte      char   kG
#define KH 5  // 2 short     short  kH
#define KI 6  // 4 int       int    kI
#define KJ 7  // 8 long      long   kJ
#define KE 8  // 4 real      float  kE
#define KF 9  // 8 float     double kF
#define KC 10 // 1 char      char   kC
#define KS 11 // * symbol    char*  kS

#define KP 12 // 8 timestamp long   kJ (nanoseconds from 2000.01.01)
#define KM 13 // 4 month     int    kI (months from 2000.01.01)
#define KD 14 // 4 date      int    kI (days from 2000.01.01)

#define KN 16 // 8 timespan  long   kJ (nanoseconds)
#define KU 17 // 4 minute    int    kI
#define KV 18 // 4 second    int    kI
#define KT 19 // 4 time      int    kI (millisecond)

#define KZ 15 // 8 datetime  double kF (DO NOT USE)

#define XT 98 // - table     -      x->k is XD
#define XD 99 // - dict      -      kK(x)[0] is keys. kK(x)[1] is values.

#ifdef __cplusplus
#include<cstdarg>
extern"C"{
extern V m9();
#else
#include<stdarg.h>
extern V m9(V);
#endif
extern J gc(J j);
extern I khpunc(S,I,S,I,I),khpun(const S,I,const S,I),khpu(const S,I,const S),khp(const S,I),okx(K),ymd(I,I,I),dj(I);extern V r0(K),sd0(I),sd0x(I d,I f),kclose(I);extern S sn(S,I),ss(S);
extern K ee(K),ktj(I,J),ka(I),kb(I),kg(I),kh(I),ki(I),kj(J),ke(F),kf(F),kc(I),ks(S),kd(I),kz(F),kt(I),sd1(I,K(*)(I)),dl(V*f,J),m4(I),
 knk(I,...),kp(S),ja(K*,V*),js(K*,S),jk(K*,K),jv(K*k,K),k(I,const S,...),xT(K),xD(K,K),ktd(K),r1(K),krr(const S),orr(const S),dot(K,K),b9(I,K),d9(K),sslInfo(K x),vaknk(I,va_list),vak(I,const S,va_list),vi(K,UJ),m4(I);
#ifdef __cplusplus 
}
#endif

// nulls(n?) and infinities(w?)
#define nh ((I)0xFFFF8000)
#define wh ((I)0x7FFF)
#define ni ((I)0x80000000)
#define wi ((I)0x7FFFFFFF)
#define nj ((J)0x8000000000000000LL) 
#define wj 0x7FFFFFFFFFFFFFFFLL

#if defined(WIN32) || defined(_WIN32)
#define nf (log(-1.0))
#define wf (-log(0.0))
#define finite _finite
extern double log(double);
#else  
#define nf (0/0.0)
#define wf (1/0.0)
#define closesocket(x) close(x)
#endif 

// Aliases of K for type annotation
#define _K0 K // generic list
// #define _K0(x) K // list with length?
#define _KB K // boolean vector
#define _UU K // guid vector       //~ _K?
#define _KG K // byte vector
#define _KH K // short vector
#define _KI K // int vector
#define _KJ K // long vector
#define _KE K // real vector
#define _KF K // float vector
#define _KC K // char vector
#define _KS K // symbol vector
#define _KP K // timestamp vector   (nanoseconds from 2000.01.01)
#define _KM K // month vector       (months from 2000.01.01)
#define _KD K // date vector        (days from 2000.01.01)
#define _KN K // timespan vector    (nanoseconds)
#define _KU K // minute vector
#define _KV K // second vector
#define _KT K // time vector        (millisecond)
#define _KZ K // datetime vector    (DO NOT USE)
//     //  *_KA, // table vector
//     //  *_KY, // dict vector

#define _Kb K // boolean
#define _Uu K // guid       //~ _K?
#define _Kg K // byte
#define _Kh K // short
#define _Ki K // int
#define _Kj K // long
#define _Ke K // real
#define _Kf K // float
#define _Kc K // char
#define _Ks K // symbol
#define _Kp K // timestamp  (nanoseconds from 2000.01.01)
#define _Km K // month      (months from 2000.01.01)
#define _Kd K // date       (days from 2000.01.01)
#define _Kn K // timespan   (nanoseconds)
#define _Ku K // minute
#define _Kv K // second
#define _Kt K // time       (millisecond)
#define _Kz K // datetime   (DO NOT USE)
#define _Ka K // table
#define _Ky K // dict

#endif // _KC_H_
