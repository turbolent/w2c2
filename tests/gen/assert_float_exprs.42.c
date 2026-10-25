
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.42.h"

void test() {
    m14_floatX5FexprsX2E42Instance instance;
    m14_floatX5FexprsX2E42Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.42.wasm");
    m14_floatX5FexprsX2E42Export4_init(&instance, 0u, 15.100000381469727);
    printOK("init(0u, 15.100000381469727)");
    m14_floatX5FexprsX2E42Export4_init(&instance, 4u, 15.199999809265137);
    printOK("init(4u, 15.199999809265137)");
    m14_floatX5FexprsX2E42Export4_init(&instance, 8u, 15.300000190734863);
    printOK("init(8u, 15.300000190734863)");
    m14_floatX5FexprsX2E42Export4_init(&instance, 12u, 15.399999618530273);
    printOK("init(12u, 15.399999618530273)");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E42Export5_check(&instance, 0u)),
        1097963930u,
        "check(0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E42Export5_check(&instance, 4u)),
        1098068787u,
        "check(4u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E42Export5_check(&instance, 8u)),
        1098173645u,
        "check(8u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E42Export5_check(&instance, 12u)),
        1098278502u,
        "check(12u)"
    );
    m14_floatX5FexprsX2E42Export3_run(&instance, 16u, 3.0);
    printOK("run(16u, 3.0)");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E42Export5_check(&instance, 0u)),
        1084297489u,
        "check(0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E42Export5_check(&instance, 4u)),
        1084367394u,
        "check(4u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E42Export5_check(&instance, 8u)),
        1084437299u,
        "check(8u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E42Export5_check(&instance, 12u)),
        1084507204u,
        "check(12u)"
    );
}
