
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.49.h"

void test() {
    m14_floatX5FexprsX2E49Instance instance;
    m14_floatX5FexprsX2E49Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.49.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E49Export24_f32X2EincorrectX5Fcorrection(&instance),
        1.1920928955078125e-07,
        "f32.incorrect_correction()"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E49Export24_f64X2EincorrectX5Fcorrection(&instance),
        -2.220446049250313e-16,
        "f64.incorrect_correction()"
    );
}
