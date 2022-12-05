
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.249.h"

void test() {
    const249Instance instance;
    const249Instantiate(&instance, resolveTestImports);
    printStart("const.249.wasm");
    assertEqualF32(
        const249_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
