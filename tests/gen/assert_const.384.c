
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.384.h"

void test() {
    const384Instance instance;
    const384Instantiate(&instance, resolveTestImports);
    printStart("const.384.wasm");
    assertEqualF64(
        const384_f(&instance),
        4.149515568880994e+180,
        "f()"
    );
}
