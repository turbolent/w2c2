
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.313.h"

void test() {
    const313Instance instance;
    const313Instantiate(&instance, resolveTestImports);
    printStart("const.313.wasm");
    assertEqualF32(
        const313_f(&instance),
        -2.802596928649634e-45,
        "f()"
    );
}
