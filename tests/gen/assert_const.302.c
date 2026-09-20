
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.302.h"

void test() {
    m9_constX2E302Instance instance;
    m9_constX2E302Instantiate(&instance, resolveTestImports);
    printStart("const.302.wasm");
    assertEqualF32(
        m9_constX2E302Export1_f(&instance),
        2.802596928649634e-45,
        "f()"
    );
}
