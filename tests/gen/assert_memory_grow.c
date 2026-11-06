#include "test.h"
#include "test_memory_grow.0.h"
#include "test_memory_grow.1.h"
#include "test_memory_grow.2.h"
#include "test_memory_grow.3.h"
#include "test_memory_grow.4.h"
#include "test_memory_grow.5.h"

static m13_memoryX5FgrowX2E0Instance instance_0;
static m13_memoryX5FgrowX2E1Instance instance_1;
static m13_memoryX5FgrowX2E2Instance instance_2;
static m13_memoryX5FgrowX2E3Instance instance_3;
static m13_memoryX5FgrowX2E4Instance instance_4;
static m13_memoryX5FgrowX2E5Instance instance_5;

void test(void) {
    m13_memoryX5FgrowX2E0Instantiate(&instance_0, resolveTestImports);
    printStart("memory_grow.0.wasm");
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export4_size(&instance_0),
        0u,
        "WAST line 14: size()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FgrowX2E0Export13_storeX5FatX5Fzero(&instance_0), trapMemoryOutOfBounds, "WAST line 15: store_at_zero()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FgrowX2E0Export12_loadX5FatX5Fzero(&instance_0), trapMemoryOutOfBounds, "WAST line 16: load_at_zero()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FgrowX2E0Export18_storeX5FatX5FpageX5Fsize(&instance_0), trapMemoryOutOfBounds, "WAST line 17: store_at_page_size()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FgrowX2E0Export17_loadX5FatX5FpageX5Fsize(&instance_0), trapMemoryOutOfBounds, "WAST line 18: load_at_page_size()");
#endif
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export4_grow(&instance_0, 1u),
        0u,
        "WAST line 19: grow(1u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export4_size(&instance_0),
        1u,
        "WAST line 20: size()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export12_loadX5FatX5Fzero(&instance_0),
        0u,
        "WAST line 21: load_at_zero()"
    );
    (void)(m13_memoryX5FgrowX2E0Export13_storeX5FatX5Fzero(&instance_0));
    printOK("WAST line 22: store_at_zero()");
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export12_loadX5FatX5Fzero(&instance_0),
        2u,
        "WAST line 23: load_at_zero()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FgrowX2E0Export18_storeX5FatX5FpageX5Fsize(&instance_0), trapMemoryOutOfBounds, "WAST line 24: store_at_page_size()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FgrowX2E0Export17_loadX5FatX5FpageX5Fsize(&instance_0), trapMemoryOutOfBounds, "WAST line 25: load_at_page_size()");
