
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.189.h"

void test() {
    const189Instance instance;
    const189Instantiate(&instance, resolveTestImports);
    printStart("const.189.wasm");
    assertEqualF32(
        const189_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
