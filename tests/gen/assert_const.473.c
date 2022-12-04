
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.473.h"

void test() {
    const473Instance instance;
    const473Instantiate(&instance, resolveTestImports);
    printStart("const.473.wasm");
    assertEqualF64(
        const473_f(&instance),
        -2.225073858507203e-308,
        "f()"
    );
}
