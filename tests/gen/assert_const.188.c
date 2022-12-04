
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.188.h"

void test() {
    const188Instance instance;
    const188Instantiate(&instance, resolveTestImports);
    printStart("const.188.wasm");
    assertEqualF32(
        const188_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
