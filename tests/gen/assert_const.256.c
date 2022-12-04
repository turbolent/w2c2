
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.256.h"

void test() {
    const256Instance instance;
    const256Instantiate(&instance, resolveTestImports);
    printStart("const.256.wasm");
    assertEqualF32(
        const256_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
