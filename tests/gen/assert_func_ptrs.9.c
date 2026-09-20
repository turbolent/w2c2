
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func_ptrs.9.h"

void test() {
    m11_funcX5FptrsX2E9Instance instance;
    m11_funcX5FptrsX2E9Instantiate(&instance, resolveTestImports);
    printStart("func_ptrs.9.wasm");
    assertEqualU32(
        m11_funcX5FptrsX2E9Export5_callt(&instance, 0u),
        1u,
        "callt(0u)"
    );
    assertEqualU32(
        m11_funcX5FptrsX2E9Export5_callt(&instance, 1u),
        2u,
        "callt(1u)"
    );
}
