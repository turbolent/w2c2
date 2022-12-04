
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_forward.0.h"

void test() {
    forward0Instance instance;
    forward0Instantiate(&instance, resolveTestImports);
    printStart("forward.0.wasm");
    assertEqualU32(
        forward0_even(&instance, 13u),
        0u,
        "even(13u)"
    );
    assertEqualU32(
        forward0_even(&instance, 20u),
        1u,
        "even(20u)"
    );
    assertEqualU32(
        forward0_odd(&instance, 13u),
        1u,
        "odd(13u)"
    );
    assertEqualU32(
        forward0_odd(&instance, 20u),
        0u,
        "odd(20u)"
    );
}
