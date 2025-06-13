
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.65.h"

void test() {
    floatexprs65Instance instance;
    floatexprs65Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.65.wasm");
    assertEqualF32(
        floatexprs65_f32X2Eno_fold_neg_sub(&instance, -0.0, -0.0),
        -0.0,
        "f32.no_fold_neg_sub(-0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs65_f32X2Eno_fold_neg_sub(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_neg_sub(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs65_f32X2Eno_fold_neg_sub(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_neg_sub(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs65_f32X2Eno_fold_neg_sub(&instance, 0.0, 0.0),
        -0.0,
        "f32.no_fold_neg_sub(0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs65_f64X2Eno_fold_neg_sub(&instance, -0.0, -0.0),
        -0.0,
        "f64.no_fold_neg_sub(-0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs65_f64X2Eno_fold_neg_sub(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_neg_sub(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs65_f64X2Eno_fold_neg_sub(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_neg_sub(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs65_f64X2Eno_fold_neg_sub(&instance, 0.0, 0.0),
        -0.0,
        "f64.no_fold_neg_sub(0.0, 0.0)"
    );
}
