
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.325.h"

void test() {
    const325Instance instance;
    const325Instantiate(&instance, resolveTestImports);
    printStart("const.325.wasm");
    assertEqualF64(
        const325_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
