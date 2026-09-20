
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.188.h"

void test() {
    m9_constX2E188Instance instance;
    m9_constX2E188Instantiate(&instance, resolveTestImports);
    printStart("const.188.wasm");
    assertEqualF32(
        m9_constX2E188Export1_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
