/* Compile with the translated simd_bench module at -O3. Compare identical
 * reductions, both compiled with the same compiler and target flags. */
#include <stdio.h>
#include <time.h>
#include "simd_bench.h"

static volatile U32 sink;

void trap(Trap reason) {
    fprintf(stderr, "Unexpected trap: %s\n", trapDescription(reason));
    abort();
}

V128 native_dot(const U8* a, const U8* b, U32 count);

int main(void) {
    m10_simdX5FbenchInstance instance;
    const U32 count = 32768;
    const U32 repetitions = 4096;
    wasmMemory* memory;
    U32 index;
    U32 round;
    U32 native_bits[4];
    U32 translated_bits[4];
    double native_best = 1e9;
    double translated_best = 1e9;
    m10_simdX5FbenchInstantiate(&instance, NULL);
    memory = m10_simdX5FbenchExport6_memory(&instance);
    for (index = 0; index < count * 8; index++) {
        i32_store(memory, index * 4, index * 2654435761U + 17U);
    }
    simde_wasm_v128_store(native_bits, native_dot(memory->data, memory->data + count * 16, count));
    simde_wasm_v128_store(translated_bits, m10_simdX5FbenchExport3_dot(&instance, 0, count * 16, count));
    if (memcmp(native_bits, translated_bits, 16) != 0) {
        fprintf(stderr, "Checksum mismatch\n");
        return 1;
    }
    for (round = 0; round < 5; round++) {
        clock_t start = clock();
        double elapsed;
        for (index = 0; index < repetitions; index++) {
            sink = (U32)simde_wasm_i32x4_extract_lane(native_dot(memory->data, memory->data + count * 16, count), 0);
        }
        elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
        if (elapsed < native_best) native_best = elapsed;
        start = clock();
        for (index = 0; index < repetitions; index++) {
            sink = (U32)simde_wasm_i32x4_extract_lane(m10_simdX5FbenchExport3_dot(&instance, 0, count * 16, count), 0);
        }
        elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
        if (elapsed < translated_best) translated_best = elapsed;
    }
    printf("Native %.3f ms; translated %.3f ms; ratio %.3f; checksum %08x\n",
        native_best * 1000, translated_best * 1000,
        translated_best / native_best, native_bits[0]);
    m10_simdX5FbenchFreeInstance(&instance);
    return 0;
}
