
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.340.h"

void test() {
    m9_constX2E340Instance instance;
    m9_constX2E340Instantiate(&instance, resolveTestImports);
    printStart("const.340.wasm");
    assertEqualF64(
        m9_constX2E340Export1_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
