#include "test.h"
#include "test_conversions.0.h"

void test(void) {
    static m13_conversionsX2E0Instance instance;
    m13_conversionsX2E0Instantiate(&instance, resolveTestImports);
    printStart("conversions.0.wasm");
    assertEqualU64(
        m13_conversionsX2E0Export16_i64X2EextendX5Fi32X5Fs(&instance, 0u),
        0ull,
        "i64.extend_i32_s(0u)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export16_i64X2EextendX5Fi32X5Fs(&instance, 10000u),
        10000ull,
        "i64.extend_i32_s(10000u)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export16_i64X2EextendX5Fi32X5Fs(&instance, 4294957296u),
        18446744073709541616ull,
        "i64.extend_i32_s(4294957296u)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export16_i64X2EextendX5Fi32X5Fs(&instance, 4294967295u),
        18446744073709551615ull,
        "i64.extend_i32_s(4294967295u)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export16_i64X2EextendX5Fi32X5Fs(&instance, 2147483647u),
        2147483647ull,
        "i64.extend_i32_s(2147483647u)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export16_i64X2EextendX5Fi32X5Fs(&instance, 2147483648u),
        18446744071562067968ull,
        "i64.extend_i32_s(2147483648u)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export16_i64X2EextendX5Fi32X5Fu(&instance, 0u),
        0ull,
        "i64.extend_i32_u(0u)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export16_i64X2EextendX5Fi32X5Fu(&instance, 10000u),
        10000ull,
        "i64.extend_i32_u(10000u)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export16_i64X2EextendX5Fi32X5Fu(&instance, 4294957296u),
        4294957296ull,
        "i64.extend_i32_u(4294957296u)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export16_i64X2EextendX5Fi32X5Fu(&instance, 4294967295u),
        4294967295ull,
        "i64.extend_i32_u(4294967295u)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export16_i64X2EextendX5Fi32X5Fu(&instance, 2147483647u),
        2147483647ull,
        "i64.extend_i32_u(2147483647u)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export16_i64X2EextendX5Fi32X5Fu(&instance, 2147483648u),
        2147483648ull,
        "i64.extend_i32_u(2147483648u)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export12_i32X2EwrapX5Fi64(&instance, 18446744073709551615ull),
        4294967295u,
        "i32.wrap_i64(18446744073709551615ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export12_i32X2EwrapX5Fi64(&instance, 18446744073709451616ull),
        4294867296u,
        "i32.wrap_i64(18446744073709451616ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export12_i32X2EwrapX5Fi64(&instance, 2147483648ull),
        2147483648u,
        "i32.wrap_i64(2147483648ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export12_i32X2EwrapX5Fi64(&instance, 18446744071562067967ull),
        2147483647u,
        "i32.wrap_i64(18446744071562067967ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export12_i32X2EwrapX5Fi64(&instance, 18446744069414584320ull),
        0u,
        "i32.wrap_i64(18446744069414584320ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export12_i32X2EwrapX5Fi64(&instance, 18446744069414584319ull),
        4294967295u,
        "i32.wrap_i64(18446744069414584319ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export12_i32X2EwrapX5Fi64(&instance, 18446744069414584321ull),
        1u,
        "i32.wrap_i64(18446744069414584321ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export12_i32X2EwrapX5Fi64(&instance, 0ull),
        0u,
        "i32.wrap_i64(0ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export12_i32X2EwrapX5Fi64(&instance, 1311768467463790320ull),
        2596069104u,
        "i32.wrap_i64(1311768467463790320ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export12_i32X2EwrapX5Fi64(&instance, 4294967295ull),
        4294967295u,
        "i32.wrap_i64(4294967295ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export12_i32X2EwrapX5Fi64(&instance, 4294967296ull),
        0u,
        "i32.wrap_i64(4294967296ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export12_i32X2EwrapX5Fi64(&instance, 4294967297ull),
        1u,
        "i32.wrap_i64(4294967297ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x00000000u)),
        0u,
        "i32.trunc_f32_s(0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x80000000u)),
        0u,
        "i32.trunc_f32_s(-0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x00000001u)),
        0u,
        "i32.trunc_f32_s(1.401298464324817e-45)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x80000001u)),
        0u,
        "i32.trunc_f32_s(-1.401298464324817e-45)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x3f800000u)),
        1u,
        "i32.trunc_f32_s(1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x3f8ccccdu)),
        1u,
        "i32.trunc_f32_s(1.100000023841858)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x3fc00000u)),
        1u,
        "i32.trunc_f32_s(1.5)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbf800000u)),
        4294967295u,
        "i32.trunc_f32_s(-1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbf8ccccdu)),
        4294967295u,
        "i32.trunc_f32_s(-1.100000023841858)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbfc00000u)),
        4294967295u,
        "i32.trunc_f32_s(-1.5)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbff33333u)),
        4294967295u,
        "i32.trunc_f32_s(-1.899999976158142)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xc0000000u)),
        4294967294u,
        "i32.trunc_f32_s(-2.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x4effffffu)),
        2147483520u,
        "i32.trunc_f32_s(2147483520.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xcf000000u)),
        2147483648u,
        "i32.trunc_f32_s(-2147483648.0)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x4f000000u)), trapIntOverflow, "i32.trunc_f32_s(2147483648.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xcf000001u)), trapIntOverflow, "i32.trunc_f32_s(-2147483904.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7f800000u)), trapIntOverflow, "i32.trunc_f32_s(INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xff800000u)), trapIntOverflow, "i32.trunc_f32_s(-INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7fc00000u)), trapInvalidConversion, "i32.trunc_f32_s(f32_reinterpret_i32(0x7fc00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7fa00000u)), trapInvalidConversion, "i32.trunc_f32_s(f32_reinterpret_i32(0x7fa00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xffc00000u)), trapInvalidConversion, "i32.trunc_f32_s(f32_reinterpret_i32(0xffc00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xffa00000u)), trapInvalidConversion, "i32.trunc_f32_s(f32_reinterpret_i32(0xffa00000u))");
#endif
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x00000000u)),
        0u,
        "i32.trunc_f32_u(0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x80000000u)),
        0u,
        "i32.trunc_f32_u(-0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x00000001u)),
        0u,
        "i32.trunc_f32_u(1.401298464324817e-45)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x80000001u)),
        0u,
        "i32.trunc_f32_u(-1.401298464324817e-45)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3f800000u)),
        1u,
        "i32.trunc_f32_u(1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3f8ccccdu)),
        1u,
        "i32.trunc_f32_u(1.100000023841858)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3fc00000u)),
        1u,
        "i32.trunc_f32_u(1.5)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3ff33333u)),
        1u,
        "i32.trunc_f32_u(1.899999976158142)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x40000000u)),
        2u,
        "i32.trunc_f32_u(2.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x4f000000u)),
        2147483648u,
        "i32.trunc_f32_u(2147483648.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x4f7fffffu)),
        4294967040u,
        "i32.trunc_f32_u(4294967040.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xbf666666u)),
        0u,
        "i32.trunc_f32_u(-0.8999999761581421)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xbf7fffffu)),
        0u,
        "i32.trunc_f32_u(-0.9999999403953552)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x4f800000u)), trapIntOverflow, "i32.trunc_f32_u(4294967296.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xbf800000u)), trapIntOverflow, "i32.trunc_f32_u(-1.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7f800000u)), trapIntOverflow, "i32.trunc_f32_u(INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xff800000u)), trapIntOverflow, "i32.trunc_f32_u(-INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7fc00000u)), trapInvalidConversion, "i32.trunc_f32_u(f32_reinterpret_i32(0x7fc00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7fa00000u)), trapInvalidConversion, "i32.trunc_f32_u(f32_reinterpret_i32(0x7fa00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xffc00000u)), trapInvalidConversion, "i32.trunc_f32_u(f32_reinterpret_i32(0xffc00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xffa00000u)), trapInvalidConversion, "i32.trunc_f32_u(f32_reinterpret_i32(0xffa00000u))");