#endif
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export4_grow(&instance_0, 4u),
        1u,
        "WAST line 26: grow(4u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export4_size(&instance_0),
        5u,
        "WAST line 27: size()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export12_loadX5FatX5Fzero(&instance_0),
        2u,
        "WAST line 28: load_at_zero()"
    );
    (void)(m13_memoryX5FgrowX2E0Export13_storeX5FatX5Fzero(&instance_0));
    printOK("WAST line 29: store_at_zero()");
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export12_loadX5FatX5Fzero(&instance_0),
        2u,
        "WAST line 30: load_at_zero()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export17_loadX5FatX5FpageX5Fsize(&instance_0),
        0u,
        "WAST line 31: load_at_page_size()"
    );
    (void)(m13_memoryX5FgrowX2E0Export18_storeX5FatX5FpageX5Fsize(&instance_0));
    printOK("WAST line 32: store_at_page_size()");
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export17_loadX5FatX5FpageX5Fsize(&instance_0),
        3u,
        "WAST line 33: load_at_page_size()"
    );
    m13_memoryX5FgrowX2E1Instantiate(&instance_1, resolveTestImports);
    printStart("memory_grow.1.wasm");
    assertEqualU32(
        m13_memoryX5FgrowX2E1Export4_grow(&instance_1, 0u),
        0u,
        "WAST line 41: grow(0u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E1Export4_grow(&instance_1, 1u),
        0u,
        "WAST line 42: grow(1u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E1Export4_grow(&instance_1, 0u),
        1u,
        "WAST line 43: grow(0u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E1Export4_grow(&instance_1, 2u),
        1u,
        "WAST line 44: grow(2u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E1Export4_grow(&instance_1, 800u),
        3u,
        "WAST line 45: grow(800u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E1Export4_grow(&instance_1, 65536u),
        4294967295u,
        "WAST line 46: grow(65536u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E1Export4_grow(&instance_1, 64736u),
        4294967295u,
        "WAST line 47: grow(64736u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E1Export4_grow(&instance_1, 1u),
        803u,
        "WAST line 48: grow(1u)"
    );
    m13_memoryX5FgrowX2E2Instantiate(&instance_2, resolveTestImports);
    printStart("memory_grow.2.wasm");
    assertEqualU32(
        m13_memoryX5FgrowX2E2Export4_grow(&instance_2, 0u),
        0u,
        "WAST line 55: grow(0u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E2Export4_grow(&instance_2, 1u),
        0u,
        "WAST line 56: grow(1u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E2Export4_grow(&instance_2, 1u),
        1u,
        "WAST line 57: grow(1u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E2Export4_grow(&instance_2, 2u),
        2u,
        "WAST line 58: grow(2u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E2Export4_grow(&instance_2, 6u),
        4u,
        "WAST line 59: grow(6u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E2Export4_grow(&instance_2, 0u),
        10u,
        "WAST line 60: grow(0u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E2Export4_grow(&instance_2, 1u),
        4294967295u,
        "WAST line 61: grow(1u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E2Export4_grow(&instance_2, 65536u),
        4294967295u,
        "WAST line 62: grow(65536u)"
    );
    m13_memoryX5FgrowX2E3Instantiate(&instance_3, resolveTestImports);
    printStart("memory_grow.3.wasm");
    assertEqualU32(
        m13_memoryX5FgrowX2E3Export17_checkX2DmemoryX2Dzero(&instance_3, 0u, 65535u),
        0u,
        "WAST line 87: check-memory-zero(0u, 65535u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E3Export4_grow(&instance_3, 1u),
        1u,
        "WAST line 88: grow(1u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E3Export17_checkX2DmemoryX2Dzero(&instance_3, 65536u, 131071u),
        0u,
        "WAST line 89: check-memory-zero(65536u, 131071u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E3Export4_grow(&instance_3, 1u),
        2u,
        "WAST line 90: grow(1u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E3Export17_checkX2DmemoryX2Dzero(&instance_3, 131072u, 196607u),
        0u,
        "WAST line 91: check-memory-zero(131072u, 196607u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E3Export4_grow(&instance_3, 1u),
        3u,
        "WAST line 92: grow(1u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E3Export17_checkX2DmemoryX2Dzero(&instance_3, 196608u, 262143u),
        0u,
        "WAST line 93: check-memory-zero(196608u, 262143u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E3Export4_grow(&instance_3, 1u),
        4u,
        "WAST line 94: grow(1u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E3Export17_checkX2DmemoryX2Dzero(&instance_3, 262144u, 327679u),
        0u,
        "WAST line 95: check-memory-zero(262144u, 327679u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E3Export4_grow(&instance_3, 1u),
        5u,
        "WAST line 96: grow(1u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E3Export17_checkX2DmemoryX2Dzero(&instance_3, 327680u, 393215u),
        0u,
        "WAST line 97: check-memory-zero(327680u, 393215u)"
    );
    m13_memoryX5FgrowX2E4Instantiate(&instance_4, resolveTestImports);
    printStart("memory_grow.4.wasm");
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export11_asX2DbrX2Dvalue(&instance_4),
        1u,
        "WAST line 259: as-br-value()"
    );
    (void)(m13_memoryX5FgrowX2E4Export13_asX2DbrX5FifX2Dcond(&instance_4));
    printOK("WAST line 261: as-br_if-cond()");
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export14_asX2DbrX5FifX2Dvalue(&instance_4),
        1u,
        "WAST line 262: as-br_if-value()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export19_asX2DbrX5FifX2DvalueX2Dcond(&instance_4),
        6u,
        "WAST line 263: as-br_if-value-cond()"
    );
    (void)(m13_memoryX5FgrowX2E4Export17_asX2DbrX5FtableX2Dindex(&instance_4));
    printOK("WAST line 265: as-br_table-index()");
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export17_asX2DbrX5FtableX2Dvalue(&instance_4),
        1u,
        "WAST line 266: as-br_table-value()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export23_asX2DbrX5FtableX2DvalueX2Dindex(&instance_4),
        6u,
        "WAST line 267: as-br_table-value-index()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export15_asX2DreturnX2Dvalue(&instance_4),
        1u,
        "WAST line 269: as-return-value()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export10_asX2DifX2Dcond(&instance_4),
        0u,
        "WAST line 271: as-if-cond()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export10_asX2DifX2Dthen(&instance_4),
        1u,
        "WAST line 272: as-if-then()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export10_asX2DifX2Delse(&instance_4),
        1u,
        "WAST line 273: as-if-else()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export15_asX2DselectX2Dfirst(&instance_4, 0u, 1u),
        1u,
        "WAST line 275: as-select-first(0u, 1u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export16_asX2DselectX2Dsecond(&instance_4, 0u, 0u),
        1u,
        "WAST line 276: as-select-second(0u, 0u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export14_asX2DselectX2Dcond(&instance_4),
        0u,
        "WAST line 277: as-select-cond()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export13_asX2DcallX2Dfirst(&instance_4),
        4294967295u,
        "WAST line 279: as-call-first()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export11_asX2DcallX2Dmid(&instance_4),
        4294967295u,
        "WAST line 280: as-call-mid()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export12_asX2DcallX2Dlast(&instance_4),
        4294967295u,
        "WAST line 281: as-call-last()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export22_asX2DcallX5FindirectX2Dfirst(&instance_4),
        4294967295u,
        "WAST line 283: as-call_indirect-first()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export20_asX2DcallX5FindirectX2Dmid(&instance_4),
        4294967295u,
        "WAST line 284: as-call_indirect-mid()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export21_asX2DcallX5FindirectX2Dlast(&instance_4),
        4294967295u,
        "WAST line 285: as-call_indirect-last()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FgrowX2E4Export22_asX2DcallX5FindirectX2Dindex(&instance_4), trapTableOutOfBounds, "WAST line 286: as-call_indirect-index()");
