
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.475.h"

void test() {
    const475Instance instance;
    const475Instantiate(&instance, resolveTestImports);
    printStart("const.475.wasm");
    assertEqualF64(
        const475_f(&instance),
        -1.7976931348623157e+308,
        "f()"
    );
}
