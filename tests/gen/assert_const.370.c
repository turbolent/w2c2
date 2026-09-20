
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.370.h"

void test() {
    m9_constX2E370Instance instance;
    m9_constX2E370Instantiate(&instance, resolveTestImports);
    printStart("const.370.wasm");
    assertEqualF64(
        m9_constX2E370Export1_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
