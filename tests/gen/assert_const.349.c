
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.349.h"

void test() {
    const349Instance instance;
    const349Instantiate(&instance, resolveTestImports);
    printStart("const.349.wasm");
    assertEqualF64(
        const349_f(&instance),
        -2.409919865102884e-181,
        "f()"
    );
}