#endif
    (void)(m13_memoryX5FgrowX2E4Export18_asX2DlocalX2EsetX2Dvalue(&instance_4));
    printOK("WAST line 288: as-local.set-value()");
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export18_asX2DlocalX2EteeX2Dvalue(&instance_4),
        1u,
        "WAST line 289: as-local.tee-value()"
    );
    (void)(m13_memoryX5FgrowX2E4Export19_asX2DglobalX2EsetX2Dvalue(&instance_4));
    printOK("WAST line 290: as-global.set-value()");
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export15_asX2DloadX2Daddress(&instance_4),
        0u,
        "WAST line 292: as-load-address()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export16_asX2DloadNX2Daddress(&instance_4),
        0u,
        "WAST line 293: as-loadN-address()"
    );
    (void)(m13_memoryX5FgrowX2E4Export16_asX2DstoreX2Daddress(&instance_4));
    printOK("WAST line 294: as-store-address()");
    (void)(m13_memoryX5FgrowX2E4Export14_asX2DstoreX2Dvalue(&instance_4));
    printOK("WAST line 295: as-store-value()");
    (void)(m13_memoryX5FgrowX2E4Export17_asX2DstoreNX2Daddress(&instance_4));
    printOK("WAST line 296: as-storeN-address()");
    (void)(m13_memoryX5FgrowX2E4Export15_asX2DstoreNX2Dvalue(&instance_4));
    printOK("WAST line 297: as-storeN-value()");
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export16_asX2DunaryX2Doperand(&instance_4),
        31u,
        "WAST line 299: as-unary-operand()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export14_asX2DbinaryX2Dleft(&instance_4),
        11u,
        "WAST line 301: as-binary-left()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export15_asX2DbinaryX2Dright(&instance_4),
        9u,
        "WAST line 302: as-binary-right()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export15_asX2DtestX2Doperand(&instance_4),
        0u,
        "WAST line 304: as-test-operand()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export15_asX2DcompareX2Dleft(&instance_4),
        1u,
        "WAST line 306: as-compare-left()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export16_asX2DcompareX2Dright(&instance_4),
        1u,
        "WAST line 307: as-compare-right()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E4Export19_asX2DmemoryX2EgrowX2Dsize(&instance_4),
        1u,
        "WAST line 309: as-memory.grow-size()"
    );
    m13_memoryX5FgrowX2E5Instantiate(&instance_5, resolveTestImports);
    printStart("memory_grow.5.wasm");
    bindTestImport("grown-memory", "memory", (void*)m13_memoryX5FgrowX2E5Export6_memory(&instance_5));
    assertEqualU32(
        m13_memoryX5FgrowX2E5Export4_grow(&instance_5),
        1u,
        "WAST line 317: grow()"
    );
    m13_memoryX5FgrowX2E5FreeInstance(&instance_5);
    m13_memoryX5FgrowX2E4FreeInstance(&instance_4);
    m13_memoryX5FgrowX2E3FreeInstance(&instance_3);
    m13_memoryX5FgrowX2E2FreeInstance(&instance_2);
    m13_memoryX5FgrowX2E1FreeInstance(&instance_1);
    m13_memoryX5FgrowX2E0FreeInstance(&instance_0);
}
