
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.317.h"

void test() {
    const317Instance instance;
    const317Instantiate(&instance, resolveTestImports);
    printStart("const.317.wasm");
    assertEqualF32(
        const317_f(&instance),
        -3.4028234663852886e+38,
        "f()"
    );
}
