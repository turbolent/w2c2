
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.290.h"

void test() {
    const290Instance instance;
    const290Instantiate(&instance, resolveTestImports);
    printStart("const.290.wasm");
    assertEqualF32(
        const290_f(&instance),
        1.401298464324817e-45,
        "f()"
    );
}
