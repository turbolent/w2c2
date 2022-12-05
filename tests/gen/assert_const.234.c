
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.234.h"

void test() {
    const234Instance instance;
    const234Instantiate(&instance, resolveTestImports);
    printStart("const.234.wasm");
    assertEqualF32(
        const234_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
