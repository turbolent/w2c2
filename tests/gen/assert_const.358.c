
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.358.h"

void test() {
    const358Instance instance;
    const358Instantiate(&instance, resolveTestImports);
    printStart("const.358.wasm");
    assertEqualF64(
        const358_f(&instance),
        2.4099198651028847e-181,
        "f()"
    );
}
