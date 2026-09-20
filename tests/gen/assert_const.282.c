
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.282.h"

void test() {
    m9_constX2E282Instance instance;
    m9_constX2E282Instantiate(&instance, resolveTestImports);
    printStart("const.282.wasm");
    assertEqualF32(
        m9_constX2E282Export1_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
