
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.304.h"

void test() {
    m9_constX2E304Instance instance;
    m9_constX2E304Instantiate(&instance, resolveTestImports);
    printStart("const.304.wasm");
    assertEqualF32(
        m9_constX2E304Export1_f(&instance),
        2.802596928649634e-45,
        "f()"
    );
}
