
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.232.h"

void test() {
    const232Instance instance;
    const232Instantiate(&instance, resolveTestImports);
    printStart("const.232.wasm");
    assertEqualF32(
        const232_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
