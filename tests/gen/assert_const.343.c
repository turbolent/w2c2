
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.343.h"

void test() {
    const343Instance instance;
    const343Instantiate(&instance, resolveTestImports);
    printStart("const.343.wasm");
    assertEqualF64(
        const343_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
