
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.323.h"

void test() {
    m9_constX2E323Instance instance;
    m9_constX2E323Instantiate(&instance, resolveTestImports);
    printStart("const.323.wasm");
    assertEqualF64(
        m9_constX2E323Export1_f(&instance),
        -2.409919865102884e-181,
        "f()"
    );
}
