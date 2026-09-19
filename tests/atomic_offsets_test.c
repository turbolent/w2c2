#include <stdio.h>

#include "w2c2_base.h"
#include "test_atomic_offsets.h"

static unsigned failures = 0;
static wasmMemory* expectedMemory = NULL;
static WasmPtr expectedAddress = 0;
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
    WasmPtr address,
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
    WasmPtr address,
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
    atomicoffsetsInstance instance;
    const U32 value32 = 0x87654321U;
    const U64 value64 = W2C2_LL(0x1234567887654321U);
    const U64 timeout = (U64)-1;

    atomicoffsetsInstantiate(&instance, NULL);
    expectedMemory = instance.m0;

    expectedAddress = 8;
    expect(atomicoffsets_notify(&instance, 8, 3) == 1, "notify result");
    expectedAddress = 16;
    expect(atomicoffsets_notify_offset(&instance, 0, 3) == 1, "notify offset result");
    expectedAddress = 24;
    expect(atomicoffsets_notify_offset(&instance, 8, 3) == 1, "notify base plus offset result");

    expectedAddress = 8;
    expect(atomicoffsets_wait32(&instance, 8, value32, timeout) == 2, "wait32 result");
    expectedAddress = 12;
    expect(atomicoffsets_wait32_offset(&instance, 0, value32, timeout) == 2, "wait32 offset result");
    expectedAddress = 20;
    expect(atomicoffsets_wait32_offset(&instance, 8, value32, timeout) == 2, "wait32 base plus offset result");

    expectedWait64 = true;
    expectedAddress = 8;
    expect(atomicoffsets_wait64(&instance, 8, value64, timeout) == 2, "wait64 result");
    expectedAddress = 256;
    expect(atomicoffsets_wait64_offset(&instance, 0, value64, timeout) == 2, "wait64 offset result");
    expectedAddress = 264;
    expect(atomicoffsets_wait64_offset(&instance, 8, value64, timeout) == 2, "wait64 base plus offset result");

    atomicoffsetsFreeInstance(&instance);
    if (failures != 0) {
        return 1;
    }
    fprintf(stderr, "PASS atomic offsets\n");
    return 0;
}
