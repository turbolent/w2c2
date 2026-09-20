
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.452.h"

void test() {
    m9_constX2E452Instance instance;
    m9_constX2E452Instantiate(&instance, resolveTestImports);
    printStart("const.452.wasm");
    assertEqualF64(
        m9_constX2E452Export1_f(&instance),
        5e-324,
        "f()"
    );
}
