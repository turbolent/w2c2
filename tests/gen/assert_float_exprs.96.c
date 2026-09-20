
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.96.h"

void test() {
    m14_floatX5FexprsX2E96Instance instance;
    m14_floatX5FexprsX2E96Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.96.wasm");
    assertEqualF64(
        m14_floatX5FexprsX2E96Export3_tau(&instance, 10u),
        6.283185307179583,
        "tau(10u)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E96Export3_tau(&instance, 11u),
        6.283185307179586,
        "tau(11u)"
    );
}
