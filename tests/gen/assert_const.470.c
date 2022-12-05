
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.470.h"

void test() {
    const470Instance instance;
    const470Instantiate(&instance, resolveTestImports);
    printStart("const.470.wasm");
    assertEqualF64(
        const470_f(&instance),
        1e-323,
        "f()"
    );
}
