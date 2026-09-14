#include <stdio.h>
#include <string.h>

#include "w2c2_base.h"
#include "test_runtime_lifecycle_owned.h"
#include "test_runtime_lifecycle_shared.h"
#include "test_runtime_lifecycle_imports.h"

static wasmMemory* importedMemory = NULL;
static wasmTable* importedTable = NULL;

void
trap(
    Trap trap
) {
    fprintf(stderr, "FAIL runtime lifecycle: %s\n", trapDescription(trap));
    abort();
}

static
void
expect(
    bool condition,
    const char* description
) {
    if (!condition) {
        fprintf(stderr, "FAIL runtime lifecycle: %s\n", description);
        abort();
    }
}

static
void*
resolveRuntimeImports(
    const char* module,
    const char* name
) {
    expect(strcmp(module, "spectest") == 0, "unexpected import module");

    if (strcmp(name, "shared_memory") == 0) {
        return importedMemory;
    }
    if (strcmp(name, "table") == 0) {
        return importedTable;
    }

    expect(false, "unexpected import name");
    return NULL;
}

static
void
testMemoryLifecycle(void) {
    wasmMemory* memory = wasmMemoryAllocate(1, 2, false);

    expect(memory->data != NULL, "memory data was not allocated");
    wasmMemoryFree(memory);
    wasmMemoryFree(NULL);
}

static
void
testTableLifecycle(void) {
    wasmTable table;

    wasmTableAllocate(&table, 2, 4);
    expect(table.data != NULL, "table data was not allocated");
    wasmTableFree(&table);
    expect(table.data == NULL, "table data was not cleared");
    expect(table.size == 0, "table size was not cleared");
    expect(table.maxSize == 0, "table maximum size was not cleared");
    wasmTableFree(&table);
}

static
void
testOwnedInstanceLifecycle(void) {
    runtimelifecycle0Instance root;
    runtimelifecycle0Instance* child;

    runtimelifecycle0Instantiate(&root, NULL);
    child = (runtimelifecycle0Instance*)root.common.newChild(
        (wasmModuleInstance*)&root
    );

    expect(
        child->m0 != root.m0,
        "child memory was not independently allocated"
    );
    expect(
        child->t0.data != root.t0.data,
        "child table was not independently allocated"
    );
    child->common.freeChild((wasmModuleInstance*)child);
    root.m0->data[0] = 1;
    expect(root.t0.data != NULL, "child destruction released the root table");

    runtimelifecycle0FreeInstance(&root);
    runtimelifecycle0FreeInstance(&root);
}

static
void
testSharedMemoryInstanceLifecycle(void) {
    runtimelifecycle1Instance root;
    runtimelifecycle1Instance* child;

    runtimelifecycle1Instantiate(&root, NULL);
    child = (runtimelifecycle1Instance*)root.common.newChild(
        (wasmModuleInstance*)&root
    );

    expect(child->m0 == root.m0, "child did not borrow shared memory");
    child->common.freeChild((wasmModuleInstance*)child);
    root.m0->data[0] = 1;

    runtimelifecycle1FreeInstance(&root);
    runtimelifecycle1FreeInstance(&root);
}

static
void
testImportedResourceLifecycle(void) {
    runtimelifecycle2Instance root;
    runtimelifecycle2Instance* child;
    wasmTable table;

    importedMemory = wasmMemoryAllocate(1, 2, true);
    wasmTableAllocate(&table, 10, 20);
    importedTable = &table;

    runtimelifecycle2Instantiate(&root, resolveRuntimeImports);
    child = (runtimelifecycle2Instance*)root.common.newChild(
        (wasmModuleInstance*)&root
    );
    expect(
        child->spectest__shared_memory == importedMemory,
        "child did not borrow imported memory"
    );
    expect(
        child->spectest__table == importedTable,
        "child did not borrow imported table"
    );
    child->common.freeChild((wasmModuleInstance*)child);
    runtimelifecycle2FreeInstance(&root);
    runtimelifecycle2FreeInstance(&root);

    importedMemory->data[0] = 1;
    expect(
        importedTable->data != NULL,
        "instance destruction released an imported table"
    );

    wasmMemoryFree(importedMemory);
    wasmTableFree(importedTable);
    importedMemory = NULL;
    importedTable = NULL;
}

static
void*
testRuntimeLifecycle(
    void* argument
) {
    UNUSED_PARAMETER(argument);

    testMemoryLifecycle();
    testTableLifecycle();
    testOwnedInstanceLifecycle();
    testSharedMemoryInstanceLifecycle();
    testImportedResourceLifecycle();
    return NULL;
}

int
main(void) {
    WASM_THREAD_TYPE thread;

    if (!WASM_THREAD_CREATE(&thread, testRuntimeLifecycle, NULL)) {
        fprintf(stderr, "FAIL runtime lifecycle: failed to create worker thread\n");
        return 1;
    }
    WASM_THREAD_JOIN(thread);

    fprintf(stderr, "PASS runtime lifecycle\n");
    return 0;
}
