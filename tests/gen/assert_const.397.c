
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.397.h"

void test() {
    const397Instance instance;
    const397Instantiate(&instance, resolveTestImports);
    printStart("const.397.wasm");
    assertEqualF64(
        const397_f(&instance),
        -4.149515568880995e+180,
        "f()"
    );
}
