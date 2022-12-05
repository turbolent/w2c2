
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.221.h"

void test() {
    const221Instance instance;
    const221Instantiate(&instance, resolveTestImports);
    printStart("const.221.wasm");
    assertEqualF32(
        const221_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
