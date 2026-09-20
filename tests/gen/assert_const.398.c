
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.398.h"

void test() {
    m9_constX2E398Instance instance;
    m9_constX2E398Instantiate(&instance, resolveTestImports);
    printStart("const.398.wasm");
    assertEqualF64(
        m9_constX2E398Export1_f(&instance),
        4.149515568880995e+180,
        "f()"
    );
}
