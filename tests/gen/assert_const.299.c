
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.299.h"

void test() {
    const299Instance instance;
    const299Instantiate(&instance, resolveTestImports);
    printStart("const.299.wasm");
    assertEqualF32(
        const299_f(&instance),
        -1.401298464324817e-45,
        "f()"
    );
}
