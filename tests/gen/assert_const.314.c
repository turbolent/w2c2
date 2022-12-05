
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.314.h"

void test() {
    const314Instance instance;
    const314Instantiate(&instance, resolveTestImports);
    printStart("const.314.wasm");
    assertEqualF32(
        const314_f(&instance),
        4.203895392974451e-45,
        "f()"
    );
}
