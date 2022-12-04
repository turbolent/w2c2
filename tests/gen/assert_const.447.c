
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.447.h"

void test() {
    const447Instance instance;
    const447Instantiate(&instance, resolveTestImports);
    printStart("const.447.wasm");
    assertEqualF64(
        const447_f(&instance),
        -0.0,
        "f()"
    );
}
