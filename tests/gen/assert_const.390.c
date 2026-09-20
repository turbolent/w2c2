
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.390.h"

void test() {
    m9_constX2E390Instance instance;
    m9_constX2E390Instantiate(&instance, resolveTestImports);
    printStart("const.390.wasm");
    assertEqualF64(
        m9_constX2E390Export1_f(&instance),
        4.149515568880994e+180,
        "f()"
    );
}
