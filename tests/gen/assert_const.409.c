
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.409.h"

void test() {
    m9_constX2E409Instance instance;
    m9_constX2E409Instantiate(&instance, resolveTestImports);
    printStart("const.409.wasm");
    assertEqualF64(
        m9_constX2E409Export1_f(&instance),
        -4.149515568880996e+180,
        "f()"
    );
}
