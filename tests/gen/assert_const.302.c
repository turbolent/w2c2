
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.302.h"

void test() {
    const302Instance instance;
    const302Instantiate(&instance, resolveTestImports);
    printStart("const.302.wasm");
    assertEqualF32(
        const302_f(&instance),
        2.802596928649634e-45,
        "f()"
    );
}
