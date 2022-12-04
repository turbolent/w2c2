
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.401.h"

void test() {
    const401Instance instance;
    const401Instantiate(&instance, resolveTestImports);
    printStart("const.401.wasm");
    assertEqualF64(
        const401_f(&instance),
        -4.149515568880995e+180,
        "f()"
    );
}
