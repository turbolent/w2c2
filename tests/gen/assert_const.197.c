
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.197.h"

void test() {
    const197Instance instance;
    const197Instantiate(&instance, resolveTestImports);
    printStart("const.197.wasm");
    assertEqualF32(
        const197_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
