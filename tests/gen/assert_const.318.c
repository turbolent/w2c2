
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.318.h"

void test() {
    m9_constX2E318Instance instance;
    m9_constX2E318Instantiate(&instance, resolveTestImports);
    printStart("const.318.wasm");
    assertEqualF32(
        m9_constX2E318Export1_f(&instance),
        3.4028234663852886e+38,
        "f()"
    );
}
