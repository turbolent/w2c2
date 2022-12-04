
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.333.h"

void test() {
    const333Instance instance;
    const333Instantiate(&instance, resolveTestImports);
    printStart("const.333.wasm");
    assertEqualF64(
        const333_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
