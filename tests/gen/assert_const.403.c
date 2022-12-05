
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.403.h"

void test() {
    const403Instance instance;
    const403Instantiate(&instance, resolveTestImports);
    printStart("const.403.wasm");
    assertEqualF64(
        const403_f(&instance),
        -4.149515568880995e+180,
        "f()"
    );
}
