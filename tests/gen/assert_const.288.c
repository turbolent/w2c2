
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.288.h"

void test() {
    const288Instance instance;
    const288Instantiate(&instance, resolveTestImports);
    printStart("const.288.wasm");
    assertEqualF32(
        const288_f(&instance),
        0.0,
        "f()"
    );
}
