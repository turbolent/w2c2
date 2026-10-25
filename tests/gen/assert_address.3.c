
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_address.3.h"

void test() {
    m9_addressX2E3Instance instance;
    m9_addressX2E3Instantiate(&instance, resolveTestImports);
    printStart("address.3.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood1(&instance, 0u)),
        0u,
        "32_good1(0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood2(&instance, 0u)),
        0u,
        "32_good2(0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood3(&instance, 0u)),
        0u,
        "32_good3(0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood4(&instance, 0u)),
        0u,
        "32_good4(0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood5(&instance, 0u)),
        2144337921u,
        "32_good5(0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood1(&instance, 65524u)),
        0u,
        "32_good1(65524u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood2(&instance, 65524u)),
        0u,
        "32_good2(65524u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood3(&instance, 65524u)),
        0u,
        "32_good3(65524u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood4(&instance, 65524u)),
        0u,
        "32_good4(65524u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood5(&instance, 65524u)),
        0u,
        "32_good5(65524u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood1(&instance, 65525u)),
        0u,
        "32_good1(65525u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood2(&instance, 65525u)),
        0u,
        "32_good2(65525u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood3(&instance, 65525u)),
        0u,
        "32_good3(65525u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m9_addressX2E3Export8_32X5Fgood4(&instance, 65525u)),
        0u,
        "32_good4(65525u)"
    );
}
