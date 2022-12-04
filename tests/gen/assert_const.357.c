
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.357.h"

void test() {
    const357Instance instance;
    const357Instantiate(&instance, resolveTestImports);
    printStart("const.357.wasm");
    assertEqualF64(
        const357_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
