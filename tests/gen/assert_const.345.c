
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.345.h"

void test() {
    const345Instance instance;
    const345Instantiate(&instance, resolveTestImports);
    printStart("const.345.wasm");
    assertEqualF64(
        const345_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
