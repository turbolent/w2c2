
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.244.h"

void test() {
    const244Instance instance;
    const244Instantiate(&instance, resolveTestImports);
    printStart("const.244.wasm");
    assertEqualF32(
        const244_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
