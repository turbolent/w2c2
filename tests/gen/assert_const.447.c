
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.447.h"

void test() {
    m9_constX2E447Instance instance;
    m9_constX2E447Instantiate(&instance, resolveTestImports);
    printStart("const.447.wasm");
    assertEqualF64(
        m9_constX2E447Export1_f(&instance),
        -0.0,
        "f()"
    );
}
