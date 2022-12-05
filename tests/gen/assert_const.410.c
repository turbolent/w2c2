
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.410.h"

void test() {
    const410Instance instance;
    const410Instantiate(&instance, resolveTestImports);
    printStart("const.410.wasm");
    assertEqualF64(
        const410_f(&instance),
        1.5845632502852868e+29,
        "f()"
    );
}
