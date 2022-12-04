
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.206.h"

void test() {
    const206Instance instance;
    const206Instantiate(&instance, resolveTestImports);
    printStart("const.206.wasm");
    assertEqualF32(
        const206_f(&instance),
        8.881784197001252e-16,
        "f()"
    );
}
