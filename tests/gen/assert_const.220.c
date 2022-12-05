
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.220.h"

void test() {
    const220Instance instance;
    const220Instantiate(&instance, resolveTestImports);
    printStart("const.220.wasm");
    assertEqualF32(
        const220_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
