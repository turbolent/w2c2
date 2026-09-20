
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.180.h"

void test() {
    m9_constX2E180Instance instance;
    m9_constX2E180Instantiate(&instance, resolveTestImports);
    printStart("const.180.wasm");
    assertEqualF32(
        m9_constX2E180Export1_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
