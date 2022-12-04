
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.261.h"

void test() {
    const261Instance instance;
    const261Instantiate(&instance, resolveTestImports);
    printStart("const.261.wasm");
    assertEqualF32(
        const261_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
