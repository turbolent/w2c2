
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func_ptrs.9.h"

void test() {
    funcptrs9Instance instance;
    funcptrs9Instantiate(&instance, resolveTestImports);
    printStart("func_ptrs.9.wasm");
    assertEqualU32(
        funcptrs9_callt(&instance, 0u),
        1u,
        "callt(0u)"
    );
    assertEqualU32(
        funcptrs9_callt(&instance, 1u),
        2u,
        "callt(1u)"
    );
}
