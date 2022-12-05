
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.359.h"

void test() {
    const359Instance instance;
    const359Instantiate(&instance, resolveTestImports);
    printStart("const.359.wasm");
    assertEqualF64(
        const359_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
