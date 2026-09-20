
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.344.h"

void test() {
    m9_constX2E344Instance instance;
    m9_constX2E344Instantiate(&instance, resolveTestImports);
    printStart("const.344.wasm");
    assertEqualF64(
        m9_constX2E344Export1_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
