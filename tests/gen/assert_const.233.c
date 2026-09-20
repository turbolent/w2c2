
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.233.h"

void test() {
    m9_constX2E233Instance instance;
    m9_constX2E233Instantiate(&instance, resolveTestImports);
    printStart("const.233.wasm");
    assertEqualF32(
        m9_constX2E233Export1_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
