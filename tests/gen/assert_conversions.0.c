
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_conversions.0.h"

void test() {
    conversions0Instance instance;
    conversions0Instantiate(&instance, resolveTestImports);
    printStart("conversions.0.wasm");
    assertEqualU64(
        conversions0_i64X2EextendX5Fi32X5Fs(&instance, 0u),
        0ull,
        "i64.extend_i32_s(0u)"
    );
    assertEqualU64(
        conversions0_i64X2EextendX5Fi32X5Fs(&instance, 10000u),
        10000ull,
        "i64.extend_i32_s(10000u)"
    );
    assertEqualU64(
        conversions0_i64X2EextendX5Fi32X5Fs(&instance, 4294957296u),
        18446744073709541616ull,
        "i64.extend_i32_s(4294957296u)"
    );
    assertEqualU64(
        conversions0_i64X2EextendX5Fi32X5Fs(&instance, 4294967295u),
        18446744073709551615ull,
        "i64.extend_i32_s(4294967295u)"
    );
    assertEqualU64(
        conversions0_i64X2EextendX5Fi32X5Fs(&instance, 2147483647u),
        2147483647ull,
        "i64.extend_i32_s(2147483647u)"
    );
    assertEqualU64(
        conversions0_i64X2EextendX5Fi32X5Fs(&instance, 2147483648u),
        18446744071562067968ull,
        "i64.extend_i32_s(2147483648u)"
    );
    assertEqualU64(
        conversions0_i64X2EextendX5Fi32X5Fu(&instance, 0u),
        0ull,
        "i64.extend_i32_u(0u)"
    );
    assertEqualU64(
        conversions0_i64X2EextendX5Fi32X5Fu(&instance, 10000u),
        10000ull,
        "i64.extend_i32_u(10000u)"
    );
    assertEqualU64(
        conversions0_i64X2EextendX5Fi32X5Fu(&instance, 4294957296u),
        4294957296ull,
        "i64.extend_i32_u(4294957296u)"
    );
    assertEqualU64(
        conversions0_i64X2EextendX5Fi32X5Fu(&instance, 4294967295u),
        4294967295ull,
        "i64.extend_i32_u(4294967295u)"
    );
    assertEqualU64(
        conversions0_i64X2EextendX5Fi32X5Fu(&instance, 2147483647u),
        2147483647ull,
        "i64.extend_i32_u(2147483647u)"
    );
    assertEqualU64(
        conversions0_i64X2EextendX5Fi32X5Fu(&instance, 2147483648u),
        2147483648ull,
        "i64.extend_i32_u(2147483648u)"
    );
    assertEqualU32(
        conversions0_i32X2EwrapX5Fi64(&instance, 18446744073709551615ull),
        4294967295u,
        "i32.wrap_i64(18446744073709551615ull)"
    );
    assertEqualU32(
        conversions0_i32X2EwrapX5Fi64(&instance, 18446744073709451616ull),
        4294867296u,
        "i32.wrap_i64(18446744073709451616ull)"
    );
    assertEqualU32(
        conversions0_i32X2EwrapX5Fi64(&instance, 2147483648ull),
        2147483648u,
        "i32.wrap_i64(2147483648ull)"
    );
    assertEqualU32(
        conversions0_i32X2EwrapX5Fi64(&instance, 18446744071562067967ull),
        2147483647u,
        "i32.wrap_i64(18446744071562067967ull)"
    );
    assertEqualU32(
        conversions0_i32X2EwrapX5Fi64(&instance, 18446744069414584320ull),
        0u,
        "i32.wrap_i64(18446744069414584320ull)"
    );
    assertEqualU32(
        conversions0_i32X2EwrapX5Fi64(&instance, 18446744069414584319ull),
        4294967295u,
        "i32.wrap_i64(18446744069414584319ull)"
    );
    assertEqualU32(
        conversions0_i32X2EwrapX5Fi64(&instance, 18446744069414584321ull),
        1u,
        "i32.wrap_i64(18446744069414584321ull)"
    );
    assertEqualU32(
        conversions0_i32X2EwrapX5Fi64(&instance, 0ull),
        0u,
        "i32.wrap_i64(0ull)"
    );
    assertEqualU32(
        conversions0_i32X2EwrapX5Fi64(&instance, 1311768467463790320ull),
        2596069104u,
        "i32.wrap_i64(1311768467463790320ull)"
    );
    assertEqualU32(
        conversions0_i32X2EwrapX5Fi64(&instance, 4294967295ull),
        4294967295u,
        "i32.wrap_i64(4294967295ull)"
    );
    assertEqualU32(
        conversions0_i32X2EwrapX5Fi64(&instance, 4294967296ull),
        0u,
        "i32.wrap_i64(4294967296ull)"
    );
    assertEqualU32(
        conversions0_i32X2EwrapX5Fi64(&instance, 4294967297ull),
        1u,
        "i32.wrap_i64(4294967297ull)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, 0.0),
        0u,
        "i32.trunc_f32_s(0.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, -0.0),
        0u,
        "i32.trunc_f32_s(-0.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, 1.401298464324817e-45),
        0u,
        "i32.trunc_f32_s(1.401298464324817e-45)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, -1.401298464324817e-45),
        0u,
        "i32.trunc_f32_s(-1.401298464324817e-45)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, 1.0),
        1u,
        "i32.trunc_f32_s(1.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, 1.100000023841858),
        1u,
        "i32.trunc_f32_s(1.100000023841858)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, 1.5),
        1u,
        "i32.trunc_f32_s(1.5)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, -1.0),
        4294967295u,
        "i32.trunc_f32_s(-1.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, -1.100000023841858),
        4294967295u,
        "i32.trunc_f32_s(-1.100000023841858)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, -1.5),
        4294967295u,
        "i32.trunc_f32_s(-1.5)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, -1.899999976158142),
        4294967295u,
        "i32.trunc_f32_s(-1.899999976158142)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, -2.0),
        4294967294u,
        "i32.trunc_f32_s(-2.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, 2147483520.0),
        2147483520u,
        "i32.trunc_f32_s(2147483520.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fs(&instance, -2147483648.0),
        2147483648u,
        "i32.trunc_f32_s(-2147483648.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, 0.0),
        0u,
        "i32.trunc_f32_u(0.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, -0.0),
        0u,
        "i32.trunc_f32_u(-0.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, 1.401298464324817e-45),
        0u,
        "i32.trunc_f32_u(1.401298464324817e-45)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, -1.401298464324817e-45),
        0u,
        "i32.trunc_f32_u(-1.401298464324817e-45)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, 1.0),
        1u,
        "i32.trunc_f32_u(1.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, 1.100000023841858),
        1u,
        "i32.trunc_f32_u(1.100000023841858)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, 1.5),
        1u,
        "i32.trunc_f32_u(1.5)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, 1.899999976158142),
        1u,
        "i32.trunc_f32_u(1.899999976158142)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, 2.0),
        2u,
        "i32.trunc_f32_u(2.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, 2147483648.0),
        2147483648u,
        "i32.trunc_f32_u(2147483648.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, 4294967040.0),
        4294967040u,
        "i32.trunc_f32_u(4294967040.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, -0.8999999761581421),
        0u,
        "i32.trunc_f32_u(-0.8999999761581421)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff32X5Fu(&instance, -0.9999999403953552),
        0u,
        "i32.trunc_f32_u(-0.9999999403953552)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, 0.0),
        0u,
        "i32.trunc_f64_s(0.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, -0.0),
        0u,
        "i32.trunc_f64_s(-0.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, 5e-324),
        0u,
        "i32.trunc_f64_s(5e-324)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, -5e-324),
        0u,
        "i32.trunc_f64_s(-5e-324)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, 1.0),
        1u,
        "i32.trunc_f64_s(1.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, 1.1),
        1u,
        "i32.trunc_f64_s(1.1)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, 1.5),
        1u,
        "i32.trunc_f64_s(1.5)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, -1.0),
        4294967295u,
        "i32.trunc_f64_s(-1.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, -1.1),
        4294967295u,
        "i32.trunc_f64_s(-1.1)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, -1.5),
        4294967295u,
        "i32.trunc_f64_s(-1.5)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, -1.9),
        4294967295u,
        "i32.trunc_f64_s(-1.9)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, -2.0),
        4294967294u,
        "i32.trunc_f64_s(-2.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, 2147483647.0),
        2147483647u,
        "i32.trunc_f64_s(2147483647.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, -2147483648.0),
        2147483648u,
        "i32.trunc_f64_s(-2147483648.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, -2147483648.9),
        2147483648u,
        "i32.trunc_f64_s(-2147483648.9)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fs(&instance, 2147483647.9),
        2147483647u,
        "i32.trunc_f64_s(2147483647.9)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, 0.0),
        0u,
        "i32.trunc_f64_u(0.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, -0.0),
        0u,
        "i32.trunc_f64_u(-0.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, 5e-324),
        0u,
        "i32.trunc_f64_u(5e-324)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, -5e-324),
        0u,
        "i32.trunc_f64_u(-5e-324)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, 1.0),
        1u,
        "i32.trunc_f64_u(1.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, 1.1),
        1u,
        "i32.trunc_f64_u(1.1)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, 1.5),
        1u,
        "i32.trunc_f64_u(1.5)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, 1.9),
        1u,
        "i32.trunc_f64_u(1.9)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, 2.0),
        2u,
        "i32.trunc_f64_u(2.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, 2147483648.0),
        2147483648u,
        "i32.trunc_f64_u(2147483648.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, 4294967295.0),
        4294967295u,
        "i32.trunc_f64_u(4294967295.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, -0.9),
        0u,
        "i32.trunc_f64_u(-0.9)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, -0.9999999999999999),
        0u,
        "i32.trunc_f64_u(-0.9999999999999999)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, 100000000.0),
        100000000u,
        "i32.trunc_f64_u(100000000.0)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, -0.9),
        0u,
        "i32.trunc_f64_u(-0.9)"
    );
    assertEqualU32(
        conversions0_i32X2EtruncX5Ff64X5Fu(&instance, 4294967295.9),
        4294967295u,
        "i32.trunc_f64_u(4294967295.9)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, 0.0),
        0ull,
        "i64.trunc_f32_s(0.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, -0.0),
        0ull,
        "i64.trunc_f32_s(-0.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, 1.401298464324817e-45),
        0ull,
        "i64.trunc_f32_s(1.401298464324817e-45)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, -1.401298464324817e-45),
        0ull,
        "i64.trunc_f32_s(-1.401298464324817e-45)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, 1.0),
        1ull,
        "i64.trunc_f32_s(1.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, 1.100000023841858),
        1ull,
        "i64.trunc_f32_s(1.100000023841858)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, 1.5),
        1ull,
        "i64.trunc_f32_s(1.5)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, -1.0),
        18446744073709551615ull,
        "i64.trunc_f32_s(-1.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, -1.100000023841858),
        18446744073709551615ull,
        "i64.trunc_f32_s(-1.100000023841858)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, -1.5),
        18446744073709551615ull,
        "i64.trunc_f32_s(-1.5)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, -1.899999976158142),
        18446744073709551615ull,
        "i64.trunc_f32_s(-1.899999976158142)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, -2.0),
        18446744073709551614ull,
        "i64.trunc_f32_s(-2.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, 4294967296.0),
        4294967296ull,
        "i64.trunc_f32_s(4294967296.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, -4294967296.0),
        18446744069414584320ull,
        "i64.trunc_f32_s(-4294967296.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, 9.223371487098962e+18),
        9223371487098961920ull,
        "i64.trunc_f32_s(9.223371487098962e+18)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fs(&instance, -9.223372036854776e+18),
        9223372036854775808ull,
        "i64.trunc_f32_s(-9.223372036854776e+18)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fu(&instance, 0.0),
        0ull,
        "i64.trunc_f32_u(0.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fu(&instance, -0.0),
        0ull,
        "i64.trunc_f32_u(-0.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fu(&instance, 1.401298464324817e-45),
        0ull,
        "i64.trunc_f32_u(1.401298464324817e-45)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fu(&instance, -1.401298464324817e-45),
        0ull,
        "i64.trunc_f32_u(-1.401298464324817e-45)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fu(&instance, 1.0),
        1ull,
        "i64.trunc_f32_u(1.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fu(&instance, 1.100000023841858),
        1ull,
        "i64.trunc_f32_u(1.100000023841858)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fu(&instance, 1.5),
        1ull,
        "i64.trunc_f32_u(1.5)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fu(&instance, 4294967296.0),
        4294967296ull,
        "i64.trunc_f32_u(4294967296.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fu(&instance, 1.8446742974197924e+19),
        18446742974197923840ull,
        "i64.trunc_f32_u(1.8446742974197924e+19)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fu(&instance, -0.8999999761581421),
        0ull,
        "i64.trunc_f32_u(-0.8999999761581421)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff32X5Fu(&instance, -0.9999999403953552),
        0ull,
        "i64.trunc_f32_u(-0.9999999403953552)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, 0.0),
        0ull,
        "i64.trunc_f64_s(0.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, -0.0),
        0ull,
        "i64.trunc_f64_s(-0.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, 5e-324),
        0ull,
        "i64.trunc_f64_s(5e-324)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, -5e-324),
        0ull,
        "i64.trunc_f64_s(-5e-324)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, 1.0),
        1ull,
        "i64.trunc_f64_s(1.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, 1.1),
        1ull,
        "i64.trunc_f64_s(1.1)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, 1.5),
        1ull,
        "i64.trunc_f64_s(1.5)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, -1.0),
        18446744073709551615ull,
        "i64.trunc_f64_s(-1.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, -1.1),
        18446744073709551615ull,
        "i64.trunc_f64_s(-1.1)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, -1.5),
        18446744073709551615ull,
        "i64.trunc_f64_s(-1.5)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, -1.9),
        18446744073709551615ull,
        "i64.trunc_f64_s(-1.9)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, -2.0),
        18446744073709551614ull,
        "i64.trunc_f64_s(-2.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, 4294967296.0),
        4294967296ull,
        "i64.trunc_f64_s(4294967296.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, -4294967296.0),
        18446744069414584320ull,
        "i64.trunc_f64_s(-4294967296.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, 9.223372036854775e+18),
        9223372036854774784ull,
        "i64.trunc_f64_s(9.223372036854775e+18)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fs(&instance, -9.223372036854776e+18),
        9223372036854775808ull,
        "i64.trunc_f64_s(-9.223372036854776e+18)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, 0.0),
        0ull,
        "i64.trunc_f64_u(0.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, -0.0),
        0ull,
        "i64.trunc_f64_u(-0.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, 5e-324),
        0ull,
        "i64.trunc_f64_u(5e-324)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, -5e-324),
        0ull,
        "i64.trunc_f64_u(-5e-324)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, 1.0),
        1ull,
        "i64.trunc_f64_u(1.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, 1.1),
        1ull,
        "i64.trunc_f64_u(1.1)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, 1.5),
        1ull,
        "i64.trunc_f64_u(1.5)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, 4294967295.0),
        4294967295ull,
        "i64.trunc_f64_u(4294967295.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, 4294967296.0),
        4294967296ull,
        "i64.trunc_f64_u(4294967296.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, 1.844674407370955e+19),
        18446744073709549568ull,
        "i64.trunc_f64_u(1.844674407370955e+19)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, -0.9),
        0ull,
        "i64.trunc_f64_u(-0.9)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, -0.9999999999999999),
        0ull,
        "i64.trunc_f64_u(-0.9999999999999999)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, 100000000.0),
        100000000ull,
        "i64.trunc_f64_u(100000000.0)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, 1e+16),
        10000000000000000ull,
        "i64.trunc_f64_u(1e+16)"
    );
    assertEqualU64(
        conversions0_i64X2EtruncX5Ff64X5Fu(&instance, 9.223372036854776e+18),
        9223372036854775808ull,
        "i64.trunc_f64_u(9.223372036854776e+18)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fs(&instance, 1u),
        1.0,
        "f32.convert_i32_s(1u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fs(&instance, 4294967295u),
        -1.0,
        "f32.convert_i32_s(4294967295u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fs(&instance, 0u),
        0.0,
        "f32.convert_i32_s(0u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fs(&instance, 2147483647u),
        2147483648.0,
        "f32.convert_i32_s(2147483647u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fs(&instance, 2147483648u),
        -2147483648.0,
        "f32.convert_i32_s(2147483648u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fs(&instance, 1234567890u),
        1234567936.0,
        "f32.convert_i32_s(1234567890u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fs(&instance, 16777217u),
        16777216.0,
        "f32.convert_i32_s(16777217u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fs(&instance, 4278190079u),
        -16777216.0,
        "f32.convert_i32_s(4278190079u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fs(&instance, 16777219u),
        16777220.0,
        "f32.convert_i32_s(16777219u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fs(&instance, 4278190077u),
        -16777220.0,
        "f32.convert_i32_s(4278190077u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 1ull),
        1.0,
        "f32.convert_i64_s(1ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 18446744073709551615ull),
        -1.0,
        "f32.convert_i64_s(18446744073709551615ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 0ull),
        0.0,
        "f32.convert_i64_s(0ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 9223372036854775807ull),
        9.223372036854776e+18,
        "f32.convert_i64_s(9223372036854775807ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 9223372036854775808ull),
        -9.223372036854776e+18,
        "f32.convert_i64_s(9223372036854775808ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 314159265358979ull),
        314159275180032.0,
        "f32.convert_i64_s(314159265358979ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 16777217ull),
        16777216.0,
        "f32.convert_i64_s(16777217ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 18446744073692774399ull),
        -16777216.0,
        "f32.convert_i64_s(18446744073692774399ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 16777219ull),
        16777220.0,
        "f32.convert_i64_s(16777219ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 18446744073692774397ull),
        -16777220.0,
        "f32.convert_i64_s(18446744073692774397ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 9223371212221054977ull),
        9.223371487098962e+18,
        "f32.convert_i64_s(9223371212221054977ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 9223372311732682753ull),
        -9.223371487098962e+18,
        "f32.convert_i64_s(9223372311732682753ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 9007199791611905ull),
        9007200328482816.0,
        "f32.convert_i64_s(9007199791611905ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fs(&instance, 18437736873917939711ull),
        -9007200328482816.0,
        "f32.convert_i64_s(18437736873917939711ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi32X5Fs(&instance, 1u),
        1.0,
        "f64.convert_i32_s(1u)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi32X5Fs(&instance, 4294967295u),
        -1.0,
        "f64.convert_i32_s(4294967295u)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi32X5Fs(&instance, 0u),
        0.0,
        "f64.convert_i32_s(0u)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi32X5Fs(&instance, 2147483647u),
        2147483647.0,
        "f64.convert_i32_s(2147483647u)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi32X5Fs(&instance, 2147483648u),
        -2147483648.0,
        "f64.convert_i32_s(2147483648u)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi32X5Fs(&instance, 987654321u),
        987654321.0,
        "f64.convert_i32_s(987654321u)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fs(&instance, 1ull),
        1.0,
        "f64.convert_i64_s(1ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fs(&instance, 18446744073709551615ull),
        -1.0,
        "f64.convert_i64_s(18446744073709551615ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fs(&instance, 0ull),
        0.0,
        "f64.convert_i64_s(0ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fs(&instance, 9223372036854775807ull),
        9.223372036854776e+18,
        "f64.convert_i64_s(9223372036854775807ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fs(&instance, 9223372036854775808ull),
        -9.223372036854776e+18,
        "f64.convert_i64_s(9223372036854775808ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fs(&instance, 4669201609102990ull),
        4669201609102990.0,
        "f64.convert_i64_s(4669201609102990ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fs(&instance, 9007199254740993ull),
        9007199254740992.0,
        "f64.convert_i64_s(9007199254740993ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fs(&instance, 18437736874454810623ull),
        -9007199254740992.0,
        "f64.convert_i64_s(18437736874454810623ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fs(&instance, 9007199254740995ull),
        9007199254740996.0,
        "f64.convert_i64_s(9007199254740995ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fs(&instance, 18437736874454810621ull),
        -9007199254740996.0,
        "f64.convert_i64_s(18437736874454810621ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 1u),
        1.0,
        "f32.convert_i32_u(1u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 0u),
        0.0,
        "f32.convert_i32_u(0u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 2147483647u),
        2147483648.0,
        "f32.convert_i32_u(2147483647u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 2147483648u),
        2147483648.0,
        "f32.convert_i32_u(2147483648u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 305419896u),
        305419904.0,
        "f32.convert_i32_u(305419896u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 4294967295u),
        4294967296.0,
        "f32.convert_i32_u(4294967295u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 2147483776u),
        2147483648.0,
        "f32.convert_i32_u(2147483776u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 2147483777u),
        2147483904.0,
        "f32.convert_i32_u(2147483777u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 2147483778u),
        2147483904.0,
        "f32.convert_i32_u(2147483778u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 4294966912u),
        4294966784.0,
        "f32.convert_i32_u(4294966912u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 4294966913u),
        4294967040.0,
        "f32.convert_i32_u(4294966913u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 4294966914u),
        4294967040.0,
        "f32.convert_i32_u(4294966914u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 16777217u),
        16777216.0,
        "f32.convert_i32_u(16777217u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi32X5Fu(&instance, 16777219u),
        16777220.0,
        "f32.convert_i32_u(16777219u)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fu(&instance, 1ull),
        1.0,
        "f32.convert_i64_u(1ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fu(&instance, 0ull),
        0.0,
        "f32.convert_i64_u(0ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fu(&instance, 9223372036854775807ull),
        9.223372036854776e+18,
        "f32.convert_i64_u(9223372036854775807ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fu(&instance, 9223372036854775808ull),
        9.223372036854776e+18,
        "f32.convert_i64_u(9223372036854775808ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fu(&instance, 18446744073709551615ull),
        1.8446744073709552e+19,
        "f32.convert_i64_u(18446744073709551615ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fu(&instance, 16777217ull),
        16777216.0,
        "f32.convert_i64_u(16777217ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fu(&instance, 16777219ull),
        16777220.0,
        "f32.convert_i64_u(16777219ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fu(&instance, 9007199791611905ull),
        9007200328482816.0,
        "f32.convert_i64_u(9007199791611905ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fu(&instance, 9223371761976868863ull),
        9.223371487098962e+18,
        "f32.convert_i64_u(9223371761976868863ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fu(&instance, 9223372586610589697ull),
        9.223373136366404e+18,
        "f32.convert_i64_u(9223372586610589697ull)"
    );
    assertEqualF32(
        conversions0_f32X2EconvertX5Fi64X5Fu(&instance, 18446742424442109953ull),
        1.8446742974197924e+19,
        "f32.convert_i64_u(18446742424442109953ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi32X5Fu(&instance, 1u),
        1.0,
        "f64.convert_i32_u(1u)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi32X5Fu(&instance, 0u),
        0.0,
        "f64.convert_i32_u(0u)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi32X5Fu(&instance, 2147483647u),
        2147483647.0,
        "f64.convert_i32_u(2147483647u)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi32X5Fu(&instance, 2147483648u),
        2147483648.0,
        "f64.convert_i32_u(2147483648u)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi32X5Fu(&instance, 4294967295u),
        4294967295.0,
        "f64.convert_i32_u(4294967295u)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 1ull),
        1.0,
        "f64.convert_i64_u(1ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 0ull),
        0.0,
        "f64.convert_i64_u(0ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 9223372036854775807ull),
        9.223372036854776e+18,
        "f64.convert_i64_u(9223372036854775807ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 9223372036854775808ull),
        9.223372036854776e+18,
        "f64.convert_i64_u(9223372036854775808ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 18446744073709551615ull),
        1.8446744073709552e+19,
        "f64.convert_i64_u(18446744073709551615ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 9223372036854776832ull),
        9.223372036854776e+18,
        "f64.convert_i64_u(9223372036854776832ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 9223372036854776833ull),
        9.223372036854778e+18,
        "f64.convert_i64_u(9223372036854776833ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 9223372036854776834ull),
        9.223372036854778e+18,
        "f64.convert_i64_u(9223372036854776834ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 18446744073709548544ull),
        1.8446744073709548e+19,
        "f64.convert_i64_u(18446744073709548544ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 18446744073709548545ull),
        1.844674407370955e+19,
        "f64.convert_i64_u(18446744073709548545ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 18446744073709548546ull),
        1.844674407370955e+19,
        "f64.convert_i64_u(18446744073709548546ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 9007199254740993ull),
        9007199254740992.0,
        "f64.convert_i64_u(9007199254740993ull)"
    );
    assertEqualF64(
        conversions0_f64X2EconvertX5Fi64X5Fu(&instance, 9007199254740995ull),
        9007199254740996.0,
        "f64.convert_i64_u(9007199254740995ull)"
    );
    assertEqualF64(
        conversions0_f64X2EpromoteX5Ff32(&instance, 0.0),
        0.0,
        "f64.promote_f32(0.0)"
    );
    assertEqualF64(
        conversions0_f64X2EpromoteX5Ff32(&instance, -0.0),
        -0.0,
        "f64.promote_f32(-0.0)"
    );
    assertEqualF64(
        conversions0_f64X2EpromoteX5Ff32(&instance, 1.401298464324817e-45),
        1.401298464324817e-45,
        "f64.promote_f32(1.401298464324817e-45)"
    );
    assertEqualF64(
        conversions0_f64X2EpromoteX5Ff32(&instance, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "f64.promote_f32(-1.401298464324817e-45)"
    );
    assertEqualF64(
        conversions0_f64X2EpromoteX5Ff32(&instance, 1.0),
        1.0,
        "f64.promote_f32(1.0)"
    );
    assertEqualF64(
        conversions0_f64X2EpromoteX5Ff32(&instance, -1.0),
        -1.0,
        "f64.promote_f32(-1.0)"
    );
    assertEqualF64(
        conversions0_f64X2EpromoteX5Ff32(&instance, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "f64.promote_f32(-3.4028234663852886e+38)"
    );
    assertEqualF64(
        conversions0_f64X2EpromoteX5Ff32(&instance, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "f64.promote_f32(3.4028234663852886e+38)"
    );
    assertEqualF64(
        conversions0_f64X2EpromoteX5Ff32(&instance, 1.504632769052528e-36),
        1.504632769052528e-36,
        "f64.promote_f32(1.504632769052528e-36)"
    );
    assertEqualF64(
        conversions0_f64X2EpromoteX5Ff32(&instance, 6.6382536710104395e+37),
        6.6382536710104395e+37,
        "f64.promote_f32(6.6382536710104395e+37)"
    );
    assertEqualF64(
        conversions0_f64X2EpromoteX5Ff32(&instance, INFINITY),
        INFINITY,
        "f64.promote_f32(INFINITY)"
    );
    assertEqualF64(
        conversions0_f64X2EpromoteX5Ff32(&instance, -INFINITY),
        -INFINITY,
        "f64.promote_f32(-INFINITY)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 0.0),
        0.0,
        "f32.demote_f64(0.0)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -0.0),
        -0.0,
        "f32.demote_f64(-0.0)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 5e-324),
        0.0,
        "f32.demote_f64(5e-324)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -5e-324),
        -0.0,
        "f32.demote_f64(-5e-324)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.0),
        1.0,
        "f32.demote_f64(1.0)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -1.0),
        -1.0,
        "f32.demote_f64(-1.0)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.1754942807573643e-38),
        1.1754943508222875e-38,
        "f32.demote_f64(1.1754942807573643e-38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -1.1754942807573643e-38),
        -1.1754943508222875e-38,
        "f32.demote_f64(-1.1754942807573643e-38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.1754942807573642e-38),
        1.1754942106924411e-38,
        "f32.demote_f64(1.1754942807573642e-38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -1.1754942807573642e-38),
        -1.1754942106924411e-38,
        "f32.demote_f64(-1.1754942807573642e-38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.401298464324817e-45),
        1.401298464324817e-45,
        "f32.demote_f64(1.401298464324817e-45)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "f32.demote_f64(-1.401298464324817e-45)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 3.4028233649732406e+38),
        3.4028232635611926e+38,
        "f32.demote_f64(3.4028233649732406e+38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -3.4028233649732406e+38),
        -3.4028232635611926e+38,
        "f32.demote_f64(-3.4028233649732406e+38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 3.402823364973241e+38),
        3.4028234663852886e+38,
        "f32.demote_f64(3.402823364973241e+38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -3.402823364973241e+38),
        -3.4028234663852886e+38,
        "f32.demote_f64(-3.402823364973241e+38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "f32.demote_f64(3.4028234663852886e+38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "f32.demote_f64(-3.4028234663852886e+38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 3.4028235677973362e+38),
        3.4028234663852886e+38,
        "f32.demote_f64(3.4028235677973362e+38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -3.4028235677973362e+38),
        -3.4028234663852886e+38,
        "f32.demote_f64(-3.4028235677973362e+38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 3.4028235677973366e+38),
        INFINITY,
        "f32.demote_f64(3.4028235677973366e+38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -3.4028235677973366e+38),
        -INFINITY,
        "f32.demote_f64(-3.4028235677973366e+38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.504632769052528e-36),
        1.504632769052528e-36,
        "f32.demote_f64(1.504632769052528e-36)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 6.6382536710104395e+37),
        6.6382536710104395e+37,
        "f32.demote_f64(6.6382536710104395e+37)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, INFINITY),
        INFINITY,
        "f32.demote_f64(INFINITY)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -INFINITY),
        -INFINITY,
        "f32.demote_f64(-INFINITY)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.0000000000000002),
        1.0,
        "f32.demote_f64(1.0000000000000002)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 0.9999999999999999),
        1.0,
        "f32.demote_f64(0.9999999999999999)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.0000000596046448),
        1.0,
        "f32.demote_f64(1.0000000596046448)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.000000059604645),
        1.0000001192092896,
        "f32.demote_f64(1.000000059604645)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.000000178813934),
        1.0000001192092896,
        "f32.demote_f64(1.000000178813934)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.0000001788139343),
        1.000000238418579,
        "f32.demote_f64(1.0000001788139343)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.0000002980232239),
        1.000000238418579,
        "f32.demote_f64(1.0000002980232239)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 16777217.0),
        16777216.0,
        "f32.demote_f64(16777217.0)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 16777217.000000004),
        16777218.0,
        "f32.demote_f64(16777217.000000004)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 16777218.999999996),
        16777218.0,
        "f32.demote_f64(16777218.999999996)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 16777219.0),
        16777220.0,
        "f32.demote_f64(16777219.0)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 4.242584432991427e+32),
        4.2425845416862035e+32,
        "f32.demote_f64(4.242584432991427e+32)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.569262107843488e-34),
        1.5692621142680845e-34,
        "f32.demote_f64(1.569262107843488e-34)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 1.0551773688605172e-38),
        1.055177323247048e-38,
        "f32.demote_f64(1.0551773688605172e-38)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -2.8238128484141933),
        -2.823812961578369,
        "f32.demote_f64(-2.8238128484141933)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -9.063376370095757e+33),
        -9.063376213401508e+33,
        "f32.demote_f64(-9.063376370095757e+33)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 2.2250738585072014e-308),
        0.0,
        "f32.demote_f64(2.2250738585072014e-308)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -2.2250738585072014e-308),
        -0.0,
        "f32.demote_f64(-2.2250738585072014e-308)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 7.006492321624085e-46),
        0.0,
        "f32.demote_f64(7.006492321624085e-46)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -7.006492321624085e-46),
        -0.0,
        "f32.demote_f64(-7.006492321624085e-46)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, 7.006492321624087e-46),
        1.401298464324817e-45,
        "f32.demote_f64(7.006492321624087e-46)"
    );
    assertEqualF32(
        conversions0_f32X2EdemoteX5Ff64(&instance, -7.006492321624087e-46),
        -1.401298464324817e-45,
        "f32.demote_f64(-7.006492321624087e-46)"
    );
    assertEqualF32(
        conversions0_f32X2EreinterpretX5Fi32(&instance, 0u),
        0.0,
        "f32.reinterpret_i32(0u)"
    );
    assertEqualF32(
        conversions0_f32X2EreinterpretX5Fi32(&instance, 2147483648u),
        -0.0,
        "f32.reinterpret_i32(2147483648u)"
    );
    assertEqualF32(
        conversions0_f32X2EreinterpretX5Fi32(&instance, 1u),
        1.401298464324817e-45,
        "f32.reinterpret_i32(1u)"
    );
    assertEqualF32(
        conversions0_f32X2EreinterpretX5Fi32(&instance, 123456789u),
        1.6535997013422565e-34,
        "f32.reinterpret_i32(123456789u)"
    );
    assertEqualF32(
        conversions0_f32X2EreinterpretX5Fi32(&instance, 2147483649u),
        -1.401298464324817e-45,
        "f32.reinterpret_i32(2147483649u)"
    );
    assertEqualF32(
        conversions0_f32X2EreinterpretX5Fi32(&instance, 2139095040u),
        INFINITY,
        "f32.reinterpret_i32(2139095040u)"
    );
    assertEqualF32(
        conversions0_f32X2EreinterpretX5Fi32(&instance, 4286578688u),
        -INFINITY,
        "f32.reinterpret_i32(4286578688u)"
    );
    assertEqualF64(
        conversions0_f64X2EreinterpretX5Fi64(&instance, 0ull),
        0.0,
        "f64.reinterpret_i64(0ull)"
    );
    assertEqualF64(
        conversions0_f64X2EreinterpretX5Fi64(&instance, 1ull),
        5e-324,
        "f64.reinterpret_i64(1ull)"
    );
    assertEqualF64(
        conversions0_f64X2EreinterpretX5Fi64(&instance, 9223372036854775808ull),
        -0.0,
        "f64.reinterpret_i64(9223372036854775808ull)"
    );
    assertEqualF64(
        conversions0_f64X2EreinterpretX5Fi64(&instance, 1234567890ull),
        6.09957582e-315,
        "f64.reinterpret_i64(1234567890ull)"
    );
    assertEqualF64(
        conversions0_f64X2EreinterpretX5Fi64(&instance, 9223372036854775809ull),
        -5e-324,
        "f64.reinterpret_i64(9223372036854775809ull)"
    );
    assertEqualF64(
        conversions0_f64X2EreinterpretX5Fi64(&instance, 9218868437227405312ull),
        INFINITY,
        "f64.reinterpret_i64(9218868437227405312ull)"
    );
    assertEqualF64(
        conversions0_f64X2EreinterpretX5Fi64(&instance, 18442240474082181120ull),
        -INFINITY,
        "f64.reinterpret_i64(18442240474082181120ull)"
    );
    assertEqualU32(
        conversions0_i32X2EreinterpretX5Ff32(&instance, 0.0),
        0u,
        "i32.reinterpret_f32(0.0)"
    );
    assertEqualU32(
        conversions0_i32X2EreinterpretX5Ff32(&instance, -0.0),
        2147483648u,
        "i32.reinterpret_f32(-0.0)"
    );
    assertEqualU32(
        conversions0_i32X2EreinterpretX5Ff32(&instance, 1.401298464324817e-45),
        1u,
        "i32.reinterpret_f32(1.401298464324817e-45)"
    );
    assertEqualU32(
        conversions0_i32X2EreinterpretX5Ff32(&instance, -1.401298464324817e-45),
        2147483649u,
        "i32.reinterpret_f32(-1.401298464324817e-45)"
    );
    assertEqualU32(
        conversions0_i32X2EreinterpretX5Ff32(&instance, 1.0),
        1065353216u,
        "i32.reinterpret_f32(1.0)"
    );
    assertEqualU32(
        conversions0_i32X2EreinterpretX5Ff32(&instance, 3.141592502593994),
        1078530010u,
        "i32.reinterpret_f32(3.141592502593994)"
    );
    assertEqualU32(
        conversions0_i32X2EreinterpretX5Ff32(&instance, 3.4028234663852886e+38),
        2139095039u,
        "i32.reinterpret_f32(3.4028234663852886e+38)"
    );
    assertEqualU32(
        conversions0_i32X2EreinterpretX5Ff32(&instance, -3.4028234663852886e+38),
        4286578687u,
        "i32.reinterpret_f32(-3.4028234663852886e+38)"
    );
    assertEqualU32(
        conversions0_i32X2EreinterpretX5Ff32(&instance, INFINITY),
        2139095040u,
        "i32.reinterpret_f32(INFINITY)"
    );
    assertEqualU32(
        conversions0_i32X2EreinterpretX5Ff32(&instance, -INFINITY),
        4286578688u,
        "i32.reinterpret_f32(-INFINITY)"
    );
    assertEqualU64(
        conversions0_i64X2EreinterpretX5Ff64(&instance, 0.0),
        0ull,
        "i64.reinterpret_f64(0.0)"
    );
    assertEqualU64(
        conversions0_i64X2EreinterpretX5Ff64(&instance, -0.0),
        9223372036854775808ull,
        "i64.reinterpret_f64(-0.0)"
    );
    assertEqualU64(
        conversions0_i64X2EreinterpretX5Ff64(&instance, 5e-324),
        1ull,
        "i64.reinterpret_f64(5e-324)"
    );
    assertEqualU64(
        conversions0_i64X2EreinterpretX5Ff64(&instance, -5e-324),
        9223372036854775809ull,
        "i64.reinterpret_f64(-5e-324)"
    );
    assertEqualU64(
        conversions0_i64X2EreinterpretX5Ff64(&instance, 1.0),
        4607182418800017408ull,
        "i64.reinterpret_f64(1.0)"
    );
    assertEqualU64(
        conversions0_i64X2EreinterpretX5Ff64(&instance, 3.14159265358979),
        4614256656552045841ull,
        "i64.reinterpret_f64(3.14159265358979)"
    );
    assertEqualU64(
        conversions0_i64X2EreinterpretX5Ff64(&instance, 1.7976931348623157e+308),
        9218868437227405311ull,
        "i64.reinterpret_f64(1.7976931348623157e+308)"
    );
    assertEqualU64(
        conversions0_i64X2EreinterpretX5Ff64(&instance, -1.7976931348623157e+308),
        18442240474082181119ull,
        "i64.reinterpret_f64(-1.7976931348623157e+308)"
    );
    assertEqualU64(
        conversions0_i64X2EreinterpretX5Ff64(&instance, INFINITY),
        9218868437227405312ull,
        "i64.reinterpret_f64(INFINITY)"
    );
    assertEqualU64(
        conversions0_i64X2EreinterpretX5Ff64(&instance, -INFINITY),
        18442240474082181120ull,
        "i64.reinterpret_f64(-INFINITY)"
    );
}
