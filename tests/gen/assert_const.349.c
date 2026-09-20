
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.349.h"

void test() {
    m9_constX2E349Instance instance;
    m9_constX2E349Instantiate(&instance, resolveTestImports);
    printStart("const.349.wasm");
    assertEqualF64(
        m9_constX2E349Export1_f(&instance),
        -2.409919865102884e-181,
        "f()"
    );
}
