
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.222.h"

void test() {
    m9_constX2E222Instance instance;
    m9_constX2E222Instantiate(&instance, resolveTestImports);
    printStart("const.222.wasm");
    assertEqualF32(
        m9_constX2E222Export1_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
