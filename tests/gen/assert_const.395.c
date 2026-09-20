
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.395.h"

void test() {
    m9_constX2E395Instance instance;
    m9_constX2E395Instantiate(&instance, resolveTestImports);
    printStart("const.395.wasm");
    assertEqualF64(
        m9_constX2E395Export1_f(&instance),
        -4.149515568880995e+180,
        "f()"
    );
}
