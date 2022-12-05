
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.316.h"

void test() {
    const316Instance instance;
    const316Instantiate(&instance, resolveTestImports);
    printStart("const.316.wasm");
    assertEqualF32(
        const316_f(&instance),
        3.4028234663852886e+38,
        "f()"
    );
}
