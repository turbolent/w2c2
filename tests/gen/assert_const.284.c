
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.284.h"

void test() {
    const284Instance instance;
    const284Instantiate(&instance, resolveTestImports);
    printStart("const.284.wasm");
    assertEqualF32(
        const284_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
