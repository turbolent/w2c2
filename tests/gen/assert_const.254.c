
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.254.h"

void test() {
    m9_constX2E254Instance instance;
    m9_constX2E254Instantiate(&instance, resolveTestImports);
    printStart("const.254.wasm");
    assertEqualF32(
        m9_constX2E254Export1_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
