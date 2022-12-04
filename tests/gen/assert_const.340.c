
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.340.h"

void test() {
    const340Instance instance;
    const340Instantiate(&instance, resolveTestImports);
    printStart("const.340.wasm");
    assertEqualF64(
        const340_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
