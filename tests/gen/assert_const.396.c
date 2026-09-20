
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.396.h"

void test() {
    m9_constX2E396Instance instance;
    m9_constX2E396Instantiate(&instance, resolveTestImports);
    printStart("const.396.wasm");
    assertEqualF64(
        m9_constX2E396Export1_f(&instance),
        4.149515568880995e+180,
        "f()"
    );
}
