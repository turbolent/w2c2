
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.288.h"

void test() {
    m9_constX2E288Instance instance;
    m9_constX2E288Instantiate(&instance, resolveTestImports);
    printStart("const.288.wasm");
    assertEqualF32(
        m9_constX2E288Export1_f(&instance),
        0.0,
        "f()"
    );
}
