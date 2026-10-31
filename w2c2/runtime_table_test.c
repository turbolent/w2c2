#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "runtime_table_test.h"

static
void*
tableTestRealloc(void* pointer, size_t size);

#define W2C2_RUNTIME_CHECKS 1
#define realloc tableTestRealloc
#define trap tableTestTrap
#include "w2c2_base.h"
#undef realloc
#undef trap

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testRuntimeTable: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

static bool failAllocation;
static bool expectTrap;
static jmp_buf trapTarget;
static Trap actualTrap;

static
void*
tableTestRealloc(void* pointer, const size_t size) {
    return failAllocation ? NULL : realloc(pointer, size);
}

void
tableTestTrap(const Trap reason) {
    CHECK(expectTrap);
    actualTrap = reason;
    longjmp(trapTarget, 1);
}

static
void
tableTestFunction(void) {}

static
void
testRuntimeExternTable(void) {
    U32 object = 42;
    wasmExternRef ref = &object;
    wasmExternTable table;
    wasmExternRef* original;
    wasmExternTableAllocate(&table, 1, 4);
    CHECK(wasmExternTableGetRef(&table, 0) == wasmNullExternRef);
    wasmExternTableSetRef(&table, 0, ref);
    original = table.data;
    failAllocation = true;
    CHECK(wasmExternTableGrow(&table, ref, 0) == 1);
    CHECK(wasmExternTableGrow(&table, ref, 1) == UINT32_MAX);
    CHECK(table.size == 1 && table.data == original && table.data[0] == ref);
    failAllocation = false;
    CHECK(wasmExternTableGrow(&table, wasmNullExternRef, 2) == 1);
    CHECK(table.size == 3 && table.data[1] == NULL && table.data[2] == NULL);
    CHECK(wasmExternTableGrow(&table, ref, 1) == 3);
    CHECK(table.data[3] == ref);
    original = table.data;
    CHECK(wasmExternTableGrow(&table, ref, 1) == UINT32_MAX);
    CHECK(wasmExternTableGrow(&table, ref, UINT32_MAX) == UINT32_MAX);
    CHECK(table.size == 4 && table.data == original);
    wasmExternTableCopy(&table, &table, 4, 4, 0);
    wasmExternTableInit(&table, NULL, 0, 4, 0, 0);
    expectTrap = true;
    if (setjmp(trapTarget) == 0) {
        wasmExternTableInit(&table, &ref, 1, 0, 1, 1);
        CHECK(false);
    }
    expectTrap = false;
    CHECK(actualTrap == trapTableOutOfBounds && table.data[0] == ref);
    table.size = UINT32_MAX;
    table.maxSize = UINT32_MAX;
    CHECK(wasmExternTableGrow(&table, ref, 1) == UINT32_MAX);
    CHECK(table.data == original);
    wasmExternTableFree(&table);
    CHECK(table.data == NULL && table.size == 0 && table.maxSize == 0);
    CHECK(object == 42);
    table.maxSize = 4;
    wasmExternTableCopy(&table, &table, 0, 0, 0);
    wasmExternTableInit(&table, NULL, 0, 0, 0, 0);
    wasmExternTableFill(&table, 0, ref, 0);
    wasmExternTableFree(&table);
    CHECK(table.data == NULL && table.size == 0 && table.maxSize == 0);
}

void
testRuntimeTable(void) {
    static const wasmFuncType type = {0, "", 0, ""};
    wasmModuleInstance instance = {0};
    wasmTable table;
    wasmTableEntry ref = wasmFuncRefTyped(tableTestFunction, &instance, &type);
    wasmTableEntry* original;
    wasmTableAllocate(&table, 1, 4);
    wasmTableSetRef(&table, 0, ref);
    original = table.data;
    failAllocation = true;
    CHECK(wasmTableGrow(&table, ref, 0) == 1);
    CHECK(wasmTableGrow(&table, ref, 1) == UINT32_MAX);
    CHECK(table.size == 1 && table.data == original);
    CHECK(table.data[0].func == tableTestFunction && table.data[0].instance == &instance);
    failAllocation = false;
    CHECK(wasmTableGrow(&table, wasmNullFuncRef, 2) == 1);
    CHECK(table.size == 3 && table.data[1].func == NULL && table.data[2].func == NULL);
    CHECK(wasmTableGrow(&table, ref, 1) == 3);
    CHECK(table.data[3].func == ref.func && table.data[3].instance == ref.instance && table.data[3].type == ref.type);
    original = table.data;
    CHECK(wasmTableGrow(&table, ref, 1) == UINT32_MAX);
    CHECK(wasmTableGrow(&table, ref, UINT32_MAX) == UINT32_MAX);
    CHECK(table.size == 4 && table.data == original);
    wasmTableCopy(&table, &table, 4, 4, 0);
    wasmTableInit(&table, NULL, 0, 4, 0, 0);
    expectTrap = true;
    if (setjmp(trapTarget) == 0) {
        wasmTableInit(&table, &ref, 1, 0, 1, 1);
        CHECK(false);
    }
    expectTrap = false;
    CHECK(actualTrap == trapTableOutOfBounds && table.data[0].func == ref.func);
    table.size = UINT32_MAX;
    table.maxSize = UINT32_MAX;
    CHECK(wasmTableGrow(&table, ref, 1) == UINT32_MAX);
    CHECK(table.data == original);
    wasmTableFree(&table);
    CHECK(table.data == NULL && table.size == 0 && table.maxSize == 0);
    table.maxSize = 4;
    wasmTableFree(&table);
    CHECK(table.data == NULL && table.size == 0 && table.maxSize == 0);
    testRuntimeExternTable();
    fprintf(stderr, "PASS testRuntimeTable\n");
}
