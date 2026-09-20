
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.260.h"

void test() {
    m9_constX2E260Instance instance;
    m9_constX2E260Instantiate(&instance, resolveTestImports);
    printStart("const.260.wasm");
    assertEqualF32(
        m9_constX2E260Export1_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
