
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.322.h"

void test() {
    const322Instance instance;
    const322Instantiate(&instance, resolveTestImports);
    printStart("const.322.wasm");
    assertEqualF64(
        const322_f(&instance),
        2.409919865102884e-181,
        "f()"
    );
}
