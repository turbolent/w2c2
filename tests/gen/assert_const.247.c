
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.247.h"

void test() {
    m9_constX2E247Instance instance;
    m9_constX2E247Instantiate(&instance, resolveTestImports);
    printStart("const.247.wasm");
    assertEqualF32(
        m9_constX2E247Export1_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
