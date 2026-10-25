
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func_ptrs.0.h"

void test() {
    m11_funcX5FptrsX2E0Instance instance;
    m11_funcX5FptrsX2E0Instantiate(&instance, resolveTestImports);
    printStart("func_ptrs.0.wasm");
    assertEqualU32(
        m11_funcX5FptrsX2E0Export3_one(&instance),
        13u,
        "one()"
    );
    assertEqualU32(
        m11_funcX5FptrsX2E0Export3_two(&instance, 13u),
        14u,
        "two(13u)"
    );
    assertEqualU32(
        m11_funcX5FptrsX2E0Export5_three(&instance, 13u),
        11u,
        "three(13u)"
    );
    m11_funcX5FptrsX2E0Export4_four(&instance, 83u);
    printOK("four(83u)");
}
