
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.348.h"

void test() {
    const348Instance instance;
    const348Instantiate(&instance, resolveTestImports);
    printStart("const.348.wasm");
    assertEqualF64(
        const348_f(&instance),
        2.409919865102884e-181,
        "f()"
    );
}
