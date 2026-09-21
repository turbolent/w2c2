#include <stdio.h>

#include "w2c2_base.h"
#include "test_atomic_offsets.h"

static unsigned failures = 0;
static wasmMemory* expectedMemory = NULL;
static WasmMemoryAddress expectedAddress = 0;
static bool expectedWait64 = false;

static
void
expect(
    bool condition,
    const char* description
) {
    if (!condition) {
        fprintf(stderr, "FAIL atomic offsets: %s\n", description);
        failures++;
    }
}

void
trap(
    Trap trap
) {
    fprintf(stderr, "FAIL atomic offsets: %s\n", trapDescription(trap));
    abort();
}

/* Check the generated calls at the runtime boundary,
 * without depending on futex scheduling. */
U32
wasmMemoryAtomicNotify(
    wasmMemory* memory,
    WasmMemoryAddress address,
    U32 count
) {
    expect(memory == expectedMemory, "notify memory");
    expect(address == expectedAddress, "notify address");
    expect(count == 3, "notify count");
    return 1;
}

U32
wasmMemoryAtomicWait(
    wasmMemory* memory,
    WasmMemoryAddress address,
    U64 value,
    I64 timeout,
    bool wait64
) {
    const U64 expectedValue = expectedWait64
        ? W2C2_LL(0x1234567887654321U)
        : W2C2_LL(0x87654321U);
    expect(memory == expectedMemory, "wait memory");
    expect(address == expectedAddress, expectedWait64 ? "wait64 address" : "wait32 address");
    expect(value == expectedValue, "wait expected value");
    expect(timeout == -1, "wait timeout");
    expect(wait64 == expectedWait64, "wait width");
    return 2;
}

int
main(void) {
    m14_atomicX5FoffsetsInstance instance;
    const U32 value32 = 0x87654321U;
    const U64 value64 = W2C2_LL(0x1234567887654321U);
    const U64 timeout = (U64)-1;

    m14_atomicX5FoffsetsInstantiate(&instance, NULL);
    expectedMemory = instance.m0;

    expectedAddress = 8;
    expect(m14_atomicX5FoffsetsExport6_notify(&instance, 8, 3) == 1, "notify result");
    expectedAddress = 16;
    expect(m14_atomicX5FoffsetsExport13_notifyX5Foffset(&instance, 0, 3) == 1, "notify offset result");
    expectedAddress = 24;
    expect(m14_atomicX5FoffsetsExport13_notifyX5Foffset(&instance, 8, 3) == 1, "notify base plus offset result");

    expectedAddress = 8;
    expect(m14_atomicX5FoffsetsExport6_wait32(&instance, 8, value32, timeout) == 2, "wait32 result");
    expectedAddress = 12;
    expect(m14_atomicX5FoffsetsExport13_wait32X5Foffset(&instance, 0, value32, timeout) == 2, "wait32 offset result");
    expectedAddress = 20;
    expect(m14_atomicX5FoffsetsExport13_wait32X5Foffset(&instance, 8, value32, timeout) == 2, "wait32 base plus offset result");

    expectedWait64 = true;
    expectedAddress = 8;
    expect(m14_atomicX5FoffsetsExport6_wait64(&instance, 8, value64, timeout) == 2, "wait64 result");
    expectedAddress = 256;
    expect(m14_atomicX5FoffsetsExport13_wait64X5Foffset(&instance, 0, value64, timeout) == 2, "wait64 offset result");
    expectedAddress = 264;
    expect(m14_atomicX5FoffsetsExport13_wait64X5Foffset(&instance, 8, value64, timeout) == 2, "wait64 base plus offset result");

#if W2C2_RUNTIME_CHECKS
    expectedAddress = (U64)UINT32_MAX + 16;
    expect(m14_atomicX5FoffsetsExport13_notifyX5Foffset(&instance, UINT32_MAX, 3) == 1, "wide notify address");
    expectedWait64 = false;
    expectedAddress = (U64)UINT32_MAX + 12;
    expect(m14_atomicX5FoffsetsExport13_wait32X5Foffset(&instance, UINT32_MAX, value32, timeout) == 2, "wide wait32 address");
    expectedWait64 = true;
    expectedAddress = (U64)UINT32_MAX + 256;
    expect(m14_atomicX5FoffsetsExport13_wait64X5Foffset(&instance, UINT32_MAX, value64, timeout) == 2, "wide wait64 address");
#endif

    m14_atomicX5FoffsetsFreeInstance(&instance);
    if (failures != 0) {
        return 1;
    }
    fprintf(stderr, "PASS atomic offsets\n");
    return 0;
}
