#include <stdlib.h>
#include "typestack.h"

void
wasmTypeStackFree(WasmTypeStack typeStack) {
    free(typeStack.valueTypes);
}

bool
wasmTypeStackEnsureCapacity(
    WasmTypeStack* typeStack,
    size_t length
) {
    if (length > typeStack->capacity) {
        size_t newCapacity = length + (typeStack->capacity >> 1u);
        void* newValueTypes = NULL;
        if (typeStack->valueTypes == NULL) {
            newValueTypes = calloc(newCapacity * sizeof(WasmValueType), 1);
        } else {
            newValueTypes = realloc(typeStack->valueTypes, newCapacity * sizeof(WasmValueType));
        }
        MUST (newValueTypes != NULL)
        typeStack->valueTypes = (WasmValueType*) newValueTypes;
        typeStack->capacity = newCapacity;
    }
    return true;
}
