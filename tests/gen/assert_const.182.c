
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.182.h"

void test() {
    const182Instance instance;
    const182Instantiate(&instance, resolveTestImports);
    printStart("const.182.wasm");
    assertEqualF32(
        const182_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
