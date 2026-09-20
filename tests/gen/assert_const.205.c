
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.205.h"

void test() {
    m9_constX2E205Instance instance;
    m9_constX2E205Instantiate(&instance, resolveTestImports);
    printStart("const.205.wasm");
    assertEqualF32(
        m9_constX2E205Export1_f(&instance),
        -8.881787373374805e-16,
        "f()"
    );
}
