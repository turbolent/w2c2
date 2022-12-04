
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.472.h"

void test() {
    const472Instance instance;
    const472Instantiate(&instance, resolveTestImports);
    printStart("const.472.wasm");
    assertEqualF64(
        const472_f(&instance),
        2.225073858507203e-308,
        "f()"
    );
}
