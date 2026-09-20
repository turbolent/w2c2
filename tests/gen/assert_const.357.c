
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.357.h"

void test() {
    m9_constX2E357Instance instance;
    m9_constX2E357Instantiate(&instance, resolveTestImports);
    printStart("const.357.wasm");
    assertEqualF64(
        m9_constX2E357Export1_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
