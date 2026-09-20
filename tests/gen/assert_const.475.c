
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.475.h"

void test() {
    m9_constX2E475Instance instance;
    m9_constX2E475Instantiate(&instance, resolveTestImports);
    printStart("const.475.wasm");
    assertEqualF64(
        m9_constX2E475Export1_f(&instance),
        -1.7976931348623157e+308,
        "f()"
    );
}
