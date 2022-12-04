
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.417.h"

void test() {
    const417Instance instance;
    const417Instantiate(&instance, resolveTestImports);
    printStart("const.417.wasm");
    assertEqualF64(
        const417_f(&instance),
        -1.584563250285287e+29,
        "f()"
    );
}
