
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.185.h"

void test() {
    const185Instance instance;
    const185Instantiate(&instance, resolveTestImports);
    printStart("const.185.wasm");
    assertEqualF32(
        const185_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
