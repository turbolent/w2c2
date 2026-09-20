
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.212.h"

void test() {
    m9_constX2E212Instance instance;
    m9_constX2E212Instantiate(&instance, resolveTestImports);
    printStart("const.212.wasm");
    assertEqualF32(
        m9_constX2E212Export1_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
