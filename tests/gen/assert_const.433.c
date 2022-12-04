
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.433.h"

void test() {
    const433Instance instance;
    const433Instantiate(&instance, resolveTestImports);
    printStart("const.433.wasm");
    assertEqualF64(
        const433_f(&instance),
        -1.5845632502852875e+29,
        "f()"
    );
}
