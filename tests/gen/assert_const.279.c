
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.279.h"

void test() {
    const279Instance instance;
    const279Instantiate(&instance, resolveTestImports);
    printStart("const.279.wasm");
    assertEqualF32(
        const279_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
