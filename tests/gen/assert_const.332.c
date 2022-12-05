
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.332.h"

void test() {
    const332Instance instance;
    const332Instantiate(&instance, resolveTestImports);
    printStart("const.332.wasm");
    assertEqualF64(
        const332_f(&instance),
        2.4099198651028847e-181,
        "f()"
    );
}
