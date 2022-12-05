
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.219.h"

void test() {
    const219Instance instance;
    const219Instantiate(&instance, resolveTestImports);
    printStart("const.219.wasm");
    assertEqualF32(
        const219_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
