
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.391.h"

void test() {
    const391Instance instance;
    const391Instantiate(&instance, resolveTestImports);
    printStart("const.391.wasm");
    assertEqualF64(
        const391_f(&instance),
        -4.149515568880994e+180,
        "f()"
    );
}
