
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.264.h"

void test() {
    const264Instance instance;
    const264Instantiate(&instance, resolveTestImports);
    printStart("const.264.wasm");
    assertEqualF32(
        const264_f(&instance),
        1125900309495808.0,
        "f()"
    );
}
