
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.234.h"

void test() {
    m9_constX2E234Instance instance;
    m9_constX2E234Instantiate(&instance, resolveTestImports);
    printStart("const.234.wasm");
    assertEqualF32(
        m9_constX2E234Export1_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
