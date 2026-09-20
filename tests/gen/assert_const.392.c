
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.392.h"

void test() {
    m9_constX2E392Instance instance;
    m9_constX2E392Instantiate(&instance, resolveTestImports);
    printStart("const.392.wasm");
    assertEqualF64(
        m9_constX2E392Export1_f(&instance),
        4.149515568880994e+180,
        "f()"
    );
}
