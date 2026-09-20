
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.243.h"

void test() {
    m9_constX2E243Instance instance;
    m9_constX2E243Instantiate(&instance, resolveTestImports);
    printStart("const.243.wasm");
    assertEqualF32(
        m9_constX2E243Export1_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
