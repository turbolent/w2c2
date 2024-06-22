#ifndef W2C2_BASE_H
#define W2C2_BASE_H

#include <stddef.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#ifndef __NeXT__
#include <stdint.h>
#endif

#include <assert.h>

#include <errno.h>

#ifdef __cplusplus
extern "C" {
#else

#ifndef __bool_true_false_are_defined
typedef enum bool {
    false = 0,
    true = 1
} bool;
#endif

#endif

typedef unsigned char U8;
typedef signed char I8;

typedef unsigned short U16;
typedef signed short I16;

typedef unsigned int U32;
typedef signed int I32;

typedef unsigned long long int U64;
typedef signed long long int I64;

typedef float F32;
typedef double F64;

#define MUST(_) { if (!(_)) { return false; }; }

#define WASM_LITTLE_ENDIAN  0
#define WASM_BIG_ENDIAN     1

/*
 * Endianness detection courtesy of RapidJSON,
 * extended for more architectures and operating systems
 */
#ifndef WASM_ENDIAN
/* Detect with GCC 4.6's macro */
#ifdef __BYTE_ORDER__
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define WASM_ENDIAN WASM_LITTLE_ENDIAN
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define WASM_ENDIAN WASM_BIG_ENDIAN
#else
#error Unknown endianness. Please define WASM_ENDIAN.
#endif /* __BYTE_ORDER__ */
/* Detect with GLIBC's endian.h */
#elif defined(__GLIBC__)
#include <endian.h>
#if (__BYTE_ORDER == __LITTLE_ENDIAN)
#define WASM_ENDIAN WASM_LITTLE_ENDIAN
#elif (__BYTE_ORDER == __BIG_ENDIAN)
#define WASM_ENDIAN WASM_BIG_ENDIAN
#else
#error Unknown endianness. Please define WASM_ENDIAN.
#endif /* __GLIBC__ */
/* Detect with _LITTLE_ENDIAN and _BIG_ENDIAN macro */
#elif defined(_LITTLE_ENDIAN) && !defined(_BIG_ENDIAN)
#define WASM_ENDIAN WASM_LITTLE_ENDIAN
#elif defined(_BIG_ENDIAN) && !defined(_LITTLE_ENDIAN)
#define WASM_ENDIAN WASM_BIG_ENDIAN
/* Detect with __LITTLE_ENDIAN__ and __BIG_ENDIAN__ macro */
#elif defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__)
#define WASM_ENDIAN WASM_LITTLE_ENDIAN
#elif defined(__BIG_ENDIAN__) && !defined(__LITTLE_ENDIAN__)
#define WASM_ENDIAN WASM_BIG_ENDIAN
/* Detect with architecture and operating system macros */
#elif defined(__sparc) || defined(__sparc__) \
    || defined(_POWER) || defined(__powerpc__) || defined(__ppc__) || defined(_POWER) \
    || defined(__hpux) || defined(__hppa) || defined(__hppa__) \
    || defined(_MIPSEB) || defined(__MIPSEB) || defined(__MIPSEB__) \
    || defined(__AARCH64EB__) || defined(__THUMBEB__) || defined(__ARMEB__) || defined(__ARM_BIG_ENDIAN) \
    || defined(__s390__)
#define WASM_ENDIAN WASM_BIG_ENDIAN
#elif defined(__i386__) || defined(_M_IX86) \
    || defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA) \
    || defined(__ia64) || defined(__ia64__) || defined(_M_IA64) \
    || defined(__amd64) || defined(__amd64__) || defined(_M_AMD64) \
    || defined(__x86_64) || defined(__x86_64__) || defined(_M_X64) \
    || defined(_M_ARM) || defined(_M_ARM64) \
    || defined(__AARCH64EL__) || defined(__THUMBEL__) || defined(__ARMEL__) \
    || defined(_MIPSEL) || defined(__MIPSEL) || defined(__MIPSEL__) \
    || defined(__bfin__)
#define WASM_ENDIAN WASM_LITTLE_ENDIAN
#else
#error Unknown machine endianness detected. User needs to define WASM_ENDIAN.
#endif
#endif /* WASM_ENDIAN */

#define swapU8(x) (x)

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
#define swapU16(x) (x)
#define swapU32(x) (x)
#define swapU64(x) (x)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

/*
 * Use compiler byte-swapping intrinsics if they are available.
 * 32-bit and 64-bit versions are available in Clang and GCC as of GCC 4.8.0.
 */
#if defined(__clang__) || (defined(__GNUC__) && ((__GNUC__ == 4 && __GNUC_MINOR__ >= 8) || __GNUC__ >= 5))

#define swapU16(x) __builtin_bswap16(x)
#define swapU32(x) __builtin_bswap32(x)
#define swapU64(x) __builtin_bswap64(x)

#elif defined(__APPLE__)

#include <libkern/OSByteOrder.h>

#define swapU16(x) OSSwapInt16(x)
#define swapU32(x) OSSwapInt32(x)
#define swapU64(x) OSSwapInt64(x)

#else

/*
 * Mask, and then shift.
 * Mask, and then shift.
 * Mask, and then shift.
 * Mask, and then shift.
 */
#define swapU16(x) ((((x) & 0xFF00) >> 8) \
                  | (((x) & 0x00FF) << 8))
#define swapU32(x) ((((x) & 0xFF000000) >> 24) \
                  | (((x) & 0x00FF0000) >> 8 ) \
                  | (((x) & 0x0000FF00) << 8 ) \
                  | (((x) & 0x000000FF) << 24))
#define swapU64(x) ((((x) & 0xff00000000000000ull) >> 56) \
                  | (((x) & 0x00ff000000000000ull) >> 40) \
                  | (((x) & 0x0000ff0000000000ull) >> 24) \
                  | (((x) & 0x000000ff00000000ull) >> 8 ) \
                  | (((x) & 0x00000000ff000000ull) << 8 ) \
                  | (((x) & 0x0000000000ff0000ull) << 24) \
                  | (((x) & 0x000000000000ff00ull) << 40) \
                  | (((x) & 0x00000000000000ffull) << 56))

#endif

#endif

#ifdef _MSC_VER
#define W2C2_INLINE __inline
#else
#define W2C2_INLINE __inline__
#endif

#define GCC_VERSION (__GNUC__ * 10000 \
                     + __GNUC_MINOR__ * 100 \
                     + __GNUC_PATCHLEVEL__)

#if defined(__GNUC__) && GCC_VERSION >= 30406
#define WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
#define WARN_UNUSED_RESULT
#endif

#if defined(__GNUC__) && GCC_VERSION >= 20905
#define NORETURN __attribute__((noreturn))
#else
#define NORETURN
#endif

#if defined(__GNUC__) && GCC_VERSION >= 20905
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif

#ifndef LLONG_MIN
#define LLONG_MIN (-0x7fffffffffffffffLL-1)
#endif

#ifndef LLONG_MAX
#define LLONG_MAX 0x7fffffffffffffffLL
#endif

#ifndef INT32_MAX
#define INT32_MAX 2147483647
#endif

#ifndef INT32_MIN
#define INT32_MIN (-INT32_MAX - 1)
#endif

