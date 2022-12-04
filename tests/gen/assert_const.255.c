
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.255.h"

void test() {
    const255Instance instance;
    const255Instantiate(&instance, resolveTestImports);
    printStart("const.255.wasm");
    assertEqualF32(
        const255_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
