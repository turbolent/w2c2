
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.356.h"

void test() {
    m9_constX2E356Instance instance;
    m9_constX2E356Instantiate(&instance, resolveTestImports);
    printStart("const.356.wasm");
    assertEqualF64(
        m9_constX2E356Export1_f(&instance),
        2.4099198651028847e-181,
        "f()"
    );
}
