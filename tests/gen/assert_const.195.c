
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.195.h"

void test() {
    const195Instance instance;
    const195Instantiate(&instance, resolveTestImports);
    printStart("const.195.wasm");
    assertEqualF32(
        const195_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
