
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.445.h"

void test() {
    const445Instance instance;
    const445Instantiate(&instance, resolveTestImports);
    printStart("const.445.wasm");
    assertEqualF64(
        const445_f(&instance),
        -1.1529215046068475e+18,
        "f()"
    );
}
