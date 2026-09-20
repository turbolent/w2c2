
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.201.h"

void test() {
    m9_constX2E201Instance instance;
    m9_constX2E201Instantiate(&instance, resolveTestImports);
    printStart("const.201.wasm");
    assertEqualF32(
        m9_constX2E201Export1_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
