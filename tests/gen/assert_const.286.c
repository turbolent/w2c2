
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.286.h"

void test() {
    m9_constX2E286Instance instance;
    m9_constX2E286Instantiate(&instance, resolveTestImports);
    printStart("const.286.wasm");
    assertEqualF32(
        m9_constX2E286Export1_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
