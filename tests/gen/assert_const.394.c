
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.394.h"

void test() {
    const394Instance instance;
    const394Instantiate(&instance, resolveTestImports);
    printStart("const.394.wasm");
    assertEqualF64(
        const394_f(&instance),
        4.149515568880995e+180,
        "f()"
    );
}
