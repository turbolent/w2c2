
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.329.h"

void test() {
    const329Instance instance;
    const329Instantiate(&instance, resolveTestImports);
    printStart("const.329.wasm");
    assertEqualF64(
        const329_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
