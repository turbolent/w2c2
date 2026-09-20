
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.244.h"

void test() {
    m9_constX2E244Instance instance;
    m9_constX2E244Instantiate(&instance, resolveTestImports);
    printStart("const.244.wasm");
    assertEqualF32(
        m9_constX2E244Export1_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
