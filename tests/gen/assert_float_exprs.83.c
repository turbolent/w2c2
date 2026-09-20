
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.83.h"

void test() {
    m14_floatX5FexprsX2E83Instance instance;
    m14_floatX5FexprsX2E83Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.83.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E83Export24_f32X2EnoX5FfoldX5Fsub1X5FmulX5Fadd(&instance, 2.3283064365386963e-10, 1.0)),
        0u,
        "f32.no_fold_sub1_mul_add(2.3283064365386963e-10, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E83Export24_f64X2EnoX5FfoldX5Fsub1X5FmulX5Fadd(&instance, 5.421010862427522e-20, 1.0)),
        0ull,
        "f64.no_fold_sub1_mul_add(5.421010862427522e-20, 1.0)"
    );
}
