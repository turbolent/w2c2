
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.355.h"

void test() {
    const355Instance instance;
    const355Instantiate(&instance, resolveTestImports);
    printStart("const.355.wasm");
    assertEqualF64(
        const355_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
