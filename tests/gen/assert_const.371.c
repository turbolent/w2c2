
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.371.h"

void test() {
    m9_constX2E371Instance instance;
    m9_constX2E371Instantiate(&instance, resolveTestImports);
    printStart("const.371.wasm");
    assertEqualF64(
        m9_constX2E371Export1_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
