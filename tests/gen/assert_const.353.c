
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.353.h"

void test() {
    m9_constX2E353Instance instance;
    m9_constX2E353Instantiate(&instance, resolveTestImports);
    printStart("const.353.wasm");
    assertEqualF64(
        m9_constX2E353Export1_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
