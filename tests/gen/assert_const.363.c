
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.363.h"

void test() {
    const363Instance instance;
    const363Instantiate(&instance, resolveTestImports);
    printStart("const.363.wasm");
    assertEqualF64(
        const363_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
