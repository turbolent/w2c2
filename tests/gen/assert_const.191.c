
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.191.h"

void test() {
    m9_constX2E191Instance instance;
    m9_constX2E191Instantiate(&instance, resolveTestImports);
    printStart("const.191.wasm");
    assertEqualF32(
        m9_constX2E191Export1_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