#ifndef INT64_MAX
#define INT64_MAX 9223372036854775807LL
#endif

#ifndef INT64_MIN
#define INT64_MIN (-INT64_MAX - 1)
#endif

#ifndef UINT32_MAX
#define UINT32_MAX 4294967295U
#endif

#ifndef UINT64_MAX
#define UINT64_MAX 18446744073709551615ULL
#endif

#if defined(_MSC_VER) && _MSC_VER <= 1500

/* disable warning C4756: overflow in constant arithmetic */
#pragma warning(disable:4756 4056)

#ifndef _HUGE_ENUF
#define _HUGE_ENUF  1e+300  /* _HUGE_ENUF*_HUGE_ENUF must overflow */
#endif

#define INFINITY   ((float)(_HUGE_ENUF * _HUGE_ENUF))
#define HUGE_VALF  ((float)INFINITY)
#define HUGE_VALL  ((long double)INFINITY)
#define NAN        ((float)(INFINITY * 0.0F))
#endif

#ifndef INFINITY
#define INFINITY (1.0/0.0)
#endif

static
W2C2_INLINE
U32
assertSizeU32(
    const size_t size
) {
    assert(size <= UINT32_MAX);
    return (U32) size;
}

typedef enum Trap {
    trapUnreachable,
    trapDivByZero,
    trapIntOverflow,
    trapInvalidConversion,
    trapAllocationFailed
} Trap;

static
W2C2_INLINE
const char*
trapDescription(
    const Trap trap
) {
    switch (trap) {
        case trapUnreachable:
            return "unreachable";
        case trapDivByZero:
            return "div by zero";
        case trapIntOverflow:
            return "int overflow";
        case trapInvalidConversion:
            return "invalid conversion";
        case trapAllocationFailed:
            return "allocation failed";
        default:
            return "unknown";
    }
}

extern void trap(Trap) NORETURN;

#define TRAP(x) (trap(x), 0)

#define UNREACHABLE TRAP(trapUnreachable)

#define DIV_S(ut, min, x, y)                            \
   (((y) == 0)                  ? TRAP(trapDivByZero)   \
  : ((x) == (min) && (y) == -1) ? TRAP(trapIntOverflow) \
  : (ut)((x) / (y)))

#define REM_S(ut, min, x, y)                          \
   (((y) == 0)                  ? TRAP(trapDivByZero) \
  : ((x) == (min) && (y) == -1) ? 0                   \
  : (ut)((x) % (y)))

#define I32_DIV_S(x, y) DIV_S(U32, INT32_MIN, (I32)(x), (I32)(y))
#define I64_DIV_S(x, y) DIV_S(U64, INT64_MIN, (I64)(x), (I64)(y))
#define I32_REM_S(x, y) REM_S(U32, INT32_MIN, (I32)(x), (I32)(y))
#define I64_REM_S(x, y) REM_S(U64, INT64_MIN, (I64)(x), (I64)(y))

#define DIVREM_U(op, x, y)               \
   (((y) == 0)    ? TRAP(trapIntOverflow) \
  : ((x) op (y)))

#define DIV_U(x, y) DIVREM_U(/, x, y)
#define REM_U(x, y) DIVREM_U(%, x, y)

#define ROTL(x, y, mask) \
  (((x) << ((y) & (mask))) | ((x) >> (((mask) - (y) + 1) & (mask))))
#define ROTR(x, y, mask) \
  (((x) >> ((y) & (mask))) | ((x) << (((mask) - (y) + 1) & (mask))))

#define I32_ROTL(x, y) ROTL(x, y, 31)
#define I64_ROTL(x, y) ROTL(x, y, 63)
#define I32_ROTR(x, y) ROTR(x, y, 31)
#define I64_ROTR(x, y) ROTR(x, y, 63)

#ifndef __has_builtin
#define __has_builtin(x) 0
#endif

#if __has_builtin(__builtin_popcount)
#define I32_POPCNT(x) __builtin_popcount(x)
#else
static
W2C2_INLINE
U32
I32_POPCNT(
    U32 x
) {
    x -= ((x >> 1) & 0x55555555u);
    x = ((x >> 2) & 0x33333333u) + (x & 0x33333333u);
    x = ((x >> 4) + x) & 0x0F0F0F0Fu;
    x *= 0x01010101u;
    return (x >> 24);
}
#endif

#if __has_builtin(__builtin_popcountll)
#define I64_POPCNT(x) __builtin_popcountll(x)
#else
static
W2C2_INLINE
U64 I64_POPCNT(U64 x) {
    x -= ((x >> 1) & 0x5555555555555555ull);
    x = ((x >> 2) & 0x3333333333333333ull) + (x & 0x3333333333333333ull);
    x = ((x >> 4) + x) & 0xf0f0f0f0f0f0f0full;
    x *= 0x101010101010101ull;
    return (x >> 56);
}
#endif

#if __has_builtin(__builtin_clz)
/* __builtin_clz(0) is undefined */
#define I32_CLZ(x) ((x) ? __builtin_clz(x) : 32)
#else
/* From Hacker's Delight 2nd Edition */
static
W2C2_INLINE
U32
I32_CLZ(
    U32 x
) {
    I32 n = 32;
    U32 y = x >> 16;
    if (y != 0) {
        n -= 16;
        x = y;
    }
    y = x >> 8;
    if (y != 0) {
        n -= 8;
        x = y;
    }
    y = x >> 4;
    if (y != 0) {
        n -= 4;
        x = y;
    }
    y = x >> 2;
    if (y != 0) {
        n -= 2;
        x = y;
    }
    y = x >> 1;
    if (y != 0) {
        return n - 2;
    }
    return n - x;
}
#endif

#if __has_builtin(__builtin_clzll)
/* __builtin_clzll(0) is undefined */
#define I64_CLZ(x) ((x) ? __builtin_clzll(x) : 64)
#else
/* From Hacker's Delight 2nd Edition */
static
W2C2_INLINE
U64
I64_CLZ(
    U64 x
) {
    I64 n = 64;
    U64 y = x >> 32;
    if (y != 0) {
        n -= 32;
        x = y;
    }
    y = x >> 16;
    if (y != 0) {
        n -= 16;
        x = y;
    }
    y = x >> 8;
    if (y != 0) {
        n -= 8;
        x = y;
    }
    y = x >> 4;
    if (y != 0) {
        n -= 4;
        x = y;
    }
    y = x >> 2;
    if (y != 0) {
        n -= 2;
        x = y;
    }
    y = x >> 1;
    if (y != 0) {
        return n - 2;
    }
    return n - x;
}
#endif

#if __has_builtin(__builtin_ctz)
/* __builtin_ctz(0) is undefined */
#define I32_CTZ(x) ((x) ? __builtin_ctz(x) : 32)
#else
/* From Hacker's Delight 2nd Edition */
static
W2C2_INLINE
U32
I32_CTZ(
    const U32 x
) {
    return 32 - I32_CLZ(~x & (x - 1));
}
#endif

