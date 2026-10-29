/* SPDX-License-Identifier: Apache-2.0
 * SIMD memory and endian adapters derived from WABT wasm2c
 * src/template/wasm2c_simd.declarations.c (e5cc0c4b7c46a322cd1673ffd904c69ae8625ce3).
 * Copyright the WABT authors. Licensed under the Apache License, Version 2.0.
 */
#ifndef W2C2_SIMD_H
#define W2C2_SIMD_H

#include "w2c2_base.h"
/* Keep third-party diagnostic policy out of generated application code. */
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#elif defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ >= 406)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wpedantic"
#endif
#ifndef W2C2_SIMDE_HEADER
#error "SIMD output requires SIMDe. Define W2C2_SIMDE_HEADER to the path of simde/wasm/simd128.h."
#else
#include W2C2_SIMDE_HEADER
#endif
#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ >= 406)
#pragma GCC diagnostic pop
#endif

typedef simde_v128_t V128;

/* wasm2c reverses linear memory on big-endian hosts. w2c2 keeps Wasm
 * memory in byte order, so reverse each access at the SIMD boundary. */
static W2C2_INLINE void
w2c2_simd_copy(void* dest, const void* source, size_t size) {
#if WASM_ENDIAN == WASM_BIG_ENDIAN
    size_t index;
    U8* out = (U8*)dest;
    const U8* in = (const U8*)source;
    for (index = 0; index < size; index++) out[index] = in[size - 1 - index];
#else
    memcpy(dest, source, size);
#endif
}

#if WASM_ENDIAN == WASM_BIG_ENDIAN
#define W2C2_SIMD_LANE(t, lane) ((int)(16 / sizeof(t)) - 1 - (lane))
#else
#define W2C2_SIMD_LANE(t, lane) (lane)
#endif

/* memcpy-based unaligned access. Checks use the actual access width,
 * including loads which extend lanes or zero the upper half. */
#define DEFINE_SIMD_LOAD_FUNC(name, func, t) \
    static W2C2_INLINE V128 name(wasmMemory* mem, WasmMemoryAddress addr) { \
        t value; \
        wasmMemoryCheckRange(mem, addr, sizeof(t)); \
        w2c2_simd_copy(&value, mem->data + addr, sizeof(t)); \
        return func(&value); \
    }
#define DEFINE_SIMD_LOAD_LANE(name, func, t, lane) \
    static W2C2_INLINE V128 name(wasmMemory* mem, WasmMemoryAddress addr, V128 vec) { \
        t value; \
        wasmMemoryCheckRange(mem, addr, sizeof(t)); \
        w2c2_simd_copy(&value, mem->data + addr, sizeof(t)); \
        return func(&value, vec, W2C2_SIMD_LANE(t, lane)); \
    }
#define DEFINE_SIMD_STORE(name, t) \
    static W2C2_INLINE void name(wasmMemory* mem, WasmMemoryAddress addr, V128 vec) { \
        t value; \
        wasmMemoryCheckRange(mem, addr, sizeof(t)); \
        simde_wasm_v128_store(&value, vec); \
        w2c2_simd_copy(mem->data + addr, &value, sizeof(t)); \
    }
#define DEFINE_SIMD_STORE_LANE(name, func, t, lane) \
    static W2C2_INLINE void name(wasmMemory* mem, WasmMemoryAddress addr, V128 vec) { \
        t value; \
        wasmMemoryCheckRange(mem, addr, sizeof(t)); \
        func(&value, vec, W2C2_SIMD_LANE(t, lane)); \
        w2c2_simd_copy(mem->data + addr, &value, sizeof(t)); \
    }


#if (WASM_ENDIAN == WASM_BIG_ENDIAN)
static W2C2_INLINE V128 w2c2_v128_impl_load32_zero(const void* a) {
  return simde_wasm_i8x16_swizzle(
      simde_wasm_v128_load32_zero(a),
      simde_wasm_i8x16_const(12,13,14,15,8,9,10,11,4,5,6,7,0,1,2,3));
}
static W2C2_INLINE V128 w2c2_v128_impl_load64_zero(const void* a) {
  return simde_wasm_i8x16_swizzle(
      simde_wasm_v128_load64_zero(a),
      simde_wasm_i8x16_const(8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7));
}
#else
#define w2c2_v128_impl_load32_zero simde_wasm_v128_load32_zero
#define w2c2_v128_impl_load64_zero simde_wasm_v128_load64_zero
#endif

