
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.47.h"

void test() {
    floatexprs47Instance instance;
    floatexprs47Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.47.wasm");
    assertEqualF32(
        floatexprs47_f32X2Eno_fold_lt_select_to_abs(&instance, 0.0),
        0.0,
        "f32.no_fold_lt_select_to_abs(0.0)"
    );
    assertEqualF32(
        floatexprs47_f32X2Eno_fold_lt_select_to_abs(&instance, -0.0),
        -0.0,
        "f32.no_fold_lt_select_to_abs(-0.0)"
    );
    assertEqualF32(
        floatexprs47_f32X2Eno_fold_le_select_to_abs(&instance, 0.0),
        -0.0,
        "f32.no_fold_le_select_to_abs(0.0)"
    );
    assertEqualF32(
        floatexprs47_f32X2Eno_fold_le_select_to_abs(&instance, -0.0),
        0.0,
        "f32.no_fold_le_select_to_abs(-0.0)"
    );
    assertEqualF32(
        floatexprs47_f32X2Eno_fold_gt_select_to_abs(&instance, 0.0),
        -0.0,
        "f32.no_fold_gt_select_to_abs(0.0)"
    );
    assertEqualF32(
        floatexprs47_f32X2Eno_fold_gt_select_to_abs(&instance, -0.0),
        0.0,
        "f32.no_fold_gt_select_to_abs(-0.0)"
    );
    assertEqualF32(
        floatexprs47_f32X2Eno_fold_ge_select_to_abs(&instance, 0.0),
        0.0,
        "f32.no_fold_ge_select_to_abs(0.0)"
    );
    assertEqualF32(
        floatexprs47_f32X2Eno_fold_ge_select_to_abs(&instance, -0.0),
        -0.0,
        "f32.no_fold_ge_select_to_abs(-0.0)"
    );
    assertEqualF64(
        floatexprs47_f64X2Eno_fold_lt_select_to_abs(&instance, 0.0),
        0.0,
        "f64.no_fold_lt_select_to_abs(0.0)"
    );
    assertEqualF64(
        floatexprs47_f64X2Eno_fold_lt_select_to_abs(&instance, -0.0),
        -0.0,
        "f64.no_fold_lt_select_to_abs(-0.0)"
    );
    assertEqualF64(
        floatexprs47_f64X2Eno_fold_le_select_to_abs(&instance, 0.0),
        -0.0,
        "f64.no_fold_le_select_to_abs(0.0)"
    );
    assertEqualF64(
        floatexprs47_f64X2Eno_fold_le_select_to_abs(&instance, -0.0),
        0.0,
        "f64.no_fold_le_select_to_abs(-0.0)"
    );
    assertEqualF64(
        floatexprs47_f64X2Eno_fold_gt_select_to_abs(&instance, 0.0),
        -0.0,
        "f64.no_fold_gt_select_to_abs(0.0)"
    );
    assertEqualF64(
        floatexprs47_f64X2Eno_fold_gt_select_to_abs(&instance, -0.0),
        0.0,
        "f64.no_fold_gt_select_to_abs(-0.0)"
    );
    assertEqualF64(
        floatexprs47_f64X2Eno_fold_ge_select_to_abs(&instance, 0.0),
        0.0,
        "f64.no_fold_ge_select_to_abs(0.0)"
    );
    assertEqualF64(
        floatexprs47_f64X2Eno_fold_ge_select_to_abs(&instance, -0.0),
        -0.0,
        "f64.no_fold_ge_select_to_abs(-0.0)"
    );
}
