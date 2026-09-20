
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.187.h"

void test() {
    m9_constX2E187Instance instance;
    m9_constX2E187Instantiate(&instance, resolveTestImports);
    printStart("const.187.wasm");
    assertEqualF32(
        m9_constX2E187Export1_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
