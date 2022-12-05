
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.458.h"

void test() {
    const458Instance instance;
    const458Instantiate(&instance, resolveTestImports);
    printStart("const.458.wasm");
    assertEqualF64(
        const458_f(&instance),
        1e-323,
        "f()"
    );
}
