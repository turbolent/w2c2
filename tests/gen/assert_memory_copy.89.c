
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.89.h"

void test() {
    memorycopy89Instance instance;
    memorycopy89Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.89.wasm");
    memorycopy89_test(&instance);
    printOK("test()");
    assertEqualU32(
        memorycopy89_checkRange(&instance, 0u, 32768u, 85u),
        4294967295u,
        "checkRange(0u, 32768u, 85u)"
    );
    assertEqualU32(
        memorycopy89_checkRange(&instance, 32768u, 65536u, 170u),
        4294967295u,
        "checkRange(32768u, 65536u, 170u)"
    );
}
