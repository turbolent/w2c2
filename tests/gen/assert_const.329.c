
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.329.h"

void test() {
    m9_constX2E329Instance instance;
    m9_constX2E329Instantiate(&instance, resolveTestImports);
    printStart("const.329.wasm");
    assertEqualF64(
        m9_constX2E329Export1_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
