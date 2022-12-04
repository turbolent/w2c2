
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.393.h"

void test() {
    const393Instance instance;
    const393Instantiate(&instance, resolveTestImports);
    printStart("const.393.wasm");
    assertEqualF64(
        const393_f(&instance),
        -4.149515568880994e+180,
        "f()"
    );
}
