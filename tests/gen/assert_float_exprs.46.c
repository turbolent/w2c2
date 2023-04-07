
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.46.h"

void test() {
    floatexprs46Instance instance;
    floatexprs46Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.46.wasm");
    assertEqualF32(
        floatexprs46_f32X2Eno_fold_lt_if_to_abs(&instance, 0.0),
        0.0,
        "f32.no_fold_lt_if_to_abs(0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2Eno_fold_lt_if_to_abs(&instance, -0.0),
        -0.0,
        "f32.no_fold_lt_if_to_abs(-0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2Eno_fold_le_if_to_abs(&instance, 0.0),
        -0.0,
        "f32.no_fold_le_if_to_abs(0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2Eno_fold_le_if_to_abs(&instance, -0.0),
        0.0,
        "f32.no_fold_le_if_to_abs(-0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2Eno_fold_gt_if_to_abs(&instance, 0.0),
        -0.0,
        "f32.no_fold_gt_if_to_abs(0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2Eno_fold_gt_if_to_abs(&instance, -0.0),
        0.0,
        "f32.no_fold_gt_if_to_abs(-0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2Eno_fold_ge_if_to_abs(&instance, 0.0),
        0.0,
        "f32.no_fold_ge_if_to_abs(0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2Eno_fold_ge_if_to_abs(&instance, -0.0),
        -0.0,
        "f32.no_fold_ge_if_to_abs(-0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2Eno_fold_lt_if_to_abs(&instance, 0.0),
        0.0,
        "f64.no_fold_lt_if_to_abs(0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2Eno_fold_lt_if_to_abs(&instance, -0.0),
        -0.0,
        "f64.no_fold_lt_if_to_abs(-0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2Eno_fold_le_if_to_abs(&instance, 0.0),
        -0.0,
        "f64.no_fold_le_if_to_abs(0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2Eno_fold_le_if_to_abs(&instance, -0.0),
        0.0,
        "f64.no_fold_le_if_to_abs(-0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2Eno_fold_gt_if_to_abs(&instance, 0.0),
        -0.0,
        "f64.no_fold_gt_if_to_abs(0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2Eno_fold_gt_if_to_abs(&instance, -0.0),
        0.0,
        "f64.no_fold_gt_if_to_abs(-0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2Eno_fold_ge_if_to_abs(&instance, 0.0),
        0.0,
        "f64.no_fold_ge_if_to_abs(0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2Eno_fold_ge_if_to_abs(&instance, -0.0),
        -0.0,
        "f64.no_fold_ge_if_to_abs(-0.0)"
    );
}