#endif
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x0000000000000000ull)),
        0u,
        "i32.trunc_f64_s(0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x8000000000000000ull)),
        0u,
        "i32.trunc_f64_s(-0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x0000000000000001ull)),
        0u,
        "i32.trunc_f64_s(5e-324)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x8000000000000001ull)),
        0u,
        "i32.trunc_f64_s(-5e-324)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x3ff0000000000000ull)),
        1u,
        "i32.trunc_f64_s(1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x3ff199999999999aull)),
        1u,
        "i32.trunc_f64_s(1.1)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x3ff8000000000000ull)),
        1u,
        "i32.trunc_f64_s(1.5)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbff0000000000000ull)),
        4294967295u,
        "i32.trunc_f64_s(-1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbff199999999999aull)),
        4294967295u,
        "i32.trunc_f64_s(-1.1)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbff8000000000000ull)),
        4294967295u,
        "i32.trunc_f64_s(-1.5)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbffe666666666666ull)),
        4294967295u,
        "i32.trunc_f64_s(-1.9)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc000000000000000ull)),
        4294967294u,
        "i32.trunc_f64_s(-2.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x41dfffffffc00000ull)),
        2147483647u,
        "i32.trunc_f64_s(2147483647.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc1e0000000000000ull)),
        2147483648u,
        "i32.trunc_f64_s(-2147483648.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc1e00000001ccccdull)),
        2147483648u,
        "i32.trunc_f64_s(-2147483648.9)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x41dffffffff9999aull)),
        2147483647u,
        "i32.trunc_f64_s(2147483647.9)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x41e0000000000000ull)), trapIntOverflow, "i32.trunc_f64_s(2147483648.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc1e0000000200000ull)), trapIntOverflow, "i32.trunc_f64_s(-2147483649.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff0000000000000ull)), trapIntOverflow, "i32.trunc_f64_s(INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xfff0000000000000ull)), trapIntOverflow, "i32.trunc_f64_s(-INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)), trapInvalidConversion, "i32.trunc_f64_s(f64_reinterpret_i64(0x7ff8000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff4000000000000ull)), trapInvalidConversion, "i32.trunc_f64_s(f64_reinterpret_i64(0x7ff4000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xfff8000000000000ull)), trapInvalidConversion, "i32.trunc_f64_s(f64_reinterpret_i64(0xfff8000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xfff4000000000000ull)), trapInvalidConversion, "i32.trunc_f64_s(f64_reinterpret_i64(0xfff4000000000000ull))");
#endif
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x0000000000000000ull)),
        0u,
        "i32.trunc_f64_u(0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x8000000000000000ull)),
        0u,
        "i32.trunc_f64_u(-0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x0000000000000001ull)),
        0u,
        "i32.trunc_f64_u(5e-324)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x8000000000000001ull)),
        0u,
        "i32.trunc_f64_u(-5e-324)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ff0000000000000ull)),
        1u,
        "i32.trunc_f64_u(1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ff199999999999aull)),
        1u,
        "i32.trunc_f64_u(1.1)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ff8000000000000ull)),
        1u,
        "i32.trunc_f64_u(1.5)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ffe666666666666ull)),
        1u,
        "i32.trunc_f64_u(1.9)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x4000000000000000ull)),
        2u,
        "i32.trunc_f64_u(2.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x41e0000000000000ull)),
        2147483648u,
        "i32.trunc_f64_u(2147483648.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x41efffffffe00000ull)),
        4294967295u,
        "i32.trunc_f64_u(4294967295.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbfeccccccccccccdull)),
        0u,
        "i32.trunc_f64_u(-0.9)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbfefffffffffffffull)),
        0u,
        "i32.trunc_f64_u(-0.9999999999999999)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x4197d78400000000ull)),
        100000000u,
        "i32.trunc_f64_u(100000000.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbfeccccccccccccdull)),
        0u,
        "i32.trunc_f64_u(-0.9)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x41effffffffccccdull)),
        4294967295u,
        "i32.trunc_f64_u(4294967295.9)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x41f0000000000000ull)), trapIntOverflow, "i32.trunc_f64_u(4294967296.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbff0000000000000ull)), trapIntOverflow, "i32.trunc_f64_u(-1.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x4341c37937e08000ull)), trapIntOverflow, "i32.trunc_f64_u(1e+16)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x46293e5939a08ceaull)), trapIntOverflow, "i32.trunc_f64_u(1e+30)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x43e0000000000000ull)), trapIntOverflow, "i32.trunc_f64_u(9.223372036854776e+18)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff0000000000000ull)), trapIntOverflow, "i32.trunc_f64_u(INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xfff0000000000000ull)), trapIntOverflow, "i32.trunc_f64_u(-INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)), trapInvalidConversion, "i32.trunc_f64_u(f64_reinterpret_i64(0x7ff8000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff4000000000000ull)), trapInvalidConversion, "i32.trunc_f64_u(f64_reinterpret_i64(0x7ff4000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xfff8000000000000ull)), trapInvalidConversion, "i32.trunc_f64_u(f64_reinterpret_i64(0xfff8000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xfff4000000000000ull)), trapInvalidConversion, "i32.trunc_f64_u(f64_reinterpret_i64(0xfff4000000000000ull))");
#endif
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x00000000u)),
        0ull,
        "i64.trunc_f32_s(0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x80000000u)),
        0ull,
        "i64.trunc_f32_s(-0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x00000001u)),
        0ull,
        "i64.trunc_f32_s(1.401298464324817e-45)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x80000001u)),
        0ull,
        "i64.trunc_f32_s(-1.401298464324817e-45)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x3f800000u)),
        1ull,
        "i64.trunc_f32_s(1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x3f8ccccdu)),
        1ull,
        "i64.trunc_f32_s(1.100000023841858)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x3fc00000u)),
        1ull,
        "i64.trunc_f32_s(1.5)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbf800000u)),
        18446744073709551615ull,
        "i64.trunc_f32_s(-1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbf8ccccdu)),
        18446744073709551615ull,
        "i64.trunc_f32_s(-1.100000023841858)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbfc00000u)),
        18446744073709551615ull,
        "i64.trunc_f32_s(-1.5)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbff33333u)),
        18446744073709551615ull,
        "i64.trunc_f32_s(-1.899999976158142)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xc0000000u)),
        18446744073709551614ull,
        "i64.trunc_f32_s(-2.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x4f800000u)),
        4294967296ull,
        "i64.trunc_f32_s(4294967296.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xcf800000u)),
        18446744069414584320ull,
        "i64.trunc_f32_s(-4294967296.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x5effffffu)),
        9223371487098961920ull,
        "i64.trunc_f32_s(9.223371487098962e+18)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xdf000000u)),
        9223372036854775808ull,
        "i64.trunc_f32_s(-9.223372036854776e+18)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x5f000000u)), trapIntOverflow, "i64.trunc_f32_s(9.223372036854776e+18)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xdf000001u)), trapIntOverflow, "i64.trunc_f32_s(-9.223373136366404e+18)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7f800000u)), trapIntOverflow, "i64.trunc_f32_s(INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xff800000u)), trapIntOverflow, "i64.trunc_f32_s(-INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7fc00000u)), trapInvalidConversion, "i64.trunc_f32_s(f32_reinterpret_i32(0x7fc00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7fa00000u)), trapInvalidConversion, "i64.trunc_f32_s(f32_reinterpret_i32(0x7fa00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xffc00000u)), trapInvalidConversion, "i64.trunc_f32_s(f32_reinterpret_i32(0xffc00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xffa00000u)), trapInvalidConversion, "i64.trunc_f32_s(f32_reinterpret_i32(0xffa00000u))");
