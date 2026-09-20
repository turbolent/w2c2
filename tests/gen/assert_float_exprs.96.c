
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.96.h"

void test() {
    m14_floatX5FexprsX2E96Instance instance;
    m14_floatX5FexprsX2E96Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.96.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E96Export3_tau(&instance, 10u)),
        4618760256179416340ull,
        "tau(10u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E96Export3_tau(&instance, 11u)),
        4618760256179416344ull,
        "tau(11u)"
    );
}
