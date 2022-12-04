
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.205.h"

void test() {
    const205Instance instance;
    const205Instantiate(&instance, resolveTestImports);
    printStart("const.205.wasm");
    assertEqualF32(
        const205_f(&instance),
        -8.881787373374805e-16,
        "f()"
    );
}
