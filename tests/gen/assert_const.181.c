
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.181.h"

void test() {
    const181Instance instance;
    const181Instantiate(&instance, resolveTestImports);
    printStart("const.181.wasm");
    assertEqualF32(
        const181_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
