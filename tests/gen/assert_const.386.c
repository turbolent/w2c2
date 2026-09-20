
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.386.h"

void test() {
    m9_constX2E386Instance instance;
    m9_constX2E386Instantiate(&instance, resolveTestImports);
    printStart("const.386.wasm");
    assertEqualF64(
        m9_constX2E386Export1_f(&instance),
        4.149515568880994e+180,
        "f()"
    );
}
