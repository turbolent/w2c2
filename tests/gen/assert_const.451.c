
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.451.h"

void test() {
    const451Instance instance;
    const451Instantiate(&instance, resolveTestImports);
    printStart("const.451.wasm");
    assertEqualF64(
        const451_f(&instance),
        -5e-324,
        "f()"
    );
}
