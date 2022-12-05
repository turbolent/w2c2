
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.367.h"

void test() {
    const367Instance instance;
    const367Instantiate(&instance, resolveTestImports);
    printStart("const.367.wasm");
    assertEqualF64(
        const367_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
