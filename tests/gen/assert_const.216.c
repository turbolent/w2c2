
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.216.h"

void test() {
    const216Instance instance;
    const216Instantiate(&instance, resolveTestImports);
    printStart("const.216.wasm");
    assertEqualF32(
        const216_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
