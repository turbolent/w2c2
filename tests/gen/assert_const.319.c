
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.319.h"

void test() {
    m9_constX2E319Instance instance;
    m9_constX2E319Instantiate(&instance, resolveTestImports);
    printStart("const.319.wasm");
    assertEqualF32(
        m9_constX2E319Export1_f(&instance),
        -3.4028234663852886e+38,
        "f()"
    );
}
