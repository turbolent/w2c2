
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.200.h"

void test() {
    const200Instance instance;
    const200Instantiate(&instance, resolveTestImports);
    printStart("const.200.wasm");
    assertEqualF32(
        const200_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
