
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.341.h"

void test() {
    m9_constX2E341Instance instance;
    m9_constX2E341Instantiate(&instance, resolveTestImports);
    printStart("const.341.wasm");
    assertEqualF64(
        m9_constX2E341Export1_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
