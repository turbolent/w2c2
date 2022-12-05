
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.231.h"

void test() {
    const231Instance instance;
    const231Instantiate(&instance, resolveTestImports);
    printStart("const.231.wasm");
    assertEqualF32(
        const231_f(&instance),
        -8.881784197001252e-16,
        "f()"
    );
}
