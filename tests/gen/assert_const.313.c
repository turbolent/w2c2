
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.313.h"

void test() {
    m9_constX2E313Instance instance;
    m9_constX2E313Instantiate(&instance, resolveTestImports);
    printStart("const.313.wasm");
    assertEqualF32(
        m9_constX2E313Export1_f(&instance),
        -2.802596928649634e-45,
        "f()"
    );
}
