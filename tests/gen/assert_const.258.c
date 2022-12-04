
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.258.h"

void test() {
    const258Instance instance;
    const258Instantiate(&instance, resolveTestImports);
    printStart("const.258.wasm");
    assertEqualF32(
        const258_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
