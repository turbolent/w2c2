
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.289.h"

void test() {
    const289Instance instance;
    const289Instantiate(&instance, resolveTestImports);
    printStart("const.289.wasm");
    assertEqualF32(
        const289_f(&instance),
        -0.0,
        "f()"
    );
}
