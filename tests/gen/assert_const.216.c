
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.216.h"

void test() {
    m9_constX2E216Instance instance;
    m9_constX2E216Instantiate(&instance, resolveTestImports);
    printStart("const.216.wasm");
    assertEqualF32(
        m9_constX2E216Export1_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
