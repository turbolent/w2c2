
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.179.h"

void test() {
    const179Instance instance;
    const179Instantiate(&instance, resolveTestImports);
    printStart("const.179.wasm");
    assertEqualF32(
        const179_f(&instance),
        -8.881784197001252e-16,
        "f()"
    );
}
