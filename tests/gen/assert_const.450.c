
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.450.h"

void test() {
    m9_constX2E450Instance instance;
    m9_constX2E450Instantiate(&instance, resolveTestImports);
    printStart("const.450.wasm");
    assertEqualF64(
        m9_constX2E450Export1_f(&instance),
        5e-324,
        "f()"
    );
}
