
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.462.h"

void test() {
    const462Instance instance;
    const462Instantiate(&instance, resolveTestImports);
    printStart("const.462.wasm");
    assertEqualF64(
        const462_f(&instance),
        1e-323,
        "f()"
    );
}
