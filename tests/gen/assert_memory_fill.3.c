
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.3.h"

void test() {
    memoryfill3Instance instance;
    memoryfill3Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.3.wasm");
    memoryfill3_test(&instance);
    printOK("test()");
    assertEqualU32(
        memoryfill3_checkRange(&instance, 0u, 65536u, 0u),
        4294967295u,
        "checkRange(0u, 65536u, 0u)"
    );
}
