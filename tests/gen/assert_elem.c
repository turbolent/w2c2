#include "test.h"
#include "test_elem.0.h"
#include "test_elem.1.h"
#include "test_elem.2.h"
#include "test_elem.3.h"
#include "test_elem.4.h"
#include "test_elem.5.h"
#include "test_elem.6.h"
#include "test_elem.7.h"
#include "test_elem.8.h"
#include "test_elem.9.h"
#include "test_elem.10.h"
#include "test_elem.11.h"
#include "test_elem.12.h"
#include "test_elem.13.h"
#include "test_elem.14.h"
#include "test_elem.15.h"
#include "test_elem.16.h"
#include "test_elem.17.h"
#include "test_elem.18.h"
#include "test_elem.19.h"
#include "test_elem.20.h"
#include "test_elem.21.h"
#include "test_elem.22.h"
#include "test_elem.23.h"
#include "test_elem.24.h"
#include "test_elem.25.h"
#include "test_elem.26.h"
#include "test_elem.27.h"
#include "test_elem.28.h"
#include "test_elem.29.h"
#include "test_elem.30.h"
#include "test_elem.31.h"
#include "test_elem.32.h"
#include "test_elem.33.h"
#include "test_elem.34.h"
#include "test_elem.35.h"
#include "test_elem.36.h"
#include "test_elem.37.h"
#include "test_elem.38.h"
#include "test_elem.39.h"
#include "test_elem.40.h"
#include "test_elem.41.h"
#include "test_elem.42.h"
#include "test_elem.43.h"
#include "test_elem.44.h"
#include "test_elem.57.h"
#include "test_elem.58.h"
#include "test_elem.79.h"
#include "test_elem.80.h"
#include "test_elem.81.h"
#include "test_elem.82.h"
#include "test_elem.83.h"
#include "test_elem.88.h"
#include "test_elem.89.h"
#include "test_elem.90.h"
#include "test_elem.91.h"
#include "test_elem.92.h"
#include "test_elem.93.h"
#include "test_elem.94.h"
#include "test_elem.95.h"
#include "test_elem.96.h"

static m6_elemX2E0Instance instance_0;
static m6_elemX2E1Instance instance_1;
static m6_elemX2E2Instance instance_2;
static m6_elemX2E3Instance instance_3;
static m6_elemX2E4Instance instance_4;
static m6_elemX2E5Instance instance_5;
static m6_elemX2E6Instance instance_6;
static m6_elemX2E7Instance instance_7;
static m6_elemX2E8Instance instance_8;
static m6_elemX2E9Instance instance_9;
static m7_elemX2E10Instance instance_10;
static m7_elemX2E11Instance instance_11;
static m7_elemX2E12Instance instance_12;
static m7_elemX2E13Instance instance_13;
static m7_elemX2E14Instance instance_14;
static m7_elemX2E15Instance instance_15;
static m7_elemX2E16Instance instance_16;
static m7_elemX2E17Instance instance_17;
static m7_elemX2E18Instance instance_18;
static m7_elemX2E19Instance instance_19;
static m7_elemX2E20Instance instance_20;
static m7_elemX2E21Instance instance_21;
static m7_elemX2E22Instance instance_22;
static m7_elemX2E23Instance instance_23;
static m7_elemX2E24Instance instance_24;
static m7_elemX2E25Instance instance_25;
static m7_elemX2E26Instance instance_26;
static m7_elemX2E27Instance instance_27;
static m7_elemX2E28Instance instance_28;
static m7_elemX2E29Instance instance_29;
static m7_elemX2E30Instance instance_30;
static m7_elemX2E31Instance instance_31;
static m7_elemX2E32Instance instance_32;
static m7_elemX2E33Instance instance_33;
static m7_elemX2E34Instance instance_34;
static m7_elemX2E35Instance instance_35;
static m7_elemX2E36Instance instance_36;
static m7_elemX2E37Instance instance_37;
static m7_elemX2E38Instance instance_38;
static m7_elemX2E39Instance instance_39;
static m7_elemX2E40Instance instance_40;
static m7_elemX2E41Instance instance_41;
static m7_elemX2E42Instance instance_42;
static m7_elemX2E43Instance instance_43;
static m7_elemX2E44Instance instance_44;
static m7_elemX2E57Instance instance_45;
static m7_elemX2E58Instance instance_46;
static m7_elemX2E79Instance instance_47;
static m7_elemX2E80Instance instance_48;
static m7_elemX2E81Instance instance_49;
static m7_elemX2E82Instance instance_50;
static m7_elemX2E83Instance instance_51;
static m7_elemX2E88Instance instance_52;
static m7_elemX2E89Instance instance_53;
static m7_elemX2E90Instance instance_54;
static m7_elemX2E91Instance instance_55;
static m7_elemX2E92Instance instance_56;
static m7_elemX2E93Instance instance_57;
static m7_elemX2E94Instance instance_58;
static m7_elemX2E95Instance instance_59;
static m7_elemX2E96Instance instance_60;

