
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.262.h"

void test() {
    const262Instance instance;
    const262Instantiate(&instance, resolveTestImports);
    printStart("const.262.wasm");
    assertEqualF32(
        const262_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
