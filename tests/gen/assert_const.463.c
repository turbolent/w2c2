
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.463.h"

void test() {
    m9_constX2E463Instance instance;
    m9_constX2E463Instantiate(&instance, resolveTestImports);
    printStart("const.463.wasm");
    assertEqualF64(
        m9_constX2E463Export1_f(&instance),
        -1e-323,
        "f()"
    );
}
