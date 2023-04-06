
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.106.h"

void test() {
    align106Instance instance;
    align106Instantiate(&instance, resolveTestImports);
    printStart("align.106.wasm");
    assertEqualF32(
        align106_f32_align_switch(&instance, 0u),
        10.0,
        "f32_align_switch(0u)"
    );
    assertEqualF32(
        align106_f32_align_switch(&instance, 1u),
        10.0,
        "f32_align_switch(1u)"
    );
    assertEqualF32(
        align106_f32_align_switch(&instance, 2u),
        10.0,
        "f32_align_switch(2u)"
    );
    assertEqualF32(
        align106_f32_align_switch(&instance, 3u),
        10.0,
        "f32_align_switch(3u)"
    );
    assertEqualF64(
        align106_f64_align_switch(&instance, 0u),
        10.0,
        "f64_align_switch(0u)"
    );
    assertEqualF64(
        align106_f64_align_switch(&instance, 1u),
        10.0,
        "f64_align_switch(1u)"
    );
    assertEqualF64(
        align106_f64_align_switch(&instance, 2u),
        10.0,
        "f64_align_switch(2u)"
    );
    assertEqualF64(
        align106_f64_align_switch(&instance, 3u),
        10.0,
        "f64_align_switch(3u)"
    );
    assertEqualF64(
        align106_f64_align_switch(&instance, 4u),
        10.0,
        "f64_align_switch(4u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 0u, 0u),
        10u,
        "i32_align_switch(0u, 0u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 0u, 1u),
        10u,
        "i32_align_switch(0u, 1u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 1u, 0u),
        10u,
        "i32_align_switch(1u, 0u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 1u, 1u),
        10u,
        "i32_align_switch(1u, 1u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 2u, 0u),
        10u,
        "i32_align_switch(2u, 0u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 2u, 1u),
        10u,
        "i32_align_switch(2u, 1u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 2u, 2u),
        10u,
        "i32_align_switch(2u, 2u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 3u, 0u),
        10u,
        "i32_align_switch(3u, 0u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 3u, 1u),
        10u,
        "i32_align_switch(3u, 1u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 3u, 2u),
        10u,
        "i32_align_switch(3u, 2u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 4u, 0u),
        10u,
        "i32_align_switch(4u, 0u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 4u, 1u),
        10u,
        "i32_align_switch(4u, 1u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 4u, 2u),
        10u,
        "i32_align_switch(4u, 2u)"
    );
    assertEqualU32(
        align106_i32_align_switch(&instance, 4u, 4u),
        10u,
        "i32_align_switch(4u, 4u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 0u, 0u),
        10ull,
        "i64_align_switch(0u, 0u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 0u, 1u),
        10ull,
        "i64_align_switch(0u, 1u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 1u, 0u),
        10ull,
        "i64_align_switch(1u, 0u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 1u, 1u),
        10ull,
        "i64_align_switch(1u, 1u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 2u, 0u),
        10ull,
        "i64_align_switch(2u, 0u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 2u, 1u),
        10ull,
        "i64_align_switch(2u, 1u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 2u, 2u),
        10ull,
        "i64_align_switch(2u, 2u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 3u, 0u),
        10ull,
        "i64_align_switch(3u, 0u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 3u, 1u),
        10ull,
        "i64_align_switch(3u, 1u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 3u, 2u),
        10ull,
        "i64_align_switch(3u, 2u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 4u, 0u),
        10ull,
        "i64_align_switch(4u, 0u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 4u, 1u),
        10ull,
        "i64_align_switch(4u, 1u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 4u, 2u),
        10ull,
        "i64_align_switch(4u, 2u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 4u, 4u),
        10ull,
        "i64_align_switch(4u, 4u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 5u, 0u),
        10ull,
        "i64_align_switch(5u, 0u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 5u, 1u),
        10ull,
        "i64_align_switch(5u, 1u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 5u, 2u),
        10ull,
        "i64_align_switch(5u, 2u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 5u, 4u),
        10ull,
        "i64_align_switch(5u, 4u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 6u, 0u),
        10ull,
        "i64_align_switch(6u, 0u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 6u, 1u),
        10ull,
        "i64_align_switch(6u, 1u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 6u, 2u),
        10ull,
        "i64_align_switch(6u, 2u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 6u, 4u),
        10ull,
        "i64_align_switch(6u, 4u)"
    );
    assertEqualU64(
        align106_i64_align_switch(&instance, 6u, 8u),
        10ull,
        "i64_align_switch(6u, 8u)"
    );
}
