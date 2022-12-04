
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.7.h"

void test() {
    memoryfill7Instance instance;
    memoryfill7Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.7.wasm");
    memoryfill7_test(&instance);
    printOK("test()");
    assertEqualU32(
        memoryfill7_checkRange(&instance, 0u, 18u, 0u),
        4294967295u,
        "checkRange(0u, 18u, 0u)"
    );
    assertEqualU32(
        memoryfill7_checkRange(&instance, 18u, 21u, 85u),
        4294967295u,
        "checkRange(18u, 21u, 85u)"
    );
    assertEqualU32(
        memoryfill7_checkRange(&instance, 21u, 25u, 170u),
        4294967295u,
        "checkRange(21u, 25u, 170u)"
    );
    assertEqualU32(
        memoryfill7_checkRange(&instance, 25u, 28u, 85u),
        4294967295u,
        "checkRange(25u, 28u, 85u)"
    );
    assertEqualU32(
        memoryfill7_checkRange(&instance, 28u, 65536u, 0u),
        4294967295u,
        "checkRange(28u, 65536u, 0u)"
    );
}
