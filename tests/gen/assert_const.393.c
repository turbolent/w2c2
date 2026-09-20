
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.393.h"

void test() {
    m9_constX2E393Instance instance;
    m9_constX2E393Instantiate(&instance, resolveTestImports);
    printStart("const.393.wasm");
    assertEqualF64(
        m9_constX2E393Export1_f(&instance),
        -4.149515568880994e+180,
        "f()"
    );
}
