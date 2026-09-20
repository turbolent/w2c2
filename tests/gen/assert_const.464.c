
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.464.h"

void test() {
    m9_constX2E464Instance instance;
    m9_constX2E464Instantiate(&instance, resolveTestImports);
    printStart("const.464.wasm");
    assertEqualF64(
        m9_constX2E464Export1_f(&instance),
        1e-323,
        "f()"
    );
}
