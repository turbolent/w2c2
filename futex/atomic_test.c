#include <setjmp.h>
#include <stdio.h>
#include "atomic_test.h"
#include "futex.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testAtomics: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

static jmp_buf atomicTrap;
static bool expectTrap;
static Trap actualTrap;

void trap(Trap reason) {
    if (!expectTrap) {
        fprintf(stderr, "FAIL unexpected trap: %s\n", trapDescription(reason));
        abort();
    }
    actualTrap = reason;
    longjmp(atomicTrap, 1);
}

#define CHECK_TRAP(expression, reason) \
    do { \
        expectTrap = true; \
        if (setjmp(atomicTrap) == 0) { \
            (void)(expression); \
            CHECK(false); \
        } \
        expectTrap = false; \
        CHECK(actualTrap == (reason)); \
    } while (0)

#define RMW_FULL(name, op) name##_##op
#define RMW_NARROW(name, op) name##_##op##_u

#if W2C2_RUNTIME_CHECKS
#define CHECK_ATOMIC_TRAPS(mem, bits, load, store, rmw, operation) \
    do { \
        volatile U32 offset; \
        U8 before[16]; \
        memcpy(before, (mem)->data, sizeof(before)); \
        for (offset = 1; offset <= bits / 8; offset++) { \
            const WasmMemoryAddress address = offset == bits / 8 ? (mem)->size : offset; \
            const Trap reason = offset == bits / 8 ? trapMemoryOutOfBounds : trapUnalignedAtomic; \
            CHECK_TRAP(load(mem, address), reason); \
            CHECK_TRAP(store(mem, address, 0), reason); \
            CHECK_TRAP(operation(rmw, add)(mem, address, 1), reason); \
            CHECK_TRAP(operation(rmw, sub)(mem, address, 1), reason); \
            CHECK_TRAP(operation(rmw, and)(mem, address, 0), reason); \
            CHECK_TRAP(operation(rmw, or)(mem, address, 1), reason); \
            CHECK_TRAP(operation(rmw, xor)(mem, address, 1), reason); \
            CHECK_TRAP(operation(rmw, xchg)(mem, address, 0), reason); \
            CHECK_TRAP(operation(rmw, cmpxchg)(mem, address, 0, 1), reason); \
            CHECK(memcmp(before, (mem)->data, sizeof(before)) == 0); \
        } \
    } while (0)
#else
#define CHECK_ATOMIC_TRAPS(mem, bits, load, store, rmw, operation) ((void)0)
#endif

