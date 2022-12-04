
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.372.h"

void test() {
    const372Instance instance;
    const372Instantiate(&instance, resolveTestImports);
    printStart("const.372.wasm");
    assertEqualF64(
        const372_f(&instance),
        2.4099198651028857e-181,
        "f()"
    );
}
