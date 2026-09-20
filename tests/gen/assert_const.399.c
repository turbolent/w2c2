
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.399.h"

void test() {
    m9_constX2E399Instance instance;
    m9_constX2E399Instantiate(&instance, resolveTestImports);
    printStart("const.399.wasm");
    assertEqualF64(
        m9_constX2E399Export1_f(&instance),
        -4.149515568880995e+180,
        "f()"
    );
}
