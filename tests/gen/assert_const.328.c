
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.328.h"

void test() {
    const328Instance instance;
    const328Instantiate(&instance, resolveTestImports);
    printStart("const.328.wasm");
    assertEqualF64(
        const328_f(&instance),
        2.4099198651028847e-181,
        "f()"
    );
}
