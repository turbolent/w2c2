
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.449.h"

void test() {
    const449Instance instance;
    const449Instantiate(&instance, resolveTestImports);
    printStart("const.449.wasm");
    assertEqualF64(
        const449_f(&instance),
        -5e-324,
        "f()"
    );
}
