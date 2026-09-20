
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.358.h"

void test() {
    m9_constX2E358Instance instance;
    m9_constX2E358Instantiate(&instance, resolveTestImports);
    printStart("const.358.wasm");
    assertEqualF64(
        m9_constX2E358Export1_f(&instance),
        2.4099198651028847e-181,
        "f()"
    );
}
