
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.178.h"

void test() {
    const178Instance instance;
    const178Instantiate(&instance, resolveTestImports);
    printStart("const.178.wasm");
    assertEqualF32(
        const178_f(&instance),
        8.881784197001252e-16,
        "f()"
    );
}
