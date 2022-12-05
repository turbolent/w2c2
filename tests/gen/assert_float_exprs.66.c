
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.66.h"

void test() {
    floatexprs66Instance instance;
    floatexprs66Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.66.wasm");
    assertEqualF32(
        floatexprs66_f32X2EnoX5FfoldX5FaddX5Fneg(&instance, 0.0),
        0.0,
        "f32.no_fold_add_neg(0.0)"
    );
    assertEqualF32(
        floatexprs66_f32X2EnoX5FfoldX5FaddX5Fneg(&instance, -0.0),
        0.0,
        "f32.no_fold_add_neg(-0.0)"
    );
    assertEqualF64(
        floatexprs66_f64X2EnoX5FfoldX5FaddX5Fneg(&instance, 0.0),
        0.0,
        "f64.no_fold_add_neg(0.0)"
    );
    assertEqualF64(
        floatexprs66_f64X2EnoX5FfoldX5FaddX5Fneg(&instance, -0.0),
        0.0,
        "f64.no_fold_add_neg(-0.0)"
    );
}
