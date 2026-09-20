
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.458.h"

void test() {
    m9_constX2E458Instance instance;
    m9_constX2E458Instantiate(&instance, resolveTestImports);
    printStart("const.458.wasm");
    assertEqualF64(
        m9_constX2E458Export1_f(&instance),
        1e-323,
        "f()"
    );
}
