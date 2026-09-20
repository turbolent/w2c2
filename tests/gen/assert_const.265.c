
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.265.h"

void test() {
    m9_constX2E265Instance instance;
    m9_constX2E265Instantiate(&instance, resolveTestImports);
    printStart("const.265.wasm");
    assertEqualF32(
        m9_constX2E265Export1_f(&instance),
        -1125900309495808.0,
        "f()"
    );
}
