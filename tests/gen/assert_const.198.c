
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.198.h"

void test() {
    m9_constX2E198Instance instance;
    m9_constX2E198Instantiate(&instance, resolveTestImports);
    printStart("const.198.wasm");
    assertEqualF32(
        m9_constX2E198Export1_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
