
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.258.h"

void test() {
    m9_constX2E258Instance instance;
    m9_constX2E258Instantiate(&instance, resolveTestImports);
    printStart("const.258.wasm");
    assertEqualF32(
        m9_constX2E258Export1_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
