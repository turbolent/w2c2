
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.299.h"

void test() {
    m9_constX2E299Instance instance;
    m9_constX2E299Instantiate(&instance, resolveTestImports);
    printStart("const.299.wasm");
    assertEqualF32(
        m9_constX2E299Export1_f(&instance),
        -1.401298464324817e-45,
        "f()"
    );
}
