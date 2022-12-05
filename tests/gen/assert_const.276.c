
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.276.h"

void test() {
    const276Instance instance;
    const276Instantiate(&instance, resolveTestImports);
    printStart("const.276.wasm");
    assertEqualF32(
        const276_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
