
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.265.h"

void test() {
    const265Instance instance;
    const265Instantiate(&instance, resolveTestImports);
    printStart("const.265.wasm");
    assertEqualF32(
        const265_f(&instance),
        -1125900309495808.0,
        "f()"
    );
}
