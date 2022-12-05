
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.459.h"

void test() {
    const459Instance instance;
    const459Instantiate(&instance, resolveTestImports);
    printStart("const.459.wasm");
    assertEqualF64(
        const459_f(&instance),
        -1e-323,
        "f()"
    );
}
