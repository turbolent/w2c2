
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.194.h"

void test() {
    m9_constX2E194Instance instance;
    m9_constX2E194Instantiate(&instance, resolveTestImports);
    printStart("const.194.wasm");
    assertEqualF32(
        m9_constX2E194Export1_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
