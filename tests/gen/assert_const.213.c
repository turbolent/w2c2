
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.213.h"

void test() {
    const213Instance instance;
    const213Instantiate(&instance, resolveTestImports);
    printStart("const.213.wasm");
    assertEqualF32(
        const213_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
