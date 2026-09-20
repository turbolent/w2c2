
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.469.h"

void test() {
    m9_constX2E469Instance instance;
    m9_constX2E469Instantiate(&instance, resolveTestImports);
    printStart("const.469.wasm");
    assertEqualF64(
        m9_constX2E469Export1_f(&instance),
        -1e-323,
        "f()"
    );
}
