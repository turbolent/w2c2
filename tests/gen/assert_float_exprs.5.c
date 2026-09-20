
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.5.h"

void test() {
    m13_floatX5FexprsX2E5Instance instance;
    m13_floatX5FexprsX2E5Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.5.wasm");
    assertEqualF32(
        m13_floatX5FexprsX2E5Export20_f32X2EnoX5FfoldX5FmulX5Fzero(&instance, -0.0),
        -0.0,
        "f32.no_fold_mul_zero(-0.0)"
    );
    assertEqualF32(
        m13_floatX5FexprsX2E5Export20_f32X2EnoX5FfoldX5FmulX5Fzero(&instance, -1.0),
        -0.0,
        "f32.no_fold_mul_zero(-1.0)"
    );
    assertEqualF32(
        m13_floatX5FexprsX2E5Export20_f32X2EnoX5FfoldX5FmulX5Fzero(&instance, -2.0),
        -0.0,
        "f32.no_fold_mul_zero(-2.0)"
    );
    assertEqualF64(
        m13_floatX5FexprsX2E5Export20_f64X2EnoX5FfoldX5FmulX5Fzero(&instance, -0.0),
        -0.0,
        "f64.no_fold_mul_zero(-0.0)"
    );
    assertEqualF64(
        m13_floatX5FexprsX2E5Export20_f64X2EnoX5FfoldX5FmulX5Fzero(&instance, -1.0),
        -0.0,
        "f64.no_fold_mul_zero(-1.0)"
    );
    assertEqualF64(
        m13_floatX5FexprsX2E5Export20_f64X2EnoX5FfoldX5FmulX5Fzero(&instance, -2.0),
        -0.0,
        "f64.no_fold_mul_zero(-2.0)"
    );
}
