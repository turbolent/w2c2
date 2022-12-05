
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_literals.1.h"

void test() {
    floatliterals1Instance instance;
    floatliterals1Instantiate(&instance, resolveTestImports);
    printStart("float_literals.1.wasm");
    assertEqualF64(
        floatliterals1_4294967249(&instance),
        4294967249.0,
        "4294967249()"
    );
}
