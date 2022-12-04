
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.386.h"

void test() {
    const386Instance instance;
    const386Instantiate(&instance, resolveTestImports);
    printStart("const.386.wasm");
    assertEqualF64(
        const386_f(&instance),
        4.149515568880994e+180,
        "f()"
    );
}
