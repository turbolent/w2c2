
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.285.h"

void test() {
    m9_constX2E285Instance instance;
    m9_constX2E285Instantiate(&instance, resolveTestImports);
    printStart("const.285.wasm");
    assertEqualF32(
        m9_constX2E285Export1_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
