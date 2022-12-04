
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.233.h"

void test() {
    const233Instance instance;
    const233Instantiate(&instance, resolveTestImports);
    printStart("const.233.wasm");
    assertEqualF32(
        const233_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
