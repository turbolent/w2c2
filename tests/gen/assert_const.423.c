
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.423.h"

void test() {
    const423Instance instance;
    const423Instantiate(&instance, resolveTestImports);
    printStart("const.423.wasm");
    assertEqualF64(
        const423_f(&instance),
        -1.5845632502852875e+29,
        "f()"
    );
}
