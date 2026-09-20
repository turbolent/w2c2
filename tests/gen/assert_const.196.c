
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.196.h"

void test() {
    m9_constX2E196Instance instance;
    m9_constX2E196Instantiate(&instance, resolveTestImports);
    printStart("const.196.wasm");
    assertEqualF32(
        m9_constX2E196Export1_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