#if __has_builtin(__builtin_ctzll)
/* __builtin_ctzll(0) is undefined */
#define I64_CTZ(x) ((x) ? __builtin_ctzll(x) : 64)
#else
/* From Hacker's Delight 2nd Edition */
static
W2C2_INLINE
U64
I64_CTZ(
    const U64 x
) {
    return 64 - I64_CLZ(~x & (x - 1));
}
#endif

#define FMIN(x, y)                                    \
   (((x) != (x)) ? NAN                                \
  : ((y) != (y)) ? NAN                                \
  : ((x) == 0 && (y) == 0) ? (signbit(x) ? (x) : (y)) \
  : ((x) < (y)) ? (x) : (y))

#define FMAX(x, y)                                    \
   (((x) != (x)) ? NAN                                \
  : ((y) != (y)) ? NAN                                \
  : ((x) == 0 && (y) == 0) ? (signbit(x) ? (y) : (x)) \
  : ((x) > (y)) ? (x) : (y))

#define TRUNC_S(ut, st, ft, min, minop, max, x)                     \
   (((x) != (x))                      ? TRAP(trapInvalidConversion) \
  : (!((x)minop(min) && (x) < (max))) ? TRAP(trapIntOverflow)       \
  : (ut)(st)(x))

#define I32_TRUNC_S_F32(x) TRUNC_S(U32, I32, F32, (F32)INT32_MIN, >=, 2147483648.f, x)
#define I64_TRUNC_S_F32(x) TRUNC_S(U64, I64, F32, (F32)INT64_MIN, >=, (F32)INT64_MAX, x)
#define I32_TRUNC_S_F64(x) TRUNC_S(U32, I32, F64, -2147483649., >, 2147483648., x)
#define I64_TRUNC_S_F64(x) TRUNC_S(U64, I64, F64, (F64)INT64_MIN, >=, (F64)INT64_MAX, x)

#define TRUNC_U(ut, ft, max, x)                                    \
   (((x) != (x))                     ? TRAP(trapInvalidConversion) \
  : (!((x) > (ft)-1 && (x) < (max))) ? TRAP(trapIntOverflow)       \
  : (ut)(x))

#define I32_TRUNC_U_F32(x) TRUNC_U(U32, F32, 4294967296.f, x)
#define I64_TRUNC_U_F32(x) TRUNC_U(U64, F32, (F32)UINT64_MAX, x)
#define I32_TRUNC_U_F64(x) TRUNC_U(U32, F64, 4294967296., x)
#define I64_TRUNC_U_F64(x) TRUNC_U(U64, F64, (F64)UINT64_MAX, x)

#define TRUNC_SAT_S(ut, st, ft, min, smin, minop, max, smax, x) \
   (((x) != (x)) ? 0                                            \
  : (!((x)minop(min))) ? smin                                   \
  : (!((x) < (max))) ? smax                                     \
  : (ut)(st)(x))

#define I32_TRUNC_SAT_S_F32(x) \
  TRUNC_SAT_S(U32, I32, f32, (F32)INT32_MIN, INT32_MIN, >=, 2147483648.f, INT32_MAX, x)
#define I64_TRUNC_SAT_S_F32(x) \
  TRUNC_SAT_S(U64, I64, F32, (F32)INT64_MIN, INT64_MIN, >=, (F32)INT64_MAX, INT64_MAX, x)
#define I32_TRUNC_SAT_S_F64(x) \
  TRUNC_SAT_S(U32, I32, F64, -2147483649., INT32_MIN, >, 2147483648., INT32_MAX, x)
#define I64_TRUNC_SAT_S_F64(x) \
  TRUNC_SAT_S(U64, I64, F64, (F64)INT64_MIN, INT64_MIN, >=, (F64)INT64_MAX, INT64_MAX, x)

#define TRUNC_SAT_U(ut, ft, max, smax, x) \
   (((x) != (x)) ? 0                      \
  : (!((x) > (ft)-1)) ? 0                 \
  : (!((x) < (max))) ? smax               \
  : (ut)(x))

#define I32_TRUNC_SAT_U_F32(x) \
  TRUNC_SAT_U(U32, F32, 4294967296.f, UINT32_MAX, x)
#define I64_TRUNC_SAT_U_F32(x) \
  TRUNC_SAT_U(U64, F32, (F32)UINT64_MAX, UINT64_MAX, x)
#define I32_TRUNC_SAT_U_F64(x) \
  TRUNC_SAT_U(U32, F64, 4294967296., UINT32_MAX, x)
#define I64_TRUNC_SAT_U_F64(x) \
  TRUNC_SAT_U(U64, F64, (F64)UINT64_MAX, UINT64_MAX, x)

#ifdef _WIN32
#include <float.h>
#define copysignf _copysignf
#define copysign _copysign
#endif

#define DEFINE_REINTERPRET(name, t1, t2)  \
  static W2C2_INLINE t2 name(t1 x) {      \
    t2 result;                            \
    memcpy(&result, &x, sizeof(result));  \
    return result;                        \
  }

DEFINE_REINTERPRET(f32_reinterpret_i32, U32, F32)
DEFINE_REINTERPRET(i32_reinterpret_f32, F32, U32)
DEFINE_REINTERPRET(f64_reinterpret_i64, U64, F64)
DEFINE_REINTERPRET(i64_reinterpret_f64, F64, U64)

#ifdef WASM_THREADS_PTHREADS
#include <pthread.h>

#define WASM_THREAD_TYPE pthread_t
#define WASM_THREAD_CREATE(thread, func, arg) (pthread_create(thread, NULL, func, arg) == 0)
#define WASM_THREAD_JOIN(thread) ((void)pthread_join(thread, NULL))

#define WASM_MUTEX_TYPE pthread_mutex_t
#define WASM_MUTEX_INIT(mutex) (pthread_mutex_init(mutex, NULL) == 0)
#define WASM_MUTEX_FREE(mutex) ((void)pthread_mutex_destroy(mutex))
#define WASM_MUTEX_LOCK(mutex) ((void)pthread_mutex_lock(mutex))
#define WASM_MUTEX_UNLOCK(mutex) ((void)pthread_mutex_unlock(mutex))

#define WASM_COND_TYPE pthread_cond_t
#define WASM_COND_INIT(cond) (pthread_cond_init(cond, NULL) == 0)
#define WASM_COND_FREE(cond) ((void)pthread_cond_destroy(cond))
#define WASM_COND_WAIT(cond, mutex) ((void)pthread_cond_wait(cond, mutex))
#define WASM_COND_RELATIVE_WAIT(cond, signal, timeout) wasmCondRelativeWait(cond, signal, timeout)
#define WASM_COND_SIGNAL(cond) ((void)pthread_cond_signal(cond))

#define NS_PER_S 1000000000

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCondRelativeWait(
    WASM_COND_TYPE* cond,
    WASM_MUTEX_TYPE* mutex,
    I64 relativeTimeout
) {
    struct timespec absoluteTimeout;
    clock_gettime(CLOCK_REALTIME, &absoluteTimeout);
    absoluteTimeout.tv_sec += (time_t)relativeTimeout / NS_PER_S;
    absoluteTimeout.tv_nsec += (long int)relativeTimeout % NS_PER_S;
    if (absoluteTimeout.tv_nsec >= NS_PER_S) {
        absoluteTimeout.tv_nsec -= NS_PER_S;
        absoluteTimeout.tv_sec++;
    }
    return pthread_cond_timedwait(cond, mutex, &absoluteTimeout) != ETIMEDOUT;
}

