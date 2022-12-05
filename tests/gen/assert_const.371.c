
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.371.h"

void test() {
    const371Instance instance;
    const371Instantiate(&instance, resolveTestImports);
    printStart("const.371.wasm");
    assertEqualF64(
        const371_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
