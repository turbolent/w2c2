
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.257.h"

void test() {
    m9_constX2E257Instance instance;
    m9_constX2E257Instantiate(&instance, resolveTestImports);
    printStart("const.257.wasm");
    assertEqualF32(
        m9_constX2E257Export1_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
