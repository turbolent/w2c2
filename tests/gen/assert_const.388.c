
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.388.h"

void test() {
    m9_constX2E388Instance instance;
    m9_constX2E388Instantiate(&instance, resolveTestImports);
    printStart("const.388.wasm");
    assertEqualF64(
        m9_constX2E388Export1_f(&instance),
        4.149515568880994e+180,
        "f()"
    );
}
