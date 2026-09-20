
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.442.h"

void test() {
    m9_constX2E442Instance instance;
    m9_constX2E442Instantiate(&instance, resolveTestImports);
    printStart("const.442.wasm");
    assertEqualF64(
        m9_constX2E442Export1_f(&instance),
        1.1529215046068472e+18,
        "f()"
    );
}
