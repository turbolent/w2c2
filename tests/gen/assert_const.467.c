
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.467.h"

void test() {
    const467Instance instance;
    const467Instantiate(&instance, resolveTestImports);
    printStart("const.467.wasm");
    assertEqualF64(
        const467_f(&instance),
        -1e-323,
        "f()"
    );
}
