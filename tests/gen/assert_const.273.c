
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.273.h"

void test() {
    m9_constX2E273Instance instance;
    m9_constX2E273Instantiate(&instance, resolveTestImports);
    printStart("const.273.wasm");
    assertEqualF32(
        m9_constX2E273Export1_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
