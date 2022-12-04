
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.307.h"

void test() {
    const307Instance instance;
    const307Instantiate(&instance, resolveTestImports);
    printStart("const.307.wasm");
    assertEqualF32(
        const307_f(&instance),
        -2.802596928649634e-45,
        "f()"
    );
}
