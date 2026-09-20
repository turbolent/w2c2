
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.307.h"

void test() {
    m9_constX2E307Instance instance;
    m9_constX2E307Instantiate(&instance, resolveTestImports);
    printStart("const.307.wasm");
    assertEqualF32(
        m9_constX2E307Export1_f(&instance),
        -2.802596928649634e-45,
        "f()"
    );
}