#elif defined(WASM_THREADS_WIN32)

#include <windows.h>

#define NS_PER_MS 100000

#define WASM_THREAD_TYPE HANDLE
#define WASM_THREAD_CREATE(thread, func, arg) wasmThreadCreate(thread, func, arg)
#define WASM_THREAD_JOIN(thread) (WaitForSingleObject(thread, INFINITE), (void)CloseHandle(thread))

#define WASM_MUTEX_TYPE CRITICAL_SECTION
#define WASM_MUTEX_INIT(mutex) (InitializeCriticalSection(mutex), true)
#define WASM_MUTEX_FREE(mutex) DeleteCriticalSection(mutex)
#define WASM_MUTEX_LOCK(mutex) EnterCriticalSection(mutex)
#define WASM_MUTEX_UNLOCK(mutex) LeaveCriticalSection(mutex)

#define WASM_COND_TYPE CONDITION_VARIABLE
#define WASM_COND_INIT(cond) (InitializeConditionVariable(cond), true)
#define WASM_COND_FREE(cond) ((void)cond) /* NO-OP */
#define WASM_COND_WAIT(cond, mutex) ((void)SleepConditionVariableCS(cond, mutex, INFINITE))
#define WASM_COND_RELATIVE_WAIT(cond, signal, timeout) SleepConditionVariableCS(cond, signal, (DWORD)timeout / NS_PER_MS)
#define WASM_COND_SIGNAL(cond) WakeConditionVariable(cond)

typedef struct wasmWin32ThreadStartArg {
    void* (*startFunc)(void*);
    void* startFuncArg;
} wasmWin32ThreadStartArg;

