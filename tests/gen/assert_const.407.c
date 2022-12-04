
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.407.h"

void test() {
    const407Instance instance;
    const407Instantiate(&instance, resolveTestImports);
    printStart("const.407.wasm");
    assertEqualF64(
        const407_f(&instance),
        -4.149515568880995e+180,
        "f()"
    );
}
