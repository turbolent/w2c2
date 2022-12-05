
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.183.h"

void test() {
    const183Instance instance;
    const183Instantiate(&instance, resolveTestImports);
    printStart("const.183.wasm");
    assertEqualF32(
        const183_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
