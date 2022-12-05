
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.392.h"

void test() {
    const392Instance instance;
    const392Instantiate(&instance, resolveTestImports);
    printStart("const.392.wasm");
    assertEqualF64(
        const392_f(&instance),
        4.149515568880994e+180,
        "f()"
    );
}
