
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.245.h"

void test() {
    m9_constX2E245Instance instance;
    m9_constX2E245Instantiate(&instance, resolveTestImports);
    printStart("const.245.wasm");
    assertEqualF32(
        m9_constX2E245Export1_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
