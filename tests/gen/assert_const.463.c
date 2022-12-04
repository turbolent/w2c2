
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.463.h"

void test() {
    const463Instance instance;
    const463Instantiate(&instance, resolveTestImports);
    printStart("const.463.wasm");
    assertEqualF64(
        const463_f(&instance),
        -1e-323,
        "f()"
    );
}
