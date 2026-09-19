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
resolve(const char* module, const char* name) {
    expect(strcmp(module, "module" SUFFIX) == 0, "import module bytes");
    if (strcmp(name, "memory" SUFFIX) == 0) {
        imports[0]++;
        return importedMemory;
    }
    if (strcmp(name, "table" SUFFIX) == 0) {
        imports[1]++;
        return &importedTable;
    }
    if (strcmp(name, "global" SUFFIX) == 0) {
        imports[2]++;
        return &importedGlobal;
    }
    expect(false, "import name bytes");
    return NULL;
}

int
main(void) {
    static const char* names[] = {"", "ordinary", "export" SUFFIX};
    cstringsInstance instance;
    size_t index;
    importedMemory = wasmMemoryAllocate(1, 1, false);
    wasmTableAllocate(&importedTable, 1, 1);
    cstringsInstantiate(&instance, resolve);
    for (index = 0; index < 3; index++) {
        const wasmFuncExport export = instance.common.funcExports[index];
        expect(imports[index] == 1, "import resolution count");
        expect(strcmp(export.name, names[index]) == 0, "export name bytes");
        expect(((U32 (*)(cstringsInstance*))export.func)(&instance) == 42, "export call");
    }
    expect(instance.common.funcExports[3].name == NULL, "export terminator");
    cstringsFreeInstance(&instance);
    wasmTableFree(&importedTable);
    wasmMemoryFree(importedMemory);
    fprintf(stderr, "PASS C strings\n");
    return 0;
}
