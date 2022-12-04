
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.461.h"

void test() {
    const461Instance instance;
    const461Instantiate(&instance, resolveTestImports);
    printStart("const.461.wasm");
    assertEqualF64(
        const461_f(&instance),
        -1e-323,
        "f()"
    );
}
