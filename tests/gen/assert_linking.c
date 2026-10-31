#include "test.h"
#include "test_linking.0.h"
#include "test_linking.1.h"
#include "test_linking.2.h"
#include "test_linking.5.h"
#include "test_linking.6.h"
#include "test_linking.9.h"
#include "test_linking.10.h"
#include "test_linking.11.h"
#include "test_linking.12.h"
#include "test_linking.13.h"
#include "test_linking.14.h"
#include "test_linking.15.h"
#include "test_linking.16.h"
#include "test_linking.18.h"
#include "test_linking.19.h"
#include "test_linking.20.h"
#include "test_linking.21.h"
#include "test_linking.22.h"
#include "test_linking.23.h"
#include "test_linking.24.h"
#include "test_linking.26.h"

static m9_linkingX2E0Instance instance_0;
static m9_linkingX2E1Instance instance_1;
static m9_linkingX2E2Instance instance_2;
static m9_linkingX2E5Instance instance_3;
static m9_linkingX2E6Instance instance_4;
static m9_linkingX2E9Instance instance_5;
static m10_linkingX2E10Instance instance_6;
static m10_linkingX2E11Instance instance_7;
static m10_linkingX2E12Instance instance_8;
static m10_linkingX2E13Instance instance_9;
static m10_linkingX2E14Instance instance_10;
static m10_linkingX2E15Instance instance_11;
static m10_linkingX2E16Instance instance_12;
static m10_linkingX2E18Instance instance_13;
static m10_linkingX2E19Instance instance_14;
static m10_linkingX2E20Instance instance_15;
static m10_linkingX2E21Instance instance_16;
static m10_linkingX2E22Instance instance_17;
static m10_linkingX2E23Instance instance_18;
static m10_linkingX2E24Instance instance_19;
static m10_linkingX2E26Instance instance_20;

