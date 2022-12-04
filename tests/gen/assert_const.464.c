
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.464.h"

void test() {
    const464Instance instance;
    const464Instantiate(&instance, resolveTestImports);
    printStart("const.464.wasm");
    assertEqualF64(
        const464_f(&instance),
        1e-323,
        "f()"
    );
}
