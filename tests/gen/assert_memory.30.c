
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.30.h"

void test() {
    memory30Instance instance;
    memory30Instantiate(&instance, resolveTestImports);
    printStart("memory.30.wasm");
    assertEqualU32(
        memory30_data(&instance),
        1u,
        "data()"
    );
    assertEqualF64(
        memory30_cast(&instance),
        42.0,
        "cast()"
    );
    assertEqualU32(
        memory30_i32X5Fload8X5Fs(&instance, 4294967295u),
        4294967295u,
        "i32_load8_s(4294967295u)"
    );
    assertEqualU32(
        memory30_i32X5Fload8X5Fu(&instance, 4294967295u),
        255u,
        "i32_load8_u(4294967295u)"
    );
    assertEqualU32(
        memory30_i32X5Fload16X5Fs(&instance, 4294967295u),
        4294967295u,
        "i32_load16_s(4294967295u)"
    );
    assertEqualU32(
        memory30_i32X5Fload16X5Fu(&instance, 4294967295u),
        65535u,
        "i32_load16_u(4294967295u)"
    );
    assertEqualU32(
        memory30_i32X5Fload8X5Fs(&instance, 100u),
        100u,
        "i32_load8_s(100u)"
    );
    assertEqualU32(
        memory30_i32X5Fload8X5Fu(&instance, 200u),
        200u,
        "i32_load8_u(200u)"
    );
    assertEqualU32(
        memory30_i32X5Fload16X5Fs(&instance, 20000u),
        20000u,
        "i32_load16_s(20000u)"
    );
    assertEqualU32(
        memory30_i32X5Fload16X5Fu(&instance, 40000u),
        40000u,
        "i32_load16_u(40000u)"
    );
    assertEqualU32(
        memory30_i32X5Fload8X5Fs(&instance, 4275856707u),
        67u,
        "i32_load8_s(4275856707u)"
    );
    assertEqualU32(
        memory30_i32X5Fload8X5Fs(&instance, 878104047u),
        4294967279u,
        "i32_load8_s(878104047u)"
    );
    assertEqualU32(
        memory30_i32X5Fload8X5Fu(&instance, 4275856707u),
        67u,
        "i32_load8_u(4275856707u)"
    );
    assertEqualU32(
        memory30_i32X5Fload8X5Fu(&instance, 878104047u),
        239u,
        "i32_load8_u(878104047u)"
    );
    assertEqualU32(
        memory30_i32X5Fload16X5Fs(&instance, 4275856707u),
        25923u,
        "i32_load16_s(4275856707u)"
    );
    assertEqualU32(
        memory30_i32X5Fload16X5Fs(&instance, 878104047u),
        4294954479u,
        "i32_load16_s(878104047u)"
    );
    assertEqualU32(
        memory30_i32X5Fload16X5Fu(&instance, 4275856707u),
        25923u,
        "i32_load16_u(4275856707u)"
    );
    assertEqualU32(
        memory30_i32X5Fload16X5Fu(&instance, 878104047u),
        52719u,
        "i32_load16_u(878104047u)"
    );
    assertEqualU64(
        memory30_i64X5Fload8X5Fs(&instance, 18446744073709551615ull),
        18446744073709551615ull,
        "i64_load8_s(18446744073709551615ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload8X5Fu(&instance, 18446744073709551615ull),
        255ull,
        "i64_load8_u(18446744073709551615ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload16X5Fs(&instance, 18446744073709551615ull),
        18446744073709551615ull,
        "i64_load16_s(18446744073709551615ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload16X5Fu(&instance, 18446744073709551615ull),
        65535ull,
        "i64_load16_u(18446744073709551615ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload32X5Fs(&instance, 18446744073709551615ull),
        18446744073709551615ull,
        "i64_load32_s(18446744073709551615ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload32X5Fu(&instance, 18446744073709551615ull),
        4294967295ull,
        "i64_load32_u(18446744073709551615ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload8X5Fs(&instance, 100ull),
        100ull,
        "i64_load8_s(100ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload8X5Fu(&instance, 200ull),
        200ull,
        "i64_load8_u(200ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload16X5Fs(&instance, 20000ull),
        20000ull,
        "i64_load16_s(20000ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload16X5Fu(&instance, 40000ull),
        40000ull,
        "i64_load16_u(40000ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload32X5Fs(&instance, 20000ull),
        20000ull,
        "i64_load32_s(20000ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload32X5Fu(&instance, 40000ull),
        40000ull,
        "i64_load32_u(40000ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload8X5Fs(&instance, 18364758543954109763ull),
        67ull,
        "i64_load8_s(18364758543954109763ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload8X5Fs(&instance, 3771275841602506223ull),
        18446744073709551599ull,
        "i64_load8_s(3771275841602506223ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload8X5Fu(&instance, 18364758543954109763ull),
        67ull,
        "i64_load8_u(18364758543954109763ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload8X5Fu(&instance, 3771275841602506223ull),
        239ull,
        "i64_load8_u(3771275841602506223ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload16X5Fs(&instance, 18364758543954109763ull),
        25923ull,
        "i64_load16_s(18364758543954109763ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload16X5Fs(&instance, 3771275841602506223ull),
        18446744073709538799ull,
        "i64_load16_s(3771275841602506223ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload16X5Fu(&instance, 18364758543954109763ull),
        25923ull,
        "i64_load16_u(18364758543954109763ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload16X5Fu(&instance, 3771275841602506223ull),
        52719ull,
        "i64_load16_u(3771275841602506223ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload32X5Fs(&instance, 18364758543954109763ull),
        1446274371ull,
        "i64_load32_s(18364758543954109763ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload32X5Fs(&instance, 3771275841602506223ull),
        18446744071976963567ull,
        "i64_load32_s(3771275841602506223ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload32X5Fu(&instance, 18364758543954109763ull),
        1446274371ull,
        "i64_load32_u(18364758543954109763ull)"
    );
    assertEqualU64(
        memory30_i64X5Fload32X5Fu(&instance, 3771275841602506223ull),
        2562379247ull,
        "i64_load32_u(3771275841602506223ull)"
    );
}
