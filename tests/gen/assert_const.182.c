
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.182.h"

void test() {
    m9_constX2E182Instance instance;
    m9_constX2E182Instantiate(&instance, resolveTestImports);
    printStart("const.182.wasm");
    assertEqualF32(
        m9_constX2E182Export1_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
