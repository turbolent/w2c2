
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.225.h"

void test() {
    const225Instance instance;
    const225Instantiate(&instance, resolveTestImports);
    printStart("const.225.wasm");
    assertEqualF32(
        const225_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
