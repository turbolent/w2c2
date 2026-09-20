
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.336.h"

void test() {
    m9_constX2E336Instance instance;
    m9_constX2E336Instantiate(&instance, resolveTestImports);
    printStart("const.336.wasm");
    assertEqualF64(
        m9_constX2E336Export1_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
