
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.204.h"

void test() {
    m9_constX2E204Instance instance;
    m9_constX2E204Instantiate(&instance, resolveTestImports);
    printStart("const.204.wasm");
    assertEqualF32(
        m9_constX2E204Export1_f(&instance),
        8.881787373374805e-16,
        "f()"
    );
}
