
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.315.h"

void test() {
    const315Instance instance;
    const315Instantiate(&instance, resolveTestImports);
    printStart("const.315.wasm");
    assertEqualF32(
        const315_f(&instance),
        -4.203895392974451e-45,
        "f()"
    );
}
