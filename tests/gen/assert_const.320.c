
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.320.h"

void test() {
    m9_constX2E320Instance instance;
    m9_constX2E320Instantiate(&instance, resolveTestImports);
    printStart("const.320.wasm");
    assertEqualF32(
        m9_constX2E320Export1_f(&instance),
        3.4028234663852886e+38,
        "f()"
    );
}