#endif
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x00000000u)),
        0ull,
        "i64.trunc_f32_u(0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x80000000u)),
        0ull,
        "i64.trunc_f32_u(-0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x00000001u)),
        0ull,
        "i64.trunc_f32_u(1.401298464324817e-45)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x80000001u)),
        0ull,
        "i64.trunc_f32_u(-1.401298464324817e-45)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3f800000u)),
        1ull,
        "i64.trunc_f32_u(1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3f8ccccdu)),
        1ull,
        "i64.trunc_f32_u(1.100000023841858)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3fc00000u)),
        1ull,
        "i64.trunc_f32_u(1.5)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x4f800000u)),
        4294967296ull,
        "i64.trunc_f32_u(4294967296.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x5f7fffffu)),
        18446742974197923840ull,
        "i64.trunc_f32_u(1.8446742974197924e+19)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xbf666666u)),
        0ull,
        "i64.trunc_f32_u(-0.8999999761581421)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xbf7fffffu)),
        0ull,
        "i64.trunc_f32_u(-0.9999999403953552)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x5f800000u)), trapIntOverflow, "i64.trunc_f32_u(1.8446744073709552e+19)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xbf800000u)), trapIntOverflow, "i64.trunc_f32_u(-1.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7f800000u)), trapIntOverflow, "i64.trunc_f32_u(INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xff800000u)), trapIntOverflow, "i64.trunc_f32_u(-INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7fc00000u)), trapInvalidConversion, "i64.trunc_f32_u(f32_reinterpret_i32(0x7fc00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7fa00000u)), trapInvalidConversion, "i64.trunc_f32_u(f32_reinterpret_i32(0x7fa00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xffc00000u)), trapInvalidConversion, "i64.trunc_f32_u(f32_reinterpret_i32(0xffc00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xffa00000u)), trapInvalidConversion, "i64.trunc_f32_u(f32_reinterpret_i32(0xffa00000u))");
#endif
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x0000000000000000ull)),
        0ull,
        "i64.trunc_f64_s(0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x8000000000000000ull)),
        0ull,
        "i64.trunc_f64_s(-0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x0000000000000001ull)),
        0ull,
        "i64.trunc_f64_s(5e-324)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x8000000000000001ull)),
        0ull,
        "i64.trunc_f64_s(-5e-324)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x3ff0000000000000ull)),
        1ull,
        "i64.trunc_f64_s(1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x3ff199999999999aull)),
        1ull,
        "i64.trunc_f64_s(1.1)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x3ff8000000000000ull)),
        1ull,
        "i64.trunc_f64_s(1.5)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbff0000000000000ull)),
        18446744073709551615ull,
        "i64.trunc_f64_s(-1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbff199999999999aull)),
        18446744073709551615ull,
        "i64.trunc_f64_s(-1.1)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbff8000000000000ull)),
        18446744073709551615ull,
        "i64.trunc_f64_s(-1.5)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbffe666666666666ull)),
        18446744073709551615ull,
        "i64.trunc_f64_s(-1.9)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc000000000000000ull)),
        18446744073709551614ull,
        "i64.trunc_f64_s(-2.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x41f0000000000000ull)),
        4294967296ull,
        "i64.trunc_f64_s(4294967296.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc1f0000000000000ull)),
        18446744069414584320ull,
        "i64.trunc_f64_s(-4294967296.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x43dfffffffffffffull)),
        9223372036854774784ull,
        "i64.trunc_f64_s(9.223372036854775e+18)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc3e0000000000000ull)),
        9223372036854775808ull,
        "i64.trunc_f64_s(-9.223372036854776e+18)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x43e0000000000000ull)), trapIntOverflow, "i64.trunc_f64_s(9.223372036854776e+18)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc3e0000000000001ull)), trapIntOverflow, "i64.trunc_f64_s(-9.223372036854778e+18)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff0000000000000ull)), trapIntOverflow, "i64.trunc_f64_s(INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xfff0000000000000ull)), trapIntOverflow, "i64.trunc_f64_s(-INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)), trapInvalidConversion, "i64.trunc_f64_s(f64_reinterpret_i64(0x7ff8000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff4000000000000ull)), trapInvalidConversion, "i64.trunc_f64_s(f64_reinterpret_i64(0x7ff4000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xfff8000000000000ull)), trapInvalidConversion, "i64.trunc_f64_s(f64_reinterpret_i64(0xfff8000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xfff4000000000000ull)), trapInvalidConversion, "i64.trunc_f64_s(f64_reinterpret_i64(0xfff4000000000000ull))");
#endif
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x0000000000000000ull)),
        0ull,
        "i64.trunc_f64_u(0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x8000000000000000ull)),
        0ull,
        "i64.trunc_f64_u(-0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x0000000000000001ull)),
        0ull,
        "i64.trunc_f64_u(5e-324)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x8000000000000001ull)),
        0ull,
        "i64.trunc_f64_u(-5e-324)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ff0000000000000ull)),
        1ull,
        "i64.trunc_f64_u(1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ff199999999999aull)),
        1ull,
        "i64.trunc_f64_u(1.1)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ff8000000000000ull)),
        1ull,
        "i64.trunc_f64_u(1.5)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x41efffffffe00000ull)),
        4294967295ull,
        "i64.trunc_f64_u(4294967295.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x41f0000000000000ull)),
        4294967296ull,
        "i64.trunc_f64_u(4294967296.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x43efffffffffffffull)),
        18446744073709549568ull,
        "i64.trunc_f64_u(1.844674407370955e+19)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbfeccccccccccccdull)),
        0ull,
        "i64.trunc_f64_u(-0.9)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbfefffffffffffffull)),
        0ull,
        "i64.trunc_f64_u(-0.9999999999999999)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x4197d78400000000ull)),
        100000000ull,
        "i64.trunc_f64_u(100000000.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x4341c37937e08000ull)),
        10000000000000000ull,
        "i64.trunc_f64_u(1e+16)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x43e0000000000000ull)),
        9223372036854775808ull,
        "i64.trunc_f64_u(9.223372036854776e+18)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x43f0000000000000ull)), trapIntOverflow, "i64.trunc_f64_u(1.8446744073709552e+19)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbff0000000000000ull)), trapIntOverflow, "i64.trunc_f64_u(-1.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff0000000000000ull)), trapIntOverflow, "i64.trunc_f64_u(INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xfff0000000000000ull)), trapIntOverflow, "i64.trunc_f64_u(-INFINITY)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)), trapInvalidConversion, "i64.trunc_f64_u(f64_reinterpret_i64(0x7ff8000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff4000000000000ull)), trapInvalidConversion, "i64.trunc_f64_u(f64_reinterpret_i64(0x7ff4000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xfff8000000000000ull)), trapInvalidConversion, "i64.trunc_f64_u(f64_reinterpret_i64(0xfff8000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_conversionsX2E0Export15_i64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xfff4000000000000ull)), trapInvalidConversion, "i64.trunc_f64_u(f64_reinterpret_i64(0xfff4000000000000ull))");
