
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.350.h"

void test() {
    const350Instance instance;
    const350Instantiate(&instance, resolveTestImports);
    printStart("const.350.wasm");
    assertEqualF64(
        const350_f(&instance),
        2.4099198651028847e-181,
        "f()"
    );
}
