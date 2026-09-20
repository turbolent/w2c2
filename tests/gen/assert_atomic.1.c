
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_atomic.1.h"

void test() {
    m8_atomicX2E1Instance instance;
    m8_atomicX2E1Instantiate(&instance, resolveTestImports);
    printStart("atomic.1.wasm");
    m8_atomicX2E1Export4_init(&instance, 281474976710655ull);
    printOK("init(281474976710655ull)");
    assertEqualU32(
        m8_atomicX2E1Export20_memoryX2EatomicX2Ewait32(&instance, 0u, 0u, 0ull),
        1u,
        "memory.atomic.wait32(0u, 0u, 0ull)"
    );
    assertEqualU32(
        m8_atomicX2E1Export20_memoryX2EatomicX2Ewait64(&instance, 0u, 0ull, 0ull),
        1u,
        "memory.atomic.wait64(0u, 0ull, 0ull)"
    );
    assertEqualU32(
        m8_atomicX2E1Export20_memoryX2EatomicX2Enotify(&instance, 0u, 0u),
        0u,
        "memory.atomic.notify(0u, 0u)"
    );
}
