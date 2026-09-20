
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.326.h"

void test() {
    m9_constX2E326Instance instance;
    m9_constX2E326Instantiate(&instance, resolveTestImports);
    printStart("const.326.wasm");
    assertEqualF64(
        m9_constX2E326Export1_f(&instance),
        2.4099198651028847e-181,
        "f()"
    );
}
