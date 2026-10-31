#include "test.h"
#include "test_extended_const.0.h"
#include "test_extended_const.1.h"
#include "test_extended_const.2.h"

static m16_extendedX5FconstX2E0Instance instance_0;
static m16_extendedX5FconstX2E1Instance instance_1;
static m16_extendedX5FconstX2E2Instance instance_2;

void test(void) {
    m16_extendedX5FconstX2E0Instantiate(&instance_0, resolveTestImports);
    printStart("extended_const.0.wasm");
    assertEqualU32(
        *m16_extendedX5FconstX2E0Export7_i32X2Dadd(&instance_0),
        1u,
        "WAST line 26: get i32-add"
    );
    assertEqualU32(
        *m16_extendedX5FconstX2E0Export7_i32X2Dsub(&instance_0),
        4294967295u,
        "WAST line 27: get i32-sub"
    );
    assertEqualU32(
        *m16_extendedX5FconstX2E0Export7_i32X2Dmul(&instance_0),
        2u,
        "WAST line 28: get i32-mul"
    );
    assertEqualU64(
        *m16_extendedX5FconstX2E0Export7_i64X2Dadd(&instance_0),
        1ull,
        "WAST line 29: get i64-add"
    );
    assertEqualU64(
        *m16_extendedX5FconstX2E0Export7_i64X2Dsub(&instance_0),
        18446744073709551615ull,
        "WAST line 30: get i64-sub"
    );
    assertEqualU64(
        *m16_extendedX5FconstX2E0Export7_i64X2Dmul(&instance_0),
        2ull,
        "WAST line 31: get i64-mul"
    );
    assertEqualU32(
        *m16_extendedX5FconstX2E0Export10_i32X2Dnested(&instance_0),
        37u,
        "WAST line 32: get i32-nested"
    );
    assertEqualU64(
        *m16_extendedX5FconstX2E0Export10_i64X2Dnested(&instance_0),
        37ull,
        "WAST line 33: get i64-nested"
    );
    assertEqualU32(
        *m16_extendedX5FconstX2E0Export8_i32X2Dflat(&instance_0),
        9u,
        "WAST line 34: get i32-flat"
    );
    assertEqualU64(
        *m16_extendedX5FconstX2E0Export8_i64X2Dflat(&instance_0),
        9ull,
        "WAST line 35: get i64-flat"
    );
    assertEqualU32(
        *m16_extendedX5FconstX2E0Export5_chain(&instance_0),
        6u,
        "WAST line 36: get chain"
    );
    assertEqualU32(
        i32_reinterpret_f32(*m16_extendedX5FconstX2E0Export10_floatX2Dcopy(&instance_0)),
        2147483648u,
        "WAST line 37: get float-copy"
    );
    assertEqualU64(
        i64_reinterpret_f64(*m16_extendedX5FconstX2E0Export11_doubleX2Dcopy(&instance_0)),
        13832806255468478464ull,
        "WAST line 38: get double-copy"
    );
    m16_extendedX5FconstX2E1Instantiate(&instance_1, resolveTestImports);
    printStart("extended_const.1.wasm");
    bindTestImport("extended-const-base", "base", (void*)m16_extendedX5FconstX2E1Export4_base(&instance_1));
    m16_extendedX5FconstX2E2Instantiate(&instance_2, resolveTestImports);
    printStart("extended_const.2.wasm");
    assertEqualU32(
        m16_extendedX5FconstX2E2Export4_load(&instance_2, 1u),
        85u,
        "WAST line 67: load(1u)"
    );
    assertEqualU32(
        m16_extendedX5FconstX2E2Export4_load(&instance_2, 10u),
        79u,
        "WAST line 68: load(10u)"
    );
    assertEqualU32(
        m16_extendedX5FconstX2E2Export4_load(&instance_2, 11u),
        75u,
        "WAST line 69: load(11u)"
    );
    assertEqualU32(
        m16_extendedX5FconstX2E2Export4_call(&instance_2, 2u),
        42u,
        "WAST line 70: call(2u)"
    );
    assertEqualU32(
        m16_extendedX5FconstX2E2Export4_call(&instance_2, 11u),
        42u,
        "WAST line 71: call(11u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m16_extendedX5FconstX2E2Export4_call(&instance_2, 0u), "WAST line 72: call(0u)");
#endif
    (void)(m16_extendedX5FconstX2E2Export4_init(&instance_2));
    printOK("WAST line 73: init()");
    assertEqualU32(
        m16_extendedX5FconstX2E2Export4_call(&instance_2, 14u),
        42u,
        "WAST line 74: call(14u)"
    );
    assertEqualU32((*m16_extendedX5FconstX2E2Export9_nullX2Dcopy(&instance_2)) == wasmNullExternRef, 1u, "WAST line 75: get null-copy");
    m16_extendedX5FconstX2E2FreeInstance(&instance_2);
    m16_extendedX5FconstX2E1FreeInstance(&instance_1);
    m16_extendedX5FconstX2E0FreeInstance(&instance_0);
}
