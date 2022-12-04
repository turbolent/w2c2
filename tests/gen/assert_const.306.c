
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.306.h"

void test() {
    const306Instance instance;
    const306Instantiate(&instance, resolveTestImports);
    printStart("const.306.wasm");
    assertEqualF32(
        const306_f(&instance),
        2.802596928649634e-45,
        "f()"
    );
}
