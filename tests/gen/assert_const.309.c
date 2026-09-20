
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.309.h"

void test() {
    m9_constX2E309Instance instance;
    m9_constX2E309Instantiate(&instance, resolveTestImports);
    printStart("const.309.wasm");
    assertEqualF32(
        m9_constX2E309Export1_f(&instance),
        -2.802596928649634e-45,
        "f()"
    );
}
