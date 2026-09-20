#ifndef W2C2_ARRAY_H
#define W2C2_ARRAY_H

#include "w2c2_base.h"
#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Overflow leaves the result unchanged. */
static
W2C2_INLINE
bool
arrayLengthAdd(const size_t length, const size_t extra, size_t* result) {
    MUST (extra <= (size_t)-1 - length)
    *result = length + extra;
    return true;
}

WasmBool
arrayEnsureCapacitySlowPath(
    void** items,
    size_t length,
    size_t* capacity,
    size_t itemSize
);

static
W2C2_INLINE
bool
arrayEnsureCapacity(
    void** items,
    const size_t length,
    size_t* capacity,
    const size_t itemSize
) {
    if (length <= *capacity) {
        return true;
    }
    return arrayEnsureCapacitySlowPath(items, length, capacity, itemSize);
}

#define ARRAY_TYPE(NAME, TYPE, INSTANCE, ITEMS, ITEM)         \
typedef struct NAME {                                         \
    size_t length;                                            \
    size_t capacity;                                          \
    TYPE* ITEMS;                                              \
} NAME;                                                       \
                                                              \
static W2C2_INLINE bool WARN_UNUSED_RESULT                    \
INSTANCE ## EnsureCapacity(                                   \
    NAME* INSTANCE,                                           \
    size_t length                                             \
) {                                                           \
    return arrayEnsureCapacity(                               \
        (void**)&INSTANCE->ITEMS,                             \
        length,                                               \
        &INSTANCE->capacity,                                  \
        sizeof(TYPE)                                          \
    );                                                        \
}                                                             \
                                                              \
static W2C2_INLINE bool WARN_UNUSED_RESULT                    \
INSTANCE ## Append(                                           \
    NAME* INSTANCE,                                           \
    TYPE ITEM                                                 \
) {                                                           \
    const size_t length = INSTANCE->length;                   \
    size_t newLength;                                        \
    MUST (arrayLengthAdd(length, 1, &newLength))              \
    MUST (INSTANCE ## EnsureCapacity(INSTANCE, newLength))    \
                                                              \
    INSTANCE->ITEMS[length] = ITEM;                           \
    INSTANCE->length = newLength;                             \
                                                              \
    return true;                                              \
}                                                             \
                                                              \
static W2C2_INLINE void                                       \
INSTANCE ## Free(NAME* INSTANCE) {                            \
    free(INSTANCE->ITEMS);                                    \
    INSTANCE->ITEMS = NULL;                                   \
    INSTANCE->length = 0;                                     \
    INSTANCE->capacity = 0;                                   \
}


#ifdef __cplusplus
}
#endif

#endif /* W2C2_ARRAY_H */
