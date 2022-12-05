
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func_ptrs.0.h"

void test() {
    funcptrs0Instance instance;
    funcptrs0Instantiate(&instance, resolveTestImports);
    printStart("func_ptrs.0.wasm");
    assertEqualU32(
        funcptrs0_one(&instance),
        13u,
        "one()"
    );
    assertEqualU32(
        funcptrs0_two(&instance, 13u),
        14u,
        "two(13u)"
    );
    assertEqualU32(
        funcptrs0_three(&instance, 13u),
        11u,
        "three(13u)"
    );
    funcptrs0_four(&instance, 83u);
    printOK("four(83u)");
}
