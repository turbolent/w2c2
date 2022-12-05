
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.272.h"

void test() {
    const272Instance instance;
    const272Instantiate(&instance, resolveTestImports);
    printStart("const.272.wasm");
    assertEqualF32(
        const272_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
