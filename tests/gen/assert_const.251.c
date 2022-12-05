
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.251.h"

void test() {
    const251Instance instance;
    const251Instantiate(&instance, resolveTestImports);
    printStart("const.251.wasm");
    assertEqualF32(
        const251_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
