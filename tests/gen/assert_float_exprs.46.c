
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.46.h"

void test() {
    floatexprs46Instance instance;
    floatexprs46Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.46.wasm");
    assertEqualF32(
        floatexprs46_f32X2EnoX5FfoldX5FltX5FifX5FtoX5Fabs(&instance, 0.0),
        0.0,
        "f32.no_fold_lt_if_to_abs(0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2EnoX5FfoldX5FltX5FifX5FtoX5Fabs(&instance, -0.0),
        -0.0,
        "f32.no_fold_lt_if_to_abs(-0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2EnoX5FfoldX5FleX5FifX5FtoX5Fabs(&instance, 0.0),
        -0.0,
        "f32.no_fold_le_if_to_abs(0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2EnoX5FfoldX5FleX5FifX5FtoX5Fabs(&instance, -0.0),
        0.0,
        "f32.no_fold_le_if_to_abs(-0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2EnoX5FfoldX5FgtX5FifX5FtoX5Fabs(&instance, 0.0),
        -0.0,
        "f32.no_fold_gt_if_to_abs(0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2EnoX5FfoldX5FgtX5FifX5FtoX5Fabs(&instance, -0.0),
        0.0,
        "f32.no_fold_gt_if_to_abs(-0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2EnoX5FfoldX5FgeX5FifX5FtoX5Fabs(&instance, 0.0),
        0.0,
        "f32.no_fold_ge_if_to_abs(0.0)"
    );
    assertEqualF32(
        floatexprs46_f32X2EnoX5FfoldX5FgeX5FifX5FtoX5Fabs(&instance, -0.0),
        -0.0,
        "f32.no_fold_ge_if_to_abs(-0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2EnoX5FfoldX5FltX5FifX5FtoX5Fabs(&instance, 0.0),
        0.0,
        "f64.no_fold_lt_if_to_abs(0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2EnoX5FfoldX5FltX5FifX5FtoX5Fabs(&instance, -0.0),
        -0.0,
        "f64.no_fold_lt_if_to_abs(-0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2EnoX5FfoldX5FleX5FifX5FtoX5Fabs(&instance, 0.0),
        -0.0,
        "f64.no_fold_le_if_to_abs(0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2EnoX5FfoldX5FleX5FifX5FtoX5Fabs(&instance, -0.0),
        0.0,
        "f64.no_fold_le_if_to_abs(-0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2EnoX5FfoldX5FgtX5FifX5FtoX5Fabs(&instance, 0.0),
        -0.0,
        "f64.no_fold_gt_if_to_abs(0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2EnoX5FfoldX5FgtX5FifX5FtoX5Fabs(&instance, -0.0),
        0.0,
        "f64.no_fold_gt_if_to_abs(-0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2EnoX5FfoldX5FgeX5FifX5FtoX5Fabs(&instance, 0.0),
        0.0,
        "f64.no_fold_ge_if_to_abs(0.0)"
    );
    assertEqualF64(
        floatexprs46_f64X2EnoX5FfoldX5FgeX5FifX5FtoX5Fabs(&instance, -0.0),
        -0.0,
        "f64.no_fold_ge_if_to_abs(-0.0)"
    );
}
