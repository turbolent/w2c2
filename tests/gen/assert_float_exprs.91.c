
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.91.h"

void test() {
    m14_floatX5FexprsX2E91Instance instance;
    m14_floatX5FexprsX2E91Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.91.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E91Export16_f32X2Econtract2fma(&instance, 1.0, 1.0),
        0.0,
        "f32.contract2fma(1.0, 1.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E91Export16_f32X2Econtract2fma(&instance, 1.100000023841858, 1.100000023841858),
        0.0,
        "f32.contract2fma(1.100000023841858, 1.100000023841858)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E91Export16_f32X2Econtract2fma(&instance, 1.1999999284744263, 1.1999999284744263),
        0.0,
        "f32.contract2fma(1.1999999284744263, 1.1999999284744263)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E91Export16_f64X2Econtract2fma(&instance, 1.0, 1.0),
        0.0,
        "f64.contract2fma(1.0, 1.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E91Export16_f64X2Econtract2fma(&instance, 1.1, 1.1),
        0.0,
        "f64.contract2fma(1.1, 1.1)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E91Export16_f64X2Econtract2fma(&instance, 1.2, 1.2),
        0.0,
        "f64.contract2fma(1.2, 1.2)"
    );
}
