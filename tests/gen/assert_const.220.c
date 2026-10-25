
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.220.h"

void test() {
    m9_constX2E220Instance instance;
    m9_constX2E220Instantiate(&instance, resolveTestImports);
    printStart("const.220.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E220Export1_f(&instance)),
        645922818u,
        "f()"
    );
}
