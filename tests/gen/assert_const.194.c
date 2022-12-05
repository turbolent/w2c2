
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.194.h"

void test() {
    const194Instance instance;
    const194Instantiate(&instance, resolveTestImports);
    printStart("const.194.wasm");
    assertEqualF32(
        const194_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
