
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.295.h"

void test() {
    m9_constX2E295Instance instance;
    m9_constX2E295Instantiate(&instance, resolveTestImports);
    printStart("const.295.wasm");
    assertEqualF32(
        m9_constX2E295Export1_f(&instance),
        -1.401298464324817e-45,
        "f()"
    );
}
