
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.383.h"

void test() {
    const383Instance instance;
    const383Instantiate(&instance, resolveTestImports);
    printStart("const.383.wasm");
    assertEqualF64(
        const383_f(&instance),
        -4.149515568880993e+180,
        "f()"
    );
}
