
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.396.h"

void test() {
    const396Instance instance;
    const396Instantiate(&instance, resolveTestImports);
    printStart("const.396.wasm");
    assertEqualF64(
        const396_f(&instance),
        4.149515568880995e+180,
        "f()"
    );
}
