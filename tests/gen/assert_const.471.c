
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.471.h"

void test() {
    const471Instance instance;
    const471Instantiate(&instance, resolveTestImports);
    printStart("const.471.wasm");
    assertEqualF64(
        const471_f(&instance),
        -1e-323,
        "f()"
    );
}
