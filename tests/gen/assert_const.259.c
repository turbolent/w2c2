
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.259.h"

void test() {
    m9_constX2E259Instance instance;
    m9_constX2E259Instantiate(&instance, resolveTestImports);
    printStart("const.259.wasm");
    assertEqualF32(
        m9_constX2E259Export1_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
