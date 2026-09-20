
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.322.h"

void test() {
    m9_constX2E322Instance instance;
    m9_constX2E322Instantiate(&instance, resolveTestImports);
    printStart("const.322.wasm");
    assertEqualF64(
        m9_constX2E322Export1_f(&instance),
        2.409919865102884e-181,
        "f()"
    );
}
