
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.443.h"

void test() {
    const443Instance instance;
    const443Instantiate(&instance, resolveTestImports);
    printStart("const.443.wasm");
    assertEqualF64(
        const443_f(&instance),
        -1.1529215046068472e+18,
        "f()"
    );
}
