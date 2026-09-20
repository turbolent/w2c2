
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.263.h"

void test() {
    m9_constX2E263Instance instance;
    m9_constX2E263Instantiate(&instance, resolveTestImports);
    printStart("const.263.wasm");
    assertEqualF32(
        m9_constX2E263Export1_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
