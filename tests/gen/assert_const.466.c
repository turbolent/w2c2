
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.466.h"

void test() {
    const466Instance instance;
    const466Instantiate(&instance, resolveTestImports);
    printStart("const.466.wasm");
    assertEqualF64(
        const466_f(&instance),
        1e-323,
        "f()"
    );
}
