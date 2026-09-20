
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.382.h"

void test() {
    m9_constX2E382Instance instance;
    m9_constX2E382Instantiate(&instance, resolveTestImports);
    printStart("const.382.wasm");
    assertEqualF64(
        m9_constX2E382Export1_f(&instance),
        4.149515568880993e+180,
        "f()"
    );
}
