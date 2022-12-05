
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.252.h"

void test() {
    const252Instance instance;
    const252Instantiate(&instance, resolveTestImports);
    printStart("const.252.wasm");
    assertEqualF32(
        const252_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
