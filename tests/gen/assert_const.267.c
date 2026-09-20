
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.267.h"

void test() {
    m9_constX2E267Instance instance;
    m9_constX2E267Instantiate(&instance, resolveTestImports);
    printStart("const.267.wasm");
    assertEqualF32(
        m9_constX2E267Export1_f(&instance),
        -1125899906842624.0,
        "f()"
    );
}
