
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.49.h"

void test() {
    floatexprs49Instance instance;
    floatexprs49Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.49.wasm");
    assertEqualF32(
        floatexprs49_f32X2Eincorrect_correction(&instance),
        1.1920928955078125e-07,
        "f32.incorrect_correction()"
    );
    assertEqualF64(
        floatexprs49_f64X2Eincorrect_correction(&instance),
        -2.220446049250313e-16,
        "f64.incorrect_correction()"
    );
}
