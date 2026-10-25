
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_address.4.h"

void test() {
    m9_addressX2E4Instance instance;
    m9_addressX2E4Instantiate(&instance, resolveTestImports);
    printStart("address.4.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood1(&instance, 0u)),
        0ull,
        "64_good1(0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood2(&instance, 0u)),
        0ull,
        "64_good2(0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood3(&instance, 0u)),
        0ull,
        "64_good3(0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood4(&instance, 0u)),
        0ull,
        "64_good4(0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood5(&instance, 0u)),
        9222246136947933185ull,
        "64_good5(0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood1(&instance, 65510u)),
        0ull,
        "64_good1(65510u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood2(&instance, 65510u)),
        0ull,
        "64_good2(65510u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood3(&instance, 65510u)),
        0ull,
        "64_good3(65510u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood4(&instance, 65510u)),
        0ull,
        "64_good4(65510u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood5(&instance, 65510u)),
        0ull,
        "64_good5(65510u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood1(&instance, 65511u)),
        0ull,
        "64_good1(65511u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood2(&instance, 65511u)),
        0ull,
        "64_good2(65511u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood3(&instance, 65511u)),
        0ull,
        "64_good3(65511u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m9_addressX2E4Export8_64X5Fgood4(&instance, 65511u)),
        0ull,
        "64_good4(65511u)"
    );
}
