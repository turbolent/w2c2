#include <stdlib.h>
#include "labelstack.h"

void
wasmLabelStackFree(WasmLabelStack labelStack) {
    free(labelStack.labels);
}

bool
wasmLabelStackEnsureCapacity(
    WasmLabelStack* labelStack,
    size_t length
) {
    if (length > labelStack->capacity) {
        size_t newCapacity = length + (labelStack->capacity >> 1u);
        void* newLabels = NULL;
        if (labelStack->labels == NULL) {
            newLabels = calloc(newCapacity * sizeof(WasmLabel), 1);
        } else {
            newLabels = realloc(labelStack->labels, newCapacity * sizeof(WasmLabel));
        }
        if (newLabels == NULL) {
            return false;
        }
        labelStack->labels = (WasmLabel*) newLabels;
        labelStack->capacity = newCapacity;
    }
    return true;
}
