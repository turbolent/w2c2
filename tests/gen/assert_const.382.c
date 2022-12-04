
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.382.h"

void test() {
    const382Instance instance;
    const382Instantiate(&instance, resolveTestImports);
    printStart("const.382.wasm");
    assertEqualF64(
        const382_f(&instance),
        4.149515568880993e+180,
        "f()"
    );
}
