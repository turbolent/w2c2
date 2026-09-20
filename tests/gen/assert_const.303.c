
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.303.h"

void test() {
    m9_constX2E303Instance instance;
    m9_constX2E303Instantiate(&instance, resolveTestImports);
    printStart("const.303.wasm");
    assertEqualF32(
        m9_constX2E303Export1_f(&instance),
        -2.802596928649634e-45,
        "f()"
    );
}
