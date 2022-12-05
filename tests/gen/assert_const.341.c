
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.341.h"

void test() {
    const341Instance instance;
    const341Instantiate(&instance, resolveTestImports);
    printStart("const.341.wasm");
    assertEqualF64(
        const341_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
