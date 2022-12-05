
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.435.h"

void test() {
    const435Instance instance;
    const435Instantiate(&instance, resolveTestImports);
    printStart("const.435.wasm");
    assertEqualF64(
        const435_f(&instance),
        -1.5845632502852875e+29,
        "f()"
    );
}
