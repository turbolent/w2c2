
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.278.h"

void test() {
    m9_constX2E278Instance instance;
    m9_constX2E278Instantiate(&instance, resolveTestImports);
    printStart("const.278.wasm");
    assertEqualF32(
        m9_constX2E278Export1_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
