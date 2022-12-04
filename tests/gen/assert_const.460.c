
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.460.h"

void test() {
    const460Instance instance;
    const460Instantiate(&instance, resolveTestImports);
    printStart("const.460.wasm");
    assertEqualF64(
        const460_f(&instance),
        1e-323,
        "f()"
    );
}
