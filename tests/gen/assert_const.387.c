
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.387.h"

void test() {
    const387Instance instance;
    const387Instantiate(&instance, resolveTestImports);
    printStart("const.387.wasm");
    assertEqualF64(
        const387_f(&instance),
        -4.149515568880994e+180,
        "f()"
    );
}
