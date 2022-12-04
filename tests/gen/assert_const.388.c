
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.388.h"

void test() {
    const388Instance instance;
    const388Instantiate(&instance, resolveTestImports);
    printStart("const.388.wasm");
    assertEqualF64(
        const388_f(&instance),
        4.149515568880994e+180,
        "f()"
    );
}