DEFINE_SIMD_LOAD_FUNC(w2c2_v128_load, simde_wasm_v128_load, V128)

DEFINE_SIMD_LOAD_FUNC(w2c2_v128_load8_splat, simde_wasm_v128_load8_splat, U8)
DEFINE_SIMD_LOAD_FUNC(w2c2_v128_load16_splat, simde_wasm_v128_load16_splat, U16)
DEFINE_SIMD_LOAD_FUNC(w2c2_v128_load32_splat, simde_wasm_v128_load32_splat, U32)
DEFINE_SIMD_LOAD_FUNC(w2c2_v128_load64_splat, simde_wasm_v128_load64_splat, U64)

DEFINE_SIMD_LOAD_FUNC(w2c2_i16x8_load8x8, simde_wasm_i16x8_load8x8, U64)
DEFINE_SIMD_LOAD_FUNC(w2c2_u16x8_load8x8, simde_wasm_u16x8_load8x8, U64)
DEFINE_SIMD_LOAD_FUNC(w2c2_i32x4_load16x4, simde_wasm_i32x4_load16x4, U64)
DEFINE_SIMD_LOAD_FUNC(w2c2_u32x4_load16x4, simde_wasm_u32x4_load16x4, U64)
DEFINE_SIMD_LOAD_FUNC(w2c2_i64x2_load32x2, simde_wasm_i64x2_load32x2, U64)
DEFINE_SIMD_LOAD_FUNC(w2c2_u64x2_load32x2, simde_wasm_u64x2_load32x2, U64)

DEFINE_SIMD_LOAD_FUNC(w2c2_v128_load32_zero, w2c2_v128_impl_load32_zero, U32)
DEFINE_SIMD_LOAD_FUNC(w2c2_v128_load64_zero, w2c2_v128_impl_load64_zero, U64)

DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane0, simde_wasm_v128_load8_lane, U8, 0)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane1, simde_wasm_v128_load8_lane, U8, 1)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane2, simde_wasm_v128_load8_lane, U8, 2)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane3, simde_wasm_v128_load8_lane, U8, 3)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane4, simde_wasm_v128_load8_lane, U8, 4)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane5, simde_wasm_v128_load8_lane, U8, 5)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane6, simde_wasm_v128_load8_lane, U8, 6)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane7, simde_wasm_v128_load8_lane, U8, 7)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane8, simde_wasm_v128_load8_lane, U8, 8)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane9, simde_wasm_v128_load8_lane, U8, 9)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane10, simde_wasm_v128_load8_lane, U8, 10)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane11, simde_wasm_v128_load8_lane, U8, 11)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane12, simde_wasm_v128_load8_lane, U8, 12)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane13, simde_wasm_v128_load8_lane, U8, 13)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane14, simde_wasm_v128_load8_lane, U8, 14)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load8_lane15, simde_wasm_v128_load8_lane, U8, 15)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load16_lane0, simde_wasm_v128_load16_lane, U16, 0)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load16_lane1, simde_wasm_v128_load16_lane, U16, 1)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load16_lane2, simde_wasm_v128_load16_lane, U16, 2)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load16_lane3, simde_wasm_v128_load16_lane, U16, 3)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load16_lane4, simde_wasm_v128_load16_lane, U16, 4)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load16_lane5, simde_wasm_v128_load16_lane, U16, 5)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load16_lane6, simde_wasm_v128_load16_lane, U16, 6)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load16_lane7, simde_wasm_v128_load16_lane, U16, 7)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load32_lane0, simde_wasm_v128_load32_lane, U32, 0)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load32_lane1, simde_wasm_v128_load32_lane, U32, 1)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load32_lane2, simde_wasm_v128_load32_lane, U32, 2)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load32_lane3, simde_wasm_v128_load32_lane, U32, 3)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load64_lane0, simde_wasm_v128_load64_lane, U64, 0)
DEFINE_SIMD_LOAD_LANE(w2c2_v128_load64_lane1, simde_wasm_v128_load64_lane, U64, 1)

DEFINE_SIMD_STORE(w2c2_v128_store, V128)

DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane0, simde_wasm_v128_store8_lane, U8, 0)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane1, simde_wasm_v128_store8_lane, U8, 1)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane2, simde_wasm_v128_store8_lane, U8, 2)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane3, simde_wasm_v128_store8_lane, U8, 3)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane4, simde_wasm_v128_store8_lane, U8, 4)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane5, simde_wasm_v128_store8_lane, U8, 5)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane6, simde_wasm_v128_store8_lane, U8, 6)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane7, simde_wasm_v128_store8_lane, U8, 7)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane8, simde_wasm_v128_store8_lane, U8, 8)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane9, simde_wasm_v128_store8_lane, U8, 9)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane10, simde_wasm_v128_store8_lane, U8, 10)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane11, simde_wasm_v128_store8_lane, U8, 11)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane12, simde_wasm_v128_store8_lane, U8, 12)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane13, simde_wasm_v128_store8_lane, U8, 13)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane14, simde_wasm_v128_store8_lane, U8, 14)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store8_lane15, simde_wasm_v128_store8_lane, U8, 15)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store16_lane0, simde_wasm_v128_store16_lane, U16, 0)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store16_lane1, simde_wasm_v128_store16_lane, U16, 1)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store16_lane2, simde_wasm_v128_store16_lane, U16, 2)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store16_lane3, simde_wasm_v128_store16_lane, U16, 3)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store16_lane4, simde_wasm_v128_store16_lane, U16, 4)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store16_lane5, simde_wasm_v128_store16_lane, U16, 5)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store16_lane6, simde_wasm_v128_store16_lane, U16, 6)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store16_lane7, simde_wasm_v128_store16_lane, U16, 7)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store32_lane0, simde_wasm_v128_store32_lane, U32, 0)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store32_lane1, simde_wasm_v128_store32_lane, U32, 1)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store32_lane2, simde_wasm_v128_store32_lane, U32, 2)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store32_lane3, simde_wasm_v128_store32_lane, U32, 3)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store64_lane0, simde_wasm_v128_store64_lane, U64, 0)
DEFINE_SIMD_STORE_LANE(w2c2_v128_store64_lane1, simde_wasm_v128_store64_lane, U64, 1)

