
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.371.h"

void test() {
    m9_constX2E371Instance instance;
    m9_constX2E371Instantiate(&instance, resolveTestImports);
    printStart("const.371.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E371Export1_f(&instance)),
        11128394679232495618ull,
        "f()"
    );
}
