
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.236.h"

void test() {
    const236Instance instance;
    const236Instantiate(&instance, resolveTestImports);
    printStart("const.236.wasm");
    assertEqualF32(
        const236_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
