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

#ifndef __bool_true_false_are_defined
typedef enum bool {
    false = 0,
    true = 1
} bool;
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

#if WASM_ENDIAN == WASM_BIG_ENDIAN

/*
 * Use compiler byte-swapping intrinsics if they are available.
 * 32-bit and 64-bit versions are available in Clang and GCC as of GCC 4.8.0.
 */
#if defined(__clang__) || (defined(__GNUC__) && ((__GNUC__ == 4 && __GNUC_MINOR__ >= 8) || __GNUC__ >= 5))

#define swap16(x) __builtin_bswap16(x)
#define swap32(x) __builtin_bswap32(x)
#define swap64(x) __builtin_bswap64(x)

#elif defined(__APPLE__)

#include <libkern/OSByteOrder.h>

#define swap16(x) OSSwapInt16(x)
#define swap32(x) OSSwapInt32(x)
#define swap64(x) OSSwapInt64(x)

#else

/*
 * Mask, and then shift.
 * Mask, and then shift.
 * Mask, and then shift.
 * Mask, and then shift.
 */
#define swap16(x) ((((x) & 0xFF00) >> 8) \
                 | (((x) & 0x00FF) << 8))
#define swap32(x) ((((x) & 0xFF000000) >> 24) \
                 | (((x) & 0x00FF0000) >> 8 ) \
                 | (((x) & 0x0000FF00) << 8 ) \
                 | (((x) & 0x000000FF) << 24))
#define swap64(x) ((((x) & 0xff00000000000000ull) >> 56) \
                 | (((x) & 0x00ff000000000000ull) >> 40) \
                 | (((x) & 0x0000ff0000000000ull) >> 24) \
                 | (((x) & 0x000000ff00000000ull) >> 8 ) \
                 | (((x) & 0x00000000ff000000ull) << 8 ) \
                 | (((x) & 0x0000000000ff0000ull) << 24) \
                 | (((x) & 0x000000000000ff00ull) << 40) \
                 | (((x) & 0x00000000000000ffull) << 56))

#endif

#elif WASM_ENDIAN == WASM_LITTLE_ENDIAN
#define swap32(x) (x)
#define swap64(x) (x)
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
#define UNUSED __attribute__((__unused__))
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
    size_t size
) {
    assert(size <= UINT32_MAX);
    return (U32) size;
}

typedef enum Trap {
    trapUnreachable,
    trapDivByZero,
    trapIntOverflow,
    trapInvalidConversion
} Trap;

