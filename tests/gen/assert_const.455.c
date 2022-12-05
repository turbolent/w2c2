
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.455.h"

void test() {
    const455Instance instance;
    const455Instantiate(&instance, resolveTestImports);
    printStart("const.455.wasm");
    assertEqualF64(
        const455_f(&instance),
        -5e-324,
        "f()"
    );
}
