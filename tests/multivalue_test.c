#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#include "test_multivalue_owner.h"
#include "test_multivalue_caller.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL multi-value: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

static m16_multivalueX5FownerInstance owner;
static m17_multivalueX5FcallerInstance caller;
static wasmTable table;
static U32 calls;
static jmp_buf trapTarget;
static bool expectingTrap;

void trap(Trap reason) {
    CHECK(expectingTrap && reason == trapIndirectCallTypeMismatch);
    longjmp(trapTarget, 1);
}

static void* resolve(WasmName module, WasmName name) {
    CHECK(module.length == 3 && memcmp(module.data, "env", 3) == 0);
    CHECK(name.length == 5 && memcmp(name.data, "table", 5) == 0);
    return &table;
}

struct w2c2_result_ijfd m16_multivalueX5FownerImport3_env4_host(wasmModuleInstance* instance, U32 value) {
    struct w2c2_result_ijfd result;
    CHECK(instance == &owner.common);
    calls++;
    result.v0 = value;
    result.v1 = 20;
    result.v2 = f32_reinterpret_i32(0x80000000u);
    result.v3 = 1.5;
    return result;
}

struct w2c2_result_ijfd m17_multivalueX5FcallerImport5_owner5_value(wasmModuleInstance* instance, U32 value) {
    CHECK(instance == &caller.common);
    return m16_multivalueX5FownerExport5_value(&owner, value);
}

static void check(struct w2c2_result_ijfd result, U32 first) {
    CHECK(result.v0 == first);
    CHECK(result.v1 == 20);
    CHECK(i32_reinterpret_f32(result.v2) == 0x80000000u);
    CHECK(result.v3 == 1.5);
}

int main(void) {
    struct w2c2_result_ijfd result;
#if W2C2_RUNTIME_CHECKS
    static const wasmFuncType mismatches[] = {
        {1, "i", 4, "ijfj"}, /* Last result type. */
        {1, "i", 4, "jifd"}, /* Result order. */
        {1, "i", 3, "ijf"},  /* Result count. */
        {1, "j", 4, "ijfd"}, /* Parameter type. */
        {0, "", 4, "ijfd"}   /* Parameter count. */
    };
    U32 index;
#endif
    wasmTableAllocate(&table, 8, 8);
    m16_multivalueX5FownerInstantiate(&owner, resolve);
    m17_multivalueX5FcallerInstantiate(&caller, resolve);
    result = m16_multivalueX5FownerExport5_value(&owner, 1);
    check(result, 11);
    result = m17_multivalueX5FcallerExport6_direct(&caller, 2);
    check(result, 13);
    result = m17_multivalueX5FcallerExport8_indirect(&caller, 0, 3);
    check(result, 16);
    check(m16_multivalueX5FownerExport4_host(&owner, 41), 41);
    CHECK(calls == 1);
    check(m17_multivalueX5FcallerExport8_indirect(&caller, 1, 42), 42);
    CHECK(calls == 2);
    check(m16_multivalueX5FownerExport8_imported(&owner, 43), 43);
    CHECK(calls == 3);
#if W2C2_RUNTIME_CHECKS
    for (index = 0; index < sizeof(mismatches) / sizeof(mismatches[0]); index++) {
        wasmTableSetTyped(&table, 2, (wasmFunc)m16_multivalueX5FownerImport3_env4_host,
            &owner.common, &mismatches[index]);
        expectingTrap = true;
        if (setjmp(trapTarget) == 0) {
            (void)m17_multivalueX5FcallerExport8_indirect(&caller, 2, 0);
            CHECK(false);
        }
        expectingTrap = false;
    }
    CHECK(calls == 3);
#endif
    m17_multivalueX5FcallerFreeInstance(&caller);
    m16_multivalueX5FownerFreeInstance(&owner);
    wasmTableFree(&table);
    fprintf(stderr, "PASS multi-value\n");
    return 0;
}
