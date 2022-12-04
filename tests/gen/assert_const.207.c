
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.207.h"

void test() {
    const207Instance instance;
    const207Instantiate(&instance, resolveTestImports);
    printStart("const.207.wasm");
    assertEqualF32(
        const207_f(&instance),
        -8.881784197001252e-16,
        "f()"
    );
}
