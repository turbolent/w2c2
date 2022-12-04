
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.215.h"

void test() {
    const215Instance instance;
    const215Instantiate(&instance, resolveTestImports);
    printStart("const.215.wasm");
    assertEqualF32(
        const215_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
