
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.440.h"

void test() {
    m9_constX2E440Instance instance;
    m9_constX2E440Instantiate(&instance, resolveTestImports);
    printStart("const.440.wasm");
    assertEqualF64(
        m9_constX2E440Export1_f(&instance),
        1.1529215046068472e+18,
        "f()"
    );
}
