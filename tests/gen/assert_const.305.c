
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.305.h"

void test() {
    m9_constX2E305Instance instance;
    m9_constX2E305Instantiate(&instance, resolveTestImports);
    printStart("const.305.wasm");
    assertEqualF32(
        m9_constX2E305Export1_f(&instance),
        -2.802596928649634e-45,
        "f()"
    );
}
