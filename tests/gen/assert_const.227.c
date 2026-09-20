
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.227.h"

void test() {
    m9_constX2E227Instance instance;
    m9_constX2E227Instantiate(&instance, resolveTestImports);
    printStart("const.227.wasm");
    assertEqualF32(
        m9_constX2E227Export1_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
