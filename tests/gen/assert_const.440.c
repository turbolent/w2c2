
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.440.h"

void test() {
    const440Instance instance;
    const440Instantiate(&instance, resolveTestImports);
    printStart("const.440.wasm");
    assertEqualF64(
        const440_f(&instance),
        1.1529215046068472e+18,
        "f()"
    );
}
