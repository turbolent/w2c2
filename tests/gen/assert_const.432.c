
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.432.h"

void test() {
    const432Instance instance;
    const432Instantiate(&instance, resolveTestImports);
    printStart("const.432.wasm");
    assertEqualF64(
        const432_f(&instance),
        1.5845632502852875e+29,
        "f()"
    );
}
