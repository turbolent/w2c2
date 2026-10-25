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
    WasmName module,
    WasmName name
) {
    expect(module.length == sizeof("spectest") - 1
        && memcmp(module.data, "spectest", module.length) == 0, "unexpected import module");

    if (name.length == sizeof("shared_memory") - 1
        && memcmp(name.data, "shared_memory", name.length) == 0) {
        return importedMemory;
    }
    if (name.length == sizeof("table") - 1
        && memcmp(name.data, "table", name.length) == 0) {
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
    m19_runtimeX5FlifecycleX2E0Instance root;
    m19_runtimeX5FlifecycleX2E0Instance* child;

    m19_runtimeX5FlifecycleX2E0Instantiate(&root, NULL);
    child = (m19_runtimeX5FlifecycleX2E0Instance*)root.common.newChild(
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

    m19_runtimeX5FlifecycleX2E0FreeInstance(&root);
    m19_runtimeX5FlifecycleX2E0FreeInstance(&root);
}

static
void
testSharedMemoryInstanceLifecycle(void) {
    m19_runtimeX5FlifecycleX2E1Instance root;
    m19_runtimeX5FlifecycleX2E1Instance* child;

    m19_runtimeX5FlifecycleX2E1Instantiate(&root, NULL);
    child = (m19_runtimeX5FlifecycleX2E1Instance*)root.common.newChild(
        (wasmModuleInstance*)&root
    );

    expect(child->m0 == root.m0, "child did not borrow shared memory");
    child->common.freeChild((wasmModuleInstance*)child);
    root.m0->data[0] = 1;

    m19_runtimeX5FlifecycleX2E1FreeInstance(&root);
    m19_runtimeX5FlifecycleX2E1FreeInstance(&root);
}

static
void
testImportedResourceLifecycle(void) {
    m19_runtimeX5FlifecycleX2E2Instance root;
    m19_runtimeX5FlifecycleX2E2Instance* child;
    wasmTable table;

    importedMemory = wasmMemoryAllocate(1, 2, true);
    memset(importedMemory->data, 0xA5, 32);
    wasmTableAllocate(&table, 10, 20);
    importedTable = &table;

    m19_runtimeX5FlifecycleX2E2Instantiate(&root, resolveRuntimeImports);
    expect(
        memcmp(importedMemory->data + 12, "data", 4) == 0,
        "active segment did not initialize imported memory"
    );
    expect(
        importedMemory->data[11] == 0xA5 && importedMemory->data[16] == 0xA5,
        "active segment changed surrounding imported memory"
    );
    importedMemory->data[12] = 0;
    child = (m19_runtimeX5FlifecycleX2E2Instance*)root.common.newChild(
        (wasmModuleInstance*)&root
    );
    expect(
        child->m0 == importedMemory,
        "child did not borrow imported memory"
    );
    expect(
        memcmp(importedMemory->data + 12, "data", 4) == 0,
        "child did not initialize its active segment"
    );
    expect(
        child->t0 == importedTable,
        "child did not borrow imported table"
    );
    child->common.freeChild((wasmModuleInstance*)child);
    m19_runtimeX5FlifecycleX2E2FreeInstance(&root);
    m19_runtimeX5FlifecycleX2E2FreeInstance(&root);

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
