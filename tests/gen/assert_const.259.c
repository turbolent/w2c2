
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.259.h"

void test() {
    const259Instance instance;
    const259Instantiate(&instance, resolveTestImports);
    printStart("const.259.wasm");
    assertEqualF32(
        const259_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
