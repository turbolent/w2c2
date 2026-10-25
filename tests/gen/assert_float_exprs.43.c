
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.43.h"

void test() {
    m14_floatX5FexprsX2E43Instance instance;
    m14_floatX5FexprsX2E43Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.43.wasm");
    m14_floatX5FexprsX2E43Export4_init(&instance, 0u, 15.1);
    printOK("init(0u, 15.1)");
    m14_floatX5FexprsX2E43Export4_init(&instance, 8u, 15.2);
    printOK("init(8u, 15.2)");
    m14_floatX5FexprsX2E43Export4_init(&instance, 16u, 15.3);
    printOK("init(16u, 15.3)");
    m14_floatX5FexprsX2E43Export4_init(&instance, 24u, 15.4);
    printOK("init(24u, 15.4)");
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E43Export5_check(&instance, 0u)),
        4624690162351420211ull,
        "check(0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E43Export5_check(&instance, 8u)),
        4624746457346762342ull,
        "check(8u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E43Export5_check(&instance, 16u)),
        4624802752342104474ull,
        "check(16u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E43Export5_check(&instance, 24u)),
        4624859047337446605ull,
        "check(24u)"
    );
    m14_floatX5FexprsX2E43Export3_run(&instance, 32u, 3.0);
    printOK("run(32u, 3.0)");
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E43Export5_check(&instance, 0u)),
        4617353047958495778ull,
        "check(0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E43Export5_check(&instance, 8u)),
        4617390577955390532ull,
        "check(8u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E43Export5_check(&instance, 16u)),
        4617428107952285287ull,
        "check(16u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E43Export5_check(&instance, 24u)),
        4617465637949180041ull,
        "check(24u)"
    );
}
