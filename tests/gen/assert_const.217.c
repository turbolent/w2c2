
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.217.h"

void test() {
    const217Instance instance;
    const217Instantiate(&instance, resolveTestImports);
    printStart("const.217.wasm");
    assertEqualF32(
        const217_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
