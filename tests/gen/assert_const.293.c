
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.293.h"

void test() {
    const293Instance instance;
    const293Instantiate(&instance, resolveTestImports);
    printStart("const.293.wasm");
    assertEqualF32(
        const293_f(&instance),
        -1.401298464324817e-45,
        "f()"
    );
}
