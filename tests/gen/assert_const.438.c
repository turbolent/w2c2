
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.438.h"

void test() {
    const438Instance instance;
    const438Instantiate(&instance, resolveTestImports);
    printStart("const.438.wasm");
    assertEqualF64(
        const438_f(&instance),
        1.152921504606847e+18,
        "f()"
    );
}
