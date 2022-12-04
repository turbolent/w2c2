
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.312.h"

void test() {
    const312Instance instance;
    const312Instantiate(&instance, resolveTestImports);
    printStart("const.312.wasm");
    assertEqualF32(
        const312_f(&instance),
        2.802596928649634e-45,
        "f()"
    );
}
