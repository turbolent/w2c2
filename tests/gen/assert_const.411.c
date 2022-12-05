
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.411.h"

void test() {
    const411Instance instance;
    const411Instantiate(&instance, resolveTestImports);
    printStart("const.411.wasm");
    assertEqualF64(
        const411_f(&instance),
        -1.5845632502852868e+29,
        "f()"
    );
}