#if (WASM_ENDIAN == WASM_BIG_ENDIAN)
#define w2c2_v128_const(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) simde_wasm_i8x16_const(p,o,n,m,l,k,j,i,h,g,f,e,d,c,b,a)
#define w2c2_v128_i8x16_extract_lane(v, l) simde_wasm_i8x16_extract_lane(v, 15-(l))
#define w2c2_v128_u8x16_extract_lane(v, l) simde_wasm_u8x16_extract_lane(v, 15-(l))
#define w2c2_v128_i16x8_extract_lane(v, l) simde_wasm_i16x8_extract_lane(v, 7-(l))
#define w2c2_v128_u16x8_extract_lane(v, l) simde_wasm_u16x8_extract_lane(v, 7-(l))
#define w2c2_v128_i32x4_extract_lane(v, l) simde_wasm_i32x4_extract_lane(v, 3-(l))
#define w2c2_v128_i64x2_extract_lane(v, l) simde_wasm_i64x2_extract_lane(v, 1-(l))
#define w2c2_v128_f32x4_extract_lane(v, l) simde_wasm_f32x4_extract_lane(v, 3-(l))
#define w2c2_v128_f64x2_extract_lane(v, l) simde_wasm_f64x2_extract_lane(v, 1-(l))
#define w2c2_v128_i8x16_replace_lane(v, l, x) simde_wasm_i8x16_replace_lane(v, 15-(l), x)
#define w2c2_v128_u8x16_replace_lane(v, l, x) simde_wasm_u8x16_replace_lane(v, 15-(l), x)
#define w2c2_v128_i16x8_replace_lane(v, l, x) simde_wasm_i16x8_replace_lane(v, 7-(l), x)
#define w2c2_v128_u16x8_replace_lane(v, l, x) simde_wasm_u16x8_replace_lane(v, 7-(l), x)
#define w2c2_v128_i32x4_replace_lane(v, l, x) simde_wasm_i32x4_replace_lane(v, 3-(l), x)
#define w2c2_v128_i64x2_replace_lane(v, l, x) simde_wasm_i64x2_replace_lane(v, 1-(l), x)
#define w2c2_v128_f32x4_replace_lane(v, l, x) simde_wasm_f32x4_replace_lane(v, 3-(l), x)
#define w2c2_v128_f64x2_replace_lane(v, l, x) simde_wasm_f64x2_replace_lane(v, 1-(l), x)
#define w2c2_v128_i8x16_bitmask(v) simde_wasm_i8x16_bitmask(simde_wasm_i8x16_swizzle(v, simde_wasm_i8x16_const(15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)))
#define w2c2_v128_i16x8_bitmask(v) simde_wasm_i16x8_bitmask(simde_wasm_i8x16_swizzle(v, simde_wasm_i8x16_const(14,15,12,13,10,11,8,9,6,7,4,5,2,3,0,1)))
#define w2c2_v128_i32x4_bitmask(v) simde_wasm_i32x4_bitmask(simde_wasm_i8x16_swizzle(v, simde_wasm_i8x16_const(12,13,14,15,8,9,10,11,4,5,6,7,0,1,2,3)))
#define w2c2_v128_i64x2_bitmask(v) simde_wasm_i64x2_bitmask(simde_wasm_i8x16_swizzle(v, simde_wasm_i8x16_const(8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7)))
#define w2c2_v128_i8x16_swizzle(v1, v2) simde_wasm_i8x16_swizzle(v1, simde_wasm_v128_xor(v2, simde_wasm_i8x16_splat(15)))
#define w2c2_v128_i8x16_shuffle(v1,v2,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) simde_wasm_i8x16_shuffle(v2,v1,31-(p),31-(o),31-(n),31-(m),31-(l),31-(k),31-(j),31-(i),31-(h),31-(g),31-(f),31-(e),31-(d),31-(c),31-(b),31-(a))
#define w2c2_v128_i16x8_extmul_high_i8x16 simde_wasm_i16x8_extmul_low_i8x16
#define w2c2_v128_u16x8_extmul_high_u8x16 simde_wasm_u16x8_extmul_low_u8x16
#define w2c2_v128_i16x8_extmul_low_i8x16  simde_wasm_i16x8_extmul_high_i8x16
#define w2c2_v128_u16x8_extmul_low_u8x16  simde_wasm_u16x8_extmul_high_u8x16
#define w2c2_v128_i32x4_extmul_high_i16x8 simde_wasm_i32x4_extmul_low_i16x8
#define w2c2_v128_u32x4_extmul_high_u16x8 simde_wasm_u32x4_extmul_low_u16x8
#define w2c2_v128_i32x4_extmul_low_i16x8  simde_wasm_i32x4_extmul_high_i16x8
#define w2c2_v128_u32x4_extmul_low_u16x8  simde_wasm_u32x4_extmul_high_u16x8
#define w2c2_v128_i64x2_extmul_high_i32x4 simde_wasm_i64x2_extmul_low_i32x4
#define w2c2_v128_u64x2_extmul_high_u32x4 simde_wasm_u64x2_extmul_low_u32x4
#define w2c2_v128_i64x2_extmul_low_i32x4  simde_wasm_i64x2_extmul_high_i32x4
#define w2c2_v128_u64x2_extmul_low_u32x4  simde_wasm_u64x2_extmul_high_u32x4
#define w2c2_v128_i16x8_extend_high_i8x16 simde_wasm_i16x8_extend_low_i8x16
#define w2c2_v128_u16x8_extend_high_u8x16 simde_wasm_u16x8_extend_low_u8x16
#define w2c2_v128_i16x8_extend_low_i8x16  simde_wasm_i16x8_extend_high_i8x16
#define w2c2_v128_u16x8_extend_low_u8x16  simde_wasm_u16x8_extend_high_u8x16
#define w2c2_v128_i32x4_extend_high_i16x8 simde_wasm_i32x4_extend_low_i16x8
#define w2c2_v128_u32x4_extend_high_u16x8 simde_wasm_u32x4_extend_low_u16x8
#define w2c2_v128_i32x4_extend_low_i16x8  simde_wasm_i32x4_extend_high_i16x8
#define w2c2_v128_u32x4_extend_low_u16x8  simde_wasm_u32x4_extend_high_u16x8
#define w2c2_v128_i64x2_extend_high_i32x4 simde_wasm_i64x2_extend_low_i32x4
#define w2c2_v128_u64x2_extend_high_u32x4 simde_wasm_u64x2_extend_low_u32x4
#define w2c2_v128_i64x2_extend_low_i32x4  simde_wasm_i64x2_extend_high_i32x4
#define w2c2_v128_u64x2_extend_low_u32x4  simde_wasm_u64x2_extend_high_u32x4
#define w2c2_v128_i32x4_trunc_sat_f64x2_zero(a)      \
  simde_wasm_i8x16_swizzle(                     \
      simde_wasm_i32x4_trunc_sat_f64x2_zero(a), \
      simde_wasm_i8x16_const(8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7))
