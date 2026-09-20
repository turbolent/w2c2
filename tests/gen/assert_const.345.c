
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.345.h"

void test() {
    m9_constX2E345Instance instance;
    m9_constX2E345Instantiate(&instance, resolveTestImports);
    printStart("const.345.wasm");
    assertEqualF64(
        m9_constX2E345Export1_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