#endif
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fs(&instance, 1u)),
        1065353216u,
        "f32.convert_i32_s(1u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fs(&instance, 4294967295u)),
        3212836864u,
        "f32.convert_i32_s(4294967295u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fs(&instance, 0u)),
        0u,
        "f32.convert_i32_s(0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fs(&instance, 2147483647u)),
        1325400064u,
        "f32.convert_i32_s(2147483647u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fs(&instance, 2147483648u)),
        3472883712u,
        "f32.convert_i32_s(2147483648u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fs(&instance, 1234567890u)),
        1318267910u,
        "f32.convert_i32_s(1234567890u)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x00000000u)),
        0u,
        "i32.trunc_sat_f32_s(0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x80000000u)),
        0u,
        "i32.trunc_sat_f32_s(-0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x00000001u)),
        0u,
        "i32.trunc_sat_f32_s(1.401298464324817e-45)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x80000001u)),
        0u,
        "i32.trunc_sat_f32_s(-1.401298464324817e-45)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x3f800000u)),
        1u,
        "i32.trunc_sat_f32_s(1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x3f8ccccdu)),
        1u,
        "i32.trunc_sat_f32_s(1.100000023841858)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x3fc00000u)),
        1u,
        "i32.trunc_sat_f32_s(1.5)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbf800000u)),
        4294967295u,
        "i32.trunc_sat_f32_s(-1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbf8ccccdu)),
        4294967295u,
        "i32.trunc_sat_f32_s(-1.100000023841858)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbfc00000u)),
        4294967295u,
        "i32.trunc_sat_f32_s(-1.5)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbff33333u)),
        4294967295u,
        "i32.trunc_sat_f32_s(-1.899999976158142)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xc0000000u)),
        4294967294u,
        "i32.trunc_sat_f32_s(-2.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x4effffffu)),
        2147483520u,
        "i32.trunc_sat_f32_s(2147483520.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xcf000000u)),
        2147483648u,
        "i32.trunc_sat_f32_s(-2147483648.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x4f000000u)),
        2147483647u,
        "i32.trunc_sat_f32_s(2147483648.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xcf000001u)),
        2147483648u,
        "i32.trunc_sat_f32_s(-2147483904.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7f800000u)),
        2147483647u,
        "i32.trunc_sat_f32_s(INFINITY)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xff800000u)),
        2147483648u,
        "i32.trunc_sat_f32_s(-INFINITY)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7fc00000u)),
        0u,
        "i32.trunc_sat_f32_s(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7fa00000u)),
        0u,
        "i32.trunc_sat_f32_s(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xffc00000u)),
        0u,
        "i32.trunc_sat_f32_s(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xffa00000u)),
        0u,
        "i32.trunc_sat_f32_s(f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x00000000u)),
        0u,
        "i32.trunc_sat_f32_u(0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x80000000u)),
        0u,
        "i32.trunc_sat_f32_u(-0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x00000001u)),
        0u,
        "i32.trunc_sat_f32_u(1.401298464324817e-45)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x80000001u)),
        0u,
        "i32.trunc_sat_f32_u(-1.401298464324817e-45)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3f800000u)),
        1u,
        "i32.trunc_sat_f32_u(1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3f8ccccdu)),
        1u,
        "i32.trunc_sat_f32_u(1.100000023841858)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3fc00000u)),
        1u,
        "i32.trunc_sat_f32_u(1.5)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3ff33333u)),
        1u,
        "i32.trunc_sat_f32_u(1.899999976158142)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x40000000u)),
        2u,
        "i32.trunc_sat_f32_u(2.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x4f000000u)),
        2147483648u,
        "i32.trunc_sat_f32_u(2147483648.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x4f7fffffu)),
        4294967040u,
        "i32.trunc_sat_f32_u(4294967040.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xbf666666u)),
        0u,
        "i32.trunc_sat_f32_u(-0.8999999761581421)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xbf7fffffu)),
        0u,
        "i32.trunc_sat_f32_u(-0.9999999403953552)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x4f800000u)),
        4294967295u,
        "i32.trunc_sat_f32_u(4294967296.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xbf800000u)),
        0u,
        "i32.trunc_sat_f32_u(-1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7f800000u)),
        4294967295u,
        "i32.trunc_sat_f32_u(INFINITY)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xff800000u)),
        0u,
        "i32.trunc_sat_f32_u(-INFINITY)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7fc00000u)),
        0u,
        "i32.trunc_sat_f32_u(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7fa00000u)),
        0u,
        "i32.trunc_sat_f32_u(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xffc00000u)),
        0u,
        "i32.trunc_sat_f32_u(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xffa00000u)),
        0u,
        "i32.trunc_sat_f32_u(f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x0000000000000000ull)),
        0u,
        "i32.trunc_sat_f64_s(0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x8000000000000000ull)),
        0u,
        "i32.trunc_sat_f64_s(-0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x0000000000000001ull)),
        0u,
        "i32.trunc_sat_f64_s(5e-324)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x8000000000000001ull)),
        0u,
        "i32.trunc_sat_f64_s(-5e-324)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x3ff0000000000000ull)),
        1u,
        "i32.trunc_sat_f64_s(1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x3ff199999999999aull)),
        1u,
        "i32.trunc_sat_f64_s(1.1)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x3ff8000000000000ull)),
        1u,
        "i32.trunc_sat_f64_s(1.5)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbff0000000000000ull)),
        4294967295u,
        "i32.trunc_sat_f64_s(-1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbff199999999999aull)),
        4294967295u,
        "i32.trunc_sat_f64_s(-1.1)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbff8000000000000ull)),
        4294967295u,
        "i32.trunc_sat_f64_s(-1.5)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbffe666666666666ull)),
        4294967295u,
        "i32.trunc_sat_f64_s(-1.9)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc000000000000000ull)),
        4294967294u,
        "i32.trunc_sat_f64_s(-2.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x41dfffffffc00000ull)),
        2147483647u,
        "i32.trunc_sat_f64_s(2147483647.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc1e0000000000000ull)),
        2147483648u,
        "i32.trunc_sat_f64_s(-2147483648.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x41e0000000000000ull)),
        2147483647u,
        "i32.trunc_sat_f64_s(2147483648.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc1e0000000200000ull)),
        2147483648u,
        "i32.trunc_sat_f64_s(-2147483649.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff0000000000000ull)),
        2147483647u,
        "i32.trunc_sat_f64_s(INFINITY)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xfff0000000000000ull)),
        2147483648u,
        "i32.trunc_sat_f64_s(-INFINITY)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)),
        0u,
        "i32.trunc_sat_f64_s(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff4000000000000ull)),
        0u,
        "i32.trunc_sat_f64_s(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xfff8000000000000ull)),
        0u,
        "i32.trunc_sat_f64_s(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xfff4000000000000ull)),
        0u,
        "i32.trunc_sat_f64_s(f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x0000000000000000ull)),
        0u,
        "i32.trunc_sat_f64_u(0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x8000000000000000ull)),
        0u,
        "i32.trunc_sat_f64_u(-0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x0000000000000001ull)),
        0u,
        "i32.trunc_sat_f64_u(5e-324)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x8000000000000001ull)),
        0u,
        "i32.trunc_sat_f64_u(-5e-324)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ff0000000000000ull)),
        1u,
        "i32.trunc_sat_f64_u(1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ff199999999999aull)),
        1u,
        "i32.trunc_sat_f64_u(1.1)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ff8000000000000ull)),
        1u,
        "i32.trunc_sat_f64_u(1.5)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ffe666666666666ull)),
        1u,
        "i32.trunc_sat_f64_u(1.9)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x4000000000000000ull)),
        2u,
        "i32.trunc_sat_f64_u(2.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x41e0000000000000ull)),
        2147483648u,
        "i32.trunc_sat_f64_u(2147483648.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x41efffffffe00000ull)),
        4294967295u,
        "i32.trunc_sat_f64_u(4294967295.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbfeccccccccccccdull)),
        0u,
        "i32.trunc_sat_f64_u(-0.9)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbfefffffffffffffull)),
        0u,
        "i32.trunc_sat_f64_u(-0.9999999999999999)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x4197d78400000000ull)),
        100000000u,
        "i32.trunc_sat_f64_u(100000000.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x41f0000000000000ull)),
        4294967295u,
        "i32.trunc_sat_f64_u(4294967296.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbff0000000000000ull)),
        0u,
        "i32.trunc_sat_f64_u(-1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x4341c37937e08000ull)),
        4294967295u,
        "i32.trunc_sat_f64_u(1e+16)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x46293e5939a08ceaull)),
        4294967295u,
        "i32.trunc_sat_f64_u(1e+30)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x43e0000000000000ull)),
        4294967295u,
        "i32.trunc_sat_f64_u(9.223372036854776e+18)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff0000000000000ull)),
        4294967295u,
        "i32.trunc_sat_f64_u(INFINITY)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xfff0000000000000ull)),
        0u,
        "i32.trunc_sat_f64_u(-INFINITY)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)),
        0u,
        "i32.trunc_sat_f64_u(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff4000000000000ull)),
        0u,
        "i32.trunc_sat_f64_u(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xfff8000000000000ull)),
        0u,
        "i32.trunc_sat_f64_u(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xfff4000000000000ull)),
        0u,
        "i32.trunc_sat_f64_u(f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x00000000u)),
        0ull,
        "i64.trunc_sat_f32_s(0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x80000000u)),
        0ull,
        "i64.trunc_sat_f32_s(-0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x00000001u)),
        0ull,
        "i64.trunc_sat_f32_s(1.401298464324817e-45)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x80000001u)),
        0ull,
        "i64.trunc_sat_f32_s(-1.401298464324817e-45)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x3f800000u)),
        1ull,
        "i64.trunc_sat_f32_s(1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x3f8ccccdu)),
        1ull,
        "i64.trunc_sat_f32_s(1.100000023841858)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x3fc00000u)),
        1ull,
        "i64.trunc_sat_f32_s(1.5)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbf800000u)),
        18446744073709551615ull,
        "i64.trunc_sat_f32_s(-1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbf8ccccdu)),
        18446744073709551615ull,
        "i64.trunc_sat_f32_s(-1.100000023841858)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbfc00000u)),
        18446744073709551615ull,
        "i64.trunc_sat_f32_s(-1.5)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xbff33333u)),
        18446744073709551615ull,
        "i64.trunc_sat_f32_s(-1.899999976158142)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xc0000000u)),
        18446744073709551614ull,
        "i64.trunc_sat_f32_s(-2.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x4f800000u)),
        4294967296ull,
        "i64.trunc_sat_f32_s(4294967296.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xcf800000u)),
        18446744069414584320ull,
        "i64.trunc_sat_f32_s(-4294967296.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x5effffffu)),
        9223371487098961920ull,
        "i64.trunc_sat_f32_s(9.223371487098962e+18)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xdf000000u)),
        9223372036854775808ull,
        "i64.trunc_sat_f32_s(-9.223372036854776e+18)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x5f000000u)),
        9223372036854775807ull,
        "i64.trunc_sat_f32_s(9.223372036854776e+18)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xdf000001u)),
        9223372036854775808ull,
        "i64.trunc_sat_f32_s(-9.223373136366404e+18)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7f800000u)),
        9223372036854775807ull,
        "i64.trunc_sat_f32_s(INFINITY)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xff800000u)),
        9223372036854775808ull,
        "i64.trunc_sat_f32_s(-INFINITY)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7fc00000u)),
        0ull,
        "i64.trunc_sat_f32_s(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7fa00000u)),
        0ull,
        "i64.trunc_sat_f32_s(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xffc00000u)),
        0ull,
        "i64.trunc_sat_f32_s(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fs(&instance, f32_reinterpret_i32(0xffa00000u)),
        0ull,
        "i64.trunc_sat_f32_s(f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x00000000u)),
        0ull,
        "i64.trunc_sat_f32_u(0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x80000000u)),
        0ull,
        "i64.trunc_sat_f32_u(-0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x00000001u)),
        0ull,
        "i64.trunc_sat_f32_u(1.401298464324817e-45)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x80000001u)),
        0ull,
        "i64.trunc_sat_f32_u(-1.401298464324817e-45)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3f800000u)),
        1ull,
        "i64.trunc_sat_f32_u(1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3f8ccccdu)),
        1ull,
        "i64.trunc_sat_f32_u(1.100000023841858)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x3fc00000u)),
        1ull,
        "i64.trunc_sat_f32_u(1.5)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x4f800000u)),
        4294967296ull,
        "i64.trunc_sat_f32_u(4294967296.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x5f7fffffu)),
        18446742974197923840ull,
        "i64.trunc_sat_f32_u(1.8446742974197924e+19)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xbf666666u)),
        0ull,
        "i64.trunc_sat_f32_u(-0.8999999761581421)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xbf7fffffu)),
        0ull,
        "i64.trunc_sat_f32_u(-0.9999999403953552)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x5f800000u)),
        18446744073709551615ull,
        "i64.trunc_sat_f32_u(1.8446744073709552e+19)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xbf800000u)),
        0ull,
        "i64.trunc_sat_f32_u(-1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7f800000u)),
        18446744073709551615ull,
        "i64.trunc_sat_f32_u(INFINITY)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xff800000u)),
        0ull,
        "i64.trunc_sat_f32_u(-INFINITY)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7fc00000u)),
        0ull,
        "i64.trunc_sat_f32_u(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7fa00000u)),
        0ull,
        "i64.trunc_sat_f32_u(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xffc00000u)),
        0ull,
        "i64.trunc_sat_f32_u(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff32X5Fu(&instance, f32_reinterpret_i32(0xffa00000u)),
        0ull,
        "i64.trunc_sat_f32_u(f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x0000000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_s(0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x8000000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_s(-0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x0000000000000001ull)),
        0ull,
        "i64.trunc_sat_f64_s(5e-324)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x8000000000000001ull)),
        0ull,
        "i64.trunc_sat_f64_s(-5e-324)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x3ff0000000000000ull)),
        1ull,
        "i64.trunc_sat_f64_s(1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x3ff199999999999aull)),
        1ull,
        "i64.trunc_sat_f64_s(1.1)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x3ff8000000000000ull)),
        1ull,
        "i64.trunc_sat_f64_s(1.5)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbff0000000000000ull)),
        18446744073709551615ull,
        "i64.trunc_sat_f64_s(-1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbff199999999999aull)),
        18446744073709551615ull,
        "i64.trunc_sat_f64_s(-1.1)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbff8000000000000ull)),
        18446744073709551615ull,
        "i64.trunc_sat_f64_s(-1.5)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xbffe666666666666ull)),
        18446744073709551615ull,
        "i64.trunc_sat_f64_s(-1.9)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc000000000000000ull)),
        18446744073709551614ull,
        "i64.trunc_sat_f64_s(-2.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x41f0000000000000ull)),
        4294967296ull,
        "i64.trunc_sat_f64_s(4294967296.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc1f0000000000000ull)),
        18446744069414584320ull,
        "i64.trunc_sat_f64_s(-4294967296.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x43dfffffffffffffull)),
        9223372036854774784ull,
        "i64.trunc_sat_f64_s(9.223372036854775e+18)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc3e0000000000000ull)),
        9223372036854775808ull,
        "i64.trunc_sat_f64_s(-9.223372036854776e+18)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x43e0000000000000ull)),
        9223372036854775807ull,
        "i64.trunc_sat_f64_s(9.223372036854776e+18)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xc3e0000000000001ull)),
        9223372036854775808ull,
        "i64.trunc_sat_f64_s(-9.223372036854778e+18)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff0000000000000ull)),
        9223372036854775807ull,
        "i64.trunc_sat_f64_s(INFINITY)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xfff0000000000000ull)),
        9223372036854775808ull,
        "i64.trunc_sat_f64_s(-INFINITY)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_s(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff4000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_s(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xfff8000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_s(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fs(&instance, f64_reinterpret_i64(0xfff4000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_s(f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x0000000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_u(0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x8000000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_u(-0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x0000000000000001ull)),
        0ull,
        "i64.trunc_sat_f64_u(5e-324)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x8000000000000001ull)),
        0ull,
        "i64.trunc_sat_f64_u(-5e-324)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ff0000000000000ull)),
        1ull,
        "i64.trunc_sat_f64_u(1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ff199999999999aull)),
        1ull,
        "i64.trunc_sat_f64_u(1.1)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x3ff8000000000000ull)),
        1ull,
        "i64.trunc_sat_f64_u(1.5)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x41efffffffe00000ull)),
        4294967295ull,
        "i64.trunc_sat_f64_u(4294967295.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x41f0000000000000ull)),
        4294967296ull,
        "i64.trunc_sat_f64_u(4294967296.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x43efffffffffffffull)),
        18446744073709549568ull,
        "i64.trunc_sat_f64_u(1.844674407370955e+19)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbfeccccccccccccdull)),
        0ull,
        "i64.trunc_sat_f64_u(-0.9)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbfefffffffffffffull)),
        0ull,
        "i64.trunc_sat_f64_u(-0.9999999999999999)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x4197d78400000000ull)),
        100000000ull,
        "i64.trunc_sat_f64_u(100000000.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x4341c37937e08000ull)),
        10000000000000000ull,
        "i64.trunc_sat_f64_u(1e+16)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x43e0000000000000ull)),
        9223372036854775808ull,
        "i64.trunc_sat_f64_u(9.223372036854776e+18)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x43f0000000000000ull)),
        18446744073709551615ull,
        "i64.trunc_sat_f64_u(1.8446744073709552e+19)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xbff0000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_u(-1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff0000000000000ull)),
        18446744073709551615ull,
        "i64.trunc_sat_f64_u(INFINITY)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xfff0000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_u(-INFINITY)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_u(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff4000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_u(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xfff8000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_u(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EtruncX5FsatX5Ff64X5Fu(&instance, f64_reinterpret_i64(0xfff4000000000000ull)),
        0ull,
        "i64.trunc_sat_f64_u(f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fs(&instance, 16777217u)),
        1266679808u,
        "f32.convert_i32_s(16777217u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fs(&instance, 4278190079u)),
        3414163456u,
        "f32.convert_i32_s(4278190079u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fs(&instance, 16777219u)),
        1266679810u,
        "f32.convert_i32_s(16777219u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fs(&instance, 4278190077u)),
        3414163458u,
        "f32.convert_i32_s(4278190077u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 1ull)),
        1065353216u,
        "f32.convert_i64_s(1ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 18446744073709551615ull)),
        3212836864u,
        "f32.convert_i64_s(18446744073709551615ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 0ull)),
        0u,
        "f32.convert_i64_s(0ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 9223372036854775807ull)),
        1593835520u,
        "f32.convert_i64_s(9223372036854775807ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 9223372036854775808ull)),
        3741319168u,
        "f32.convert_i64_s(9223372036854775808ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 314159265358979ull)),
        1468980468u,
        "f32.convert_i64_s(314159265358979ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 16777217ull)),
        1266679808u,
        "f32.convert_i64_s(16777217ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 18446744073692774399ull)),
        3414163456u,
        "f32.convert_i64_s(18446744073692774399ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 16777219ull)),
        1266679810u,
        "f32.convert_i64_s(16777219ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 18446744073692774397ull)),
        3414163458u,
        "f32.convert_i64_s(18446744073692774397ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 9223371212221054977ull)),
        1593835519u,
        "f32.convert_i64_s(9223371212221054977ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 9223372311732682753ull)),
        3741319167u,
        "f32.convert_i64_s(9223372311732682753ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 9007199791611905ull)),
        1509949441u,
        "f32.convert_i64_s(9007199791611905ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fs(&instance, 18437736873917939711ull)),
        3657433089u,
        "f32.convert_i64_s(18437736873917939711ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi32X5Fs(&instance, 1u)),
        4607182418800017408ull,
        "f64.convert_i32_s(1u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi32X5Fs(&instance, 4294967295u)),
        13830554455654793216ull,
        "f64.convert_i32_s(4294967295u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi32X5Fs(&instance, 0u)),
        0ull,
        "f64.convert_i32_s(0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi32X5Fs(&instance, 2147483647u)),
        4746794007244308480ull,
        "f64.convert_i32_s(2147483647u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi32X5Fs(&instance, 2147483648u)),
        13970166044103278592ull,
        "f64.convert_i32_s(2147483648u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi32X5Fs(&instance, 987654321u)),
        4741568253304766464ull,
        "f64.convert_i32_s(987654321u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fs(&instance, 1ull)),
        4607182418800017408ull,
        "f64.convert_i64_s(1ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fs(&instance, 18446744073709551615ull)),
        13830554455654793216ull,
        "f64.convert_i64_s(18446744073709551615ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fs(&instance, 0ull)),
        0ull,
        "f64.convert_i64_s(0ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fs(&instance, 9223372036854775807ull)),
        4890909195324358656ull,
        "f64.convert_i64_s(9223372036854775807ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fs(&instance, 9223372036854775808ull)),
        14114281232179134464ull,
        "f64.convert_i64_s(9223372036854775808ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fs(&instance, 4669201609102990ull)),
        4841535201405015694ull,
        "f64.convert_i64_s(4669201609102990ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fs(&instance, 9007199254740993ull)),
        4845873199050653696ull,
        "f64.convert_i64_s(9007199254740993ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fs(&instance, 18437736874454810623ull)),
        14069245235905429504ull,
        "f64.convert_i64_s(18437736874454810623ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fs(&instance, 9007199254740995ull)),
        4845873199050653698ull,
        "f64.convert_i64_s(9007199254740995ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fs(&instance, 18437736874454810621ull)),
        14069245235905429506ull,
        "f64.convert_i64_s(18437736874454810621ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 1u)),
        1065353216u,
        "f32.convert_i32_u(1u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 0u)),
        0u,
        "f32.convert_i32_u(0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 2147483647u)),
        1325400064u,
        "f32.convert_i32_u(2147483647u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 2147483648u)),
        1325400064u,
        "f32.convert_i32_u(2147483648u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 305419896u)),
        1301390004u,
        "f32.convert_i32_u(305419896u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 4294967295u)),
        1333788672u,
        "f32.convert_i32_u(4294967295u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 2147483776u)),
        1325400064u,
        "f32.convert_i32_u(2147483776u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 2147483777u)),
        1325400065u,
        "f32.convert_i32_u(2147483777u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 2147483778u)),
        1325400065u,
        "f32.convert_i32_u(2147483778u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 4294966912u)),
        1333788670u,
        "f32.convert_i32_u(4294966912u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 4294966913u)),
        1333788671u,
        "f32.convert_i32_u(4294966913u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 4294966914u)),
        1333788671u,
        "f32.convert_i32_u(4294966914u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 16777217u)),
        1266679808u,
        "f32.convert_i32_u(16777217u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi32X5Fu(&instance, 16777219u)),
        1266679810u,
        "f32.convert_i32_u(16777219u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fu(&instance, 1ull)),
        1065353216u,
        "f32.convert_i64_u(1ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fu(&instance, 0ull)),
        0u,
        "f32.convert_i64_u(0ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fu(&instance, 9223372036854775807ull)),
        1593835520u,
        "f32.convert_i64_u(9223372036854775807ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fu(&instance, 9223372036854775808ull)),
        1593835520u,
        "f32.convert_i64_u(9223372036854775808ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fu(&instance, 18446744073709551615ull)),
        1602224128u,
        "f32.convert_i64_u(18446744073709551615ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fu(&instance, 16777217ull)),
        1266679808u,
        "f32.convert_i64_u(16777217ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fu(&instance, 16777219ull)),
        1266679810u,
        "f32.convert_i64_u(16777219ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fu(&instance, 9007199791611905ull)),
        1509949441u,
        "f32.convert_i64_u(9007199791611905ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fu(&instance, 9223371761976868863ull)),
        1593835519u,
        "f32.convert_i64_u(9223371761976868863ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fu(&instance, 9223372586610589697ull)),
        1593835521u,
        "f32.convert_i64_u(9223372586610589697ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export17_f32X2EconvertX5Fi64X5Fu(&instance, 18446742424442109953ull)),
        1602224127u,
        "f32.convert_i64_u(18446742424442109953ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi32X5Fu(&instance, 1u)),
        4607182418800017408ull,
        "f64.convert_i32_u(1u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi32X5Fu(&instance, 0u)),
        0ull,
        "f64.convert_i32_u(0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi32X5Fu(&instance, 2147483647u)),
        4746794007244308480ull,
        "f64.convert_i32_u(2147483647u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi32X5Fu(&instance, 2147483648u)),
        4746794007248502784ull,
        "f64.convert_i32_u(2147483648u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi32X5Fu(&instance, 4294967295u)),
        4751297606873776128ull,
        "f64.convert_i32_u(4294967295u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 1ull)),
        4607182418800017408ull,
        "f64.convert_i64_u(1ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 0ull)),
        0ull,
        "f64.convert_i64_u(0ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 9223372036854775807ull)),
        4890909195324358656ull,
        "f64.convert_i64_u(9223372036854775807ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 9223372036854775808ull)),
        4890909195324358656ull,
        "f64.convert_i64_u(9223372036854775808ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 18446744073709551615ull)),
        4895412794951729152ull,
        "f64.convert_i64_u(18446744073709551615ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 9223372036854776832ull)),
        4890909195324358656ull,
        "f64.convert_i64_u(9223372036854776832ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 9223372036854776833ull)),
        4890909195324358657ull,
        "f64.convert_i64_u(9223372036854776833ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 9223372036854776834ull)),
        4890909195324358657ull,
        "f64.convert_i64_u(9223372036854776834ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 18446744073709548544ull)),
        4895412794951729150ull,
        "f64.convert_i64_u(18446744073709548544ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 18446744073709548545ull)),
        4895412794951729151ull,
        "f64.convert_i64_u(18446744073709548545ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 18446744073709548546ull)),
        4895412794951729151ull,
        "f64.convert_i64_u(18446744073709548546ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 9007199254740993ull)),
        4845873199050653696ull,
        "f64.convert_i64_u(9007199254740993ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export17_f64X2EconvertX5Fi64X5Fu(&instance, 9007199254740995ull)),
        4845873199050653698ull,
        "f64.convert_i64_u(9007199254740995ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0x00000000u))),
        0ull,
        "f64.promote_f32(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0x80000000u))),
        9223372036854775808ull,
        "f64.promote_f32(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0x00000001u))),
        3936146074321813504ull,
        "f64.promote_f32(1.401298464324817e-45)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0x80000001u))),
        13159518111176589312ull,
        "f64.promote_f32(-1.401298464324817e-45)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0x3f800000u))),
        4607182418800017408ull,
        "f64.promote_f32(1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0xbf800000u))),
        13830554455654793216ull,
        "f64.promote_f32(-1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0xff7fffffu))),
        14407015207421345792ull,
        "f64.promote_f32(-3.4028234663852886e+38)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0x7f7fffffu))),
        5183643170566569984ull,
        "f64.promote_f32(3.4028234663852886e+38)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0x04000000u))),
        4071254063142928384ull,
        "f64.promote_f32(1.504632769052528e-36)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0x7e47c33fu))),
        5172657297058430976ull,
        "f64.promote_f32(6.6382536710104395e+37)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0x7f800000u))),
        9218868437227405312ull,
        "f64.promote_f32(INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0xff800000u))),
        18442240474082181120ull,
        "f64.promote_f32(-INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0x7fc00000u))) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.promote_f32(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0x7fa00000u))) & 9221120237041090560ull),
        9221120237041090560ull,
        "f64.promote_f32(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0xffc00000u))) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.promote_f32(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m13_conversionsX2E0Export15_f64X2EpromoteX5Ff32(&instance, f32_reinterpret_i32(0xffa00000u))) & 9221120237041090560ull),
        9221120237041090560ull,
        "f64.promote_f32(f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x0000000000000000ull))),
        0u,
        "f32.demote_f64(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x8000000000000000ull))),
        2147483648u,
        "f32.demote_f64(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x0000000000000001ull))),
        0u,
        "f32.demote_f64(5e-324)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x8000000000000001ull))),
        2147483648u,
        "f32.demote_f64(-5e-324)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x3ff0000000000000ull))),
        1065353216u,
        "f32.demote_f64(1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xbff0000000000000ull))),
        3212836864u,
        "f32.demote_f64(-1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x380fffffe0000000ull))),
        8388608u,
        "f32.demote_f64(1.1754942807573643e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xb80fffffe0000000ull))),
        2155872256u,
        "f32.demote_f64(-1.1754942807573643e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x380fffffdfffffffull))),
        8388607u,
        "f32.demote_f64(1.1754942807573642e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xb80fffffdfffffffull))),
        2155872255u,
        "f32.demote_f64(-1.1754942807573642e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x36a0000000000000ull))),
        1u,
        "f32.demote_f64(1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xb6a0000000000000ull))),
        2147483649u,
        "f32.demote_f64(-1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x47efffffd0000000ull))),
        2139095038u,
        "f32.demote_f64(3.4028233649732406e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xc7efffffd0000000ull))),
        4286578686u,
        "f32.demote_f64(-3.4028233649732406e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x47efffffd0000001ull))),
        2139095039u,
        "f32.demote_f64(3.402823364973241e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xc7efffffd0000001ull))),
        4286578687u,
        "f32.demote_f64(-3.402823364973241e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x47efffffe0000000ull))),
        2139095039u,
        "f32.demote_f64(3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xc7efffffe0000000ull))),
        4286578687u,
        "f32.demote_f64(-3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x47efffffefffffffull))),
        2139095039u,
        "f32.demote_f64(3.4028235677973362e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xc7efffffefffffffull))),
        4286578687u,
        "f32.demote_f64(-3.4028235677973362e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x47effffff0000000ull))),
        2139095040u,
        "f32.demote_f64(3.4028235677973366e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xc7effffff0000000ull))),
        4286578688u,
        "f32.demote_f64(-3.4028235677973366e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x3880000000000000ull))),
        67108864u,
        "f32.demote_f64(1.504632769052528e-36)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x47c8f867e0000000ull))),
        2118632255u,
        "f32.demote_f64(6.6382536710104395e+37)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x7ff0000000000000ull))),
        2139095040u,
        "f32.demote_f64(INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xfff0000000000000ull))),
        4286578688u,
        "f32.demote_f64(-INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x3ff0000000000001ull))),
        1065353216u,
        "f32.demote_f64(1.0000000000000002)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x3fefffffffffffffull))),
        1065353216u,
        "f32.demote_f64(0.9999999999999999)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x3ff0000010000000ull))),
        1065353216u,
        "f32.demote_f64(1.0000000596046448)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x3ff0000010000001ull))),
        1065353217u,
        "f32.demote_f64(1.000000059604645)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x3ff000002fffffffull))),
        1065353217u,
        "f32.demote_f64(1.000000178813934)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x3ff0000030000000ull))),
        1065353218u,
        "f32.demote_f64(1.0000001788139343)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x3ff0000050000000ull))),
        1065353218u,
        "f32.demote_f64(1.0000002980232239)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x4170000010000000ull))),
        1266679808u,
        "f32.demote_f64(16777217.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x4170000010000001ull))),
        1266679809u,
        "f32.demote_f64(16777217.000000004)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x417000002fffffffull))),
        1266679809u,
        "f32.demote_f64(16777218.999999996)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x4170000030000000ull))),
        1266679810u,
        "f32.demote_f64(16777219.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x46b4eae4f7024c70ull))),
        1973901096u,
        "f32.demote_f64(4.242584432991427e+32)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x38ea12e71e358685ull))),
        122722105u,
        "f32.demote_f64(1.569262107843488e-34)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x380cb98354d521ffull))),
        7529997u,
        "f32.demote_f64(1.0551773688605172e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xc006972b30cfb562ull))),
        3224680794u,
        "f32.demote_f64(-2.8238128484141933)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xc6fbedbe4819d4c4ull))),
        4158615026u,
        "f32.demote_f64(-9.063376370095757e+33)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x7ff8000000000000ull))) & 2147483647u),
        2143289344u,
        "f32.demote_f64(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))) & 2143289344u),
        2143289344u,
        "f32.demote_f64(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xfff8000000000000ull))) & 2147483647u),
        2143289344u,
        "f32.demote_f64(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xfff4000000000000ull))) & 2143289344u),
        2143289344u,
        "f32.demote_f64(f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x0010000000000000ull))),
        0u,
        "f32.demote_f64(2.2250738585072014e-308)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x8010000000000000ull))),
        2147483648u,
        "f32.demote_f64(-2.2250738585072014e-308)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x3690000000000000ull))),
        0u,
        "f32.demote_f64(7.006492321624085e-46)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xb690000000000000ull))),
        2147483648u,
        "f32.demote_f64(-7.006492321624085e-46)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0x3690000000000001ull))),
        1u,
        "f32.demote_f64(7.006492321624087e-46)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export14_f32X2EdemoteX5Ff64(&instance, f64_reinterpret_i64(0xb690000000000001ull))),
        2147483649u,
        "f32.demote_f64(-7.006492321624087e-46)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export19_f32X2EreinterpretX5Fi32(&instance, 0u)),
        0u,
        "f32.reinterpret_i32(0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export19_f32X2EreinterpretX5Fi32(&instance, 2147483648u)),
        2147483648u,
        "f32.reinterpret_i32(2147483648u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export19_f32X2EreinterpretX5Fi32(&instance, 1u)),
        1u,
        "f32.reinterpret_i32(1u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export19_f32X2EreinterpretX5Fi32(&instance, 4294967295u)),
        4294967295u,
        "f32.reinterpret_i32(4294967295u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export19_f32X2EreinterpretX5Fi32(&instance, 123456789u)),
        123456789u,
        "f32.reinterpret_i32(123456789u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export19_f32X2EreinterpretX5Fi32(&instance, 2147483649u)),
        2147483649u,
        "f32.reinterpret_i32(2147483649u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export19_f32X2EreinterpretX5Fi32(&instance, 2139095040u)),
        2139095040u,
        "f32.reinterpret_i32(2139095040u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export19_f32X2EreinterpretX5Fi32(&instance, 4286578688u)),
        4286578688u,
        "f32.reinterpret_i32(4286578688u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export19_f32X2EreinterpretX5Fi32(&instance, 2143289344u)),
        2143289344u,
        "f32.reinterpret_i32(2143289344u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export19_f32X2EreinterpretX5Fi32(&instance, 4290772992u)),
        4290772992u,
        "f32.reinterpret_i32(4290772992u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export19_f32X2EreinterpretX5Fi32(&instance, 2141192192u)),
        2141192192u,
        "f32.reinterpret_i32(2141192192u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_conversionsX2E0Export19_f32X2EreinterpretX5Fi32(&instance, 4288675840u)),
        4288675840u,
        "f32.reinterpret_i32(4288675840u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export19_f64X2EreinterpretX5Fi64(&instance, 0ull)),
        0ull,
        "f64.reinterpret_i64(0ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export19_f64X2EreinterpretX5Fi64(&instance, 1ull)),
        1ull,
        "f64.reinterpret_i64(1ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export19_f64X2EreinterpretX5Fi64(&instance, 18446744073709551615ull)),
        18446744073709551615ull,
        "f64.reinterpret_i64(18446744073709551615ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export19_f64X2EreinterpretX5Fi64(&instance, 9223372036854775808ull)),
        9223372036854775808ull,
        "f64.reinterpret_i64(9223372036854775808ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export19_f64X2EreinterpretX5Fi64(&instance, 1234567890ull)),
        1234567890ull,
        "f64.reinterpret_i64(1234567890ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export19_f64X2EreinterpretX5Fi64(&instance, 9223372036854775809ull)),
        9223372036854775809ull,
        "f64.reinterpret_i64(9223372036854775809ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export19_f64X2EreinterpretX5Fi64(&instance, 9218868437227405312ull)),
        9218868437227405312ull,
        "f64.reinterpret_i64(9218868437227405312ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export19_f64X2EreinterpretX5Fi64(&instance, 18442240474082181120ull)),
        18442240474082181120ull,
        "f64.reinterpret_i64(18442240474082181120ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export19_f64X2EreinterpretX5Fi64(&instance, 9221120237041090560ull)),
        9221120237041090560ull,
        "f64.reinterpret_i64(9221120237041090560ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export19_f64X2EreinterpretX5Fi64(&instance, 18444492273895866368ull)),
        18444492273895866368ull,
        "f64.reinterpret_i64(18444492273895866368ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export19_f64X2EreinterpretX5Fi64(&instance, 9219994337134247936ull)),
        9219994337134247936ull,
        "f64.reinterpret_i64(9219994337134247936ull)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_conversionsX2E0Export19_f64X2EreinterpretX5Fi64(&instance, 18443366373989023744ull)),
        18443366373989023744ull,
        "f64.reinterpret_i64(18443366373989023744ull)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0x00000000u)),
        0u,
        "i32.reinterpret_f32(0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0x80000000u)),
        2147483648u,
        "i32.reinterpret_f32(-0.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0x00000001u)),
        1u,
        "i32.reinterpret_f32(1.401298464324817e-45)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0xffffffffu)),
        4294967295u,
        "i32.reinterpret_f32(f32_reinterpret_i32(0xffffffffu))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0x80000001u)),
        2147483649u,
        "i32.reinterpret_f32(-1.401298464324817e-45)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0x3f800000u)),
        1065353216u,
        "i32.reinterpret_f32(1.0)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0x40490fdau)),
        1078530010u,
        "i32.reinterpret_f32(3.141592502593994)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0x7f7fffffu)),
        2139095039u,
        "i32.reinterpret_f32(3.4028234663852886e+38)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0xff7fffffu)),
        4286578687u,
        "i32.reinterpret_f32(-3.4028234663852886e+38)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0x7f800000u)),
        2139095040u,
        "i32.reinterpret_f32(INFINITY)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0xff800000u)),
        4286578688u,
        "i32.reinterpret_f32(-INFINITY)"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0x7fc00000u)),
        2143289344u,
        "i32.reinterpret_f32(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0xffc00000u)),
        4290772992u,
        "i32.reinterpret_f32(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0x7fa00000u)),
        2141192192u,
        "i32.reinterpret_f32(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        m13_conversionsX2E0Export19_i32X2EreinterpretX5Ff32(&instance, f32_reinterpret_i32(0xffa00000u)),
        4288675840u,
        "i32.reinterpret_f32(f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0x0000000000000000ull)),
        0ull,
        "i64.reinterpret_f64(0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0x8000000000000000ull)),
        9223372036854775808ull,
        "i64.reinterpret_f64(-0.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0x0000000000000001ull)),
        1ull,
        "i64.reinterpret_f64(5e-324)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0xffffffffffffffffull)),
        18446744073709551615ull,
        "i64.reinterpret_f64(f64_reinterpret_i64(0xffffffffffffffffull))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0x8000000000000001ull)),
        9223372036854775809ull,
        "i64.reinterpret_f64(-5e-324)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0x3ff0000000000000ull)),
        4607182418800017408ull,
        "i64.reinterpret_f64(1.0)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0x400921fb54442d11ull)),
        4614256656552045841ull,
        "i64.reinterpret_f64(3.14159265358979)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0x7fefffffffffffffull)),
        9218868437227405311ull,
        "i64.reinterpret_f64(1.7976931348623157e+308)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0xffefffffffffffffull)),
        18442240474082181119ull,
        "i64.reinterpret_f64(-1.7976931348623157e+308)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0x7ff0000000000000ull)),
        9218868437227405312ull,
        "i64.reinterpret_f64(INFINITY)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0xfff0000000000000ull)),
        18442240474082181120ull,
        "i64.reinterpret_f64(-INFINITY)"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)),
        9221120237041090560ull,
        "i64.reinterpret_f64(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0xfff8000000000000ull)),
        18444492273895866368ull,
        "i64.reinterpret_f64(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0x7ff4000000000000ull)),
        9219994337134247936ull,
        "i64.reinterpret_f64(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        m13_conversionsX2E0Export19_i64X2EreinterpretX5Ff64(&instance, f64_reinterpret_i64(0xfff4000000000000ull)),
        18443366373989023744ull,
        "i64.reinterpret_f64(f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    m13_conversionsX2E0FreeInstance(&instance);
}
