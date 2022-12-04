
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.318.h"

void test() {
    const318Instance instance;
    const318Instantiate(&instance, resolveTestImports);
    printStart("const.318.wasm");
    assertEqualF32(
        const318_f(&instance),
        3.4028234663852886e+38,
        "f()"
    );
}
