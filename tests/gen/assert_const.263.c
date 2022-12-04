
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.263.h"

void test() {
    const263Instance instance;
    const263Instantiate(&instance, resolveTestImports);
    printStart("const.263.wasm");
    assertEqualF32(
        const263_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
