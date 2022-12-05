
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.214.h"

void test() {
    const214Instance instance;
    const214Instantiate(&instance, resolveTestImports);
    printStart("const.214.wasm");
    assertEqualF32(
        const214_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
