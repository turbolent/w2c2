
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.272.h"

void test() {
    m9_constX2E272Instance instance;
    m9_constX2E272Instantiate(&instance, resolveTestImports);
    printStart("const.272.wasm");
    assertEqualF32(
        m9_constX2E272Export1_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
