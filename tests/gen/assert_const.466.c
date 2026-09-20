
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.466.h"

void test() {
    m9_constX2E466Instance instance;
    m9_constX2E466Instantiate(&instance, resolveTestImports);
    printStart("const.466.wasm");
    assertEqualF64(
        m9_constX2E466Export1_f(&instance),
        1e-323,
        "f()"
    );
}
