
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.45.h"

void test() {
    floatexprs45Instance instance;
    floatexprs45Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.45.wasm");
    assertEqualF32(
        floatexprs45_f32X2Eno_fold_lt_select(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_lt_select(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs45_f32X2Eno_fold_lt_select(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_lt_select(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs45_f32X2Eno_fold_le_select(&instance, 0.0, -0.0),
        0.0,
        "f32.no_fold_le_select(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs45_f32X2Eno_fold_le_select(&instance, -0.0, 0.0),
        -0.0,
        "f32.no_fold_le_select(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs45_f32X2Eno_fold_gt_select(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_gt_select(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs45_f32X2Eno_fold_gt_select(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_gt_select(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs45_f32X2Eno_fold_ge_select(&instance, 0.0, -0.0),
        0.0,
        "f32.no_fold_ge_select(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs45_f32X2Eno_fold_ge_select(&instance, -0.0, 0.0),
        -0.0,
        "f32.no_fold_ge_select(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs45_f64X2Eno_fold_lt_select(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_lt_select(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs45_f64X2Eno_fold_lt_select(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_lt_select(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs45_f64X2Eno_fold_le_select(&instance, 0.0, -0.0),
        0.0,
        "f64.no_fold_le_select(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs45_f64X2Eno_fold_le_select(&instance, -0.0, 0.0),
        -0.0,
        "f64.no_fold_le_select(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs45_f64X2Eno_fold_gt_select(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_gt_select(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs45_f64X2Eno_fold_gt_select(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_gt_select(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs45_f64X2Eno_fold_ge_select(&instance, 0.0, -0.0),
        0.0,
        "f64.no_fold_ge_select(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs45_f64X2Eno_fold_ge_select(&instance, -0.0, 0.0),
        -0.0,
        "f64.no_fold_ge_select(-0.0, 0.0)"
    );
}
