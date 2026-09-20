
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.296.h"

void test() {
    m9_constX2E296Instance instance;
    m9_constX2E296Instantiate(&instance, resolveTestImports);
    printStart("const.296.wasm");
    assertEqualF32(
        m9_constX2E296Export1_f(&instance),
        1.401298464324817e-45,
        "f()"
    );
}