#define DEFINE_ATOMIC_TEST(name, t, size, load, store, rmw, operation) \
    static void name(wasmMemory* mem) { \
        const t mask = (t)(U ## size)-1; \
        const t value = (t)W2C2_LL(0xFEDCBA9876543210U); \
        U32 index; \
        store(mem, 16, value); \
        CHECK(load(mem, 16) == (value & mask)); \
        for (index = 0; index < size / 8; index++) { \
            CHECK(mem->data[16 + index] == (U8)(value >> (index * 8))); \
        } \
        store(mem, 16, mask); \
        CHECK(operation(rmw, add)(mem, 16, 1) == mask); \
        CHECK(load(mem, 16) == 0); \
        CHECK(operation(rmw, sub)(mem, 16, 1) == 0); \
        CHECK(load(mem, 16) == mask); \
        CHECK(operation(rmw, and)(mem, 16, 0x55) == mask); \
        CHECK(load(mem, 16) == 0x55); \
        CHECK(operation(rmw, or)(mem, 16, 0xAA) == 0x55); \
        CHECK(load(mem, 16) == 0xFF); \
        CHECK(operation(rmw, xor)(mem, 16, 0xF0) == 0xFF); \
        CHECK(load(mem, 16) == 0x0F); \
        CHECK(operation(rmw, xchg)(mem, 16, value) == 0x0F); \
        CHECK(operation(rmw, cmpxchg)(mem, 16, value, mask) == (value & mask)); \
        CHECK(load(mem, 16) == mask); \
        CHECK(operation(rmw, cmpxchg)(mem, 16, 0, 0) == mask); \
        CHECK(load(mem, 16) == mask); \
        CHECK_ATOMIC_TRAPS(mem, size, load, store, rmw, operation); \
    }

DEFINE_ATOMIC_TEST(testI32U8, U32, 8, i32_atomic_load8_u, i32_atomic_store8, i32_atomic_rmw8, RMW_NARROW)
DEFINE_ATOMIC_TEST(testI32U16, U32, 16, i32_atomic_load16_u, i32_atomic_store16, i32_atomic_rmw16, RMW_NARROW)
DEFINE_ATOMIC_TEST(testI32U32, U32, 32, i32_atomic_load, i32_atomic_store, i32_atomic_rmw, RMW_FULL)
DEFINE_ATOMIC_TEST(testI64U8, U64, 8, i64_atomic_load8_u, i64_atomic_store8, i64_atomic_rmw8, RMW_NARROW)
DEFINE_ATOMIC_TEST(testI64U16, U64, 16, i64_atomic_load16_u, i64_atomic_store16, i64_atomic_rmw16, RMW_NARROW)
DEFINE_ATOMIC_TEST(testI64U32, U64, 32, i64_atomic_load32_u, i64_atomic_store32, i64_atomic_rmw32, RMW_NARROW)
DEFINE_ATOMIC_TEST(testI64U64, U64, 64, i64_atomic_load, i64_atomic_store, i64_atomic_rmw, RMW_FULL)

static void testWaitNotify(wasmMemory* mem) {
    const U64 value = W2C2_LL(0x1234567887654321U);
    i64_atomic_store(mem, 0, value);
#if W2C2_RUNTIME_CHECKS
    {
        volatile U32 offset;
        for (offset = 1; offset < 8; offset++) {
            CHECK_TRAP(wasmMemoryAtomicWait(mem, offset, 0, 0, true), trapUnalignedAtomic);
            if (offset % 4 != 0) {
                CHECK_TRAP(wasmMemoryAtomicWait(mem, offset, 0, 0, false), trapUnalignedAtomic);
                CHECK_TRAP(wasmMemoryAtomicNotify(mem, offset, 0), trapUnalignedAtomic);
            }
        }
    }
    CHECK_TRAP(wasmMemoryAtomicWait(mem, mem->size, 0, 0, false), trapMemoryOutOfBounds);
    CHECK_TRAP(wasmMemoryAtomicWait(mem, mem->size, 0, 0, true), trapMemoryOutOfBounds);
    CHECK_TRAP(wasmMemoryAtomicNotify(mem, mem->size, 0), trapMemoryOutOfBounds);
    CHECK_TRAP(wasmMemoryAtomicNotify(mem, (U64)UINT32_MAX + 1, 0), trapMemoryOutOfBounds);
    CHECK(mem->futex == NULL);
#endif
    if (mem->shared) {
        CHECK(wasmMemoryAtomicNotify(mem, 0, 0) == 0);
        CHECK(wasmMemoryAtomicNotify(mem, 4, 1) == 0);
        CHECK(wasmMemoryAtomicWait(mem, 0, 0, -1, false) == 1);
        CHECK(wasmMemoryAtomicWait(mem, 0, 0, -1, true) == 1);
        CHECK(mem->futex == NULL);
        CHECK(wasmMemoryAtomicWait(mem, 0, (U32)value, 0, false) == 2);
        CHECK(wasmMemoryAtomicWait(mem, 0, value, 0, true) == 2);
        CHECK(wasmMemoryAtomicNotify(mem, 0, 1) == 0);
    } else {
        CHECK_TRAP(wasmMemoryAtomicWait(mem, 0, 0, 0, false), trapUnsharedMemoryWait);
        CHECK_TRAP(wasmMemoryAtomicWait(mem, 0, value, 0, true), trapUnsharedMemoryWait);
        CHECK(wasmMemoryAtomicNotify(mem, 0, 1) == 0);
        CHECK(mem->futex == NULL);
    }
}

#define ATOMIC_ITERATIONS 20000U

static void* addThread(void* context) {
    wasmMemory* mem = (wasmMemory*)context;
    U32 index;
    while (i32_atomic_load(mem, 0) == 0) { W2C2_LOOP_START }
    for (index = 0; index < ATOMIC_ITERATIONS; index++) {
        i32_atomic_rmw_add(mem, 16, 1);
    }
    return NULL;
}

static void* compareExchangeThread(void* context) {
    wasmMemory* mem = (wasmMemory*)context;
    U32 index;
    while (i32_atomic_load(mem, 0) == 0) { W2C2_LOOP_START }
    for (index = 0; index < ATOMIC_ITERATIONS; index++) {
        U32 old = atomic_load_U32(mem->data + 16);
        if (index == ATOMIC_ITERATIONS / 2) {
            CHECK(wasmMemoryGrow(mem, 1) == 1);
        }
        for (;;) {
            U32 expected = old;
            const U32 desired = swapU32(swapU32(old) + 65536U);
            const U32 observed = atomic_compare_exchange_U32(mem->data + 16, &expected, desired);
            if (observed == old) {
                break;
            }
            old = observed;
        }
    }
    return NULL;
}

static void testMixedAtomics(wasmMemory* mem) {
    WASM_THREAD_TYPE first;
    WASM_THREAD_TYPE second;
    i32_atomic_store(mem, 0, 0);
    i32_atomic_store(mem, 16, 0);
    /* Native atomics and Wasm RMW must share one atomic modification order. */
    CHECK(WASM_THREAD_CREATE(&first, addThread, mem));
    CHECK(WASM_THREAD_CREATE(&second, compareExchangeThread, mem));
    i32_atomic_store(mem, 0, 1);
    WASM_THREAD_JOIN(first);
    WASM_THREAD_JOIN(second);
    CHECK(i32_atomic_load(mem, 16) == ATOMIC_ITERATIONS * 65537U);
}

void testAtomics(void) {
    unsigned shared;
    for (shared = 0; shared < 2; shared++) {
        wasmMemory* mem = wasmMemoryAllocate(1, 2, shared != 0);
        testI32U8(mem);
        testI32U16(mem);
        testI32U32(mem);
        testI64U8(mem);
        testI64U16(mem);
        testI64U32(mem);
        testI64U64(mem);
        /* Byte accesses remain valid at odd addresses. */
        i32_atomic_store8(mem, 1, 7);
        CHECK(i64_atomic_rmw8_add_u(mem, 1, 1) == 7);
        CHECK(i32_atomic_load8_u(mem, 1) == 8);
        testWaitNotify(mem);
        if (shared) {
            testMixedAtomics(mem);
        }
        wasmMemoryFree(mem);
    }
    atomic_fence();
    fprintf(stderr, "PASS testAtomics\n");
}