static
DWORD
wasmWin32ThreadStart(
    void *arg
) {
    wasmWin32ThreadStartArg* startArg = (wasmWin32ThreadStartArg*)arg;
    void* (*startFunc)(void*) = startArg->startFunc;
    void* startFuncArg = startArg->startFuncArg;

    free(arg);

    startFunc(startFuncArg);

    return ERROR_SUCCESS;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmThreadCreate(
    WASM_THREAD_TYPE* thread,
    void* (*startFunc)(void*),
    void* startFuncArg
) {
    wasmWin32ThreadStartArg* startArg = (wasmWin32ThreadStartArg*)calloc(1, sizeof(wasmWin32ThreadStartArg));
    if (!startArg) {
        return false;
    }

    startArg->startFunc = startFunc;
    startArg->startFuncArg = startFuncArg;

    *thread = CreateThread(NULL, 0, wasmWin32ThreadStart, startArg, 0, NULL);
    return thread != NULL;
}

#endif

typedef struct wasmMemory {
    U8* data;
    U32 size;
    U32 pages;
    U32 maxPages;
    bool shared;
    void* futex;
    void (*futexFree)(void* futex);
#ifdef WASM_MUTEX_TYPE
    WASM_MUTEX_TYPE mutex;
#endif
} wasmMemory;

#define WASM_PAGE_SIZE 65536

static
W2C2_INLINE
wasmMemory*
wasmMemoryAllocate(
    const U32 initialPages,
    const U32 maxPages,
    const bool shared
) {
    const U32 size = (shared ? maxPages : initialPages) * WASM_PAGE_SIZE;
    wasmMemory* memory = (wasmMemory*)calloc(1, sizeof(wasmMemory));
    if (!memory) {
        abort();
    }
    memory->data = (U8*)calloc(size, 1);
    memory->size = size;
    memory->pages = initialPages;
    memory->maxPages = maxPages;
    memory->shared = shared;
    memory->futex = NULL;
    memory->futexFree = NULL;
    if (shared) {
#ifdef WASM_MUTEX_TYPE
        if (!WASM_MUTEX_INIT(&memory->mutex)) {
            abort();
        }
#else
        abort();
#endif
    }
    return memory;
}

#ifdef WASM_MUTEX_TYPE
#define WASM_MEMORY_ALLOCATE_SHARED(initialPages, maxPages) \
    wasmMemoryAllocate(initialPages, maxPages, true)
#else
#define WASM_MEMORY_ALLOCATE_SHARED(initialPages, maxPages) \
    (_Pragma ("GCC error \"Shared memory not supported. Please define a threads implementation to use (WASM_THREADS_*)\"") NULL)
#endif

static
W2C2_INLINE
void
wasmMemoryFree(
    wasmMemory* memory
) {
    free(memory->data);

    memory->size = 0;
    memory->pages = 0;

#ifdef WASM_MUTEX_TYPE
    if (memory->shared) {
        WASM_MUTEX_FREE(&memory->mutex);
    }
#endif

    if (memory->futexFree) {
        memory->futexFree(memory->futex);
    }
    memory->futex = NULL;
    memory->futexFree = NULL;
}

static
W2C2_INLINE
U32
wasmMemoryGrow(
    wasmMemory* memory,
    const U32 delta
) {
    bool doRealloc = true;

    const U32 oldPages = memory->pages;
    const U32 newPages = memory->pages + delta;

    if (newPages == 0) {
        return 0;
    }

    if (newPages < oldPages || newPages > memory->maxPages) {
        return (U32) -1;
    }

    if (memory->shared) {
        doRealloc = false;
#ifdef WASM_MUTEX_TYPE
        WASM_MUTEX_LOCK(&memory->mutex);
#else
        abort();
#endif
    }

    {
        const U32 newSize = newPages * WASM_PAGE_SIZE;
        if (doRealloc) {
            const U32 oldSize = oldPages * WASM_PAGE_SIZE;
            const U32 deltaSize = delta * WASM_PAGE_SIZE;
            U8* newData = (U8*)realloc(memory->data, newSize);
            if (newData == NULL) {
                return (U32) -1;
            }

            memset(newData + oldSize, 0, deltaSize);
            memory->data = newData;
        }

        memory->pages = newPages;
        memory->size = newSize;
    }

    if (memory->shared) {
#ifdef WASM_MUTEX_TYPE
        WASM_MUTEX_UNLOCK(&memory->mutex);
#else
        abort();
#endif
    }

    return oldPages;
}

static
W2C2_INLINE
void
wasmMemoryCopy(
    const wasmMemory* destinationMemory,
    const wasmMemory* sourceMemory,
    const U32 destinationAddress,
    const U32 sourceAddress,
    const U32 count
) {
    memmove(
        destinationMemory->data + destinationAddress,
        sourceMemory->data + sourceAddress,
        count
    );
}

static
W2C2_INLINE
void
wasmMemoryFill(
    const wasmMemory* memory,
    const U32 destinationAddress,
    const U32 value,
    const U32 count
) {
    memset(
        memory->data + destinationAddress,
        (int) value,
        (size_t) count
    );
}

static
W2C2_INLINE
void
load_data(
    void *dest,
    const void *src,
    const size_t n
) {
    memcpy(dest, src, n);
}

#if WASM_ENDIAN == WASM_BIG_ENDIAN

#define readSwapU8(base, offset) (*(U8*)((base) + (offset)))
#define writeSwapU8(base, offset, value) (*(U8*)((base) + (offset)) = (value))

#if defined(__APPLE__)

#include <libkern/OSByteOrder.h>
#define readSwapU16(base, offset) OSReadSwapInt16(base, offset)
#define readSwapU32(base, offset) OSReadSwapInt32(base, offset)
#define readSwapU64(base, offset) OSReadSwapInt64(base, offset)

#define writeSwapU16(base, offset, value) OSWriteSwapInt16(base, offset, value)
#define writeSwapU32(base, offset, value) OSWriteSwapInt32(base, offset, value)
#define writeSwapU64(base, offset, value) OSWriteSwapInt64(base, offset, value)

#else

#define readSwapU16(base, offset) swapU16(*(U16*)((base) + (offset)))
#define readSwapU32(base, offset) swapU32(*(U32*)((base) + (offset)))
#define readSwapU64(base, offset) swapU64(*(U64*)((base) + (offset)))

#define writeSwapU16(base, offset, value) (*(U16*)((base) + (offset)) = swapU16(value))
#define writeSwapU32(base, offset, value) (*(U32*)((base) + (offset)) = swapU32(value))
#define writeSwapU64(base, offset, value) (*(U64*)((base) + (offset)) = swapU64(value))

#endif

#endif

/* LOAD_DATA */

#define LOAD_DATA(m, o, i, s) \
    load_data(&((m).data[o]), i, s)

/* DEFINE_LOAD */

#define DEFINE_LOAD(name, t1, t2, t3)                       \
    static W2C2_INLINE t3 name(wasmMemory* mem, U64 addr) { \
        t1 result;                                          \
        memcpy(&result, &mem->data[addr], sizeof(t1));      \
        return (t3)(t2)result;                              \
    }

/* DEFINE_LOAD8 */

#define DEFINE_LOAD8(name, t1, t2, t3) DEFINE_LOAD(name, t1, t2, t3)

/* DEFINE_LOAD16 */

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_LOAD16(name, t1, t2, t3) DEFINE_LOAD(name, t1, t2, t3)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_LOAD16(name, t1, t2, t3)                     \
    static W2C2_INLINE t3 name(wasmMemory* mem, U64 addr) { \
        t1 result;                                          \
        U16 v = readSwapU16(mem->data, addr);               \
        memcpy(&result, &v, sizeof(U16));                   \
        return (t3)(t2)result;                              \
    }

#endif

/* DEFINE_LOAD32 */

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_LOAD32(name, t1, t2, t3) DEFINE_LOAD(name, t1, t2, t3)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_LOAD32(name, t1, t2, t3)                     \
    static W2C2_INLINE t3 name(wasmMemory* mem, U64 addr) { \
        t1 result;                                          \
        U32 v = readSwapU32(mem->data, addr);               \
        memcpy(&result, &v, sizeof(U32));                   \
        return (t3)(t2)result;                              \
    }

#endif

/* DEFINE_LOAD64 */

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_LOAD64(name, t1, t2, t3) DEFINE_LOAD(name, t1, t2, t3)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_LOAD64(name, t1, t2, t3)                     \
    static W2C2_INLINE t3 name(wasmMemory* mem, U64 addr) { \
        t1 result;                                          \
        U64 v = readSwapU64(mem->data, addr);               \
        memcpy(&result, &v, sizeof(U64));                   \
        return (t3)(t2)result;                              \
    }

#endif

/* DEFINE_STORE */

#define DEFINE_STORE(name, t1, t2)                                      \
    static W2C2_INLINE void name(wasmMemory* mem, U64 addr, t2 value) { \
        t1 wrapped = (t1)value;                                         \
        memcpy(&mem->data[addr], &wrapped, sizeof(t1));                 \
    }

/* DEFINE_STORE8 */

#define DEFINE_STORE8(name, t1, t2) DEFINE_STORE(name, t1, t2)

/* DEFINE_STORE16 */

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_STORE16(name, t1, t2) DEFINE_STORE(name, t1, t2)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_STORE16(name, t1, t2)                                    \
    static W2C2_INLINE void name(wasmMemory* mem, U64 addr, t2 value) { \
        t1 wrapped = (t1)value;                                         \
        U16 v;                                                          \
        memcpy(&v, &wrapped, sizeof(U16));                              \
        writeSwapU16(mem->data, addr, v);                               \
    }

#endif

/* DEFINE_STORE32 */

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_STORE32(name, t1, t2) DEFINE_STORE(name, t1, t2)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_STORE32(name, t1, t2)                                    \
    static W2C2_INLINE void name(wasmMemory* mem, U64 addr, t2 value) { \
        t1 wrapped = (t1)value;                                         \
        U32 v;                                                          \
        memcpy(&v, &wrapped, sizeof(U32));                              \
        writeSwapU32(mem->data, addr, v);                               \
    }

#endif

/* DEFINE_STORE64 */

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_STORE64(name, t1, t2) DEFINE_STORE(name, t1, t2)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_STORE64(name, t1, t2)                                    \
    static W2C2_INLINE void name(wasmMemory* mem, U64 addr, t2 value) { \
        t1 wrapped = (t1)value;                                         \
        U64 v;                                                          \
        memcpy(&v, &wrapped, sizeof(U64));                              \
        writeSwapU64(mem->data, addr, v);                               \
    }

#endif

DEFINE_LOAD32(i32_load, U32, U32, U32)
DEFINE_LOAD64(i64_load, U64, U64, U64)
DEFINE_LOAD32(f32_load, F32, F32, F32)
DEFINE_LOAD64(f64_load, F64, F64, F64)
DEFINE_LOAD8(i32_load8_s, I8, I32, U32)
DEFINE_LOAD8(i64_load8_s, I8, I64, U64)
DEFINE_LOAD8(i32_load8_u, U8, U32, U32)
DEFINE_LOAD8(i64_load8_u, U8, U64, U64)
DEFINE_LOAD16(i32_load16_s, I16, I32, U32)
DEFINE_LOAD16(i64_load16_s, I16, I64, U64)
DEFINE_LOAD16(i32_load16_u, U16, U32, U32)
DEFINE_LOAD16(i64_load16_u, U16, U64, U64)
DEFINE_LOAD32(i64_load32_s, I32, I64, U64)
DEFINE_LOAD32(i64_load32_u, U32, U64, U64)
DEFINE_STORE32(i32_store, U32, U32)
DEFINE_STORE64(i64_store, U64, U64)
DEFINE_STORE32(f32_store, F32, F32)
DEFINE_STORE64(f64_store, F64, F64)
DEFINE_STORE8(i32_store8, U8, U32)
DEFINE_STORE16(i32_store16, U16, U32)
DEFINE_STORE8(i64_store8, U8, U64)
DEFINE_STORE16(i64_store16, U16, U64)
DEFINE_STORE32(i64_store32, U32, U64)

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_SWAP(size, suffix, type) \
    static W2C2_INLINE void swap_ ## suffix(type* v) { (void)v; }

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_SWAP(size, suffix, type)                \
    static W2C2_INLINE void swap_ ## suffix(type* v) { \
        U ## size tmp;                                 \
        memcpy(&tmp, v, size / 8);                     \
        tmp = swapU ## size(tmp);                      \
        memcpy(v, &tmp, size / 8);                     \
    }

