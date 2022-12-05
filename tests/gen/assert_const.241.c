
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.241.h"

void test() {
    const241Instance instance;
    const241Instantiate(&instance, resolveTestImports);
    printStart("const.241.wasm");
    assertEqualF32(
        const241_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