#define w2c2_v128_u32x4_trunc_sat_f64x2_zero(a)      \
  simde_wasm_i8x16_swizzle(                     \
      simde_wasm_u32x4_trunc_sat_f64x2_zero(a), \
      simde_wasm_i8x16_const(8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7))
#define w2c2_v128_i16x8_narrow_i32x4(a,b) simde_wasm_i16x8_narrow_i32x4(b,a)
#define w2c2_v128_u16x8_narrow_i32x4(a,b) simde_wasm_u16x8_narrow_i32x4(b,a)
#define w2c2_v128_i8x16_narrow_i16x8(a,b) simde_wasm_i8x16_narrow_i16x8(b,a)
#define w2c2_v128_u8x16_narrow_i16x8(a,b) simde_wasm_u8x16_narrow_i16x8(b,a)
#define w2c2_v128_f64x2_promote_low_f32x4(a)                        \
  simde_wasm_f64x2_promote_low_f32x4(simde_wasm_i8x16_swizzle( \
      a,                                                       \
      simde_wasm_i8x16_const(8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7)))
#define w2c2_v128_f32x4_demote_f64x2_zero(a)      \
  simde_wasm_i8x16_swizzle(                  \
      simde_wasm_f32x4_demote_f64x2_zero(a), \
      simde_wasm_i8x16_const(8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7))
#define w2c2_v128_f64x2_convert_low_i32x4(a)                        \
  simde_wasm_f64x2_convert_low_i32x4(simde_wasm_i8x16_swizzle( \
      a,                                                       \
      simde_wasm_i8x16_const(8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7)))
#define w2c2_v128_f64x2_convert_low_u32x4(a)                        \
  simde_wasm_f64x2_convert_low_u32x4(simde_wasm_i8x16_swizzle( \
      a,                                                       \
      simde_wasm_i8x16_const(8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7)))
