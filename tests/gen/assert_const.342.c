
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.342.h"

void test() {
    m9_constX2E342Instance instance;
    m9_constX2E342Instantiate(&instance, resolveTestImports);
    printStart("const.342.wasm");
    assertEqualF64(
        m9_constX2E342Export1_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
