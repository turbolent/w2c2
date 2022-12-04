
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.356.h"

void test() {
    const356Instance instance;
    const356Instantiate(&instance, resolveTestImports);
    printStart("const.356.wasm");
    assertEqualF64(
        const356_f(&instance),
        2.4099198651028847e-181,
        "f()"
    );
}
