
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.311.h"

void test() {
    const311Instance instance;
    const311Instantiate(&instance, resolveTestImports);
    printStart("const.311.wasm");
    assertEqualF32(
        const311_f(&instance),
        -2.802596928649634e-45,
        "f()"
    );
}
