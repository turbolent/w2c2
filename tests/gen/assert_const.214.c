
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.214.h"

void test() {
    m9_constX2E214Instance instance;
    m9_constX2E214Instantiate(&instance, resolveTestImports);
    printStart("const.214.wasm");
    assertEqualF32(
        m9_constX2E214Export1_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
