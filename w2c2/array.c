#include <assert.h>
#include "array.h"

bool
arrayEnsureCapacitySlowPath(
    void** items,
    const size_t length,
    size_t* capacity,
    const size_t itemSize
) {
    size_t newCapacity = 0;
    void* newItems = NULL;

    assert(length > *capacity);

    newCapacity = length + (*capacity >> 1U);
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
