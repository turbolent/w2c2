#include <stdio.h>
#include <setjmp.h>
#include <string.h>
#include <stdlib.h>

static void* tableTestRealloc(void* pointer, size_t size);

#define realloc tableTestRealloc
#include "test_table_owner.h"
#include "test_table_caller.h"
#undef realloc

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL table instances: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

static wasmTable sharedTable;
static wasmExternTable sharedExternTable;
static U32* slot;
static wasmExternRef* object;
static wasmModuleInstance* expectedHostInstance;
static jmp_buf tableTrap;
static bool expectTrap;
static Trap actualTrap;
static bool failAllocation;

static void* tableTestRealloc(void* pointer, size_t size) {
    return failAllocation ? NULL : realloc(pointer, size);
}

typedef struct HostInstance {
    wasmModuleInstance common;
    U32 value;
} HostInstance;

void trap(Trap trap) {
    if (expectTrap) {
        actualTrap = trap;
        longjmp(tableTrap, 1);
    }
    fprintf(stderr, "FAIL table instances: %s\n", trapDescription(trap));
    abort();
}

#define CHECK_TRAP(expression, reason) \
    do { \
        expectTrap = true; \
        if (setjmp(tableTrap) == 0) { \
            (void)(expression); \
            CHECK(false); \
        } \
        expectTrap = false; \
        CHECK(actualTrap == (reason)); \
    } while (0)

static void* resolve(WasmName module, WasmName name) {
    CHECK(module.length == 3 && memcmp(module.data, "env", 3) == 0);
    if (name.length == 4 && memcmp(name.data, "slot", 4) == 0) {
        return slot;
    }
    if (name.length == 6 && memcmp(name.data, "object", 6) == 0) {
        return object;
    }
    if (name.length == 7 && memcmp(name.data, "externs", 7) == 0) {
        return &sharedExternTable;
    }
    CHECK(name.length == 5 && memcmp(name.data, "table", 5) == 0);
    return &sharedTable;
}

U32 m11_tableX5FownerImport3_env4_host(wasmModuleInstance* instance, U32 delta) {
    CHECK(instance == expectedHostInstance);
    return m11_tableX5FownerExport5_state((m11_tableX5FownerInstance*)instance) + delta;
}

struct w2c2_result_ee
m11_tableX5FownerImport3_env8_external(wasmModuleInstance* instance, wasmExternRef value) {
    struct w2c2_result_ee result;
    CHECK(instance == expectedHostInstance);
    result.v0 = value;
    result.v1 = *((m11_tableX5FownerInstance*)instance)->g1;
    return result;
}

static U32 hostWithContext(wasmModuleInstance* instance, U32 delta) {
    HostInstance* host = (HostInstance*)instance;
    CHECK(instance == expectedHostInstance);
    host->value += delta;
    return host->value;
}

#if W2C2_RUNTIME_CHECKS
static void testIndirectTraps(m12_tableX5FcallerInstance* caller) {
    /* Parameter count, result count, parameter type, and result type must match. */
    CHECK_TRAP(m12_tableX5FcallerExport4_call(caller, 2, 0), trapIndirectCallTypeMismatch);
    CHECK_TRAP(m12_tableX5FcallerExport4_call(caller, 3, 0), trapIndirectCallTypeMismatch);
    CHECK_TRAP(m12_tableX5FcallerExport4_call(caller, 5, 0), trapIndirectCallTypeMismatch);
    CHECK_TRAP(m12_tableX5FcallerExport4_call(caller, 6, 0), trapIndirectCallTypeMismatch);
    CHECK_TRAP(m12_tableX5FcallerExport4_read(caller, 11), trapUninitializedElement);
    CHECK_TRAP(m12_tableX5FcallerExport4_call(caller, 11, 0), trapUninitializedElement);
    CHECK_TRAP(m12_tableX5FcallerExport5_write(caller, 11, 0), trapUninitializedElement);
}

#endif

