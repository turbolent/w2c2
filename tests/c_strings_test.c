#include <stdio.h>
#include <string.h>

#include "test_c_strings.h"

#define SUFFIX "\"\\\n\r\t\b\f\0017AF\177\303\251\?" "\?/end\\"

static wasmMemory* importedMemory;
static wasmTable importedTable;
static U32 importedGlobal = 42;
static unsigned int imports[3];

static
void
expect(bool condition, const char* description) {
    if (!condition) {
        fprintf(stderr, "FAIL C strings: %s\n", description);
        abort();
    }
}

void
trap(Trap trap) {
    fprintf(stderr, "FAIL C strings: %s\n", trapDescription(trap));
    abort();
}

static
void*
resolve(WasmName module, WasmName name) {
    expect(module.length == sizeof("module" SUFFIX) - 1
        && memcmp(module.data, "module" SUFFIX, module.length) == 0, "import module bytes");
    if (name.length == sizeof("memory" SUFFIX) - 1
        && memcmp(name.data, "memory" SUFFIX, name.length) == 0) {
        imports[0]++;
        return importedMemory;
    }
    if (name.length == sizeof("table" SUFFIX) - 1
        && memcmp(name.data, "table" SUFFIX, name.length) == 0) {
        imports[1]++;
        return &importedTable;
    }
    if (name.length == sizeof("global" SUFFIX) - 1
        && memcmp(name.data, "global" SUFFIX, name.length) == 0) {
        imports[2]++;
        return &importedGlobal;
    }
    expect(false, "import name bytes");
    return NULL;
}

int
main(void) {
    static const char* names[] = {"", "ordinary", "export" SUFFIX};
    m9_cX5FstringsInstance instance;
    size_t index;
    importedMemory = wasmMemoryAllocate(1, 1, false);
    wasmTableAllocate(&importedTable, 1, 1);
    m9_cX5FstringsInstantiate(&instance, resolve);
    for (index = 0; index < 3; index++) {
        const wasmFuncExport export = instance.common.funcExports[index];
        expect(imports[index] == 1, "import resolution count");
        expect(export.name.length == strlen(names[index]), "export name length");
        expect(memcmp(export.name.data, names[index], export.name.length) == 0, "export name bytes");
        expect(((U32 (*)(m9_cX5FstringsInstance*))export.func)(&instance) == 42, "export call");
    }
    expect(instance.common.funcExports[3].name.data == NULL, "export terminator");
    m9_cX5FstringsFreeInstance(&instance);
    wasmTableFree(&importedTable);
    wasmMemoryFree(importedMemory);
    fprintf(stderr, "PASS C strings\n");
    return 0;
}
