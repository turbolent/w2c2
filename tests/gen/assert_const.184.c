
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.184.h"

void test() {
    const184Instance instance;
    const184Instantiate(&instance, resolveTestImports);
    printStart("const.184.wasm");
    assertEqualF32(
        const184_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
