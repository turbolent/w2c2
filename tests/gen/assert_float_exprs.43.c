
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
    assertEqualF64(
        m14_floatX5FexprsX2E43Export5_check(&instance, 0u),
        15.1,
        "check(0u)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E43Export5_check(&instance, 8u),
        15.2,
        "check(8u)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E43Export5_check(&instance, 16u),
        15.3,
        "check(16u)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E43Export5_check(&instance, 24u),
        15.4,
        "check(24u)"
    );
    m14_floatX5FexprsX2E43Export3_run(&instance, 32u, 3.0);
    printOK("run(32u, 3.0)");
    assertEqualF64(
        m14_floatX5FexprsX2E43Export5_check(&instance, 0u),
        5.033333333333333,
        "check(0u)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E43Export5_check(&instance, 8u),
        5.066666666666666,
        "check(8u)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E43Export5_check(&instance, 16u),
        5.1000000000000005,
        "check(16u)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E43Export5_check(&instance, 24u),
        5.133333333333334,
        "check(24u)"
    );
}
