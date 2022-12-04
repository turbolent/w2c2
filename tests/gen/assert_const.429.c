
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.429.h"

void test() {
    const429Instance instance;
    const429Instantiate(&instance, resolveTestImports);
    printStart("const.429.wasm");
    assertEqualF64(
        const429_f(&instance),
        -1.5845632502852875e+29,
        "f()"
    );
}
