
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.385.h"

void test() {
    m9_constX2E385Instance instance;
    m9_constX2E385Instantiate(&instance, resolveTestImports);
    printStart("const.385.wasm");
    assertEqualF64(
        m9_constX2E385Export1_f(&instance),
        -4.149515568880994e+180,
        "f()"
    );
}
