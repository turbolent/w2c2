
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.292.h"

void test() {
    m9_constX2E292Instance instance;
    m9_constX2E292Instantiate(&instance, resolveTestImports);
    printStart("const.292.wasm");
    assertEqualF32(
        m9_constX2E292Export1_f(&instance),
        1.401298464324817e-45,
        "f()"
    );
}
