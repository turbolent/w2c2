
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.241.h"

void test() {
    m9_constX2E241Instance instance;
    m9_constX2E241Instantiate(&instance, resolveTestImports);
    printStart("const.241.wasm");
    assertEqualF32(
        m9_constX2E241Export1_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
