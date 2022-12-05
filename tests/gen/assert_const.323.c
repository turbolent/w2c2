
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.323.h"

void test() {
    const323Instance instance;
    const323Instantiate(&instance, resolveTestImports);
    printStart("const.323.wasm");
    assertEqualF64(
        const323_f(&instance),
        -2.409919865102884e-181,
        "f()"
    );
}
