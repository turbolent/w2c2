
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.24.h"

void test() {
    floatexprs24Instance instance;
    floatexprs24Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.24.wasm");
    assertEqualF32(
        floatexprs24_f32X2EnoX5FfoldX5FdivX5Fneg0(&instance, 1.0),
        -INFINITY,
        "f32.no_fold_div_neg0(1.0)"
    );
    assertEqualF32(
        floatexprs24_f32X2EnoX5FfoldX5FdivX5Fneg0(&instance, -1.0),
        INFINITY,
        "f32.no_fold_div_neg0(-1.0)"
    );
    assertEqualF32(
        floatexprs24_f32X2EnoX5FfoldX5FdivX5Fneg0(&instance, INFINITY),
        -INFINITY,
        "f32.no_fold_div_neg0(INFINITY)"
    );
    assertEqualF32(
        floatexprs24_f32X2EnoX5FfoldX5FdivX5Fneg0(&instance, -INFINITY),
        INFINITY,
        "f32.no_fold_div_neg0(-INFINITY)"
    );
    assertEqualF64(
        floatexprs24_f64X2EnoX5FfoldX5FdivX5Fneg0(&instance, 1.0),
        -INFINITY,
        "f64.no_fold_div_neg0(1.0)"
    );
    assertEqualF64(
        floatexprs24_f64X2EnoX5FfoldX5FdivX5Fneg0(&instance, -1.0),
        INFINITY,
        "f64.no_fold_div_neg0(-1.0)"
    );
    assertEqualF64(
        floatexprs24_f64X2EnoX5FfoldX5FdivX5Fneg0(&instance, INFINITY),
        -INFINITY,
        "f64.no_fold_div_neg0(INFINITY)"
    );
    assertEqualF64(
        floatexprs24_f64X2EnoX5FfoldX5FdivX5Fneg0(&instance, -INFINITY),
        INFINITY,
        "f64.no_fold_div_neg0(-INFINITY)"
    );
}
