#include <stdio.h>
#include <string.h>

#include "test_binary_names.h"

static U32 globals[] = {11, 22, 33};
static unsigned int imports[5];
static wasmMemory* memory;
static wasmTable table;

static
void
expect(bool condition, const char* description) {
    if (!condition) {
        fprintf(stderr, "FAIL binary names: %s\n", description);
        abort();
    }
}

void
trap(Trap trap) {
    fprintf(stderr, "FAIL binary names: %s\n", trapDescription(trap));
    abort();
}

U32
i5_envX00a10_functionX00a(wasmModuleInstance* instance) {
    (void)instance;
    return 44;
}

U32
i5_envX00a10_functionX00b(wasmModuleInstance* instance) {
    (void)instance;
    return 55;
}

static
void*
resolve(WasmName module, WasmName name) {
    expect(module.length >= 7 && memcmp(module.data, "module\0", 7) == 0, "module prefix");
    if (module.length == 8 && name.length == 8 && memcmp(name.data, "global\0", 7) == 0) {
        size_t index;
        if (module.data[7] == 'a' && name.data[7] == 'a') {
            index = 0;
        } else if (module.data[7] == 'b' && name.data[7] == 'a') {
            index = 1;
        } else {
            expect(module.data[7] == 'b' && name.data[7] == 'b', "global suffix");
            index = 2;
        }
        imports[index]++;
        return &globals[index];
    }
    if (module.length == 7 && name.length == 7 && memcmp(name.data, "memory\0", 7) == 0) {
        imports[3]++;
        return memory;
    }
    if (module.length == 7 && name.length == 6 && memcmp(name.data, "table\0", 6) == 0) {
        imports[4]++;
        return &table;
    }
    expect(false, "unexpected import name");
    return NULL;
}

int
main(void) {
    static const struct {
        const char* name;
        size_t length;
        U32 value;
    } expected[] = {
        {"value", 5, 11}, {"value\0", 6, 22}, {"value\0a", 7, 33},
        {"value\0b", 7, 44}, {"\0", 1, 55}
    };
    m12_binaryX5FnamesInstance instance;
    wasmModuleInstance* child;
    size_t index;
    memory = wasmMemoryAllocate(1, 1, false);
    wasmTableAllocate(&table, 1, 1);
    m12_binaryX5FnamesInstantiate(&instance, resolve);
    child = instance.common.newChild(&instance.common);
    for (index = 0; index < sizeof(expected) / sizeof(expected[0]); index++) {
        const wasmFuncExport functionExport = instance.common.funcExports[index];
        expect(imports[index] == 2, "root and child import resolution");
        expect(functionExport.name.length == expected[index].length, "export length");
        expect(memcmp(functionExport.name.data, expected[index].name, functionExport.name.length) == 0, "export bytes");
        expect(((U32 (*)(wasmModuleInstance*))functionExport.func)(&instance.common) == expected[index].value,
            "export target");
    }
    expect(instance.common.funcExports[index].name.data == NULL, "export terminator");
    child->freeChild(child);
    m12_binaryX5FnamesFreeInstance(&instance);
    wasmTableFree(&table);
    wasmMemoryFree(memory);
    fprintf(stderr, "PASS binary names\n");
    return 0;
}
