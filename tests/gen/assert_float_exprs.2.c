
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.2.h"

void test() {
    m13_floatX5FexprsX2E2Instance instance;
    m13_floatX5FexprsX2E2Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.2.wasm");
    assertEqualF32(
        m13_floatX5FexprsX2E2Export20_f32X2EnoX5FfoldX5FaddX5Fzero(&instance, -0.0),
        0.0,
        "f32.no_fold_add_zero(-0.0)"
    );
    assertEqualF64(
        m13_floatX5FexprsX2E2Export20_f64X2EnoX5FfoldX5FaddX5Fzero(&instance, -0.0),
        0.0,
        "f64.no_fold_add_zero(-0.0)"
    );
}
