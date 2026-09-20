
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.279.h"

void test() {
    m9_constX2E279Instance instance;
    m9_constX2E279Instantiate(&instance, resolveTestImports);
    printStart("const.279.wasm");
    assertEqualF32(
        m9_constX2E279Export1_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
