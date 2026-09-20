
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.23.h"

void test() {
    m14_floatX5FexprsX2E23Instance instance;
    m14_floatX5FexprsX2E23Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.23.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E23Export17_f32X2EnoX5FfoldX5FdivX5F0(&instance, 1.0),
        INFINITY,
        "f32.no_fold_div_0(1.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E23Export17_f32X2EnoX5FfoldX5FdivX5F0(&instance, -1.0),
        -INFINITY,
        "f32.no_fold_div_0(-1.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E23Export17_f32X2EnoX5FfoldX5FdivX5F0(&instance, INFINITY),
        INFINITY,
        "f32.no_fold_div_0(INFINITY)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E23Export17_f32X2EnoX5FfoldX5FdivX5F0(&instance, -INFINITY),
        -INFINITY,
        "f32.no_fold_div_0(-INFINITY)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E23Export17_f64X2EnoX5FfoldX5FdivX5F0(&instance, 1.0),
        INFINITY,
        "f64.no_fold_div_0(1.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E23Export17_f64X2EnoX5FfoldX5FdivX5F0(&instance, -1.0),
        -INFINITY,
        "f64.no_fold_div_0(-1.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E23Export17_f64X2EnoX5FfoldX5FdivX5F0(&instance, INFINITY),
        INFINITY,
        "f64.no_fold_div_0(INFINITY)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E23Export17_f64X2EnoX5FfoldX5FdivX5F0(&instance, -INFINITY),
        -INFINITY,
        "f64.no_fold_div_0(-INFINITY)"
    );
}
