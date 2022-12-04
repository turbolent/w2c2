
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.309.h"

void test() {
    const309Instance instance;
    const309Instantiate(&instance, resolveTestImports);
    printStart("const.309.wasm");
    assertEqualF32(
        const309_f(&instance),
        -2.802596928649634e-45,
        "f()"
    );
}
