
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.274.h"

void test() {
    const274Instance instance;
    const274Instantiate(&instance, resolveTestImports);
    printStart("const.274.wasm");
    assertEqualF32(
        const274_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
