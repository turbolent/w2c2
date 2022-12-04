
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.405.h"

void test() {
    const405Instance instance;
    const405Instantiate(&instance, resolveTestImports);
    printStart("const.405.wasm");
    assertEqualF64(
        const405_f(&instance),
        -4.149515568880995e+180,
        "f()"
    );
}
