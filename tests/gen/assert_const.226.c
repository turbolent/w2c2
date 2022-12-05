
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.226.h"

void test() {
    const226Instance instance;
    const226Instantiate(&instance, resolveTestImports);
    printStart("const.226.wasm");
    assertEqualF32(
        const226_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
