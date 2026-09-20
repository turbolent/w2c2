
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.459.h"

void test() {
    m9_constX2E459Instance instance;
    m9_constX2E459Instantiate(&instance, resolveTestImports);
    printStart("const.459.wasm");
    assertEqualF64(
        m9_constX2E459Export1_f(&instance),
        -1e-323,
        "f()"
    );
}
