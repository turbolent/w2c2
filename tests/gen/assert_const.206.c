
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.206.h"

void test() {
    m9_constX2E206Instance instance;
    m9_constX2E206Instantiate(&instance, resolveTestImports);
    printStart("const.206.wasm");
    assertEqualF32(
        m9_constX2E206Export1_f(&instance),
        8.881784197001252e-16,
        "f()"
    );
}