#endif

DEFINE_SWAP(16, s, short)
DEFINE_SWAP(16, S, unsigned short)
DEFINE_SWAP(32, i, int)
DEFINE_SWAP(32, I, unsigned int)
DEFINE_SWAP(32, l, long)
DEFINE_SWAP(32, L, unsigned long)
DEFINE_SWAP(64, q, long long)
DEFINE_SWAP(64, Q, unsigned long long)
DEFINE_SWAP(32, f, float)
DEFINE_SWAP(64, d, double)

typedef void (*wasmFunc)(void);

typedef struct wasmTable {
    wasmFunc* data;
    U32 size, maxSize;
} wasmTable;

static
W2C2_INLINE
void
wasmTableAllocate(
    wasmTable* table,
    const U32 size,
    const U32 maxSize
) {
    table->size = size;
    table->maxSize = maxSize;
    table->data = (wasmFunc*)calloc(size, sizeof(wasmFunc));
}

static
W2C2_INLINE
void
wasmTableFree(
    wasmTable* table
) {
    if (table->data == NULL) {
        return;
    }

    free(table->data);

    table->size = 0;
}

#define TF(table, index, t) ((t)((table).data[index]))

typedef struct wasmFuncExport {
    wasmFunc func;
    char* name;
} wasmFuncExport;

typedef struct wasmModuleInstance {
    wasmFuncExport* funcExports;
    void* (*resolveImports)(const char* module, const char* name);
    struct wasmModuleInstance* (*newChild)(struct wasmModuleInstance* self);
} wasmModuleInstance;


#ifndef __has_feature
#define __has_feature(x) 0
#endif
#ifndef __has_extension
#define __has_extension __has_feature
#endif

#ifdef _MSC_VER
#define WASM_ATOMICS_MSVC
#elif defined(__GNUC__) && (GCC_VERSION >= 40700 || __has_extension(c_atomic))
#define WASM_ATOMICS_GCC
#endif

#ifdef WASM_ATOMICS_MSVC

#include <intrin.h>

#define atomic_load_U8(a) _InterlockedOr8(a, 0)
#define atomic_load_U16(a) _InterlockedOr16(a, 0)
#define atomic_load_U32(a) _InterlockedOr(a, 0)
#define atomic_load_U64(a) _InterlockedOr64(a, 0)

#define atomic_store_U8(a, v) _InterlockedExchange8(a, v)
#define atomic_store_U16(a, v) _InterlockedExchange16(a, v)
#define atomic_store_U32(a, v) _InterlockedExchange(a, v)
#define atomic_store_U64(a, v) _InterlockedExchange64(a, v)

#define atomic_fence() _ReadWriteBarrier()

#elif defined(WASM_ATOMICS_GCC)

/* Use gcc/clang/icc intrinsics */
#define atomic_load_U8(a) __atomic_load_n((U8*)(a), __ATOMIC_SEQ_CST)
#define atomic_load_U16(a) __atomic_load_n((U16*)(a), __ATOMIC_SEQ_CST)
#define atomic_load_U32(a) __atomic_load_n((U32*)(a), __ATOMIC_SEQ_CST)
#define atomic_load_U64(a) __atomic_load_n((U64*)(a), __ATOMIC_SEQ_CST)

#define atomic_store_U8(a, v) __atomic_store_n((U8*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_store_U16(a, v) __atomic_store_n((U16*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_store_U32(a, v) __atomic_store_n((U32*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_store_U64(a, v) __atomic_store_n((U64*)(a), v, __ATOMIC_SEQ_CST)

#define atomic_fence() __atomic_thread_fence(__ATOMIC_SEQ_CST)

#endif

#ifdef WASM_ATOMICS_MSVC

#include <intrin.h>

#define atomic_add_U8(a, v) _InterlockedExchangeAdd8(a, v)
#define atomic_add_U16(a, v) _InterlockedExchangeAdd16(a, v)
#define atomic_add_U32(a, v) _InterlockedExchangeAdd(a, v)
#define atomic_add_U64(a, v) _InterlockedExchangeAdd64(a, v)

#define atomic_sub_U8(a, v) _InterlockedExchangeAdd8(a, -(v))
#define atomic_sub_U16(a, v) _InterlockedExchangeAdd16(a, -(v))
#define atomic_sub_U32(a, v) _InterlockedExchangeAdd(a, -(v))
#define atomic_sub_U64(a, v) _InterlockedExchangeAdd64(a, -(v))

#define atomic_and_U8(a, v) _InterlockedAnd8(a, v)
#define atomic_and_U16(a, v) _InterlockedAnd16(a, v)
#define atomic_and_U32(a, v) _InterlockedAnd(a, v)
#define atomic_and_U64(a, v) _InterlockedAnd64(a, v)

#define atomic_or_U8(a, v) _InterlockedOr8(a, v)
#define atomic_or_U16(a, v) _InterlockedOr16(a, v)
#define atomic_or_U32(a, v) _InterlockedOr(a, v)
#define atomic_or_U64(a, v) _InterlockedOr64(a, v)

#define atomic_xor_U8(a, v) _InterlockedXor8(a, v)
#define atomic_xor_U16(a, v) _InterlockedXor16(a, v)
#define atomic_xor_U32(a, v) _InterlockedXor(a, v)
#define atomic_xor_U64(a, v) _InterlockedXor64(a, v)

#define atomic_exchange_U8(a, v) _InterlockedExchange8(a, v)
#define atomic_exchange_U16(a, v) _InterlockedExchange16(a, v)
#define atomic_exchange_U32(a, v) _InterlockedExchange(a, v)
#define atomic_exchange_U64(a, v) _InterlockedExchange64(a, v)

#define atomic_compare_exchange_U8(a, expected_ptr, desired) \
    _InterlockedCompareExchange8(a, desired, *(expected_ptr))
#define atomic_compare_exchange_U16(a, expected_ptr, desired) \
    _InterlockedCompareExchange16(a, desired, *(expected_ptr))
#define atomic_compare_exchange_U32(a, expected_ptr, desired) \
    _InterlockedCompareExchange(a, desired, *(expected_ptr))
#define atomic_compare_exchange_U64(a, expected_ptr, desired) \
    _InterlockedCompareExchange64(a, desired, *(expected_ptr))

#elif defined(WASM_ATOMICS_GCC)

/* Use gcc/clang/icc intrinsics */

#define atomic_add_U8(a, v) __atomic_fetch_add((U8*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_add_U16(a, v) __atomic_fetch_add((U16*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_add_U32(a, v) __atomic_fetch_add((U32*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_add_U64(a, v) __atomic_fetch_add((U64*)(a), v, __ATOMIC_SEQ_CST)

