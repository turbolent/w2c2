
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.246.h"

void test() {
    m9_constX2E246Instance instance;
    m9_constX2E246Instantiate(&instance, resolveTestImports);
    printStart("const.246.wasm");
    assertEqualF32(
        m9_constX2E246Export1_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
