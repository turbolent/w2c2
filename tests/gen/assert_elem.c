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
#include "test_elem.34.h"
#include "test_elem.35.h"
#include "test_elem.56.h"
#include "test_elem.57.h"
#include "test_elem.58.h"
#include "test_elem.59.h"
#include "test_elem.60.h"
#include "test_elem.61.h"
#include "test_elem.62.h"

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
static m7_elemX2E12Instance instance_10;
static m7_elemX2E13Instance instance_11;
static m7_elemX2E14Instance instance_12;
static m7_elemX2E15Instance instance_13;
static m7_elemX2E16Instance instance_14;
static m7_elemX2E17Instance instance_15;
static m7_elemX2E18Instance instance_16;
static m7_elemX2E19Instance instance_17;
static m7_elemX2E20Instance instance_18;
static m7_elemX2E21Instance instance_19;
static m7_elemX2E34Instance instance_20;
static m7_elemX2E35Instance instance_21;
static m7_elemX2E56Instance instance_22;
static m7_elemX2E57Instance instance_23;
static m7_elemX2E58Instance instance_24;
static m7_elemX2E59Instance instance_25;
static m7_elemX2E60Instance instance_26;
static m7_elemX2E61Instance instance_27;
static m7_elemX2E62Instance instance_28;

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
    m7_elemX2E12Instantiate(&instance_10, resolveTestImports);
    printStart("elem.12.wasm");
    m7_elemX2E13Instantiate(&instance_11, resolveTestImports);
    printStart("elem.13.wasm");
    m7_elemX2E14Instantiate(&instance_12, resolveTestImports);
    printStart("elem.14.wasm");
    m7_elemX2E15Instantiate(&instance_13, resolveTestImports);
    printStart("elem.15.wasm");
    m7_elemX2E16Instantiate(&instance_14, resolveTestImports);
    printStart("elem.16.wasm");
    m7_elemX2E17Instantiate(&instance_15, resolveTestImports);
    printStart("elem.17.wasm");
    m7_elemX2E18Instantiate(&instance_16, resolveTestImports);
    printStart("elem.18.wasm");
    m7_elemX2E19Instantiate(&instance_17, resolveTestImports);
    printStart("elem.19.wasm");
    m7_elemX2E20Instantiate(&instance_18, resolveTestImports);
    printStart("elem.20.wasm");
    m7_elemX2E21Instantiate(&instance_19, resolveTestImports);
    printStart("elem.21.wasm");
    m7_elemX2E34Instantiate(&instance_20, resolveTestImports);
    printStart("elem.34.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_elemX2E34Export4_init(&instance_20), "WAST line 345: init()");
#endif
    m7_elemX2E35Instantiate(&instance_21, resolveTestImports);
    printStart("elem.35.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_elemX2E35Export4_init(&instance_21), "WAST line 354: init()");
#endif
    m7_elemX2E56Instantiate(&instance_22, resolveTestImports);
    printStart("elem.56.wasm");
    assertEqualU32(
        m7_elemX2E56Export16_callX2Doverwritten(&instance_22),
        66u,
        "WAST line 539: call-overwritten()"
    );
    m7_elemX2E57Instantiate(&instance_23, resolveTestImports);
    printStart("elem.57.wasm");
    assertEqualU32(
        m7_elemX2E57Export24_callX2DoverwrittenX2Delement(&instance_23),
        66u,
        "WAST line 552: call-overwritten-element()"
    );
    m7_elemX2E58Instantiate(&instance_24, resolveTestImports);
    printStart("elem.58.wasm");
    bindTestImport("module1", "shared-table", (void*)m7_elemX2E58Export12_sharedX2Dtable(&instance_24));
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_elemX2E58Export6_callX2D7(&instance_24), "WAST line 576: call-7()");
#endif
    assertEqualU32(
        m7_elemX2E58Export6_callX2D8(&instance_24),
        65u,
        "WAST line 577: call-8()"
    );
    assertEqualU32(
        m7_elemX2E58Export6_callX2D9(&instance_24),
        66u,
        "WAST line 578: call-9()"
    );
    m7_elemX2E59Instantiate(&instance_25, resolveTestImports);
    printStart("elem.59.wasm");
    assertEqualU32(
        m7_elemX2E58Export6_callX2D7(&instance_24),
        67u,
        "WAST line 589: call-7()"
    );
    assertEqualU32(
        m7_elemX2E58Export6_callX2D8(&instance_24),
        68u,
        "WAST line 590: call-8()"
    );
    assertEqualU32(
        m7_elemX2E58Export6_callX2D9(&instance_24),
        66u,
        "WAST line 591: call-9()"
    );
    m7_elemX2E60Instantiate(&instance_26, resolveTestImports);
    printStart("elem.60.wasm");
    assertEqualU32(
        m7_elemX2E58Export6_callX2D7(&instance_24),
        67u,
        "WAST line 602: call-7()"
    );
    assertEqualU32(
        m7_elemX2E58Export6_callX2D8(&instance_24),
        69u,
        "WAST line 603: call-8()"
    );
    assertEqualU32(
        m7_elemX2E58Export6_callX2D9(&instance_24),
        70u,
        "WAST line 604: call-9()"
    );
    m7_elemX2E61Instantiate(&instance_27, resolveTestImports);
    printStart("elem.61.wasm");
    bindTestImport("module4", "f", (void*)m7_elemX2E61Export1_f(&instance_27));
    m7_elemX2E62Instantiate(&instance_28, resolveTestImports);
    printStart("elem.62.wasm");
    assertEqualU32(
        m7_elemX2E62Export18_callX5FimportedX5Felem(&instance_28),
        42u,
        "WAST line 684: call_imported_elem()"
    );
    m7_elemX2E62FreeInstance(&instance_28);
    m7_elemX2E61FreeInstance(&instance_27);
    m7_elemX2E60FreeInstance(&instance_26);
    m7_elemX2E59FreeInstance(&instance_25);
    m7_elemX2E58FreeInstance(&instance_24);
    m7_elemX2E57FreeInstance(&instance_23);
    m7_elemX2E56FreeInstance(&instance_22);
    m7_elemX2E35FreeInstance(&instance_21);
    m7_elemX2E34FreeInstance(&instance_20);
    m7_elemX2E21FreeInstance(&instance_19);
    m7_elemX2E20FreeInstance(&instance_18);
    m7_elemX2E19FreeInstance(&instance_17);
    m7_elemX2E18FreeInstance(&instance_16);
    m7_elemX2E17FreeInstance(&instance_15);
    m7_elemX2E16FreeInstance(&instance_14);
    m7_elemX2E15FreeInstance(&instance_13);
    m7_elemX2E14FreeInstance(&instance_12);
    m7_elemX2E13FreeInstance(&instance_11);
    m7_elemX2E12FreeInstance(&instance_10);
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
