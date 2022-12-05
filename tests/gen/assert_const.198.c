
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.198.h"

void test() {
    const198Instance instance;
    const198Instantiate(&instance, resolveTestImports);
    printStart("const.198.wasm");
    assertEqualF32(
        const198_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
