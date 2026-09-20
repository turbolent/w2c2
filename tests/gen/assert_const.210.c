
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.210.h"

void test() {
    m9_constX2E210Instance instance;
    m9_constX2E210Instantiate(&instance, resolveTestImports);
    printStart("const.210.wasm");
    assertEqualF32(
        m9_constX2E210Export1_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
