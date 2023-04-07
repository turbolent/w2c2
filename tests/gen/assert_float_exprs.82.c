
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.82.h"

void test() {
    floatexprs82Instance instance;
    floatexprs82Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.82.wasm");
    assertEqualU32(
        floatexprs82_f32X2Eno_fold_add_le_monotonicity(&instance, INFINITY, -INFINITY, INFINITY),
        0u,
        "f32.no_fold_add_le_monotonicity(INFINITY, -INFINITY, INFINITY)"
    );
    assertEqualU32(
        floatexprs82_f64X2Eno_fold_add_le_monotonicity(&instance, INFINITY, -INFINITY, INFINITY),
        0u,
        "f64.no_fold_add_le_monotonicity(INFINITY, -INFINITY, INFINITY)"
    );
}
