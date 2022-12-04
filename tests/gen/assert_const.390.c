
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.390.h"

void test() {
    const390Instance instance;
    const390Instantiate(&instance, resolveTestImports);
    printStart("const.390.wasm");
    assertEqualF64(
        const390_f(&instance),
        4.149515568880994e+180,
        "f()"
    );
}
