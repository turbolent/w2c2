
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.191.h"

void test() {
    const191Instance instance;
    const191Instantiate(&instance, resolveTestImports);
    printStart("const.191.wasm");
    assertEqualF32(
        const191_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
