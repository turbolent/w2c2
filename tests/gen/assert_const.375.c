
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.375.h"

void test() {
    m9_constX2E375Instance instance;
    m9_constX2E375Instantiate(&instance, resolveTestImports);
    printStart("const.375.wasm");
    assertEqualF64(
        m9_constX2E375Export1_f(&instance),
        -5.357543035931337e+300,
        "f()"
    );
}
