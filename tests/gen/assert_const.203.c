
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.203.h"

void test() {
    m9_constX2E203Instance instance;
    m9_constX2E203Instantiate(&instance, resolveTestImports);
    printStart("const.203.wasm");
    assertEqualF32(
        m9_constX2E203Export1_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
