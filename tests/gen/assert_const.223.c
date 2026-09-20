
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.223.h"

void test() {
    m9_constX2E223Instance instance;
    m9_constX2E223Instantiate(&instance, resolveTestImports);
    printStart("const.223.wasm");
    assertEqualF32(
        m9_constX2E223Export1_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
