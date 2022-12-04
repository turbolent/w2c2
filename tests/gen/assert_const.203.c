
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.203.h"

void test() {
    const203Instance instance;
    const203Instantiate(&instance, resolveTestImports);
    printStart("const.203.wasm");
    assertEqualF32(
        const203_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
