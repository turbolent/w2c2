
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.34.h"

void test() {
    m14_floatX5FexprsX2E34Instance instance;
    m14_floatX5FexprsX2E34Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.34.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E34Export21_f32X2EnoX5FfoldX5Fdiv2X5Fmul2(&instance, 2.3509885615147286e-38)),
        16777216u,
        "f32.no_fold_div2_mul2(2.3509885615147286e-38)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E34Export21_f64X2EnoX5FfoldX5Fdiv2X5Fmul2(&instance, 4.4501477170144023e-308)),
        9007199254740992ull,
        "f64.no_fold_div2_mul2(4.4501477170144023e-308)"
    );
}
