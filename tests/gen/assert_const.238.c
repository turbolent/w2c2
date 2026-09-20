
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.238.h"

void test() {
    m9_constX2E238Instance instance;
    m9_constX2E238Instantiate(&instance, resolveTestImports);
    printStart("const.238.wasm");
    assertEqualF32(
        m9_constX2E238Export1_f(&instance),
        1125899906842624.0,
        "f()"
    );
}
