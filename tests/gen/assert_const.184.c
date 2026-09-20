
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.184.h"

void test() {
    m9_constX2E184Instance instance;
    m9_constX2E184Instantiate(&instance, resolveTestImports);
    printStart("const.184.wasm");
    assertEqualF32(
        m9_constX2E184Export1_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