U32 m9_linkingX2E1Import2_Mf4_call(wasmModuleInstance* instance) {
    (void)instance;
    return m9_linkingX2E0Export4_call(&instance_0);
}
void m9_linkingX2E2Import8_spectest9_printX5Fi32(wasmModuleInstance* instance, U32 p0) {
    void i8_spectest9_printX5Fi32(wasmModuleInstance* instance, U32 p0);
    i8_spectest9_printX5Fi32(instance, p0);
}
U32 m9_linkingX2E6Import2_Mg3_get(wasmModuleInstance* instance) {
    (void)instance;
    return m9_linkingX2E5Export3_get(&instance_3);
}
U32 m9_linkingX2E6Import2_Mg7_getX5Fmut(wasmModuleInstance* instance) {
    (void)instance;
    return m9_linkingX2E5Export7_getX5Fmut(&instance_3);
}
void m9_linkingX2E6Import2_Mg7_setX5Fmut(wasmModuleInstance* instance, U32 p0) {
    (void)instance;
    m9_linkingX2E5Export7_setX5Fmut(&instance_3, p0);
}
U32 m10_linkingX2E12Import2_Mt4_call(wasmModuleInstance* instance, U32 p0) {
    (void)instance;
    return m10_linkingX2E11Export4_call(&instance_7, p0);
}
U32 m10_linkingX2E12Import2_Mt1_h(wasmModuleInstance* instance) {
    (void)instance;
    return m10_linkingX2E11Export1_h(&instance_7);
}
U32 m10_linkingX2E13Import2_Mt1_h(wasmModuleInstance* instance) {
    (void)instance;
    return m10_linkingX2E11Export1_h(&instance_7);
}
U32 m10_linkingX2E21Import2_Mm4_load(wasmModuleInstance* instance, U32 p0) {
    (void)instance;
    return m10_linkingX2E20Export4_load(&instance_15, p0);
}
void test(void) {
    m9_linkingX2E0Instantiate(&instance_0, resolveTestImports);
    printStart("linking.0.wasm");
    m9_linkingX2E1Instantiate(&instance_1, resolveTestImports);
    printStart("linking.1.wasm");
    assertEqualU32(
        m9_linkingX2E0Export4_call(&instance_0),
        2u,
        "WAST line 17: call()"
    );
    assertEqualU32(
        m9_linkingX2E1Export7_MfX2Ecall(&instance_1),
        2u,
        "WAST line 18: Mf.call()"
    );
    assertEqualU32(
        m9_linkingX2E1Export4_call(&instance_1),
        3u,
        "WAST line 19: call()"
    );
    assertEqualU32(
        m9_linkingX2E1Export12_callX20MfX2Ecall(&instance_1),
        2u,
        "WAST line 20: call Mf.call()"
    );
    m9_linkingX2E2Instantiate(&instance_2, resolveTestImports);
    printStart("linking.2.wasm");
    m9_linkingX2E5Instantiate(&instance_3, resolveTestImports);
    printStart("linking.5.wasm");
    bindTestImport("Mg", "glob", (void*)m9_linkingX2E5Export4_glob(&instance_3));
    bindTestImport("Mg", "mut_glob", (void*)m9_linkingX2E5Export8_mutX5Fglob(&instance_3));
    m9_linkingX2E6Instantiate(&instance_4, resolveTestImports);
    printStart("linking.6.wasm");
    assertEqualU32(
        *m9_linkingX2E5Export4_glob(&instance_3),
        42u,
        "WAST line 67: get glob"
    );
    assertEqualU32(
        *m9_linkingX2E6Export7_MgX2Eglob(&instance_4),
        42u,
        "WAST line 68: get Mg.glob"
    );
    assertEqualU32(
        *m9_linkingX2E6Export4_glob(&instance_4),
        43u,
        "WAST line 69: get glob"
    );
    assertEqualU32(
        m9_linkingX2E5Export3_get(&instance_3),
        42u,
        "WAST line 70: get()"
    );
    assertEqualU32(
        m9_linkingX2E6Export6_MgX2Eget(&instance_4),
        42u,
        "WAST line 71: Mg.get()"
    );
    assertEqualU32(
        m9_linkingX2E6Export3_get(&instance_4),
        43u,
        "WAST line 72: get()"
    );
    assertEqualU32(
        *m9_linkingX2E5Export8_mutX5Fglob(&instance_3),
        142u,
        "WAST line 74: get mut_glob"
    );
    assertEqualU32(
        *m9_linkingX2E6Export11_MgX2EmutX5Fglob(&instance_4),
        142u,
        "WAST line 75: get Mg.mut_glob"
    );
    assertEqualU32(
        m9_linkingX2E5Export7_getX5Fmut(&instance_3),
        142u,
        "WAST line 76: get_mut()"
    );
    assertEqualU32(
        m9_linkingX2E6Export10_MgX2EgetX5Fmut(&instance_4),
        142u,
        "WAST line 77: Mg.get_mut()"
    );
    (void)(m9_linkingX2E5Export7_setX5Fmut(&instance_3, 241u));
    printOK("WAST line 79: set_mut(241u)");
    assertEqualU32(
        *m9_linkingX2E5Export8_mutX5Fglob(&instance_3),
        241u,
        "WAST line 80: get mut_glob"
    );
    assertEqualU32(
        *m9_linkingX2E6Export11_MgX2EmutX5Fglob(&instance_4),
        241u,
        "WAST line 81: get Mg.mut_glob"
    );
    assertEqualU32(
        m9_linkingX2E5Export7_getX5Fmut(&instance_3),
        241u,
        "WAST line 82: get_mut()"
    );
    assertEqualU32(
        m9_linkingX2E6Export10_MgX2EgetX5Fmut(&instance_4),
        241u,
        "WAST line 83: Mg.get_mut()"
    );
    m9_linkingX2E9Instantiate(&instance_5, resolveTestImports);
    printStart("linking.9.wasm");
    bindTestImport("Mref_ex", "g-const-extern", (void*)m9_linkingX2E9Export14_gX2DconstX2Dextern(&instance_5));
    bindTestImport("Mref_ex", "g-var-extern", (void*)m9_linkingX2E9Export12_gX2DvarX2Dextern(&instance_5));
    m10_linkingX2E10Instantiate(&instance_6, resolveTestImports);
    printStart("linking.10.wasm");
    m10_linkingX2E11Instantiate(&instance_7, resolveTestImports);
    printStart("linking.11.wasm");
    bindTestImport("Mt", "tab", (void*)m10_linkingX2E11Export3_tab(&instance_7));
    m10_linkingX2E12Instantiate(&instance_8, resolveTestImports);
    printStart("linking.12.wasm");
    assertEqualU32(
        m10_linkingX2E11Export4_call(&instance_7, 2u),
        4u,
        "WAST line 316: call(2u)"
    );
    assertEqualU32(
        m10_linkingX2E12Export7_MtX2Ecall(&instance_8, 2u),
        4u,
        "WAST line 317: Mt.call(2u)"
    );
    assertEqualU32(
        m10_linkingX2E12Export4_call(&instance_8, 2u),
        5u,
        "WAST line 318: call(2u)"
    );
    assertEqualU32(
        m10_linkingX2E12Export12_callX20MtX2Ecall(&instance_8, 2u),
        4u,
        "WAST line 319: call Mt.call(2u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E11Export4_call(&instance_7, 1u), "WAST line 321: call(1u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E12Export7_MtX2Ecall(&instance_8, 1u), "WAST line 322: Mt.call(1u)");
#endif
    assertEqualU32(
        m10_linkingX2E12Export4_call(&instance_8, 1u),
        5u,
        "WAST line 323: call(1u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E12Export12_callX20MtX2Ecall(&instance_8, 1u), "WAST line 324: call Mt.call(1u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E11Export4_call(&instance_7, 0u), "WAST line 326: call(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E12Export7_MtX2Ecall(&instance_8, 0u), "WAST line 327: Mt.call(0u)");
#endif
    assertEqualU32(
        m10_linkingX2E12Export4_call(&instance_8, 0u),
        5u,
        "WAST line 328: call(0u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E12Export12_callX20MtX2Ecall(&instance_8, 0u), "WAST line 329: call Mt.call(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E11Export4_call(&instance_7, 20u), "WAST line 331: call(20u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E12Export7_MtX2Ecall(&instance_8, 20u), "WAST line 332: Mt.call(20u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E12Export4_call(&instance_8, 7u), "WAST line 333: call(7u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E12Export12_callX20MtX2Ecall(&instance_8, 20u), "WAST line 334: call Mt.call(20u)");
#endif
    assertEqualU32(
        m10_linkingX2E12Export4_call(&instance_8, 3u),
        4294967292u,
        "WAST line 336: call(3u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E12Export4_call(&instance_8, 4u), "WAST line 337: call(4u)");
#endif
    m10_linkingX2E13Instantiate(&instance_9, resolveTestImports);
    printStart("linking.13.wasm");
    assertEqualU32(
        m10_linkingX2E11Export4_call(&instance_7, 3u),
        4u,
        "WAST line 352: call(3u)"
    );
    assertEqualU32(
        m10_linkingX2E12Export7_MtX2Ecall(&instance_8, 3u),
        4u,
        "WAST line 353: Mt.call(3u)"
    );
    assertEqualU32(
        m10_linkingX2E12Export12_callX20MtX2Ecall(&instance_8, 3u),
        4u,
        "WAST line 354: call Mt.call(3u)"
    );
    assertEqualU32(
        m10_linkingX2E13Export4_call(&instance_9, 3u),
        4u,
        "WAST line 355: call(3u)"
    );
    assertEqualU32(
        m10_linkingX2E11Export4_call(&instance_7, 2u),
        4294967292u,
        "WAST line 357: call(2u)"
    );
    assertEqualU32(
        m10_linkingX2E12Export7_MtX2Ecall(&instance_8, 2u),
        4294967292u,
        "WAST line 358: Mt.call(2u)"
    );
    assertEqualU32(
        m10_linkingX2E12Export4_call(&instance_8, 2u),
        5u,
        "WAST line 359: call(2u)"
    );
    assertEqualU32(
        m10_linkingX2E12Export12_callX20MtX2Ecall(&instance_8, 2u),
        4294967292u,
        "WAST line 360: call Mt.call(2u)"
    );
    assertEqualU32(
        m10_linkingX2E13Export4_call(&instance_9, 2u),
        4294967292u,
        "WAST line 361: call(2u)"
    );
    assertEqualU32(
        m10_linkingX2E11Export4_call(&instance_7, 1u),
        6u,
        "WAST line 363: call(1u)"
    );
    assertEqualU32(
        m10_linkingX2E12Export7_MtX2Ecall(&instance_8, 1u),
        6u,
        "WAST line 364: Mt.call(1u)"
    );
    assertEqualU32(
        m10_linkingX2E12Export4_call(&instance_8, 1u),
        5u,
        "WAST line 365: call(1u)"
    );
    assertEqualU32(
        m10_linkingX2E12Export12_callX20MtX2Ecall(&instance_8, 1u),
        6u,
        "WAST line 366: call Mt.call(1u)"
    );
    assertEqualU32(
        m10_linkingX2E13Export4_call(&instance_9, 1u),
        6u,
        "WAST line 367: call(1u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E11Export4_call(&instance_7, 0u), "WAST line 369: call(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E12Export7_MtX2Ecall(&instance_8, 0u), "WAST line 370: Mt.call(0u)");
#endif
    assertEqualU32(
        m10_linkingX2E12Export4_call(&instance_8, 0u),
        5u,
        "WAST line 371: call(0u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E12Export12_callX20MtX2Ecall(&instance_8, 0u), "WAST line 372: call Mt.call(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E13Export4_call(&instance_9, 0u), "WAST line 373: call(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E13Export4_call(&instance_9, 20u), "WAST line 375: call(20u)");
#endif
    m10_linkingX2E14Instantiate(&instance_10, resolveTestImports);
    printStart("linking.14.wasm");
    m10_linkingX2E15Instantiate(&instance_11, resolveTestImports);
    printStart("linking.15.wasm");
    bindTestImport("G1", "g", (void*)m10_linkingX2E15Export1_g(&instance_11));
    m10_linkingX2E16Instantiate(&instance_12, resolveTestImports);
    printStart("linking.16.wasm");
    assertEqualU32(
        *m10_linkingX2E16Export1_g(&instance_12),
        5u,
        "WAST line 389: get g"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m10_linkingX2E11Export4_call(&instance_7, 7u), "WAST line 411: call(7u)");
#endif
    m10_linkingX2E18Instantiate(&instance_13, resolveTestImports);
    printStart("linking.18.wasm");
    bindTestImport("Mtable_ex", "t-extern", (void*)m10_linkingX2E18Export8_tX2Dextern(&instance_13));
    m10_linkingX2E19Instantiate(&instance_14, resolveTestImports);
    printStart("linking.19.wasm");
    m10_linkingX2E20Instantiate(&instance_15, resolveTestImports);
    printStart("linking.20.wasm");
    bindTestImport("Mm", "mem", (void*)m10_linkingX2E20Export3_mem(&instance_15));
    m10_linkingX2E21Instantiate(&instance_16, resolveTestImports);
    printStart("linking.21.wasm");
    assertEqualU32(
        m10_linkingX2E20Export4_load(&instance_15, 12u),
        2u,
        "WAST line 514: load(12u)"
    );
    assertEqualU32(
        m10_linkingX2E21Export7_MmX2Eload(&instance_16, 12u),
        2u,
        "WAST line 515: Mm.load(12u)"
    );
    assertEqualU32(
        m10_linkingX2E21Export4_load(&instance_16, 12u),
        242u,
        "WAST line 516: load(12u)"
    );
    m10_linkingX2E22Instantiate(&instance_17, resolveTestImports);
    printStart("linking.22.wasm");
    assertEqualU32(
        m10_linkingX2E20Export4_load(&instance_15, 12u),
        167u,
        "WAST line 527: load(12u)"
    );
    assertEqualU32(
        m10_linkingX2E21Export7_MmX2Eload(&instance_16, 12u),
        167u,
        "WAST line 528: Mm.load(12u)"
    );
    assertEqualU32(
        m10_linkingX2E21Export4_load(&instance_16, 12u),
        242u,
        "WAST line 529: load(12u)"
    );
    assertEqualU32(
        m10_linkingX2E22Export4_load(&instance_17, 12u),
        167u,
        "WAST line 530: load(12u)"
    );
    m10_linkingX2E23Instantiate(&instance_18, resolveTestImports);
    printStart("linking.23.wasm");
    m10_linkingX2E24Instantiate(&instance_19, resolveTestImports);
    printStart("linking.24.wasm");
    assertEqualU32(
        m10_linkingX2E24Export4_grow(&instance_19, 0u),
        1u,
        "WAST line 554: grow(0u)"
    );
    assertEqualU32(
        m10_linkingX2E24Export4_grow(&instance_19, 2u),
        1u,
        "WAST line 555: grow(2u)"
    );
    assertEqualU32(
        m10_linkingX2E24Export4_grow(&instance_19, 0u),
        3u,
        "WAST line 556: grow(0u)"
    );
    assertEqualU32(
        m10_linkingX2E24Export4_grow(&instance_19, 1u),
        3u,
        "WAST line 557: grow(1u)"
    );
    assertEqualU32(
        m10_linkingX2E24Export4_grow(&instance_19, 1u),
        4u,
        "WAST line 558: grow(1u)"
    );
    assertEqualU32(
        m10_linkingX2E24Export4_grow(&instance_19, 0u),
        5u,
        "WAST line 559: grow(0u)"
    );
    assertEqualU32(
        m10_linkingX2E24Export4_grow(&instance_19, 1u),
        4294967295u,
        "WAST line 560: grow(1u)"
    );
    assertEqualU32(
        m10_linkingX2E24Export4_grow(&instance_19, 0u),
        5u,
        "WAST line 561: grow(0u)"
    );
    assertEqualU32(
        m10_linkingX2E20Export4_load(&instance_15, 0u),
        0u,
        "WAST line 572: load(0u)"
    );
    m10_linkingX2E26Instantiate(&instance_20, resolveTestImports);
    printStart("linking.26.wasm");
    bindTestImport("Ms", "memory", (void*)m10_linkingX2E26Export6_memory(&instance_20));
    bindTestImport("Ms", "table", (void*)m10_linkingX2E26Export5_table(&instance_20));
    m10_linkingX2E26FreeInstance(&instance_20);
    m10_linkingX2E24FreeInstance(&instance_19);
    m10_linkingX2E23FreeInstance(&instance_18);
    m10_linkingX2E22FreeInstance(&instance_17);
    m10_linkingX2E21FreeInstance(&instance_16);
    m10_linkingX2E20FreeInstance(&instance_15);
    m10_linkingX2E19FreeInstance(&instance_14);
    m10_linkingX2E18FreeInstance(&instance_13);
    m10_linkingX2E16FreeInstance(&instance_12);
    m10_linkingX2E15FreeInstance(&instance_11);
    m10_linkingX2E14FreeInstance(&instance_10);
    m10_linkingX2E13FreeInstance(&instance_9);
    m10_linkingX2E12FreeInstance(&instance_8);
    m10_linkingX2E11FreeInstance(&instance_7);
    m10_linkingX2E10FreeInstance(&instance_6);
    m9_linkingX2E9FreeInstance(&instance_5);
    m9_linkingX2E6FreeInstance(&instance_4);
    m9_linkingX2E5FreeInstance(&instance_3);
    m9_linkingX2E2FreeInstance(&instance_2);
    m9_linkingX2E1FreeInstance(&instance_1);
    m9_linkingX2E0FreeInstance(&instance_0);
}
