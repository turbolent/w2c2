
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.83.h"

void test() {
    memorycopy83Instance instance;
    memorycopy83Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.83.wasm");
    memorycopy83_test(&instance);
    printOK("test()");
    assertEqualU32(
        memorycopy83_checkRange(&instance, 0u, 9u, 0u),
        4294967295u,
        "checkRange(0u, 9u, 0u)"
    );
    assertEqualU32(
        memorycopy83_checkRange(&instance, 9u, 20u, 85u),
        4294967295u,
        "checkRange(9u, 20u, 85u)"
    );
    assertEqualU32(
        memorycopy83_checkRange(&instance, 20u, 65536u, 0u),
        4294967295u,
        "checkRange(20u, 65536u, 0u)"
    );
}
