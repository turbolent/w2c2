
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.253.h"

void test() {
    m9_constX2E253Instance instance;
    m9_constX2E253Instantiate(&instance, resolveTestImports);
    printStart("const.253.wasm");
    assertEqualF32(
        m9_constX2E253Export1_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
