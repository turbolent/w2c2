
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.47.h"

void test() {
    floatexprs47Instance instance;
    floatexprs47Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.47.wasm");
    assertEqualF32(
        floatexprs47_f32X2Eincorrect_correction(&instance),
        1.1920928955078125e-07,
        "f32.incorrect_correction()"
    );
    assertEqualF64(
        floatexprs47_f64X2Eincorrect_correction(&instance),
        -2.220446049250313e-16,
        "f64.incorrect_correction()"
    );
}
