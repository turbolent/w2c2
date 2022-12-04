
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.292.h"

void test() {
    const292Instance instance;
    const292Instantiate(&instance, resolveTestImports);
    printStart("const.292.wasm");
    assertEqualF32(
        const292_f(&instance),
        1.401298464324817e-45,
        "f()"
    );
}
