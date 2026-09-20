
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.186.h"

void test() {
    m9_constX2E186Instance instance;
    m9_constX2E186Instantiate(&instance, resolveTestImports);
    printStart("const.186.wasm");
    assertEqualF32(
        m9_constX2E186Export1_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
