
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.319.h"

void test() {
    const319Instance instance;
    const319Instantiate(&instance, resolveTestImports);
    printStart("const.319.wasm");
    assertEqualF32(
        const319_f(&instance),
        -3.4028234663852886e+38,
        "f()"
    );
}
