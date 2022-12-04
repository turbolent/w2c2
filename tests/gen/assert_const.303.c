
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.303.h"

void test() {
    const303Instance instance;
    const303Instantiate(&instance, resolveTestImports);
    printStart("const.303.wasm");
    assertEqualF32(
        const303_f(&instance),
        -2.802596928649634e-45,
        "f()"
    );
}
