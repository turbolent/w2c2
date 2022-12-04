
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.304.h"

void test() {
    const304Instance instance;
    const304Instantiate(&instance, resolveTestImports);
    printStart("const.304.wasm");
    assertEqualF32(
        const304_f(&instance),
        2.802596928649634e-45,
        "f()"
    );
}
