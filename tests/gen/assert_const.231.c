
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.231.h"

void test() {
    m9_constX2E231Instance instance;
    m9_constX2E231Instantiate(&instance, resolveTestImports);
    printStart("const.231.wasm");
    assertEqualF32(
        m9_constX2E231Export1_f(&instance),
        -8.881784197001252e-16,
        "f()"
    );
}
