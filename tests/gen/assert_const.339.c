
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.339.h"

void test() {
    m9_constX2E339Instance instance;
    m9_constX2E339Instantiate(&instance, resolveTestImports);
    printStart("const.339.wasm");
    assertEqualF64(
        m9_constX2E339Export1_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
