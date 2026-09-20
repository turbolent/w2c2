
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.383.h"

void test() {
    m9_constX2E383Instance instance;
    m9_constX2E383Instantiate(&instance, resolveTestImports);
    printStart("const.383.wasm");
    assertEqualF64(
        m9_constX2E383Export1_f(&instance),
        -4.149515568880993e+180,
        "f()"
    );
}