#define atomic_sub_U8(a, v) __atomic_fetch_sub((U8*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_sub_U16(a, v) __atomic_fetch_sub((U16*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_sub_U32(a, v) __atomic_fetch_sub((U32*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_sub_U64(a, v) __atomic_fetch_sub((U64*)(a), v, __ATOMIC_SEQ_CST)

#define atomic_and_U8(a, v) __atomic_fetch_and((U8*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_and_U16(a, v) __atomic_fetch_and((U16*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_and_U32(a, v) __atomic_fetch_and((U32*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_and_U64(a, v) __atomic_fetch_and((U64*)(a), v, __ATOMIC_SEQ_CST)

#define atomic_or_U8(a, v) __atomic_fetch_or((U8*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_or_U16(a, v) __atomic_fetch_or((U16*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_or_U32(a, v) __atomic_fetch_or((U32*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_or_U64(a, v) __atomic_fetch_or((U64*)(a), v, __ATOMIC_SEQ_CST)

#define atomic_xor_U8(a, v) __atomic_fetch_xor((U8*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_xor_U16(a, v) __atomic_fetch_xor((U16*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_xor_U32(a, v) __atomic_fetch_xor((U32*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_xor_U64(a, v) __atomic_fetch_xor((U64*)(a), v, __ATOMIC_SEQ_CST)

#define atomic_exchange_U8(a, v) __atomic_exchange_n((U8*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_exchange_U16(a, v) __atomic_exchange_n((U16*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_exchange_U32(a, v) __atomic_exchange_n((U32*)(a), v, __ATOMIC_SEQ_CST)
#define atomic_exchange_U64(a, v) __atomic_exchange_n((U64*)(a), v, __ATOMIC_SEQ_CST)

#define __atomic_compare_exchange_helper(a, expected_ptr, desired)        \
  (__atomic_compare_exchange_n(a, expected_ptr, desired, 0 /* is_weak */, \
                               __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST),       \
   *(expected_ptr))

#define atomic_compare_exchange_U8(a, expected_ptr, desired) \
    __atomic_compare_exchange_helper((U8*)(a), expected_ptr, desired)
#define atomic_compare_exchange_U16(a, expected_ptr, desired) \
    __atomic_compare_exchange_helper((U16*)(a), expected_ptr, desired)
#define atomic_compare_exchange_U32(a, expected_ptr, desired) \
    __atomic_compare_exchange_helper((U32*)(a), expected_ptr, desired)
#define atomic_compare_exchange_U64(a, expected_ptr, desired) \
    __atomic_compare_exchange_helper((U64*)(a), expected_ptr, desired)

#endif

#if defined(WASM_ATOMICS_MSVC) || defined(WASM_ATOMICS_GCC)

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_ATOMIC_LOAD(name, t1, t2)                    \
    static W2C2_INLINE t2 name(wasmMemory* mem, U64 addr) { \
        t1 result;                                          \
        result = atomic_load_##t1(&mem->data[addr]);        \
        return (t2)result;                                  \
    }

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_ATOMIC_LOAD(name, t1, t2)                    \
    static W2C2_INLINE t2 name(wasmMemory* mem, U64 addr) { \
        t1 result;                                          \
        result = atomic_load_##t1(&mem->data[addr]);        \
        result = swap##t1(result);                          \
        return (t2)result;                                  \
    }

#endif

DEFINE_ATOMIC_LOAD(i32_atomic_load8_u, U8, U32)
DEFINE_ATOMIC_LOAD(i64_atomic_load8_u, U8, U64)
DEFINE_ATOMIC_LOAD(i32_atomic_load16_u, U16, U32)
DEFINE_ATOMIC_LOAD(i64_atomic_load16_u, U16, U64)
DEFINE_ATOMIC_LOAD(i64_atomic_load32_u, U32, U64)
DEFINE_ATOMIC_LOAD(i32_atomic_load, U32, U32)
DEFINE_ATOMIC_LOAD(i64_atomic_load, U64, U64)

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_ATOMIC_STORE(name, t1, t2)                               \
    static W2C2_INLINE void name(wasmMemory* mem, U64 addr, t2 value) { \
        t1 wrapped = (t1)value;                                         \
        atomic_store_##t1(&mem->data[addr], wrapped);                   \
    }

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_ATOMIC_STORE(name, t1, t2)                               \
    static W2C2_INLINE void name(wasmMemory* mem, U64 addr, t2 value) { \
        t1 wrapped = (t1)value;                                         \
        wrapped = swap##t1(wrapped);                                    \
        atomic_store_##t1(&mem->data[addr], wrapped);                   \
    }

#endif

DEFINE_ATOMIC_STORE(i32_atomic_store, U32, U32)
DEFINE_ATOMIC_STORE(i64_atomic_store, U64, U64)
DEFINE_ATOMIC_STORE(i32_atomic_store8, U8, U32)
DEFINE_ATOMIC_STORE(i32_atomic_store16, U16, U32)
DEFINE_ATOMIC_STORE(i64_atomic_store8, U8, U64)
DEFINE_ATOMIC_STORE(i64_atomic_store16, U16, U64)
DEFINE_ATOMIC_STORE(i64_atomic_store32, U32, U64)

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_ATOMIC_RMW(name, op, op2, size, t)                           \
    static W2C2_INLINE t name(wasmMemory* mem, U64 addr, t value) {         \
        U ## size wrapped = (U ## size)value;                               \
        U ## size ret = atomic_##op##_##U##size(&mem->data[addr], wrapped); \
        return (t)ret;                                                      \
    }

#elif WASM_ENDIAN == WASM_BIG_ENDIAN && defined(WASM_MUTEX_TYPE)

