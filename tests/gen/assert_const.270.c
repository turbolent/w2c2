
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.270.h"

void test() {
    m9_constX2E270Instance instance;
    m9_constX2E270Instantiate(&instance, resolveTestImports);
    printStart("const.270.wasm");
    assertEqualF32(
        m9_constX2E270Export1_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
