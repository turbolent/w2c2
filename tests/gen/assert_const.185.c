
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.185.h"

void test() {
    m9_constX2E185Instance instance;
    m9_constX2E185Instantiate(&instance, resolveTestImports);
    printStart("const.185.wasm");
    assertEqualF32(
        m9_constX2E185Export1_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
