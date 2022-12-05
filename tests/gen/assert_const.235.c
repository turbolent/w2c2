
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.235.h"

void test() {
    const235Instance instance;
    const235Instantiate(&instance, resolveTestImports);
    printStart("const.235.wasm");
    assertEqualF32(
        const235_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
