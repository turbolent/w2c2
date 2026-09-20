
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.95.h"

void test() {
    m14_floatX5FexprsX2E95Instance instance;
    m14_floatX5FexprsX2E95Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.95.wasm");
    assertEqualU32(
        m14_floatX5FexprsX2E95Export10_pointX5Ffour(&instance, 4.0, 10.0),
        0u,
        "point_four(4.0, 10.0)"
    );
}