int main(void) {
    m11_tableX5FownerInstance first;
    m11_tableX5FownerInstance second;
    m12_tableX5FcallerInstance caller;
    m12_tableX5FcallerInstance* child;
    U32 offsets[] = {0, 4};
    U32 objects[] = {10, 20, 30};
    wasmExternRef refs[2];
    wasmExternRef* original;
    struct w2c2_result_ee pair;
#if W2C2_RUNTIME_CHECKS
    static const wasmFuncType hostType = {1, "i", 1, "i"};
#endif
    HostInstance host = {0};
    host.value = 40;
    refs[0] = &objects[0];
    refs[1] = &objects[1];
    wasmTableAllocate(&sharedTable, 12, 12);
    wasmExternTableAllocate(&sharedExternTable, 4, 8);
    slot = &offsets[0];
    object = &refs[0];
    m11_tableX5FownerInstantiate(&first, resolve);
    slot = &offsets[1];
    object = &refs[1];
    m11_tableX5FownerInstantiate(&second, resolve);
    m11_tableX5FownerExport4_init(&first, 10, 1);
    m11_tableX5FownerExport4_init(&second, 20, 2);

    /* Both instances import the same table;
     * each entry must keep the instance that installed it. */
    CHECK(m11_tableX5FownerExport4_call(&first, 4, 3) == 23008);
    CHECK(m11_tableX5FownerExport5_state(&first) == 10001);
    CHECK(m11_tableX5FownerExport4_call(&second, 0, 2) == 12005);
    CHECK(m11_tableX5FownerExport4_read(&first, 6) == 23008);
    m11_tableX5FownerExport5_write(&first, 7, 30);
    CHECK(m11_tableX5FownerExport5_state(&second) == 30006);
    expectedHostInstance = &second.common;
    CHECK(m11_tableX5FownerExport4_call(&first, 5, 7) == 30013);

    /* Calls between different module types also preserve globals and memory. */
    m12_tableX5FcallerInstantiate(&caller, NULL);
    CHECK(m12_tableX5FcallerExport4_call(&caller, 0, 1) == 91007);
    caller.t0.data[1] = sharedTable.data[0];
    caller.t0.data[2] = sharedTable.data[2];
    caller.t0.data[3] = sharedTable.data[3];
    caller.t0.data[4] = sharedTable.data[1];
    CHECK(m12_tableX5FcallerExport4_call(&caller, 1, 4) == 16013);
    CHECK(m12_tableX5FcallerExport5_state(&caller) == 91007);
    CHECK(m12_tableX5FcallerExport4_read(&caller, 2) == 16013);
    m12_tableX5FcallerExport5_write(&caller, 3, 50);
    CHECK(m11_tableX5FownerExport5_state(&first) == 50006);
    expectedHostInstance = &first.common;
    CHECK(m12_tableX5FcallerExport4_call(&caller, 4, 9) == 50015);
    sharedTable.data[8] = caller.t0.data[0];
    CHECK(m11_tableX5FownerExport4_call(&second, 8, 2) == 93011);
    CHECK(m11_tableX5FownerExport5_state(&second) == 30006);

    child = (m12_tableX5FcallerInstance*)caller.common.newChild(&caller.common);
    CHECK(m12_tableX5FcallerExport4_call(child, 0, 2) == 92009);
    CHECK(m12_tableX5FcallerExport5_state(&caller) == 93011);
    child->common.freeChild(&child->common);

    /* Hosts may install a callback with its own context. */
    wasmTableSetTyped(&sharedTable, 9, (wasmFunc)hostWithContext, &host.common, &hostType);
    expectedHostInstance = &host.common;
    CHECK(m11_tableX5FownerExport4_call(&first, 9, 2) == 42);
    CHECK(host.value == 42);

    /* Moving a host reference through generated get/set preserves its context. */
    m11_tableX5FownerExport7_setX2Dref(&second, 10, m11_tableX5FownerExport7_getX2Dref(&first, 9));
    CHECK(m11_tableX5FownerExport4_call(&second, 10, 0) == 42);

    /* Passive elements and their dropped state belong to each instance. */
    m11_tableX5FownerExport13_initX2Delements(&first, 8);
    expectedHostInstance = &first.common;
    CHECK(m11_tableX5FownerExport4_call(&second, 9, 0) == 50006);
    m11_tableX5FownerExport13_dropX2Delements(&first);
    m11_tableX5FownerExport13_initX2Delements(&second, 8);
    expectedHostInstance = &second.common;
    CHECK(m11_tableX5FownerExport4_call(&first, 9, 0) == 30006);
#if W2C2_RUNTIME_CHECKS
    CHECK_TRAP(m11_tableX5FownerExport13_initX2Delements(&first, 8), trapTableOutOfBounds);
#endif
    wasmTableSetTyped(&sharedTable, 9, (wasmFunc)hostWithContext, &host.common, &hostType);
    expectedHostInstance = &host.common;

    /* Equivalent types may have different indices within and across modules. */
    CHECK(m12_tableX5FcallerExport10_callX5Falias(&caller, 1, 0) == 50006);
    CHECK(m12_tableX5FcallerExport10_callX5Falias(&caller, 0, 0) == 93011);
#if W2C2_RUNTIME_CHECKS
    testIndirectTraps(&caller);
    CHECK_TRAP(m11_tableX5FownerExport4_read(&first, 9), trapIndirectCallTypeMismatch);
    CHECK(host.value == 42);
    CHECK_TRAP(m11_tableX5FownerExport4_call(&first, 11, 0), trapUninitializedElement);

    CHECK_TRAP(m12_tableX5FcallerExport4_call(&caller, 12, 0), trapTableOutOfBounds);
    CHECK_TRAP(m12_tableX5FcallerExport4_call(&caller, UINT32_MAX, 0), trapTableOutOfBounds);
    CHECK_TRAP(wasmTableSet(&sharedTable, 12, NULL, NULL), trapTableOutOfBounds);
    /* Replacing a typed entry through the legacy setter must clear its type. */
    wasmTableSet(&sharedTable, 9, (wasmFunc)hostWithContext, &host.common);
    CHECK_TRAP(m11_tableX5FownerExport4_call(&first, 9, 0), trapIndirectCallTypeMismatch);
#endif

    /* External references preserve host identity across modules and instances. */
    CHECK(m11_tableX5FownerExport7_externs(&first) == &sharedExternTable);
    CHECK(m11_tableX5FownerExport7_externs(&second) == &sharedExternTable);
    CHECK(m11_tableX5FownerExport5_owned(&first)->data[0] == refs[0]);
    CHECK(m11_tableX5FownerExport5_owned(&second)->data[0] == refs[1]);
    m11_tableX5FownerExport10_setX2Dobject(&first, 0, &objects[2]);
    CHECK(m11_tableX5FownerExport10_getX2Dobject(&second, 0) == &objects[2]);
    original = sharedExternTable.data;
    failAllocation = true;
    CHECK(wasmExternTableGrow(&sharedExternTable, refs[0], 0) == 4);
    CHECK(wasmExternTableGrow(&sharedExternTable, refs[0], 1) == UINT32_MAX);
    CHECK(sharedExternTable.data == original && sharedExternTable.size == 4);
    CHECK(sharedExternTable.data[0] == &objects[2]);
    failAllocation = false;
    m11_tableX5FownerExport12_initX2Dobjects(&first, 0);
    m11_tableX5FownerExport12_dropX2Dobjects(&first);
    m11_tableX5FownerExport12_dropX2Dobjects(&first);
    m11_tableX5FownerExport12_initX2Dobjects(&second, 2);
    CHECK(sharedExternTable.data[0] == refs[0] && sharedExternTable.data[1] == NULL);
    CHECK(sharedExternTable.data[2] == refs[1] && sharedExternTable.data[3] == NULL);
#if W2C2_RUNTIME_CHECKS
    CHECK_TRAP(m11_tableX5FownerExport12_initX2Dobjects(&first, 0), trapTableOutOfBounds);
    CHECK(sharedExternTable.data[0] == refs[0]);
#endif
    expectedHostInstance = &first.common;
    pair = m11_tableX5FownerExport9_hostX2Dpair(&first, &objects[2]);
    CHECK(pair.v0 == &objects[2] && pair.v1 == refs[0]);
    caller.t0.data[8] = m11_tableX5FownerExport8_pairX2Dref(&second);
    pair = m12_tableX5FcallerExport4_pair(&caller, 8, &objects[2]);
    CHECK(pair.v0 == &objects[2] && pair.v1 == refs[1]);
    caller.t0.data[8] = m11_tableX5FownerExport8_hostX2Dref(&first);
    pair = m12_tableX5FcallerExport4_pair(&caller, 8, refs[1]);
    CHECK(pair.v0 == refs[1] && pair.v1 == refs[0]);
    objects[0] = 11;
    CHECK(*(U32*)pair.v1 == 11);

    m12_tableX5FcallerFreeInstance(&caller);
    m11_tableX5FownerFreeInstance(&second);
    m11_tableX5FownerFreeInstance(&first);
    wasmTableFree(&sharedTable);
    CHECK(sharedExternTable.data[0] == refs[0] && sharedExternTable.data[2] == refs[1]);
    wasmExternTableFree(&sharedExternTable);
    CHECK(objects[0] == 11 && objects[1] == 20 && objects[2] == 30);
    fprintf(stderr, "PASS table instances\n");
    return 0;
}
