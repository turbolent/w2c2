
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.274.h"

void test() {
    m9_constX2E274Instance instance;
    m9_constX2E274Instantiate(&instance, resolveTestImports);
    printStart("const.274.wasm");
    assertEqualF32(
        m9_constX2E274Export1_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
