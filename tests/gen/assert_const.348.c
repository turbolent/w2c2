
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.348.h"

void test() {
    m9_constX2E348Instance instance;
    m9_constX2E348Instantiate(&instance, resolveTestImports);
    printStart("const.348.wasm");
    assertEqualF64(
        m9_constX2E348Export1_f(&instance),
        2.409919865102884e-181,
        "f()"
    );
}
