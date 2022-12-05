
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.457.h"

void test() {
    const457Instance instance;
    const457Instantiate(&instance, resolveTestImports);
    printStart("const.457.wasm");
    assertEqualF64(
        const457_f(&instance),
        -5e-324,
        "f()"
    );
}
