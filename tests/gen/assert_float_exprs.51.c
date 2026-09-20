
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.51.h"

void test() {
    m14_floatX5FexprsX2E51Instance instance;
    m14_floatX5FexprsX2E51Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.51.wasm");
    assertEqualF64(
        m14_floatX5FexprsX2E51Export9_calculate(&instance),
        -466.926956301738,
        "calculate()"
    );
}
