
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.290.h"

void test() {
    m9_constX2E290Instance instance;
    m9_constX2E290Instantiate(&instance, resolveTestImports);
    printStart("const.290.wasm");
    assertEqualF32(
        m9_constX2E290Export1_f(&instance),
        1.401298464324817e-45,
        "f()"
    );
}
