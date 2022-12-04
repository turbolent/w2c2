
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.229.h"

void test() {
    const229Instance instance;
    const229Instantiate(&instance, resolveTestImports);
    printStart("const.229.wasm");
    assertEqualF32(
        const229_f(&instance),
        -8.881787373374805e-16,
        "f()"
    );
}
