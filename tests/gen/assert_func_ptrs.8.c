
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func_ptrs.8.h"

void test() {
    funcptrs8Instance instance;
    funcptrs8Instantiate(&instance, resolveTestImports);
    printStart("func_ptrs.8.wasm");
    assertEqualU32(
        funcptrs8_callt(&instance, 0u),
        1u,
        "callt(0u)"
    );
    assertEqualU32(
        funcptrs8_callt(&instance, 1u),
        2u,
        "callt(1u)"
    );
    assertEqualU32(
        funcptrs8_callt(&instance, 2u),
        3u,
        "callt(2u)"
    );
    assertEqualU32(
        funcptrs8_callt(&instance, 3u),
        4u,
        "callt(3u)"
    );
    assertEqualU32(
        funcptrs8_callt(&instance, 4u),
        5u,
        "callt(4u)"
    );
    assertEqualU32(
        funcptrs8_callt(&instance, 5u),
        1u,
        "callt(5u)"
    );
    assertEqualU32(
        funcptrs8_callt(&instance, 6u),
        3u,
        "callt(6u)"
    );
    assertEqualU32(
        funcptrs8_callu(&instance, 0u),
        1u,
        "callu(0u)"
    );
    assertEqualU32(
        funcptrs8_callu(&instance, 1u),
        2u,
        "callu(1u)"
    );
    assertEqualU32(
        funcptrs8_callu(&instance, 2u),
        3u,
        "callu(2u)"
    );
    assertEqualU32(
        funcptrs8_callu(&instance, 3u),
        4u,
        "callu(3u)"
    );
    assertEqualU32(
        funcptrs8_callu(&instance, 4u),
        5u,
        "callu(4u)"
    );
    assertEqualU32(
        funcptrs8_callu(&instance, 5u),
        1u,
        "callu(5u)"
    );
    assertEqualU32(
        funcptrs8_callu(&instance, 6u),
        3u,
        "callu(6u)"
    );
}
