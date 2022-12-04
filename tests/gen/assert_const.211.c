
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.211.h"

void test() {
    const211Instance instance;
    const211Instantiate(&instance, resolveTestImports);
    printStart("const.211.wasm");
    assertEqualF32(
        const211_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