#define DEFINE_ATOMIC_RMW(name, op, op2, size, t)                   \
    static W2C2_INLINE t name(wasmMemory* mem, U64 addr, t value) { \
        U ## size old = 0;                                          \
        U ## size wrapped = 0;                                      \
        U ## size new = 0;                                          \
        WASM_MUTEX_LOCK(&mem->mutex);                               \
        old = readSwapU ## size(mem->data, addr);                   \
        wrapped = (U ## size)value;                                 \
        new = old op2 wrapped;                                      \
        writeSwapU ## size(mem->data, addr, new);                   \
        WASM_MUTEX_UNLOCK(&mem->mutex);                             \
        return (t)old;                                              \
    }

#endif

#if (WASM_ENDIAN == WASM_LITTLE_ENDIAN) || (WASM_ENDIAN == WASM_BIG_ENDIAN && defined(WASM_MUTEX_TYPE))
DEFINE_ATOMIC_RMW(i32_atomic_rmw8_add_u, add, +, 8, U32)
DEFINE_ATOMIC_RMW(i32_atomic_rmw16_add_u, add, +, 16, U32)
DEFINE_ATOMIC_RMW(i32_atomic_rmw_add, add, +, 32, U32)
DEFINE_ATOMIC_RMW(i64_atomic_rmw8_add_u, add, +, 8, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw16_add_u, add, +, 16, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw32_add_u, add, +, 32, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw_add, add, +, 64, U64)

DEFINE_ATOMIC_RMW(i32_atomic_rmw8_sub_u, sub, -, 8, U32)
DEFINE_ATOMIC_RMW(i32_atomic_rmw16_sub_u, sub, -, 16, U32)
DEFINE_ATOMIC_RMW(i32_atomic_rmw_sub, sub, -, 32, U32)
DEFINE_ATOMIC_RMW(i64_atomic_rmw8_sub_u, sub, -, 8, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw16_sub_u, sub, -, 16, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw32_sub_u, sub, -, 32, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw_sub, sub, -, 64, U64)

DEFINE_ATOMIC_RMW(i32_atomic_rmw8_and_u, and, &, 8, U32)
DEFINE_ATOMIC_RMW(i32_atomic_rmw16_and_u, and, &, 16, U32)
DEFINE_ATOMIC_RMW(i32_atomic_rmw_and, and, &, 32, U32)
DEFINE_ATOMIC_RMW(i64_atomic_rmw8_and_u, and, &, 8, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw16_and_u, and, &, 16, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw32_and_u, and, &, 32, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw_and, and, &, 64, U64)

DEFINE_ATOMIC_RMW(i32_atomic_rmw8_or_u, or, |, 8, U32)
DEFINE_ATOMIC_RMW(i32_atomic_rmw16_or_u, or, |, 16, U32)
DEFINE_ATOMIC_RMW(i32_atomic_rmw_or, or, |, 32, U32)
DEFINE_ATOMIC_RMW(i64_atomic_rmw8_or_u, or, |, 8, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw16_or_u, or, |, 16, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw32_or_u, or, |, 32, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw_or, or, |, 64, U64)

DEFINE_ATOMIC_RMW(i32_atomic_rmw8_xor_u, xor, ^, 8, U32)
DEFINE_ATOMIC_RMW(i32_atomic_rmw16_xor_u, xor, ^, 16, U32)
DEFINE_ATOMIC_RMW(i32_atomic_rmw_xor, xor, ^, 32, U32)
DEFINE_ATOMIC_RMW(i64_atomic_rmw8_xor_u, xor, ^, 8, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw16_xor_u, xor, ^, 16, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw32_xor_u, xor, ^, 32, U64)
DEFINE_ATOMIC_RMW(i64_atomic_rmw_xor, xor, ^, 64, U64)
#endif

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_ATOMIC_RMW_XCHG(name, size, t) \
    DEFINE_ATOMIC_RMW(name, exchange, +0*, size, t)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN && defined(WASM_MUTEX_TYPE)

#define DEFINE_ATOMIC_RMW_XCHG(name, size, t)                       \
    static W2C2_INLINE t name(wasmMemory* mem, U64 addr, t value) { \
        U ## size old = 0;                                          \
        U ## size wrapped = 0;                                      \
        WASM_MUTEX_LOCK(&mem->mutex);                               \
        old = readSwapU ## size(mem->data, addr);                   \
        wrapped = (U ## size)value;                                 \
        writeSwapU ## size(mem->data, addr, wrapped);               \
        WASM_MUTEX_UNLOCK(&mem->mutex);                             \
        return (t)old;                                              \
    }

#endif

#if (WASM_ENDIAN == WASM_LITTLE_ENDIAN) || (WASM_ENDIAN == WASM_BIG_ENDIAN && defined(WASM_MUTEX_TYPE))
DEFINE_ATOMIC_RMW_XCHG(i32_atomic_rmw8_xchg_u, 8, U32)
DEFINE_ATOMIC_RMW_XCHG(i32_atomic_rmw16_xchg_u, 16, U32)
DEFINE_ATOMIC_RMW_XCHG(i32_atomic_rmw_xchg, 32, U32)
DEFINE_ATOMIC_RMW_XCHG(i64_atomic_rmw8_xchg_u, 8, U64)
DEFINE_ATOMIC_RMW_XCHG(i64_atomic_rmw16_xchg_u, 16, U64)
DEFINE_ATOMIC_RMW_XCHG(i64_atomic_rmw32_xchg_u, 32, U64)
DEFINE_ATOMIC_RMW_XCHG(i64_atomic_rmw_xchg, 64, U64)
#endif

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_ATOMIC_RMW_CMPXCHG(name, size, t)                                      \
    static W2C2_INLINE t name(wasmMemory* mem, U64 addr, t expected, t replacement) { \
        U ## size expected_wrapped = (U ## size)expected;                             \
        U ## size replacement_wrapped = (U ## size)replacement;                       \
        U ## size old = atomic_compare_exchange_U##size(                              \
            &mem->data[addr],                                                         \
            &expected_wrapped,                                                        \
            replacement_wrapped                                                       \
        );                                                                            \
        return (t)old;                                                                \
    }

#elif WASM_ENDIAN == WASM_BIG_ENDIAN && defined(WASM_MUTEX_TYPE)

#define DEFINE_ATOMIC_RMW_CMPXCHG(name, size, t)                                      \
    static W2C2_INLINE t name(wasmMemory* mem, U64 addr, t expected, t replacement) { \
        U ## size old = 0;                                                            \
        U ## size expected_wrapped = (U ## size)expected;                             \
        U ## size replacement_wrapped = (U ## size)replacement;                       \
        WASM_MUTEX_LOCK(&mem->mutex);                                                 \
        expected_wrapped = (U ## size)expected;                                       \
        replacement_wrapped = (U ## size)replacement;                                 \
        old = readSwapU ## size(mem->data, addr);                                     \
        if (old == expected_wrapped) {                                                \
            writeSwapU ## size(mem->data, addr, replacement_wrapped);                 \
        }                                                                             \
        WASM_MUTEX_UNLOCK(&mem->mutex);                                               \
        return (t)old;                                                                \
    }

#endif

#if (WASM_ENDIAN == WASM_LITTLE_ENDIAN) || (WASM_ENDIAN == WASM_BIG_ENDIAN && defined(WASM_MUTEX_TYPE))
DEFINE_ATOMIC_RMW_CMPXCHG(i32_atomic_rmw8_cmpxchg_u, 8, U32)
DEFINE_ATOMIC_RMW_CMPXCHG(i32_atomic_rmw16_cmpxchg_u, 16, U32)
DEFINE_ATOMIC_RMW_CMPXCHG(i32_atomic_rmw_cmpxchg, 32, U32)
DEFINE_ATOMIC_RMW_CMPXCHG(i64_atomic_rmw8_cmpxchg_u, 8, U64)
DEFINE_ATOMIC_RMW_CMPXCHG(i64_atomic_rmw16_cmpxchg_u, 16, U64)
DEFINE_ATOMIC_RMW_CMPXCHG(i64_atomic_rmw32_cmpxchg_u, 32, U64)
DEFINE_ATOMIC_RMW_CMPXCHG(i64_atomic_rmw_cmpxchg, 64, U64)
#endif

#endif /* WASM_ATOMICS_MSVC || WASM_ATOMICS_GCC */

U32
wasmMemoryAtomicWait(
    wasmMemory* mem,
    U32 address,
    U64 expect,
    I64 timeout,
    bool wait64
);

U32
wasmMemoryAtomicNotify(
    wasmMemory *mem,
    U32 address,
    U32 count
);

#ifdef __cplusplus
}
#endif

#endif /* W2C2_BASE_H */
