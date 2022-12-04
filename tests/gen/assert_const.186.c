
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.186.h"

void test() {
    const186Instance instance;
    const186Instantiate(&instance, resolveTestImports);
    printStart("const.186.wasm");
    assertEqualF32(
        const186_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
