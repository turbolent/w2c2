
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.253.h"

void test() {
    const253Instance instance;
    const253Instantiate(&instance, resolveTestImports);
    printStart("const.253.wasm");
    assertEqualF32(
        const253_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
