
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.275.h"

void test() {
    m9_constX2E275Instance instance;
    m9_constX2E275Instantiate(&instance, resolveTestImports);
    printStart("const.275.wasm");
    assertEqualF32(
        m9_constX2E275Export1_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