void test(void) {
    m6_elemX2E0Instantiate(&instance_0, resolveTestImports);
    printStart("elem.0.wasm");
    m6_elemX2E1Instantiate(&instance_1, resolveTestImports);
    printStart("elem.1.wasm");
    m6_elemX2E2Instantiate(&instance_2, resolveTestImports);
    printStart("elem.2.wasm");
    m6_elemX2E3Instantiate(&instance_3, resolveTestImports);
    printStart("elem.3.wasm");
    m6_elemX2E4Instantiate(&instance_4, resolveTestImports);
    printStart("elem.4.wasm");
    m6_elemX2E5Instantiate(&instance_5, resolveTestImports);
    printStart("elem.5.wasm");
    m6_elemX2E6Instantiate(&instance_6, resolveTestImports);
    printStart("elem.6.wasm");
    m6_elemX2E7Instantiate(&instance_7, resolveTestImports);
    printStart("elem.7.wasm");
    m6_elemX2E8Instantiate(&instance_8, resolveTestImports);
    printStart("elem.8.wasm");
    assertEqualU32(
        m6_elemX2E8Export6_callX2D7(&instance_8),
        65u,
        "WAST line 145: call-7()"
    );
    assertEqualU32(
        m6_elemX2E8Export6_callX2D9(&instance_8),
        66u,
        "WAST line 146: call-9()"
    );
    m6_elemX2E9Instantiate(&instance_9, resolveTestImports);
    printStart("elem.9.wasm");
    assertEqualU32(
        m6_elemX2E9Export6_callX2D7(&instance_9),
        65u,
        "WAST line 163: call-7()"
    );
    assertEqualU32(
        m6_elemX2E9Export6_callX2D9(&instance_9),
        66u,
        "WAST line 164: call-9()"
    );
    m7_elemX2E10Instantiate(&instance_10, resolveTestImports);
    printStart("elem.10.wasm");
    m7_elemX2E11Instantiate(&instance_11, resolveTestImports);
    printStart("elem.11.wasm");
    m7_elemX2E12Instantiate(&instance_12, resolveTestImports);
    printStart("elem.12.wasm");
    m7_elemX2E13Instantiate(&instance_13, resolveTestImports);
    printStart("elem.13.wasm");
    m7_elemX2E14Instantiate(&instance_14, resolveTestImports);
    printStart("elem.14.wasm");
    m7_elemX2E15Instantiate(&instance_15, resolveTestImports);
    printStart("elem.15.wasm");
    m7_elemX2E16Instantiate(&instance_16, resolveTestImports);
    printStart("elem.16.wasm");
    m7_elemX2E17Instantiate(&instance_17, resolveTestImports);
    printStart("elem.17.wasm");
    m7_elemX2E18Instantiate(&instance_18, resolveTestImports);
    printStart("elem.18.wasm");
    m7_elemX2E19Instantiate(&instance_19, resolveTestImports);
    printStart("elem.19.wasm");
    m7_elemX2E20Instantiate(&instance_20, resolveTestImports);
    printStart("elem.20.wasm");
    m7_elemX2E21Instantiate(&instance_21, resolveTestImports);
    printStart("elem.21.wasm");
    m7_elemX2E22Instantiate(&instance_22, resolveTestImports);
    printStart("elem.22.wasm");
    m7_elemX2E23Instantiate(&instance_23, resolveTestImports);
    printStart("elem.23.wasm");
    m7_elemX2E24Instantiate(&instance_24, resolveTestImports);
    printStart("elem.24.wasm");
    m7_elemX2E25Instantiate(&instance_25, resolveTestImports);
    printStart("elem.25.wasm");
    m7_elemX2E26Instantiate(&instance_26, resolveTestImports);
    printStart("elem.26.wasm");
    m7_elemX2E27Instantiate(&instance_27, resolveTestImports);
    printStart("elem.27.wasm");
    m7_elemX2E28Instantiate(&instance_28, resolveTestImports);
    printStart("elem.28.wasm");
    m7_elemX2E29Instantiate(&instance_29, resolveTestImports);
    printStart("elem.29.wasm");
    m7_elemX2E30Instantiate(&instance_30, resolveTestImports);
    printStart("elem.30.wasm");
    m7_elemX2E31Instantiate(&instance_31, resolveTestImports);
    printStart("elem.31.wasm");
    m7_elemX2E32Instantiate(&instance_32, resolveTestImports);
    printStart("elem.32.wasm");
    m7_elemX2E33Instantiate(&instance_33, resolveTestImports);
    printStart("elem.33.wasm");
    m7_elemX2E34Instantiate(&instance_34, resolveTestImports);
    printStart("elem.34.wasm");
    m7_elemX2E35Instantiate(&instance_35, resolveTestImports);
    printStart("elem.35.wasm");
    m7_elemX2E36Instantiate(&instance_36, resolveTestImports);
    printStart("elem.36.wasm");
    m7_elemX2E37Instantiate(&instance_37, resolveTestImports);
    printStart("elem.37.wasm");
    m7_elemX2E38Instantiate(&instance_38, resolveTestImports);
    printStart("elem.38.wasm");
    m7_elemX2E39Instantiate(&instance_39, resolveTestImports);
    printStart("elem.39.wasm");
    m7_elemX2E40Instantiate(&instance_40, resolveTestImports);
    printStart("elem.40.wasm");
    m7_elemX2E41Instantiate(&instance_41, resolveTestImports);
    printStart("elem.41.wasm");
    m7_elemX2E42Instantiate(&instance_42, resolveTestImports);
    printStart("elem.42.wasm");
    m7_elemX2E43Instantiate(&instance_43, resolveTestImports);
    printStart("elem.43.wasm");
    m7_elemX2E44Instantiate(&instance_44, resolveTestImports);
    printStart("elem.44.wasm");
    m7_elemX2E57Instantiate(&instance_45, resolveTestImports);
    printStart("elem.57.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_elemX2E57Export4_init(&instance_45), "WAST line 702: init()");
#endif
    m7_elemX2E58Instantiate(&instance_46, resolveTestImports);
    printStart("elem.58.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_elemX2E58Export4_init(&instance_46), "WAST line 711: init()");
#endif
    m7_elemX2E79Instantiate(&instance_47, resolveTestImports);
    printStart("elem.79.wasm");
    assertEqualU32(
        m7_elemX2E79Export16_callX2Doverwritten(&instance_47),
        66u,
        "WAST line 896: call-overwritten()"
    );
    m7_elemX2E80Instantiate(&instance_48, resolveTestImports);
    printStart("elem.80.wasm");
    assertEqualU32(
        m7_elemX2E80Export24_callX2DoverwrittenX2Delement(&instance_48),
        66u,
        "WAST line 909: call-overwritten-element()"
    );
    m7_elemX2E81Instantiate(&instance_49, resolveTestImports);
    printStart("elem.81.wasm");
    bindTestImport("module1", "shared-table", (void*)m7_elemX2E81Export12_sharedX2Dtable(&instance_49));
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_elemX2E81Export6_callX2D7(&instance_49), "WAST line 933: call-7()");
#endif
    assertEqualU32(
        m7_elemX2E81Export6_callX2D8(&instance_49),
        65u,
        "WAST line 934: call-8()"
    );
    assertEqualU32(
        m7_elemX2E81Export6_callX2D9(&instance_49),
        66u,
        "WAST line 935: call-9()"
    );
    m7_elemX2E82Instantiate(&instance_50, resolveTestImports);
    printStart("elem.82.wasm");
    assertEqualU32(
        m7_elemX2E81Export6_callX2D7(&instance_49),
        67u,
        "WAST line 946: call-7()"
    );
    assertEqualU32(
        m7_elemX2E81Export6_callX2D8(&instance_49),
        68u,
        "WAST line 947: call-8()"
    );
    assertEqualU32(
        m7_elemX2E81Export6_callX2D9(&instance_49),
        66u,
        "WAST line 948: call-9()"
    );
    m7_elemX2E83Instantiate(&instance_51, resolveTestImports);
    printStart("elem.83.wasm");
    assertEqualU32(
        m7_elemX2E81Export6_callX2D7(&instance_49),
        67u,
        "WAST line 959: call-7()"
    );
    assertEqualU32(
        m7_elemX2E81Export6_callX2D8(&instance_49),
        69u,
        "WAST line 960: call-8()"
    );
    assertEqualU32(
        m7_elemX2E81Export6_callX2D9(&instance_49),
        70u,
        "WAST line 961: call-9()"
    );
    m7_elemX2E88Instantiate(&instance_52, resolveTestImports);
    printStart("elem.88.wasm");
    bindTestImport("exporter", "table", (void*)m7_elemX2E88Export5_table(&instance_52));
    assertEqualU32((m7_elemX2E88Export3_get(&instance_52, 0u)) == wasmNullExternRef, 1u, "WAST line 1003: get(0u)");
    assertEqualU32((m7_elemX2E88Export3_get(&instance_52, 1u)) == wasmNullExternRef, 1u, "WAST line 1004: get(1u)");
    (void)(m7_elemX2E88Export3_set(&instance_52, 0u, testExternRef(42u)));
    printOK("WAST line 1006: set(0u, testExternRef(42u))");
    (void)(m7_elemX2E88Export3_set(&instance_52, 1u, testExternRef(137u)));
    printOK("WAST line 1007: set(1u, testExternRef(137u))");
    assertEqualU32((m7_elemX2E88Export3_get(&instance_52, 0u)) == testExternRef(42u), 1u, "WAST line 1009: get(0u)");
    assertEqualU32((m7_elemX2E88Export3_get(&instance_52, 1u)) == testExternRef(137u), 1u, "WAST line 1010: get(1u)");
    m7_elemX2E89Instantiate(&instance_53, resolveTestImports);
    printStart("elem.89.wasm");
    assertEqualU32((m7_elemX2E88Export3_get(&instance_52, 0u)) == wasmNullExternRef, 1u, "WAST line 1016: get(0u)");
    assertEqualU32((m7_elemX2E88Export3_get(&instance_52, 1u)) == testExternRef(137u), 1u, "WAST line 1017: get(1u)");
    m7_elemX2E90Instantiate(&instance_54, resolveTestImports);
    printStart("elem.90.wasm");
    bindTestImport("module4", "f", (void*)m7_elemX2E90Export1_f(&instance_54));
    m7_elemX2E91Instantiate(&instance_55, resolveTestImports);
    printStart("elem.91.wasm");
    assertEqualU32(
        m7_elemX2E91Export18_callX5FimportedX5Felem(&instance_55),
        42u,
        "WAST line 1040: call_imported_elem()"
    );
    m7_elemX2E92Instantiate(&instance_56, resolveTestImports);
    printStart("elem.92.wasm");
    assertEqualU32(
        m7_elemX2E92Export13_callX5FinX5Ftable(&instance_56, 3u),
        42u,
        "WAST line 1053: call_in_table(3u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_elemX2E92Export13_callX5FinX5Ftable(&instance_56, 0u), "WAST line 1054: call_in_table(0u)");
#endif
    m7_elemX2E93Instantiate(&instance_57, resolveTestImports);
    printStart("elem.93.wasm");
    assertEqualU32(
        m7_elemX2E93Export13_callX5FinX5Ftable(&instance_57, 1u),
        42u,
        "WAST line 1064: call_in_table(1u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_elemX2E93Export13_callX5FinX5Ftable(&instance_57, 0u), "WAST line 1065: call_in_table(0u)");
#endif
    m7_elemX2E94Instantiate(&instance_58, resolveTestImports);
    printStart("elem.94.wasm");
    assertEqualU32(
        m7_elemX2E94Export13_callX5FinX5Ftable(&instance_58, 4u),
        42u,
        "WAST line 1075: call_in_table(4u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_elemX2E94Export13_callX5FinX5Ftable(&instance_58, 0u), "WAST line 1076: call_in_table(0u)");
#endif
    m7_elemX2E95Instantiate(&instance_59, resolveTestImports);
    printStart("elem.95.wasm");
    assertEqualU32(
        m7_elemX2E95Export13_callX5FinX5Ftable(&instance_59, 6u),
        42u,
        "WAST line 1097: call_in_table(6u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_elemX2E95Export13_callX5FinX5Ftable(&instance_59, 0u), "WAST line 1098: call_in_table(0u)");
#endif
    m7_elemX2E96Instantiate(&instance_60, resolveTestImports);
    printStart("elem.96.wasm");
    (void)(m7_elemX2E96Export4_init(&instance_60));
    printOK("WAST line 1113: init()");
    assertEqualU32(
        m7_elemX2E96Export3_run(&instance_60),
        205u,
        "WAST line 1114: run()"
    );
    m7_elemX2E96FreeInstance(&instance_60);
    m7_elemX2E95FreeInstance(&instance_59);
    m7_elemX2E94FreeInstance(&instance_58);
    m7_elemX2E93FreeInstance(&instance_57);
    m7_elemX2E92FreeInstance(&instance_56);
    m7_elemX2E91FreeInstance(&instance_55);
    m7_elemX2E90FreeInstance(&instance_54);
    m7_elemX2E89FreeInstance(&instance_53);
    m7_elemX2E88FreeInstance(&instance_52);
    m7_elemX2E83FreeInstance(&instance_51);
    m7_elemX2E82FreeInstance(&instance_50);
    m7_elemX2E81FreeInstance(&instance_49);
    m7_elemX2E80FreeInstance(&instance_48);
    m7_elemX2E79FreeInstance(&instance_47);
    m7_elemX2E58FreeInstance(&instance_46);
    m7_elemX2E57FreeInstance(&instance_45);
    m7_elemX2E44FreeInstance(&instance_44);
    m7_elemX2E43FreeInstance(&instance_43);
    m7_elemX2E42FreeInstance(&instance_42);
    m7_elemX2E41FreeInstance(&instance_41);
    m7_elemX2E40FreeInstance(&instance_40);
    m7_elemX2E39FreeInstance(&instance_39);
    m7_elemX2E38FreeInstance(&instance_38);
    m7_elemX2E37FreeInstance(&instance_37);
    m7_elemX2E36FreeInstance(&instance_36);
    m7_elemX2E35FreeInstance(&instance_35);
    m7_elemX2E34FreeInstance(&instance_34);
    m7_elemX2E33FreeInstance(&instance_33);
    m7_elemX2E32FreeInstance(&instance_32);
    m7_elemX2E31FreeInstance(&instance_31);
    m7_elemX2E30FreeInstance(&instance_30);
    m7_elemX2E29FreeInstance(&instance_29);
    m7_elemX2E28FreeInstance(&instance_28);
    m7_elemX2E27FreeInstance(&instance_27);
    m7_elemX2E26FreeInstance(&instance_26);
    m7_elemX2E25FreeInstance(&instance_25);
    m7_elemX2E24FreeInstance(&instance_24);
    m7_elemX2E23FreeInstance(&instance_23);
    m7_elemX2E22FreeInstance(&instance_22);
    m7_elemX2E21FreeInstance(&instance_21);
    m7_elemX2E20FreeInstance(&instance_20);
    m7_elemX2E19FreeInstance(&instance_19);
    m7_elemX2E18FreeInstance(&instance_18);
    m7_elemX2E17FreeInstance(&instance_17);
    m7_elemX2E16FreeInstance(&instance_16);
    m7_elemX2E15FreeInstance(&instance_15);
    m7_elemX2E14FreeInstance(&instance_14);
    m7_elemX2E13FreeInstance(&instance_13);
    m7_elemX2E12FreeInstance(&instance_12);
    m7_elemX2E11FreeInstance(&instance_11);
    m7_elemX2E10FreeInstance(&instance_10);
    m6_elemX2E9FreeInstance(&instance_9);
    m6_elemX2E8FreeInstance(&instance_8);
    m6_elemX2E7FreeInstance(&instance_7);
    m6_elemX2E6FreeInstance(&instance_6);
    m6_elemX2E5FreeInstance(&instance_5);
    m6_elemX2E4FreeInstance(&instance_4);
    m6_elemX2E3FreeInstance(&instance_3);
    m6_elemX2E2FreeInstance(&instance_2);
    m6_elemX2E1FreeInstance(&instance_1);
    m6_elemX2E0FreeInstance(&instance_0);
}
