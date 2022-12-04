
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.425.h"

void test() {
    const425Instance instance;
    const425Instantiate(&instance, resolveTestImports);
    printStart("const.425.wasm");
    assertEqualF64(
        const425_f(&instance),
        -1.5845632502852875e+29,
        "f()"
    );
}
