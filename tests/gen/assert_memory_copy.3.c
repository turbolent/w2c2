
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.3.h"

void test() {
    memorycopy3Instance instance;
    memorycopy3Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.3.wasm");
    memorycopy3_test(&instance);
    printOK("test()");
    assertEqualU32(
        memorycopy3_load8_u(&instance, 0u),
        0u,
        "load8_u(0u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 1u),
        0u,
        "load8_u(1u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 2u),
        3u,
        "load8_u(2u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 3u),
        1u,
        "load8_u(3u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 4u),
        4u,
        "load8_u(4u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 5u),
        1u,
        "load8_u(5u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 6u),
        0u,
        "load8_u(6u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 7u),
        0u,
        "load8_u(7u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 8u),
        0u,
        "load8_u(8u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 9u),
        0u,
        "load8_u(9u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 10u),
        0u,
        "load8_u(10u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 11u),
        0u,
        "load8_u(11u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 12u),
        7u,
        "load8_u(12u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 13u),
        0u,
        "load8_u(13u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 14u),
        0u,
        "load8_u(14u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 15u),
        0u,
        "load8_u(15u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 16u),
        6u,
        "load8_u(16u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 17u),
        0u,
        "load8_u(17u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 18u),
        0u,
        "load8_u(18u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 19u),
        0u,
        "load8_u(19u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 20u),
        0u,
        "load8_u(20u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 21u),
        0u,
        "load8_u(21u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 22u),
        0u,
        "load8_u(22u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 23u),
        0u,
        "load8_u(23u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 24u),
        0u,
        "load8_u(24u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 25u),
        0u,
        "load8_u(25u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 26u),
        0u,
        "load8_u(26u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 27u),
        0u,
        "load8_u(27u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 28u),
        0u,
        "load8_u(28u)"
    );
    assertEqualU32(
        memorycopy3_load8_u(&instance, 29u),
        0u,
        "load8_u(29u)"
    );
}
