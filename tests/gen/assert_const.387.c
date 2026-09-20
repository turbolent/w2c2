
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.387.h"

void test() {
    m9_constX2E387Instance instance;
    m9_constX2E387Instantiate(&instance, resolveTestImports);
    printStart("const.387.wasm");
    assertEqualF64(
        m9_constX2E387Export1_f(&instance),
        -4.149515568880994e+180,
        "f()"
    );
}
