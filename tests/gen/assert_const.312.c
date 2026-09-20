
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.312.h"

void test() {
    m9_constX2E312Instance instance;
    m9_constX2E312Instantiate(&instance, resolveTestImports);
    printStart("const.312.wasm");
    assertEqualF32(
        m9_constX2E312Export1_f(&instance),
        2.802596928649634e-45,
        "f()"
    );
}
