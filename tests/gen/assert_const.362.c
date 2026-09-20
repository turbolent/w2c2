
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.362.h"

void test() {
    m9_constX2E362Instance instance;
    m9_constX2E362Instantiate(&instance, resolveTestImports);
    printStart("const.362.wasm");
    assertEqualF64(
        m9_constX2E362Export1_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
