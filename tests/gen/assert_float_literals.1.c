
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_literals.1.h"

void test() {
    m16_floatX5FliteralsX2E1Instance instance;
    m16_floatX5FliteralsX2E1Instantiate(&instance, resolveTestImports);
    printStart("float_literals.1.wasm");
    assertEqualF64(
        m16_floatX5FliteralsX2E1Export10_4294967249(&instance),
        4294967249.0,
        "4294967249()"
    );
}
