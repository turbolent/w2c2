
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.442.h"

void test() {
    const442Instance instance;
    const442Instantiate(&instance, resolveTestImports);
    printStart("const.442.wasm");
    assertEqualF64(
        const442_f(&instance),
        1.1529215046068472e+18,
        "f()"
    );
}
