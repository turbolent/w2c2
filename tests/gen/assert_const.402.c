
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.402.h"

void test() {
    const402Instance instance;
    const402Instantiate(&instance, resolveTestImports);
    printStart("const.402.wasm");
    assertEqualF64(
        const402_f(&instance),
        4.149515568880995e+180,
        "f()"
    );
}
