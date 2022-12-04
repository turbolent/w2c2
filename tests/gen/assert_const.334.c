
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.334.h"

void test() {
    const334Instance instance;
    const334Instantiate(&instance, resolveTestImports);
    printStart("const.334.wasm");
    assertEqualF64(
        const334_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
