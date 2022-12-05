
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.321.h"

void test() {
    const321Instance instance;
    const321Instantiate(&instance, resolveTestImports);
    printStart("const.321.wasm");
    assertEqualF32(
        const321_f(&instance),
        -3.4028234663852886e+38,
        "f()"
    );
}
