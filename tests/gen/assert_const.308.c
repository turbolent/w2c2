
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.308.h"

void test() {
    const308Instance instance;
    const308Instantiate(&instance, resolveTestImports);
    printStart("const.308.wasm");
    assertEqualF32(
        const308_f(&instance),
        2.802596928649634e-45,
        "f()"
    );
}
