#include <stdio.h>
#include "w2c2_base.h"
#include "allocation_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testAllocations: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

static bool failAllocations;
static size_t allocationCalls;
static size_t allocationBytes;

static void* testCalloc(size_t count, size_t size) {
    CHECK(size != 0 && count <= (size_t)-1 / size);
    allocationCalls++;
    allocationBytes = count * size;
    return failAllocations ? NULL : calloc(count, size);
}

static void* testRealloc(void* items, size_t size) {
    CHECK(size != 0);
    allocationCalls++;
    allocationBytes = size;
    return failAllocations ? NULL : realloc(items, size);
}

/*
 * Exercise allocation limits with local fault injection,
 * without requesting large allocations or adding production hooks.
 */
#define calloc testCalloc
#define realloc testRealloc
#define arrayEnsureCapacitySlowPath testArrayEnsureCapacitySlowPath
#include "array.c"
#undef arrayEnsureCapacitySlowPath
#undef calloc
#undef realloc

#include "typestack.h"

ARRAY_TYPE(AllocationValues, U32, allocationValues, values, value)

static void testLengthAddition(void) {
    const size_t maximum = (size_t)-1;
    size_t length = 42;
    CHECK(!arrayLengthAdd(maximum, 1, &length) && length == 42);
    CHECK(!arrayLengthAdd(1, maximum, &length) && length == 42);
    CHECK(arrayLengthAdd(maximum - 1, 1, &length) && length == maximum);
    CHECK(arrayLengthAdd(0, maximum, &length) && length == maximum);
    CHECK(arrayLengthAdd(maximum, 0, &length) && length == maximum);
    CHECK(arrayLengthAdd(0, 0, &length) && length == 0);
    if ((U64)maximum > UINT32_MAX) {
        CHECK(arrayLengthAdd(UINT32_MAX, 1, &length));
        CHECK((U64)length == (U64)UINT32_MAX + 1);
    } else {
        CHECK(!arrayLengthAdd(UINT32_MAX, 1, &length) && length == 0);
    }
}

static void testArrayGrowth(void) {
    AllocationValues array = {0, 0, NULL};
    size_t index;
    size_t calls;
    U32* previous;
    size_t capacity;

    failAllocations = false;
    for (index = 0; index < 256; index++) {
        CHECK(allocationValuesAppend(&array, (U32)index));
    }
    while (array.length < array.capacity) {
        CHECK(allocationValuesAppend(&array, (U32)array.length));
    }
    capacity = array.capacity;
    previous = array.values;
    calls = allocationCalls;
    CHECK(allocationValuesEnsureCapacity(&array, capacity));
    CHECK(allocationCalls == calls && array.values == previous);

    failAllocations = true;
    CHECK(!allocationValuesAppend(&array, (U32)array.length));
    CHECK(array.values == previous && array.capacity == capacity && array.length == capacity);
    CHECK(allocationCalls == calls + 1);
    for (index = 0; index < array.length; index++) {
        CHECK(array.values[index] == (U32)index);
    }

    failAllocations = false;
    CHECK(allocationValuesAppend(&array, (U32)array.length));
    CHECK(array.length == capacity + 1 && array.values[capacity] == (U32)capacity);
    allocationValuesFree(&array);
    CHECK(array.values == NULL && array.capacity == 0 && array.length == 0);
}

static void checkArrayFailure(
    size_t length, size_t capacity, size_t itemSize, size_t expectedBytes
) {
    U8 saved = 42;
    void* items = capacity == 0 ? NULL : &saved;
    void* previous = items;
    const size_t previousCapacity = capacity;
    failAllocations = true;
    allocationCalls = 0;
    allocationBytes = 0;
    CHECK(!arrayEnsureCapacity(&items, length, &capacity, itemSize));
    CHECK(allocationCalls == (expectedBytes == 0 ? 0 : 1));
    CHECK(allocationBytes == expectedBytes);
    CHECK(items == previous && capacity == previousCapacity && saved == 42);
}

static void testArrayLimits(void) {
    const size_t maximum = (size_t)-1;
    const size_t itemSize = sizeof(U32);
    const size_t maximumCount = maximum / itemSize;
    U32 saved = 42;
    AllocationValues array;

    checkArrayFailure(4, 0, itemSize, 4 * itemSize);
    checkArrayFailure(5, 4, itemSize, 7 * itemSize);
    checkArrayFailure(maximumCount + 1, 4, itemSize, 0);
    checkArrayFailure(maximumCount + 1, 0, itemSize, 0);
    checkArrayFailure(maximumCount, 4, itemSize, maximumCount * itemSize);
    checkArrayFailure(maximumCount - 1, 4, itemSize, (maximumCount - 1) * itemSize);
    checkArrayFailure(maximum, maximum - 1, 1, maximum);

    array.values = &saved;
    array.length = maximum;
    array.capacity = maximum;
    allocationCalls = 0;
    CHECK(!allocationValuesAppend(&array, 99));
    CHECK(array.values == &saved && array.length == maximum && array.capacity == maximum);
    CHECK(allocationCalls == 0 && saved == 42);

    array.length = maximumCount;
    array.capacity = maximumCount;
    CHECK(!allocationValuesAppend(&array, 99));
    CHECK(array.values == &saved && array.length == maximumCount && array.capacity == maximumCount);
    CHECK(allocationCalls == 0 && saved == 42);
}

static void testTypeStackAllocation(void) {
    WasmValueType saved = (WasmValueType)(1 << wasmValueTypeI32);
    WasmTypeStack stack = {1, 1, NULL};
    const U64 length = (U64)UINT32_MAX + 1;
    stack.valueTypes = &saved;
    failAllocations = true;
    allocationCalls = 0;
    allocationBytes = 0;
    CHECK(!wasmTypeStackSet(&stack, UINT32_MAX, wasmValueTypeF64));
    CHECK(stack.valueTypes == &saved && stack.length == 1 && stack.capacity == 1);
    CHECK(saved == (1 << wasmValueTypeI32));
    if (length > (U64)((size_t)-1 / sizeof(WasmValueType))) {
        CHECK(allocationCalls == 0);
    } else {
        CHECK(allocationCalls == 1);
        CHECK((U64)allocationBytes == length * sizeof(WasmValueType));
    }
}

void testAllocations(void) {
    testLengthAddition();
    testArrayGrowth();
    testArrayLimits();
    testTypeStackAllocation();
    failAllocations = false;
    fprintf(stderr, "PASS testAllocations\n");
}
