
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.82.h"

void test() {
    m14_floatX5FexprsX2E82Instance instance;
    m14_floatX5FexprsX2E82Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.82.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E82Export17_f32X2EcomputeX5Fradix(&instance, 1.0, 1.0),
        2.0,
        "f32.compute_radix(1.0, 1.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E82Export17_f64X2EcomputeX5Fradix(&instance, 1.0, 1.0),
        2.0,
        "f64.compute_radix(1.0, 1.0)"
    );
}
