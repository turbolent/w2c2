
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.298.h"

void test() {
    m9_constX2E298Instance instance;
    m9_constX2E298Instantiate(&instance, resolveTestImports);
    printStart("const.298.wasm");
    assertEqualF32(
        m9_constX2E298Export1_f(&instance),
        1.401298464324817e-45,
        "f()"
    );
}
