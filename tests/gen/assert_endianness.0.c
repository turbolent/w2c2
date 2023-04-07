
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_endianness.0.h"

void test() {
    endianness0Instance instance;
    endianness0Instantiate(&instance, resolveTestImports);
    printStart("endianness.0.wasm");
    assertEqualU32(
        endianness0_i32_load16_s(&instance, 4294967295u),
        4294967295u,
        "i32_load16_s(4294967295u)"
    );
    assertEqualU32(
        endianness0_i32_load16_s(&instance, 4294963054u),
        4294963054u,
        "i32_load16_s(4294963054u)"
    );
    assertEqualU32(
        endianness0_i32_load16_s(&instance, 42u),
        42u,
        "i32_load16_s(42u)"
    );
    assertEqualU32(
        endianness0_i32_load16_s(&instance, 12816u),
        12816u,
        "i32_load16_s(12816u)"
    );
    assertEqualU32(
        endianness0_i32_load16_u(&instance, 4294967295u),
        65535u,
        "i32_load16_u(4294967295u)"
    );
    assertEqualU32(
        endianness0_i32_load16_u(&instance, 4294963054u),
        61294u,
        "i32_load16_u(4294963054u)"
    );
    assertEqualU32(
        endianness0_i32_load16_u(&instance, 42u),
        42u,
        "i32_load16_u(42u)"
    );
    assertEqualU32(
        endianness0_i32_load16_u(&instance, 51966u),
        51966u,
        "i32_load16_u(51966u)"
    );
    assertEqualU32(
        endianness0_i32_load(&instance, 4294967295u),
        4294967295u,
        "i32_load(4294967295u)"
    );
    assertEqualU32(
        endianness0_i32_load(&instance, 4252543054u),
        4252543054u,
        "i32_load(4252543054u)"
    );
    assertEqualU32(
        endianness0_i32_load(&instance, 42424242u),
        42424242u,
        "i32_load(42424242u)"
    );
    assertEqualU32(
        endianness0_i32_load(&instance, 2880249322u),
        2880249322u,
        "i32_load(2880249322u)"
    );
    assertEqualU64(
        endianness0_i64_load16_s(&instance, 18446744073709551615ull),
        18446744073709551615ull,
        "i64_load16_s(18446744073709551615ull)"
    );
    assertEqualU64(
        endianness0_i64_load16_s(&instance, 18446744073709547374ull),
        18446744073709547374ull,
        "i64_load16_s(18446744073709547374ull)"
    );
    assertEqualU64(
        endianness0_i64_load16_s(&instance, 42ull),
        42ull,
        "i64_load16_s(42ull)"
    );
    assertEqualU64(
        endianness0_i64_load16_s(&instance, 12816ull),
        12816ull,
        "i64_load16_s(12816ull)"
    );
    assertEqualU64(
        endianness0_i64_load16_u(&instance, 18446744073709551615ull),
        65535ull,
        "i64_load16_u(18446744073709551615ull)"
    );
    assertEqualU64(
        endianness0_i64_load16_u(&instance, 18446744073709547374ull),
        61294ull,
        "i64_load16_u(18446744073709547374ull)"
    );
    assertEqualU64(
        endianness0_i64_load16_u(&instance, 42ull),
        42ull,
        "i64_load16_u(42ull)"
    );
    assertEqualU64(
        endianness0_i64_load16_u(&instance, 51966ull),
        51966ull,
        "i64_load16_u(51966ull)"
    );
    assertEqualU64(
        endianness0_i64_load32_s(&instance, 18446744073709551615ull),
        18446744073709551615ull,
        "i64_load32_s(18446744073709551615ull)"
    );
    assertEqualU64(
        endianness0_i64_load32_s(&instance, 18446744073667127374ull),
        18446744073667127374ull,
        "i64_load32_s(18446744073667127374ull)"
    );
    assertEqualU64(
        endianness0_i64_load32_s(&instance, 42424242ull),
        42424242ull,
        "i64_load32_s(42424242ull)"
    );
    assertEqualU64(
        endianness0_i64_load32_s(&instance, 305419896ull),
        305419896ull,
        "i64_load32_s(305419896ull)"
    );
    assertEqualU64(
        endianness0_i64_load32_u(&instance, 18446744073709551615ull),
        4294967295ull,
        "i64_load32_u(18446744073709551615ull)"
    );
    assertEqualU64(
        endianness0_i64_load32_u(&instance, 18446744073667127374ull),
        4252543054ull,
        "i64_load32_u(18446744073667127374ull)"
    );
    assertEqualU64(
        endianness0_i64_load32_u(&instance, 42424242ull),
        42424242ull,
        "i64_load32_u(42424242ull)"
    );
    assertEqualU64(
        endianness0_i64_load32_u(&instance, 2880249322ull),
        2880249322ull,
        "i64_load32_u(2880249322ull)"
    );
    assertEqualU64(
        endianness0_i64_load(&instance, 18446744073709551615ull),
        18446744073709551615ull,
        "i64_load(18446744073709551615ull)"
    );
    assertEqualU64(
        endianness0_i64_load(&instance, 18446744073667127374ull),
        18446744073667127374ull,
        "i64_load(18446744073667127374ull)"
    );
    assertEqualU64(
        endianness0_i64_load(&instance, 2880249322ull),
        2880249322ull,
        "i64_load(2880249322ull)"
    );
    assertEqualU64(
        endianness0_i64_load(&instance, 12370766947463011818ull),
        12370766947463011818ull,
        "i64_load(12370766947463011818ull)"
    );
    assertEqualF32(
        endianness0_f32_load(&instance, -1.0),
        -1.0,
        "f32_load(-1.0)"
    );
    assertEqualF32(
        endianness0_f32_load(&instance, 0.01233999989926815),
        0.01233999989926815,
        "f32_load(0.01233999989926815)"
    );
    assertEqualF32(
        endianness0_f32_load(&instance, 4242.42431640625),
        4242.42431640625,
        "f32_load(4242.42431640625)"
    );
    assertEqualF32(
        endianness0_f32_load(&instance, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "f32_load(3.4028234663852886e+38)"
    );
    assertEqualF64(
        endianness0_f64_load(&instance, -1.0),
        -1.0,
        "f64_load(-1.0)"
    );
    assertEqualF64(
        endianness0_f64_load(&instance, 1234.56789),
        1234.56789,
        "f64_load(1234.56789)"
    );
    assertEqualF64(
        endianness0_f64_load(&instance, 424242.424242),
        424242.424242,
        "f64_load(424242.424242)"
    );
    assertEqualF64(
        endianness0_f64_load(&instance, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "f64_load(1.7976931348623157e+308)"
    );
    assertEqualU32(
        endianness0_i32_store16(&instance, 4294967295u),
        65535u,
        "i32_store16(4294967295u)"
    );
    assertEqualU32(
        endianness0_i32_store16(&instance, 4294963054u),
        61294u,
        "i32_store16(4294963054u)"
    );
    assertEqualU32(
        endianness0_i32_store16(&instance, 42u),
        42u,
        "i32_store16(42u)"
    );
    assertEqualU32(
        endianness0_i32_store16(&instance, 51966u),
        51966u,
        "i32_store16(51966u)"
    );
    assertEqualU32(
        endianness0_i32_store(&instance, 4294967295u),
        4294967295u,
        "i32_store(4294967295u)"
    );
    assertEqualU32(
        endianness0_i32_store(&instance, 4294963054u),
        4294963054u,
        "i32_store(4294963054u)"
    );
    assertEqualU32(
        endianness0_i32_store(&instance, 42424242u),
        42424242u,
        "i32_store(42424242u)"
    );
    assertEqualU32(
        endianness0_i32_store(&instance, 3735931646u),
        3735931646u,
        "i32_store(3735931646u)"
    );
    assertEqualU64(
        endianness0_i64_store16(&instance, 18446744073709551615ull),
        65535ull,
        "i64_store16(18446744073709551615ull)"
    );
    assertEqualU64(
        endianness0_i64_store16(&instance, 18446744073709547374ull),
        61294ull,
        "i64_store16(18446744073709547374ull)"
    );
    assertEqualU64(
        endianness0_i64_store16(&instance, 42ull),
        42ull,
        "i64_store16(42ull)"
    );
    assertEqualU64(
        endianness0_i64_store16(&instance, 51966ull),
        51966ull,
        "i64_store16(51966ull)"
    );
    assertEqualU64(
        endianness0_i64_store32(&instance, 18446744073709551615ull),
        4294967295ull,
        "i64_store32(18446744073709551615ull)"
    );
    assertEqualU64(
        endianness0_i64_store32(&instance, 18446744073709547374ull),
        4294963054ull,
        "i64_store32(18446744073709547374ull)"
    );
    assertEqualU64(
        endianness0_i64_store32(&instance, 42424242ull),
        42424242ull,
        "i64_store32(42424242ull)"
    );
    assertEqualU64(
        endianness0_i64_store32(&instance, 3735931646ull),
        3735931646ull,
        "i64_store32(3735931646ull)"
    );
    assertEqualU64(
        endianness0_i64_store(&instance, 18446744073709551615ull),
        18446744073709551615ull,
        "i64_store(18446744073709551615ull)"
    );
    assertEqualU64(
        endianness0_i64_store(&instance, 18446744073667127374ull),
        18446744073667127374ull,
        "i64_store(18446744073667127374ull)"
    );
    assertEqualU64(
        endianness0_i64_store(&instance, 2880249322ull),
        2880249322ull,
        "i64_store(2880249322ull)"
    );
    assertEqualU64(
        endianness0_i64_store(&instance, 12370766947463011818ull),
        12370766947463011818ull,
        "i64_store(12370766947463011818ull)"
    );
    assertEqualF32(
        endianness0_f32_store(&instance, -1.0),
        -1.0,
        "f32_store(-1.0)"
    );
    assertEqualF32(
        endianness0_f32_store(&instance, 0.01233999989926815),
        0.01233999989926815,
        "f32_store(0.01233999989926815)"
    );
    assertEqualF32(
        endianness0_f32_store(&instance, 4242.42431640625),
        4242.42431640625,
        "f32_store(4242.42431640625)"
    );
    assertEqualF32(
        endianness0_f32_store(&instance, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "f32_store(3.4028234663852886e+38)"
    );
    assertEqualF64(
        endianness0_f64_store(&instance, -1.0),
        -1.0,
        "f64_store(-1.0)"
    );
    assertEqualF64(
        endianness0_f64_store(&instance, 1234.56789),
        1234.56789,
        "f64_store(1234.56789)"
    );
    assertEqualF64(
        endianness0_f64_store(&instance, 424242.424242),
        424242.424242,
        "f64_store(424242.424242)"
    );
    assertEqualF64(
        endianness0_f64_store(&instance, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "f64_store(1.7976931348623157e+308)"
    );
}
