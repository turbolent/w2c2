
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.267.h"

void test() {
    m9_constX2E267Instance instance;
    m9_constX2E267Instantiate(&instance, resolveTestImports);
    printStart("const.267.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E267Export1_f(&instance)),
        3632267264u,
        "f()"
    );
}
