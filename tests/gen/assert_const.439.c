
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.439.h"

void test() {
    const439Instance instance;
    const439Instantiate(&instance, resolveTestImports);
    printStart("const.439.wasm");
    assertEqualF64(
        const439_f(&instance),
        -1.152921504606847e+18,
        "f()"
    );
}
