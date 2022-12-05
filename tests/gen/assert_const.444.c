
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.444.h"

void test() {
    const444Instance instance;
    const444Instantiate(&instance, resolveTestImports);
    printStart("const.444.wasm");
    assertEqualF64(
        const444_f(&instance),
        1.1529215046068475e+18,
        "f()"
    );
}
