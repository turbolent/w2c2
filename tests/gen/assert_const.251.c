
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.251.h"

void test() {
    m9_constX2E251Instance instance;
    m9_constX2E251Instantiate(&instance, resolveTestImports);
    printStart("const.251.wasm");
    assertEqualF32(
        m9_constX2E251Export1_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
