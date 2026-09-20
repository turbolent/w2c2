
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.97.h"

void test() {
    m14_floatX5FexprsX2E97Instance instance;
    m14_floatX5FexprsX2E97Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.97.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E97Export27_f32X2EnoX5FfoldX5FconditionalX5Finc(&instance, -0.0, -1.0),
        -0.0,
        "f32.no_fold_conditional_inc(-0.0, -1.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E97Export27_f64X2EnoX5FfoldX5FconditionalX5Finc(&instance, -0.0, -1.0),
        -0.0,
        "f64.no_fold_conditional_inc(-0.0, -1.0)"
    );
}
