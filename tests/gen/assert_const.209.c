
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.209.h"

void test() {
    const209Instance instance;
    const209Instantiate(&instance, resolveTestImports);
    printStart("const.209.wasm");
    assertEqualF32(
        const209_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
