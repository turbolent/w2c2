
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.297.h"

void test() {
    const297Instance instance;
    const297Instantiate(&instance, resolveTestImports);
    printStart("const.297.wasm");
    assertEqualF32(
        const297_f(&instance),
        -1.401298464324817e-45,
        "f()"
    );
}
