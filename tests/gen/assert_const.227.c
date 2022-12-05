
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.227.h"

void test() {
    const227Instance instance;
    const227Instantiate(&instance, resolveTestImports);
    printStart("const.227.wasm");
    assertEqualF32(
        const227_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
