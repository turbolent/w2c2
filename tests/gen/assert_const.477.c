
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.477.h"

void test() {
    m9_constX2E477Instance instance;
    m9_constX2E477Instantiate(&instance, resolveTestImports);
    printStart("const.477.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E477Export1_f(&instance)),
        18442240474082181119ull,
        "f()"
    );
}
