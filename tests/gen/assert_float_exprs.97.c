
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.97.h"

void test() {
    floatexprs97Instance instance;
    floatexprs97Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.97.wasm");
    assertEqualF32(
        floatexprs97_f32X2Eno_fold_conditional_inc(&instance, -0.0, -1.0),
        -0.0,
        "f32.no_fold_conditional_inc(-0.0, -1.0)"
    );
    assertEqualF64(
        floatexprs97_f64X2Eno_fold_conditional_inc(&instance, -0.0, -1.0),
        -0.0,
        "f64.no_fold_conditional_inc(-0.0, -1.0)"
    );
}
