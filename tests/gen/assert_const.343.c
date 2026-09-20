
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.343.h"

void test() {
    m9_constX2E343Instance instance;
    m9_constX2E343Instantiate(&instance, resolveTestImports);
    printStart("const.343.wasm");
    assertEqualF64(
        m9_constX2E343Export1_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
