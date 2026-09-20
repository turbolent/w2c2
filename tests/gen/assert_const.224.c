
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.224.h"

void test() {
    m9_constX2E224Instance instance;
    m9_constX2E224Instantiate(&instance, resolveTestImports);
    printStart("const.224.wasm");
    assertEqualF32(
        m9_constX2E224Export1_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
