
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.337.h"

void test() {
    const337Instance instance;
    const337Instantiate(&instance, resolveTestImports);
    printStart("const.337.wasm");
    assertEqualF64(
        const337_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
