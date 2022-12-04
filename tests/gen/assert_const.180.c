
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.180.h"

void test() {
    const180Instance instance;
    const180Instantiate(&instance, resolveTestImports);
    printStart("const.180.wasm");
    assertEqualF32(
        const180_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
