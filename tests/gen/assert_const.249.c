
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.249.h"

void test() {
    m9_constX2E249Instance instance;
    m9_constX2E249Instantiate(&instance, resolveTestImports);
    printStart("const.249.wasm");
    assertEqualF32(
        m9_constX2E249Export1_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
