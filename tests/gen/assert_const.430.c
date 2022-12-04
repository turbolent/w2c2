
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.430.h"

void test() {
    const430Instance instance;
    const430Instantiate(&instance, resolveTestImports);
    printStart("const.430.wasm");
    assertEqualF64(
        const430_f(&instance),
        1.5845632502852875e+29,
        "f()"
    );
}
