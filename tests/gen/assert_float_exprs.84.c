
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.84.h"

void test() {
    m14_floatX5FexprsX2E84Instance instance;
    m14_floatX5FexprsX2E84Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.84.wasm");
    assertEqualU32(
        m14_floatX5FexprsX2E84Export31_f32X2EnoX5FfoldX5FaddX5FleX5Fmonotonicity(&instance, INFINITY, -INFINITY, INFINITY),
        0u,
        "f32.no_fold_add_le_monotonicity(INFINITY, -INFINITY, INFINITY)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E84Export31_f64X2EnoX5FfoldX5FaddX5FleX5Fmonotonicity(&instance, INFINITY, -INFINITY, INFINITY),
        0u,
        "f64.no_fold_add_le_monotonicity(INFINITY, -INFINITY, INFINITY)"
    );
}
