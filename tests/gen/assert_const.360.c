
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.360.h"

void test() {
    const360Instance instance;
    const360Instantiate(&instance, resolveTestImports);
    printStart("const.360.wasm");
    assertEqualF64(
        const360_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
