
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.43.h"

void test() {
    floatexprs43Instance instance;
    floatexprs43Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.43.wasm");
    assertEqualF32(
        floatexprs43_f32X2EnoX5FfoldX5FltX5Fselect(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_lt_select(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs43_f32X2EnoX5FfoldX5FltX5Fselect(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_lt_select(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs43_f32X2EnoX5FfoldX5FleX5Fselect(&instance, 0.0, -0.0),
        0.0,
        "f32.no_fold_le_select(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs43_f32X2EnoX5FfoldX5FleX5Fselect(&instance, -0.0, 0.0),
        -0.0,
        "f32.no_fold_le_select(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs43_f32X2EnoX5FfoldX5FgtX5Fselect(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_gt_select(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs43_f32X2EnoX5FfoldX5FgtX5Fselect(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_gt_select(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs43_f32X2EnoX5FfoldX5FgeX5Fselect(&instance, 0.0, -0.0),
        0.0,
        "f32.no_fold_ge_select(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs43_f32X2EnoX5FfoldX5FgeX5Fselect(&instance, -0.0, 0.0),
        -0.0,
        "f32.no_fold_ge_select(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs43_f64X2EnoX5FfoldX5FltX5Fselect(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_lt_select(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs43_f64X2EnoX5FfoldX5FltX5Fselect(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_lt_select(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs43_f64X2EnoX5FfoldX5FleX5Fselect(&instance, 0.0, -0.0),
        0.0,
        "f64.no_fold_le_select(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs43_f64X2EnoX5FfoldX5FleX5Fselect(&instance, -0.0, 0.0),
        -0.0,
        "f64.no_fold_le_select(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs43_f64X2EnoX5FfoldX5FgtX5Fselect(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_gt_select(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs43_f64X2EnoX5FfoldX5FgtX5Fselect(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_gt_select(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs43_f64X2EnoX5FfoldX5FgeX5Fselect(&instance, 0.0, -0.0),
        0.0,
        "f64.no_fold_ge_select(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs43_f64X2EnoX5FfoldX5FgeX5Fselect(&instance, -0.0, 0.0),
        -0.0,
        "f64.no_fold_ge_select(-0.0, 0.0)"
    );
}
