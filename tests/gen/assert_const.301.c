
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.301.h"

void test() {
    const301Instance instance;
    const301Instantiate(&instance, resolveTestImports);
    printStart("const.301.wasm");
    assertEqualF32(
        const301_f(&instance),
        -2.802596928649634e-45,
        "f()"
    );
}
