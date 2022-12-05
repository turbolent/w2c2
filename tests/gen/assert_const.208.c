
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.208.h"

void test() {
    const208Instance instance;
    const208Instantiate(&instance, resolveTestImports);
    printStart("const.208.wasm");
    assertEqualF32(
        const208_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
