
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.314.h"

void test() {
    m9_constX2E314Instance instance;
    m9_constX2E314Instantiate(&instance, resolveTestImports);
    printStart("const.314.wasm");
    assertEqualF32(
        m9_constX2E314Export1_f(&instance),
        4.203895392974451e-45,
        "f()"
    );
}
