
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_address.4.h"

void test() {
    address4Instance instance;
    address4Instantiate(&instance, resolveTestImports);
    printStart("address.4.wasm");
    assertEqualF64(
        address4_64_good1(&instance, 0u),
        0.0,
        "64_good1(0u)"
    );
    assertEqualF64(
        address4_64_good2(&instance, 0u),
        0.0,
        "64_good2(0u)"
    );
    assertEqualF64(
        address4_64_good3(&instance, 0u),
        0.0,
        "64_good3(0u)"
    );
    assertEqualF64(
        address4_64_good4(&instance, 0u),
        0.0,
        "64_good4(0u)"
    );
    assertEqualF64(
        address4_64_good1(&instance, 65510u),
        0.0,
        "64_good1(65510u)"
    );
    assertEqualF64(
        address4_64_good2(&instance, 65510u),
        0.0,
        "64_good2(65510u)"
    );
    assertEqualF64(
        address4_64_good3(&instance, 65510u),
        0.0,
        "64_good3(65510u)"
    );
    assertEqualF64(
        address4_64_good4(&instance, 65510u),
        0.0,
        "64_good4(65510u)"
    );
    assertEqualF64(
        address4_64_good5(&instance, 65510u),
        0.0,
        "64_good5(65510u)"
    );
    assertEqualF64(
        address4_64_good1(&instance, 65511u),
        0.0,
        "64_good1(65511u)"
    );
    assertEqualF64(
        address4_64_good2(&instance, 65511u),
        0.0,
        "64_good2(65511u)"
    );
    assertEqualF64(
        address4_64_good3(&instance, 65511u),
        0.0,
        "64_good3(65511u)"
    );
    assertEqualF64(
        address4_64_good4(&instance, 65511u),
        0.0,
        "64_good4(65511u)"
    );
}
