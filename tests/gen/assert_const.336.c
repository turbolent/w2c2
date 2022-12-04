
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.336.h"

void test() {
    const336Instance instance;
    const336Instantiate(&instance, resolveTestImports);
    printStart("const.336.wasm");
    assertEqualF64(
        const336_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
