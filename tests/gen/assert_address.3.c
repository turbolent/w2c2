
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_address.3.h"

void test() {
    address3Instance instance;
    address3Instantiate(&instance, resolveTestImports);
    printStart("address.3.wasm");
    assertEqualF32(
        address3_32X5Fgood1(&instance, 0u),
        0.0,
        "32_good1(0u)"
    );
    assertEqualF32(
        address3_32X5Fgood2(&instance, 0u),
        0.0,
        "32_good2(0u)"
    );
    assertEqualF32(
        address3_32X5Fgood3(&instance, 0u),
        0.0,
        "32_good3(0u)"
    );
    assertEqualF32(
        address3_32X5Fgood4(&instance, 0u),
        0.0,
        "32_good4(0u)"
    );
    assertEqualF32(
        address3_32X5Fgood1(&instance, 65524u),
        0.0,
        "32_good1(65524u)"
    );
    assertEqualF32(
        address3_32X5Fgood2(&instance, 65524u),
        0.0,
        "32_good2(65524u)"
    );
    assertEqualF32(
        address3_32X5Fgood3(&instance, 65524u),
        0.0,
        "32_good3(65524u)"
    );
    assertEqualF32(
        address3_32X5Fgood4(&instance, 65524u),
        0.0,
        "32_good4(65524u)"
    );
    assertEqualF32(
        address3_32X5Fgood5(&instance, 65524u),
        0.0,
        "32_good5(65524u)"
    );
    assertEqualF32(
        address3_32X5Fgood1(&instance, 65525u),
        0.0,
        "32_good1(65525u)"
    );
    assertEqualF32(
        address3_32X5Fgood2(&instance, 65525u),
        0.0,
        "32_good2(65525u)"
    );
    assertEqualF32(
        address3_32X5Fgood3(&instance, 65525u),
        0.0,
        "32_good3(65525u)"
    );
    assertEqualF32(
        address3_32X5Fgood4(&instance, 65525u),
        0.0,
        "32_good4(65525u)"
    );
}
