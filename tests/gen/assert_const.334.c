
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.334.h"

void test() {
    m9_constX2E334Instance instance;
    m9_constX2E334Instantiate(&instance, resolveTestImports);
    printStart("const.334.wasm");
    assertEqualF64(
        m9_constX2E334Export1_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
