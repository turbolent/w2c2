
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.179.h"

void test() {
    m9_constX2E179Instance instance;
    m9_constX2E179Instantiate(&instance, resolveTestImports);
    printStart("const.179.wasm");
    assertEqualF32(
        m9_constX2E179Export1_f(&instance),
        -8.881784197001252e-16,
        "f()"
    );
}
