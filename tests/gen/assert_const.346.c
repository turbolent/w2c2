
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.346.h"

void test() {
    const346Instance instance;
    const346Instantiate(&instance, resolveTestImports);
    printStart("const.346.wasm");
    assertEqualF64(
        const346_f(&instance),
        2.4099198651028857e-181,
        "f()"
    );
}
