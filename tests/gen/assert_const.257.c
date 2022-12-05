
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.257.h"

void test() {
    const257Instance instance;
    const257Instantiate(&instance, resolveTestImports);
    printStart("const.257.wasm");
    assertEqualF32(
        const257_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
