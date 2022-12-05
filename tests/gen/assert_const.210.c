
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.210.h"

void test() {
    const210Instance instance;
    const210Instantiate(&instance, resolveTestImports);
    printStart("const.210.wasm");
    assertEqualF32(
        const210_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
