
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.441.h"

void test() {
    const441Instance instance;
    const441Instantiate(&instance, resolveTestImports);
    printStart("const.441.wasm");
    assertEqualF64(
        const441_f(&instance),
        -1.1529215046068472e+18,
        "f()"
    );
}
