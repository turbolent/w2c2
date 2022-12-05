
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.193.h"

void test() {
    const193Instance instance;
    const193Instantiate(&instance, resolveTestImports);
    printStart("const.193.wasm");
    assertEqualF32(
        const193_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
