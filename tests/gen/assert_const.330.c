
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.330.h"

void test() {
    m9_constX2E330Instance instance;
    m9_constX2E330Instantiate(&instance, resolveTestImports);
    printStart("const.330.wasm");
    assertEqualF64(
        m9_constX2E330Export1_f(&instance),
        2.4099198651028847e-181,
        "f()"
    );
}
