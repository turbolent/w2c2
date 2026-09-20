
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.213.h"

void test() {
    m9_constX2E213Instance instance;
    m9_constX2E213Instantiate(&instance, resolveTestImports);
    printStart("const.213.wasm");
    assertEqualF32(
        m9_constX2E213Export1_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
