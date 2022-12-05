
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.84.h"

void test() {
    memorycopy84Instance instance;
    memorycopy84Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.84.wasm");
    memorycopy84_test(&instance);
    printOK("test()");
    assertEqualU32(
        memorycopy84_checkRange(&instance, 0u, 10u, 0u),
        4294967295u,
        "checkRange(0u, 10u, 0u)"
    );
    assertEqualU32(
        memorycopy84_checkRange(&instance, 10u, 21u, 85u),
        4294967295u,
        "checkRange(10u, 21u, 85u)"
    );
    assertEqualU32(
        memorycopy84_checkRange(&instance, 21u, 65536u, 0u),
        4294967295u,
        "checkRange(21u, 65536u, 0u)"
    );
}
