
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.276.h"

void test() {
    m9_constX2E276Instance instance;
    m9_constX2E276Instantiate(&instance, resolveTestImports);
    printStart("const.276.wasm");
    assertEqualF32(
        m9_constX2E276Export1_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
