
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.228.h"

void test() {
    m9_constX2E228Instance instance;
    m9_constX2E228Instantiate(&instance, resolveTestImports);
    printStart("const.228.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E228Export1_f(&instance)),
        645922819u,
        "f()"
    );
}
