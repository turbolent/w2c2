
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.408.h"

void test() {
    const408Instance instance;
    const408Instantiate(&instance, resolveTestImports);
    printStart("const.408.wasm");
    assertEqualF64(
        const408_f(&instance),
        4.149515568880996e+180,
        "f()"
    );
}
