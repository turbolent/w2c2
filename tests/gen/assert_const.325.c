
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.325.h"

void test() {
    m9_constX2E325Instance instance;
    m9_constX2E325Instantiate(&instance, resolveTestImports);
    printStart("const.325.wasm");
    assertEqualF64(
        m9_constX2E325Export1_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
