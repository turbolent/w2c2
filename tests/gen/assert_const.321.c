
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.321.h"

void test() {
    m9_constX2E321Instance instance;
    m9_constX2E321Instantiate(&instance, resolveTestImports);
    printStart("const.321.wasm");
    assertEqualF32(
        m9_constX2E321Export1_f(&instance),
        -3.4028234663852886e+38,
        "f()"
    );
}
