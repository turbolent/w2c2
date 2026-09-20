
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.338.h"

void test() {
    m9_constX2E338Instance instance;
    m9_constX2E338Instantiate(&instance, resolveTestImports);
    printStart("const.338.wasm");
    assertEqualF64(
        m9_constX2E338Export1_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
