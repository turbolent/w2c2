
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.360.h"

void test() {
    m9_constX2E360Instance instance;
    m9_constX2E360Instantiate(&instance, resolveTestImports);
    printStart("const.360.wasm");
    assertEqualF64(
        m9_constX2E360Export1_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
