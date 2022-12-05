
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.354.h"

void test() {
    const354Instance instance;
    const354Instantiate(&instance, resolveTestImports);
    printStart("const.354.wasm");
    assertEqualF64(
        const354_f(&instance),
        2.4099198651028847e-181,
        "f()"
    );
}
