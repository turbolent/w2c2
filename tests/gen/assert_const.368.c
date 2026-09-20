
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.368.h"

void test() {
    m9_constX2E368Instance instance;
    m9_constX2E368Instantiate(&instance, resolveTestImports);
    printStart("const.368.wasm");
    assertEqualF64(
        m9_constX2E368Export1_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
