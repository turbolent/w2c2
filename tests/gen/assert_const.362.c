
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.362.h"

void test() {
    const362Instance instance;
    const362Instantiate(&instance, resolveTestImports);
    printStart("const.362.wasm");
    assertEqualF64(
        const362_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
