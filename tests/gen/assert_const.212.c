
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.212.h"

void test() {
    const212Instance instance;
    const212Instantiate(&instance, resolveTestImports);
    printStart("const.212.wasm");
    assertEqualF32(
        const212_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
