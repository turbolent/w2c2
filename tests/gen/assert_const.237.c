
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.237.h"

void test() {
    m9_constX2E237Instance instance;
    m9_constX2E237Instantiate(&instance, resolveTestImports);
    printStart("const.237.wasm");
    assertEqualF32(
        m9_constX2E237Export1_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
