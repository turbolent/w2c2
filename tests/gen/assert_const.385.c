
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.385.h"

void test() {
    const385Instance instance;
    const385Instantiate(&instance, resolveTestImports);
    printStart("const.385.wasm");
    assertEqualF64(
        const385_f(&instance),
        -4.149515568880994e+180,
        "f()"
    );
}
