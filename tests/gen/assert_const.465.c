
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.465.h"

void test() {
    const465Instance instance;
    const465Instantiate(&instance, resolveTestImports);
    printStart("const.465.wasm");
    assertEqualF64(
        const465_f(&instance),
        -1e-323,
        "f()"
    );
}
