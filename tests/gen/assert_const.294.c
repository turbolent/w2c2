
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.294.h"

void test() {
    const294Instance instance;
    const294Instantiate(&instance, resolveTestImports);
    printStart("const.294.wasm");
    assertEqualF32(
        const294_f(&instance),
        1.401298464324817e-45,
        "f()"
    );
}
