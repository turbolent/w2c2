
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.181.h"

void test() {
    m9_constX2E181Instance instance;
    m9_constX2E181Instantiate(&instance, resolveTestImports);
    printStart("const.181.wasm");
    assertEqualF32(
        m9_constX2E181Export1_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
