
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.347.h"

void test() {
    const347Instance instance;
    const347Instantiate(&instance, resolveTestImports);
    printStart("const.347.wasm");
    assertEqualF64(
        const347_f(&instance),
        -2.4099198651028857e-181,
        "f()"
    );
}
