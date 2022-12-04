
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.291.h"

void test() {
    const291Instance instance;
    const291Instantiate(&instance, resolveTestImports);
    printStart("const.291.wasm");
    assertEqualF32(
        const291_f(&instance),
        -1.401298464324817e-45,
        "f()"
    );
}
