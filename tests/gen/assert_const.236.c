
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.236.h"

void test() {
    m9_constX2E236Instance instance;
    m9_constX2E236Instantiate(&instance, resolveTestImports);
    printStart("const.236.wasm");
    assertEqualF32(
        m9_constX2E236Export1_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
