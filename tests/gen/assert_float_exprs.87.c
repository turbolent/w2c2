
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.87.h"

void test() {
    m14_floatX5FexprsX2E87Instance instance;
    m14_floatX5FexprsX2E87Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.87.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E87Export11_f32X2Eepsilon(&instance),
        1.1920928955078125e-07,
        "f32.epsilon()"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E87Export11_f64X2Eepsilon(&instance),
        2.220446049250313e-16,
        "f64.epsilon()"
    );
}
