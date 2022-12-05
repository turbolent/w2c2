
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.305.h"

void test() {
    const305Instance instance;
    const305Instantiate(&instance, resolveTestImports);
    printStart("const.305.wasm");
    assertEqualF32(
        const305_f(&instance),
        -2.802596928649634e-45,
        "f()"
    );
}
