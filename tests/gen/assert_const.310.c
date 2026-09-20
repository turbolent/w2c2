
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.310.h"

void test() {
    m9_constX2E310Instance instance;
    m9_constX2E310Instantiate(&instance, resolveTestImports);
    printStart("const.310.wasm");
    assertEqualF32(
        m9_constX2E310Export1_f(&instance),
        2.802596928649634e-45,
        "f()"
    );
}
