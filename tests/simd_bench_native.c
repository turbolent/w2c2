#include "w2c2_simd.h"

#if defined(__GNUC__) || defined(__clang__)
#define NOINLINE __attribute__((noinline))
#else
#define NOINLINE
#endif

/* Native baseline uses the same instruction primitives, without translation. */
V128
native_dot(const U8* a, const U8* b, U32 count) {
    V128 sum = simde_wasm_i32x4_splat(0);
    U32 index;
    for (index = 0; index < count; index++) {
        sum = simde_wasm_i32x4_add(sum, simde_wasm_i32x4_mul(
            simde_wasm_v128_load(a + index * 16),
            simde_wasm_v128_load(b + index * 16)));
    }
    return sum;
}
