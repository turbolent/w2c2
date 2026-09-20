
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.106.h"

void test() {
    m9_alignX2E106Instance instance;
    m9_alignX2E106Instantiate(&instance, resolveTestImports);
    printStart("align.106.wasm");
    assertEqualF32(
        m9_alignX2E106Export16_f32X5FalignX5Fswitch(&instance, 0u),
        10.0,
        "f32_align_switch(0u)"
    );
    assertEqualF32(
        m9_alignX2E106Export16_f32X5FalignX5Fswitch(&instance, 1u),
        10.0,
        "f32_align_switch(1u)"
    );
    assertEqualF32(
        m9_alignX2E106Export16_f32X5FalignX5Fswitch(&instance, 2u),
        10.0,
        "f32_align_switch(2u)"
    );
    assertEqualF32(
        m9_alignX2E106Export16_f32X5FalignX5Fswitch(&instance, 3u),
        10.0,
        "f32_align_switch(3u)"
    );
    assertEqualF64(
        m9_alignX2E106Export16_f64X5FalignX5Fswitch(&instance, 0u),
        10.0,
        "f64_align_switch(0u)"
    );
    assertEqualF64(
        m9_alignX2E106Export16_f64X5FalignX5Fswitch(&instance, 1u),
        10.0,
        "f64_align_switch(1u)"
    );
    assertEqualF64(
        m9_alignX2E106Export16_f64X5FalignX5Fswitch(&instance, 2u),
        10.0,
        "f64_align_switch(2u)"
    );
    assertEqualF64(
        m9_alignX2E106Export16_f64X5FalignX5Fswitch(&instance, 3u),
        10.0,
        "f64_align_switch(3u)"
    );
    assertEqualF64(
        m9_alignX2E106Export16_f64X5FalignX5Fswitch(&instance, 4u),
        10.0,
        "f64_align_switch(4u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 0u, 0u),
        10u,
        "i32_align_switch(0u, 0u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 0u, 1u),
        10u,
        "i32_align_switch(0u, 1u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 1u, 0u),
        10u,
        "i32_align_switch(1u, 0u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 1u, 1u),
        10u,
        "i32_align_switch(1u, 1u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 2u, 0u),
        10u,
        "i32_align_switch(2u, 0u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 2u, 1u),
        10u,
        "i32_align_switch(2u, 1u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 2u, 2u),
        10u,
        "i32_align_switch(2u, 2u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 3u, 0u),
        10u,
        "i32_align_switch(3u, 0u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 3u, 1u),
        10u,
        "i32_align_switch(3u, 1u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 3u, 2u),
        10u,
        "i32_align_switch(3u, 2u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 4u, 0u),
        10u,
        "i32_align_switch(4u, 0u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 4u, 1u),
        10u,
        "i32_align_switch(4u, 1u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 4u, 2u),
        10u,
        "i32_align_switch(4u, 2u)"
    );
    assertEqualU32(
        m9_alignX2E106Export16_i32X5FalignX5Fswitch(&instance, 4u, 4u),
        10u,
        "i32_align_switch(4u, 4u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 0u, 0u),
        10ull,
        "i64_align_switch(0u, 0u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 0u, 1u),
        10ull,
        "i64_align_switch(0u, 1u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 1u, 0u),
        10ull,
        "i64_align_switch(1u, 0u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 1u, 1u),
        10ull,
        "i64_align_switch(1u, 1u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 2u, 0u),
        10ull,
        "i64_align_switch(2u, 0u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 2u, 1u),
        10ull,
        "i64_align_switch(2u, 1u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 2u, 2u),
        10ull,
        "i64_align_switch(2u, 2u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 3u, 0u),
        10ull,
        "i64_align_switch(3u, 0u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 3u, 1u),
        10ull,
        "i64_align_switch(3u, 1u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 3u, 2u),
        10ull,
        "i64_align_switch(3u, 2u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 4u, 0u),
        10ull,
        "i64_align_switch(4u, 0u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 4u, 1u),
        10ull,
        "i64_align_switch(4u, 1u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 4u, 2u),
        10ull,
        "i64_align_switch(4u, 2u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 4u, 4u),
        10ull,
        "i64_align_switch(4u, 4u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 5u, 0u),
        10ull,
        "i64_align_switch(5u, 0u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 5u, 1u),
        10ull,
        "i64_align_switch(5u, 1u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 5u, 2u),
        10ull,
        "i64_align_switch(5u, 2u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 5u, 4u),
        10ull,
        "i64_align_switch(5u, 4u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 6u, 0u),
        10ull,
        "i64_align_switch(6u, 0u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 6u, 1u),
        10ull,
        "i64_align_switch(6u, 1u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 6u, 2u),
        10ull,
        "i64_align_switch(6u, 2u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 6u, 4u),
        10ull,
        "i64_align_switch(6u, 4u)"
    );
    assertEqualU64(
        m9_alignX2E106Export16_i64X5FalignX5Fswitch(&instance, 6u, 8u),
        10ull,
        "i64_align_switch(6u, 8u)"
    );
}
