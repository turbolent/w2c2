
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.400.h"

void test() {
    const400Instance instance;
    const400Instantiate(&instance, resolveTestImports);
    printStart("const.400.wasm");
    assertEqualF64(
        const400_f(&instance),
        4.149515568880995e+180,
        "f()"
    );
}
