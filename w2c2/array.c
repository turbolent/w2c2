#include <assert.h>
#include "array.h"

WasmBool
arrayEnsureCapacitySlowPath(
    void** items,
    const size_t length,
    size_t* capacity,
    const size_t itemSize
) {
    const size_t maxCapacity = (size_t)-1 / itemSize;
    const size_t extra = *capacity >> 1U;
    size_t newCapacity = length;
    void* newItems = NULL;

    assert(length > *capacity);

    MUST (length <= maxCapacity)
    /* Omit spare capacity when only the requested length is representable. */
    if (extra <= maxCapacity - length) {
        newCapacity += extra;
    }
    if (*items == NULL) {
        newItems = calloc(newCapacity, itemSize);
    } else {
        newItems = realloc(*items, newCapacity * itemSize);
    }
    if (newItems == NULL) {
        return false;
    }

    *items = newItems;
    *capacity = newCapacity;

    return true;
}
