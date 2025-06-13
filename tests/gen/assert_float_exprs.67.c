
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.67.h"

void test() {
    floatexprs67Instance instance;
    floatexprs67Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.67.wasm");
    assertEqualF32(
        floatexprs67_f32X2Eno_fold_add_neg_neg(&instance, -0.0, -0.0),
        0.0,
        "f32.no_fold_add_neg_neg(-0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs67_f32X2Eno_fold_add_neg_neg(&instance, 0.0, -0.0),
        0.0,
        "f32.no_fold_add_neg_neg(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs67_f32X2Eno_fold_add_neg_neg(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_add_neg_neg(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs67_f32X2Eno_fold_add_neg_neg(&instance, 0.0, 0.0),
        -0.0,
        "f32.no_fold_add_neg_neg(0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs67_f64X2Eno_fold_add_neg_neg(&instance, -0.0, -0.0),
        0.0,
        "f64.no_fold_add_neg_neg(-0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs67_f64X2Eno_fold_add_neg_neg(&instance, 0.0, -0.0),
        0.0,
        "f64.no_fold_add_neg_neg(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs67_f64X2Eno_fold_add_neg_neg(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_add_neg_neg(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs67_f64X2Eno_fold_add_neg_neg(&instance, 0.0, 0.0),
        -0.0,
        "f64.no_fold_add_neg_neg(0.0, 0.0)"
    );
}
