
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.287.h"

void test() {
    m9_constX2E287Instance instance;
    m9_constX2E287Instantiate(&instance, resolveTestImports);
    printStart("const.287.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E287Export1_f(&instance)),
        3632267266u,
        "f()"
    );
}
