
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.223.h"

void test() {
    const223Instance instance;
    const223Instantiate(&instance, resolveTestImports);
    printStart("const.223.wasm");
    assertEqualF32(
        const223_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
