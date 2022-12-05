
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.320.h"

void test() {
    const320Instance instance;
    const320Instantiate(&instance, resolveTestImports);
    printStart("const.320.wasm");
    assertEqualF32(
        const320_f(&instance),
        3.4028234663852886e+38,
        "f()"
    );
}
