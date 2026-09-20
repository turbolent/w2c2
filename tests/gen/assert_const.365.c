
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.365.h"

void test() {
    m9_constX2E365Instance instance;
    m9_constX2E365Instantiate(&instance, resolveTestImports);
    printStart("const.365.wasm");
    assertEqualF64(
        m9_constX2E365Export1_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
