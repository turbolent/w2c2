
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.365.h"

void test() {
    const365Instance instance;
    const365Instantiate(&instance, resolveTestImports);
    printStart("const.365.wasm");
    assertEqualF64(
        const365_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
