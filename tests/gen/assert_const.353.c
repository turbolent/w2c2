
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.353.h"

void test() {
    const353Instance instance;
    const353Instantiate(&instance, resolveTestImports);
    printStart("const.353.wasm");
    assertEqualF64(
        const353_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
