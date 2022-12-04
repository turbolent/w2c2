
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.409.h"

void test() {
    const409Instance instance;
    const409Instantiate(&instance, resolveTestImports);
    printStart("const.409.wasm");
    assertEqualF64(
        const409_f(&instance),
        -4.149515568880996e+180,
        "f()"
    );
}
