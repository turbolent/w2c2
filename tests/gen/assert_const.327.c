
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.327.h"

void test() {
    const327Instance instance;
    const327Instantiate(&instance, resolveTestImports);
    printStart("const.327.wasm");
    assertEqualF64(
        const327_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
