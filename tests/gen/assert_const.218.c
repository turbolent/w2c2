
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.218.h"

void test() {
    m9_constX2E218Instance instance;
    m9_constX2E218Instantiate(&instance, resolveTestImports);
    printStart("const.218.wasm");
    assertEqualF32(
        m9_constX2E218Export1_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
