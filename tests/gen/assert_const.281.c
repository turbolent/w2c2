
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.281.h"

void test() {
    m9_constX2E281Instance instance;
    m9_constX2E281Instantiate(&instance, resolveTestImports);
    printStart("const.281.wasm");
    assertEqualF32(
        m9_constX2E281Export1_f(&instance),
        -1125899906842624.0,
        "f()"
    );
}
