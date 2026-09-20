
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.24.h"

void test() {
    m14_floatX5FexprsX2E24Instance instance;
    m14_floatX5FexprsX2E24Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.24.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E24Export20_f32X2EnoX5FfoldX5FdivX5Fneg0(&instance, 1.0),
        -INFINITY,
        "f32.no_fold_div_neg0(1.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E24Export20_f32X2EnoX5FfoldX5FdivX5Fneg0(&instance, -1.0),
        INFINITY,
        "f32.no_fold_div_neg0(-1.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E24Export20_f32X2EnoX5FfoldX5FdivX5Fneg0(&instance, INFINITY),
        -INFINITY,
        "f32.no_fold_div_neg0(INFINITY)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E24Export20_f32X2EnoX5FfoldX5FdivX5Fneg0(&instance, -INFINITY),
        INFINITY,
        "f32.no_fold_div_neg0(-INFINITY)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E24Export20_f64X2EnoX5FfoldX5FdivX5Fneg0(&instance, 1.0),
        -INFINITY,
        "f64.no_fold_div_neg0(1.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E24Export20_f64X2EnoX5FfoldX5FdivX5Fneg0(&instance, -1.0),
        INFINITY,
        "f64.no_fold_div_neg0(-1.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E24Export20_f64X2EnoX5FfoldX5FdivX5Fneg0(&instance, INFINITY),
        -INFINITY,
        "f64.no_fold_div_neg0(INFINITY)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E24Export20_f64X2EnoX5FfoldX5FdivX5Fneg0(&instance, -INFINITY),
        INFINITY,
        "f64.no_fold_div_neg0(-INFINITY)"
    );
}
