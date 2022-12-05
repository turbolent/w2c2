
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.468.h"

void test() {
    const468Instance instance;
    const468Instantiate(&instance, resolveTestImports);
    printStart("const.468.wasm");
    assertEqualF64(
        const468_f(&instance),
        1e-323,
        "f()"
    );
}
