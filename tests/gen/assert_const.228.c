
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.228.h"

void test() {
    const228Instance instance;
    const228Instantiate(&instance, resolveTestImports);
    printStart("const.228.wasm");
    assertEqualF32(
        const228_f(&instance),
        8.881787373374805e-16,
        "f()"
    );
}