static
W2C2_INLINE
const char*
trapDescription(
    Trap trap
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
    U32 x
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
    U64 x
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

typedef struct wasmMemory {
    U8* data;
    U32 pages, maxPages;
    U32 size;
} wasmMemory;

#define WASM_PAGE_SIZE 65536

static
W2C2_INLINE
void
wasmMemoryAllocate(
    wasmMemory* memory,
    U32 initialPages,
    U32 maxPages
) {
    U32 size = initialPages * WASM_PAGE_SIZE;
    memory->data = calloc(size, 1);
    memory->size = size;
    memory->pages = initialPages;
    memory->maxPages = maxPages;
}

static
W2C2_INLINE
void
wasmMemoryFree(
    wasmMemory* memory
) {
    if (memory->data == NULL) {
        return;
    }

    free(memory->data);

    memory->size = 0;
    memory->pages = 0;
}

static
W2C2_INLINE
U32
wasmMemoryGrow(
    wasmMemory* memory,
    U32 delta
) {
    U32 oldPages = memory->pages;
    U32 newPages = memory->pages + delta;

    if (newPages == 0) {
        return 0;
    }

    if (newPages < oldPages || newPages > memory->maxPages) {
        return (U32) -1;
    }

    {
        U32 oldSize = oldPages * WASM_PAGE_SIZE;
        U32 newSize = newPages * WASM_PAGE_SIZE;
        U32 deltaSize = delta * WASM_PAGE_SIZE;
        U8* newData = realloc(memory->data, newSize);
        if (newData == NULL) {
            return (U32) -1;
        }

        memset(newData + oldSize, 0, deltaSize);
        memory->pages = newPages;
        memory->size = newSize;
        memory->data = newData;
    }

    return oldPages;
}

static
W2C2_INLINE
void
wasmMemoryCopy(
    wasmMemory* destinationMemory,
    wasmMemory* sourceMemory,
    U32 destinationAddress,
    U32 sourceAddress,
    U32 count
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
    wasmMemory* memory,
    U32 destinationAddress,
    U32 value,
    U32 count
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
    size_t n
) {
    memcpy(dest, src, n);
}

#if WASM_ENDIAN == WASM_BIG_ENDIAN

#if defined(__APPLE__)

#include <libkern/OSByteOrder.h>

#define readSwap16(base, offset) OSReadSwapInt16(base, offset)
#define readSwap32(base, offset) OSReadSwapInt32(base, offset)
#define readSwap64(base, offset) OSReadSwapInt64(base, offset)

#define writeSwap16(base, offset, value) OSWriteSwapInt16(base, offset, value)
#define writeSwap32(base, offset, value) OSWriteSwapInt32(base, offset, value)
#define writeSwap64(base, offset, value) OSWriteSwapInt64(base, offset, value)

#else

#define readSwap16(base, offset) swap16(*(U16*)((base) + (offset)))
#define readSwap32(base, offset) swap32(*(U32*)((base) + (offset)))
#define readSwap64(base, offset) swap64(*(U64*)((base) + (offset)))

#define writeSwap16(base, offset, value) (*(U16*)((base) + (offset)) = swap16(value))
#define writeSwap32(base, offset, value) (*(U32*)((base) + (offset)) = swap32(value))
#define writeSwap64(base, offset, value) (*(U64*)((base) + (offset)) = swap64(value))

#endif

#endif

/* LOAD_DATA */

#define LOAD_DATA(m, o, i, s) \
    load_data(&((m).data[o]), i, s)

/* DEFINE_LOAD */

#define DEFINE_LOAD(name, t1, t2, t3)                        \
    static W2C2_INLINE t3 name(wasmMemory* mem, U64 addr) {  \
        t1 result;                                           \
        memcpy(&result, &mem->data[addr], sizeof(t1));       \
        return (t3)(t2)result;                               \
    }

/* DEFINE_LOAD8 */

#define DEFINE_LOAD8(name, t1, t2, t3) DEFINE_LOAD(name, t1, t2, t3)

/* DEFINE_LOAD16 */

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_LOAD16(name, t1, t2, t3) DEFINE_LOAD(name, t1, t2, t3)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_LOAD16(name, t1, t2, t3)                      \
    static W2C2_INLINE t3 name(wasmMemory* mem, U64 addr) {  \
        t1 result;                                           \
        U16 v = readSwap16(mem->data, addr);                 \
        memcpy(&result, &v, sizeof(U16));                    \
        return (t3)(t2)result;                               \
    }

#endif

/* DEFINE_LOAD32 */

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_LOAD32(name, t1, t2, t3) DEFINE_LOAD(name, t1, t2, t3)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_LOAD32(name, t1, t2, t3)                      \
    static W2C2_INLINE t3 name(wasmMemory* mem, U64 addr) {  \
        t1 result;                                           \
        U32 v = readSwap32(mem->data, addr);                 \
        memcpy(&result, &v, sizeof(U32));                    \
        return (t3)(t2)result;                               \
    }

#endif

/* DEFINE_LOAD64 */

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_LOAD64(name, t1, t2, t3) DEFINE_LOAD(name, t1, t2, t3)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_LOAD64(name, t1, t2, t3)                      \
    static W2C2_INLINE t3 name(wasmMemory* mem, U64 addr) {  \
        t1 result;                                           \
        U64 v = readSwap64(mem->data, addr);                 \
        memcpy(&result, &v, sizeof(U64));                    \
        return (t3)(t2)result;                               \
    }

#endif

/* DEFINE_STORE */

#define DEFINE_STORE(name, t1, t2)                                       \
    static W2C2_INLINE void name(wasmMemory* mem, U64 addr, t2 value) {  \
        t1 wrapped = (t1)value;                                          \
        memcpy(&mem->data[addr], &wrapped, sizeof(t1));                  \
    }

/* DEFINE_STORE8 */

#define DEFINE_STORE8(name, t1, t2) DEFINE_STORE(name, t1, t2)

/* DEFINE_STORE16 */

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_STORE16(name, t1, t2) DEFINE_STORE(name, t1, t2)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_STORE16(name, t1, t2)                                     \
    static W2C2_INLINE void name(wasmMemory* mem, U64 addr, t2 value) {  \
        t1 wrapped = (t1)value;                                          \
        U16 v;                                                           \
        memcpy(&v, &wrapped, sizeof(U16));                               \
        writeSwap16(mem->data, addr, v);                                 \
    }

#endif

/* DEFINE_STORE32 */

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_STORE32(name, t1, t2) DEFINE_STORE(name, t1, t2)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_STORE32(name, t1, t2)                                     \
    static W2C2_INLINE void name(wasmMemory* mem, U64 addr, t2 value) {  \
        t1 wrapped = (t1)value;                                          \
        U32 v;                                                           \
        memcpy(&v, &wrapped, sizeof(U32));                               \
        writeSwap32(mem->data, addr, v);                                 \
    }

#endif

/* DEFINE_STORE64 */

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN

#define DEFINE_STORE64(name, t1, t2) DEFINE_STORE(name, t1, t2)

#elif WASM_ENDIAN == WASM_BIG_ENDIAN

#define DEFINE_STORE64(name, t1, t2)                                     \
    static W2C2_INLINE void name(wasmMemory* mem, U64 addr, t2 value) {  \
        t1 wrapped = (t1)value;                                          \
        U64 v;                                                           \
        memcpy(&v, &wrapped, sizeof(U64));                               \
        writeSwap64(mem->data, addr, v);                                 \
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
    U32 size,
    U32 maxSize
) {
    table->size = size;
    table->maxSize = maxSize;
    table->data = calloc(size, sizeof(wasmFunc));
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

#endif /* W2C2_BASE_H */
