
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.201.h"

void test() {
    const201Instance instance;
    const201Instantiate(&instance, resolveTestImports);
    printStart("const.201.wasm");
    assertEqualF32(
        const201_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
