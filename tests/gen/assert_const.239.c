
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.239.h"

void test() {
    m9_constX2E239Instance instance;
    m9_constX2E239Instantiate(&instance, resolveTestImports);
    printStart("const.239.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E239Export1_f(&instance)),
        3632267264u,
        "f()"
    );
}
