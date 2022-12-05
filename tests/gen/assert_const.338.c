
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.338.h"

void test() {
    const338Instance instance;
    const338Instantiate(&instance, resolveTestImports);
    printStart("const.338.wasm");
    assertEqualF64(
        const338_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
