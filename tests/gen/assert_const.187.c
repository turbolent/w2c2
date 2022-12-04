
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.187.h"

void test() {
    const187Instance instance;
    const187Instantiate(&instance, resolveTestImports);
    printStart("const.187.wasm");
    assertEqualF32(
        const187_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