#else
#define w2c2_v128_const simde_wasm_i8x16_const
#define w2c2_v128_i8x16_extract_lane simde_wasm_i8x16_extract_lane
#define w2c2_v128_u8x16_extract_lane simde_wasm_u8x16_extract_lane
#define w2c2_v128_i16x8_extract_lane simde_wasm_i16x8_extract_lane
#define w2c2_v128_u16x8_extract_lane simde_wasm_u16x8_extract_lane
#define w2c2_v128_i32x4_extract_lane simde_wasm_i32x4_extract_lane
#define w2c2_v128_i64x2_extract_lane simde_wasm_i64x2_extract_lane
#define w2c2_v128_f32x4_extract_lane simde_wasm_f32x4_extract_lane
#define w2c2_v128_f64x2_extract_lane simde_wasm_f64x2_extract_lane
#define w2c2_v128_i8x16_replace_lane simde_wasm_i8x16_replace_lane
#define w2c2_v128_u8x16_replace_lane simde_wasm_u8x16_replace_lane
#define w2c2_v128_i16x8_replace_lane simde_wasm_i16x8_replace_lane
#define w2c2_v128_u16x8_replace_lane simde_wasm_u16x8_replace_lane
#define w2c2_v128_i32x4_replace_lane simde_wasm_i32x4_replace_lane
#define w2c2_v128_i64x2_replace_lane simde_wasm_i64x2_replace_lane
#define w2c2_v128_f32x4_replace_lane simde_wasm_f32x4_replace_lane
#define w2c2_v128_f64x2_replace_lane simde_wasm_f64x2_replace_lane
#define w2c2_v128_i8x16_bitmask simde_wasm_i8x16_bitmask
#define w2c2_v128_i16x8_bitmask simde_wasm_i16x8_bitmask
#define w2c2_v128_i32x4_bitmask simde_wasm_i32x4_bitmask
#define w2c2_v128_i64x2_bitmask simde_wasm_i64x2_bitmask
#define w2c2_v128_i8x16_swizzle simde_wasm_i8x16_swizzle
#define w2c2_v128_i8x16_shuffle simde_wasm_i8x16_shuffle
#define w2c2_v128_i16x8_extmul_high_i8x16 simde_wasm_i16x8_extmul_high_i8x16
#define w2c2_v128_u16x8_extmul_high_u8x16 simde_wasm_u16x8_extmul_high_u8x16
#define w2c2_v128_i16x8_extmul_low_i8x16  simde_wasm_i16x8_extmul_low_i8x16
#define w2c2_v128_u16x8_extmul_low_u8x16  simde_wasm_u16x8_extmul_low_u8x16
#define w2c2_v128_i32x4_extmul_high_i16x8 simde_wasm_i32x4_extmul_high_i16x8
#define w2c2_v128_u32x4_extmul_high_u16x8 simde_wasm_u32x4_extmul_high_u16x8
#define w2c2_v128_i32x4_extmul_low_i16x8  simde_wasm_i32x4_extmul_low_i16x8
#define w2c2_v128_u32x4_extmul_low_u16x8  simde_wasm_u32x4_extmul_low_u16x8
#define w2c2_v128_i64x2_extmul_high_i32x4 simde_wasm_i64x2_extmul_high_i32x4
#define w2c2_v128_u64x2_extmul_high_u32x4 simde_wasm_u64x2_extmul_high_u32x4
#define w2c2_v128_i64x2_extmul_low_i32x4  simde_wasm_i64x2_extmul_low_i32x4
#define w2c2_v128_u64x2_extmul_low_u32x4  simde_wasm_u64x2_extmul_low_u32x4
#define w2c2_v128_i16x8_extend_high_i8x16 simde_wasm_i16x8_extend_high_i8x16
#define w2c2_v128_u16x8_extend_high_u8x16 simde_wasm_u16x8_extend_high_u8x16
#define w2c2_v128_i16x8_extend_low_i8x16  simde_wasm_i16x8_extend_low_i8x16
#define w2c2_v128_u16x8_extend_low_u8x16  simde_wasm_u16x8_extend_low_u8x16
#define w2c2_v128_i32x4_extend_high_i16x8 simde_wasm_i32x4_extend_high_i16x8
#define w2c2_v128_u32x4_extend_high_u16x8 simde_wasm_u32x4_extend_high_u16x8
#define w2c2_v128_i32x4_extend_low_i16x8  simde_wasm_i32x4_extend_low_i16x8
#define w2c2_v128_u32x4_extend_low_u16x8  simde_wasm_u32x4_extend_low_u16x8
#define w2c2_v128_i64x2_extend_high_i32x4 simde_wasm_i64x2_extend_high_i32x4
#define w2c2_v128_u64x2_extend_high_u32x4 simde_wasm_u64x2_extend_high_u32x4
#define w2c2_v128_i64x2_extend_low_i32x4  simde_wasm_i64x2_extend_low_i32x4
#define w2c2_v128_u64x2_extend_low_u32x4  simde_wasm_u64x2_extend_low_u32x4
#define w2c2_v128_i32x4_trunc_sat_f64x2_zero simde_wasm_i32x4_trunc_sat_f64x2_zero
#define w2c2_v128_u32x4_trunc_sat_f64x2_zero simde_wasm_u32x4_trunc_sat_f64x2_zero
#define w2c2_v128_i16x8_narrow_i32x4 simde_wasm_i16x8_narrow_i32x4
#define w2c2_v128_u16x8_narrow_i32x4 simde_wasm_u16x8_narrow_i32x4
#define w2c2_v128_i8x16_narrow_i16x8 simde_wasm_i8x16_narrow_i16x8
#define w2c2_v128_u8x16_narrow_i16x8 simde_wasm_u8x16_narrow_i16x8
#define w2c2_v128_f64x2_promote_low_f32x4 simde_wasm_f64x2_promote_low_f32x4
#define w2c2_v128_f32x4_demote_f64x2_zero simde_wasm_f32x4_demote_f64x2_zero
#define w2c2_v128_f64x2_convert_low_i32x4 simde_wasm_f64x2_convert_low_i32x4
#define w2c2_v128_f64x2_convert_low_u32x4 simde_wasm_f64x2_convert_low_u32x4
#endif


#undef W2C2_SIMD_LANE
#undef DEFINE_SIMD_LOAD_FUNC
#undef DEFINE_SIMD_LOAD_LANE
#undef DEFINE_SIMD_STORE
#undef DEFINE_SIMD_STORE_LANE
#endif /* W2C2_SIMD_H */
