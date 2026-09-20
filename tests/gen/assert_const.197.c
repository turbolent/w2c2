
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.197.h"

void test() {
    m9_constX2E197Instance instance;
    m9_constX2E197Instantiate(&instance, resolveTestImports);
    printStart("const.197.wasm");
    assertEqualF32(
        m9_constX2E197Export1_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
