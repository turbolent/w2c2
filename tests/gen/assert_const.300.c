
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.300.h"

void test() {
    const300Instance instance;
    const300Instantiate(&instance, resolveTestImports);
    printStart("const.300.wasm");
    assertEqualF32(
        const300_f(&instance),
        2.802596928649634e-45,
        "f()"
    );
}
