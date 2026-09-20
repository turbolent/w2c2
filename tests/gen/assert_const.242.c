
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.242.h"

void test() {
    m9_constX2E242Instance instance;
    m9_constX2E242Instantiate(&instance, resolveTestImports);
    printStart("const.242.wasm");
    assertEqualF32(
        m9_constX2E242Export1_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
