
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.189.h"

void test() {
    m9_constX2E189Instance instance;
    m9_constX2E189Instantiate(&instance, resolveTestImports);
    printStart("const.189.wasm");
    assertEqualF32(
        m9_constX2E189Export1_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
