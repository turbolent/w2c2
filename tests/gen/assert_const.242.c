
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.242.h"

void test() {
    const242Instance instance;
    const242Instantiate(&instance, resolveTestImports);
    printStart("const.242.wasm");
    assertEqualF32(
        const242_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
