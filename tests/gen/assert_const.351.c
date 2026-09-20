
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.351.h"

void test() {
    m9_constX2E351Instance instance;
    m9_constX2E351Instantiate(&instance, resolveTestImports);
    printStart("const.351.wasm");
    assertEqualF64(
        m9_constX2E351Export1_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
