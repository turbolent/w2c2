
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.315.h"

void test() {
    m9_constX2E315Instance instance;
    m9_constX2E315Instantiate(&instance, resolveTestImports);
    printStart("const.315.wasm");
    assertEqualF32(
        m9_constX2E315Export1_f(&instance),
        -4.203895392974451e-45,
        "f()"
    );
}
