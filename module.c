#include <stdlib.h>
#include "module.h"

bool
WARN_UNUSED_RESULT
wasmDebugSectionsEnsureCapacity(
    WasmDebugSections* debugSections,
    size_t count
) {
    if (count > debugSections->capacity) {
        size_t newCapacity = count + (debugSections->capacity >> 1u);
        void* newDebugSections = NULL;
        if (debugSections->debugSections == NULL) {
            newDebugSections = calloc(newCapacity * sizeof(WasmDebugSection), 1);
        } else {
            newDebugSections = realloc(debugSections->debugSections, newCapacity * sizeof(WasmDebugSection));
        }
        MUST (newDebugSections != NULL)
        debugSections->debugSections = (WasmDebugSection*) newDebugSections;
        debugSections->capacity = newCapacity;
    }
    return true;
}
