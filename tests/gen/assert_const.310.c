
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.310.h"

void test() {
    const310Instance instance;
    const310Instantiate(&instance, resolveTestImports);
    printStart("const.310.wasm");
    assertEqualF32(
        const310_f(&instance),
        2.802596928649634e-45,
        "f()"
    );
}
