
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.361.h"

void test() {
    m9_constX2E361Instance instance;
    m9_constX2E361Instantiate(&instance, resolveTestImports);
    printStart("const.361.wasm");
    assertEqualF64(
        m9_constX2E361Export1_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
