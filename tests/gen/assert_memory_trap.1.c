
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_trap.1.h"

void test() {
    memorytrap1Instance instance;
    memorytrap1Instantiate(&instance, resolveTestImports);
    printStart("memory_trap.1.wasm");
    assertEqualU64(
        memorytrap1_i64X2Eload(&instance, 65528u),
        7523094288207667809ull,
        "i64.load(65528u)"
    );
    assertEqualU64(
        memorytrap1_i64X2Eload(&instance, 0u),
        7523094288207667809ull,
        "i64.load(0u)"
    );
}
