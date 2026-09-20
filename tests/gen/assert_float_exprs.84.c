
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.84.h"

void test() {
    m14_floatX5FexprsX2E84Instance instance;
    m14_floatX5FexprsX2E84Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.84.wasm");
    assertEqualU32(
        m14_floatX5FexprsX2E84Export31_f32X2EnoX5FfoldX5FaddX5FleX5Fmonotonicity(&instance, 0.0, 0.0, f32_reinterpret_i32(0x7fc00000u)),
        0u,
        "f32.no_fold_add_le_monotonicity(0.0, 0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E84Export31_f32X2EnoX5FfoldX5FaddX5FleX5Fmonotonicity(&instance, INFINITY, -INFINITY, INFINITY),
        0u,
        "f32.no_fold_add_le_monotonicity(INFINITY, -INFINITY, INFINITY)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E84Export31_f64X2EnoX5FfoldX5FaddX5FleX5Fmonotonicity(&instance, 0.0, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull)),
        0u,
        "f64.no_fold_add_le_monotonicity(0.0, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E84Export31_f64X2EnoX5FfoldX5FaddX5FleX5Fmonotonicity(&instance, INFINITY, -INFINITY, INFINITY),
        0u,
        "f64.no_fold_add_le_monotonicity(INFINITY, -INFINITY, INFINITY)"
    );
}
