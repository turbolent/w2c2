
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.395.h"

void test() {
    const395Instance instance;
    const395Instantiate(&instance, resolveTestImports);
    printStart("const.395.wasm");
    assertEqualF64(
        const395_f(&instance),
        -4.149515568880995e+180,
        "f()"
    );
}
