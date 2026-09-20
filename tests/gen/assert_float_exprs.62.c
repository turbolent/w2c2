
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.62.h"

void test() {
    m14_floatX5FexprsX2E62Instance instance;
    m14_floatX5FexprsX2E62Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.62.wasm");
    m14_floatX5FexprsX2E62Export17_f64X2EsimpleX5Fx4X5Fsum(&instance, 0u, 32u, 64u);
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E62Export8_f64X2Eload(&instance, 64u)),
        2ull,
        "f64.load(64u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E62Export8_f64X2Eload(&instance, 72u)),
        0ull,
        "f64.load(72u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E62Export8_f64X2Eload(&instance, 80u)),
        1ull,
        "f64.load(80u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E62Export8_f64X2Eload(&instance, 88u)),
        9223372036854775809ull,
        "f64.load(88u)"
    );
}
