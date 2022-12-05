
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.295.h"

void test() {
    const295Instance instance;
    const295Instantiate(&instance, resolveTestImports);
    printStart("const.295.wasm");
    assertEqualF32(
        const295_f(&instance),
        -1.401298464324817e-45,
        "f()"
    );
}
