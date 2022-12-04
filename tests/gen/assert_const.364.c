
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.364.h"

void test() {
    const364Instance instance;
    const364Instantiate(&instance, resolveTestImports);
    printStart("const.364.wasm");
    assertEqualF64(
        const364_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
