
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.445.h"

void test() {
    m9_constX2E445Instance instance;
    m9_constX2E445Instantiate(&instance, resolveTestImports);
    printStart("const.445.wasm");
    assertEqualF64(
        m9_constX2E445Export1_f(&instance),
        -1.1529215046068475e+18,
        "f()"
    );
}
