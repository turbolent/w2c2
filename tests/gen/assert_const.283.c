
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.283.h"

void test() {
    m9_constX2E283Instance instance;
    m9_constX2E283Instantiate(&instance, resolveTestImports);
    printStart("const.283.wasm");
    assertEqualF32(
        m9_constX2E283Export1_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
