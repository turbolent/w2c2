
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.240.h"

void test() {
    const240Instance instance;
    const240Instantiate(&instance, resolveTestImports);
    printStart("const.240.wasm");
    assertEqualF32(
        const240_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
