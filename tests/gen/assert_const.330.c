
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.330.h"

void test() {
    const330Instance instance;
    const330Instantiate(&instance, resolveTestImports);
    printStart("const.330.wasm");
    assertEqualF64(
        const330_f(&instance),
        2.4099198651028847e-181,
        "f()"
    );
}
