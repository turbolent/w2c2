
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.389.h"

void test() {
    const389Instance instance;
    const389Instantiate(&instance, resolveTestImports);
    printStart("const.389.wasm");
    assertEqualF64(
        const389_f(&instance),
        -4.149515568880994e+180,
        "f()"
    );
}
