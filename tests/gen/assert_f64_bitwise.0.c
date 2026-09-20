
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_f64_bitwise.0.h"

void test() {
    m13_f64X5FbitwiseX2E0Instance instance;
    m13_f64X5FbitwiseX2E0Instantiate(&instance, resolveTestImports);
    printStart("f64_bitwise.0.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -0.0)),
        9223372036854775808ull,
        "copysign(-0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 0.0)),
        0ull,
        "copysign(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -0.0)),
        9223372036854775808ull,
        "copysign(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 0.0)),
        0ull,
        "copysign(0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -5e-324)),
        9223372036854775808ull,
        "copysign(-0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 5e-324)),
        0ull,
        "copysign(-0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -5e-324)),
        9223372036854775808ull,
        "copysign(0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 5e-324)),
        0ull,
        "copysign(0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -2.2250738585072014e-308)),
        9223372036854775808ull,
        "copysign(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 2.2250738585072014e-308)),
        0ull,
        "copysign(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -2.2250738585072014e-308)),
        9223372036854775808ull,
        "copysign(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 2.2250738585072014e-308)),
        0ull,
        "copysign(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -0.5)),
        9223372036854775808ull,
        "copysign(-0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 0.5)),
        0ull,
        "copysign(-0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -0.5)),
        9223372036854775808ull,
        "copysign(0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 0.5)),
        0ull,
        "copysign(0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -1.0)),
        9223372036854775808ull,
        "copysign(-0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 1.0)),
        0ull,
        "copysign(-0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -1.0)),
        9223372036854775808ull,
        "copysign(0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 1.0)),
        0ull,
        "copysign(0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -6.283185307179586)),
        9223372036854775808ull,
        "copysign(-0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 6.283185307179586)),
        0ull,
        "copysign(-0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -6.283185307179586)),
        9223372036854775808ull,
        "copysign(0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 6.283185307179586)),
        0ull,
        "copysign(0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -1.7976931348623157e+308)),
        9223372036854775808ull,
        "copysign(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 1.7976931348623157e+308)),
        0ull,
        "copysign(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -1.7976931348623157e+308)),
        9223372036854775808ull,
        "copysign(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 1.7976931348623157e+308)),
        0ull,
        "copysign(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -INFINITY)),
        9223372036854775808ull,
        "copysign(-0.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, INFINITY)),
        0ull,
        "copysign(-0.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -INFINITY)),
        9223372036854775808ull,
        "copysign(0.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, INFINITY)),
        0ull,
        "copysign(0.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, f64_reinterpret_i64(0xfff8000000000000ull))),
        9223372036854775808ull,
        "copysign(-0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.0, f64_reinterpret_i64(0x7ff8000000000000ull))),
        0ull,
        "copysign(-0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, f64_reinterpret_i64(0xfff8000000000000ull))),
        9223372036854775808ull,
        "copysign(0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))),
        0ull,
        "copysign(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, -0.0)),
        9223372036854775809ull,
        "copysign(-5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, 0.0)),
        1ull,
        "copysign(-5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, -0.0)),
        9223372036854775809ull,
        "copysign(5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, 0.0)),
        1ull,
        "copysign(5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, -5e-324)),
        9223372036854775809ull,
        "copysign(-5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, 5e-324)),
        1ull,
        "copysign(-5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, -5e-324)),
        9223372036854775809ull,
        "copysign(5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, 5e-324)),
        1ull,
        "copysign(5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, -2.2250738585072014e-308)),
        9223372036854775809ull,
        "copysign(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, 2.2250738585072014e-308)),
        1ull,
        "copysign(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, -2.2250738585072014e-308)),
        9223372036854775809ull,
        "copysign(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, 2.2250738585072014e-308)),
        1ull,
        "copysign(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, -0.5)),
        9223372036854775809ull,
        "copysign(-5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, 0.5)),
        1ull,
        "copysign(-5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, -0.5)),
        9223372036854775809ull,
        "copysign(5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, 0.5)),
        1ull,
        "copysign(5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, -1.0)),
        9223372036854775809ull,
        "copysign(-5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, 1.0)),
        1ull,
        "copysign(-5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, -1.0)),
        9223372036854775809ull,
        "copysign(5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, 1.0)),
        1ull,
        "copysign(5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, -6.283185307179586)),
        9223372036854775809ull,
        "copysign(-5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, 6.283185307179586)),
        1ull,
        "copysign(-5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, -6.283185307179586)),
        9223372036854775809ull,
        "copysign(5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, 6.283185307179586)),
        1ull,
        "copysign(5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, -1.7976931348623157e+308)),
        9223372036854775809ull,
        "copysign(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, 1.7976931348623157e+308)),
        1ull,
        "copysign(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, -1.7976931348623157e+308)),
        9223372036854775809ull,
        "copysign(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, 1.7976931348623157e+308)),
        1ull,
        "copysign(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, -INFINITY)),
        9223372036854775809ull,
        "copysign(-5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, INFINITY)),
        1ull,
        "copysign(-5e-324, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, -INFINITY)),
        9223372036854775809ull,
        "copysign(5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, INFINITY)),
        1ull,
        "copysign(5e-324, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, f64_reinterpret_i64(0xfff8000000000000ull))),
        9223372036854775809ull,
        "copysign(-5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))),
        1ull,
        "copysign(-5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, f64_reinterpret_i64(0xfff8000000000000ull))),
        9223372036854775809ull,
        "copysign(5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))),
        1ull,
        "copysign(5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, -0.0)),
        9227875636482146304ull,
        "copysign(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, 0.0)),
        4503599627370496ull,
        "copysign(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, -0.0)),
        9227875636482146304ull,
        "copysign(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, 0.0)),
        4503599627370496ull,
        "copysign(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, -5e-324)),
        9227875636482146304ull,
        "copysign(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, 5e-324)),
        4503599627370496ull,
        "copysign(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, -5e-324)),
        9227875636482146304ull,
        "copysign(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, 5e-324)),
        4503599627370496ull,
        "copysign(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "copysign(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308)),
        4503599627370496ull,
        "copysign(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "copysign(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308)),
        4503599627370496ull,
        "copysign(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, -0.5)),
        9227875636482146304ull,
        "copysign(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, 0.5)),
        4503599627370496ull,
        "copysign(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, -0.5)),
        9227875636482146304ull,
        "copysign(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, 0.5)),
        4503599627370496ull,
        "copysign(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, -1.0)),
        9227875636482146304ull,
        "copysign(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, 1.0)),
        4503599627370496ull,
        "copysign(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, -1.0)),
        9227875636482146304ull,
        "copysign(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, 1.0)),
        4503599627370496ull,
        "copysign(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, -6.283185307179586)),
        9227875636482146304ull,
        "copysign(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, 6.283185307179586)),
        4503599627370496ull,
        "copysign(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, -6.283185307179586)),
        9227875636482146304ull,
        "copysign(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, 6.283185307179586)),
        4503599627370496ull,
        "copysign(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308)),
        9227875636482146304ull,
        "copysign(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308)),
        4503599627370496ull,
        "copysign(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308)),
        9227875636482146304ull,
        "copysign(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308)),
        4503599627370496ull,
        "copysign(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, -INFINITY)),
        9227875636482146304ull,
        "copysign(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, INFINITY)),
        4503599627370496ull,
        "copysign(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, -INFINITY)),
        9227875636482146304ull,
        "copysign(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, INFINITY)),
        4503599627370496ull,
        "copysign(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))),
        9227875636482146304ull,
        "copysign(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))),
        4503599627370496ull,
        "copysign(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))),
        9227875636482146304ull,
        "copysign(2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))),
        4503599627370496ull,
        "copysign(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -0.0)),
        13826050856027422720ull,
        "copysign(-0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 0.0)),
        4602678819172646912ull,
        "copysign(-0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -0.0)),
        13826050856027422720ull,
        "copysign(0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 0.0)),
        4602678819172646912ull,
        "copysign(0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -5e-324)),
        13826050856027422720ull,
        "copysign(-0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 5e-324)),
        4602678819172646912ull,
        "copysign(-0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -5e-324)),
        13826050856027422720ull,
        "copysign(0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 5e-324)),
        4602678819172646912ull,
        "copysign(0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -2.2250738585072014e-308)),
        13826050856027422720ull,
        "copysign(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 2.2250738585072014e-308)),
        4602678819172646912ull,
        "copysign(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -2.2250738585072014e-308)),
        13826050856027422720ull,
        "copysign(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 2.2250738585072014e-308)),
        4602678819172646912ull,
        "copysign(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -0.5)),
        13826050856027422720ull,
        "copysign(-0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 0.5)),
        4602678819172646912ull,
        "copysign(-0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -0.5)),
        13826050856027422720ull,
        "copysign(0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 0.5)),
        4602678819172646912ull,
        "copysign(0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -1.0)),
        13826050856027422720ull,
        "copysign(-0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 1.0)),
        4602678819172646912ull,
        "copysign(-0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -1.0)),
        13826050856027422720ull,
        "copysign(0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 1.0)),
        4602678819172646912ull,
        "copysign(0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -6.283185307179586)),
        13826050856027422720ull,
        "copysign(-0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 6.283185307179586)),
        4602678819172646912ull,
        "copysign(-0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -6.283185307179586)),
        13826050856027422720ull,
        "copysign(0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 6.283185307179586)),
        4602678819172646912ull,
        "copysign(0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -1.7976931348623157e+308)),
        13826050856027422720ull,
        "copysign(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 1.7976931348623157e+308)),
        4602678819172646912ull,
        "copysign(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -1.7976931348623157e+308)),
        13826050856027422720ull,
        "copysign(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 1.7976931348623157e+308)),
        4602678819172646912ull,
        "copysign(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -INFINITY)),
        13826050856027422720ull,
        "copysign(-0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, INFINITY)),
        4602678819172646912ull,
        "copysign(-0.5, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -INFINITY)),
        13826050856027422720ull,
        "copysign(0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, INFINITY)),
        4602678819172646912ull,
        "copysign(0.5, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, f64_reinterpret_i64(0xfff8000000000000ull))),
        13826050856027422720ull,
        "copysign(-0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -0.5, f64_reinterpret_i64(0x7ff8000000000000ull))),
        4602678819172646912ull,
        "copysign(-0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, f64_reinterpret_i64(0xfff8000000000000ull))),
        13826050856027422720ull,
        "copysign(0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 0.5, f64_reinterpret_i64(0x7ff8000000000000ull))),
        4602678819172646912ull,
        "copysign(0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -0.0)),
        13830554455654793216ull,
        "copysign(-1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 0.0)),
        4607182418800017408ull,
        "copysign(-1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -0.0)),
        13830554455654793216ull,
        "copysign(1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 0.0)),
        4607182418800017408ull,
        "copysign(1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -5e-324)),
        13830554455654793216ull,
        "copysign(-1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 5e-324)),
        4607182418800017408ull,
        "copysign(-1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -5e-324)),
        13830554455654793216ull,
        "copysign(1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 5e-324)),
        4607182418800017408ull,
        "copysign(1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -2.2250738585072014e-308)),
        13830554455654793216ull,
        "copysign(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 2.2250738585072014e-308)),
        4607182418800017408ull,
        "copysign(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -2.2250738585072014e-308)),
        13830554455654793216ull,
        "copysign(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 2.2250738585072014e-308)),
        4607182418800017408ull,
        "copysign(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -0.5)),
        13830554455654793216ull,
        "copysign(-1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 0.5)),
        4607182418800017408ull,
        "copysign(-1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -0.5)),
        13830554455654793216ull,
        "copysign(1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 0.5)),
        4607182418800017408ull,
        "copysign(1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -1.0)),
        13830554455654793216ull,
        "copysign(-1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 1.0)),
        4607182418800017408ull,
        "copysign(-1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -1.0)),
        13830554455654793216ull,
        "copysign(1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 1.0)),
        4607182418800017408ull,
        "copysign(1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -6.283185307179586)),
        13830554455654793216ull,
        "copysign(-1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 6.283185307179586)),
        4607182418800017408ull,
        "copysign(-1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -6.283185307179586)),
        13830554455654793216ull,
        "copysign(1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 6.283185307179586)),
        4607182418800017408ull,
        "copysign(1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -1.7976931348623157e+308)),
        13830554455654793216ull,
        "copysign(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 1.7976931348623157e+308)),
        4607182418800017408ull,
        "copysign(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -1.7976931348623157e+308)),
        13830554455654793216ull,
        "copysign(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 1.7976931348623157e+308)),
        4607182418800017408ull,
        "copysign(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -INFINITY)),
        13830554455654793216ull,
        "copysign(-1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, INFINITY)),
        4607182418800017408ull,
        "copysign(-1.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -INFINITY)),
        13830554455654793216ull,
        "copysign(1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, INFINITY)),
        4607182418800017408ull,
        "copysign(1.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, f64_reinterpret_i64(0xfff8000000000000ull))),
        13830554455654793216ull,
        "copysign(-1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.0, f64_reinterpret_i64(0x7ff8000000000000ull))),
        4607182418800017408ull,
        "copysign(-1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, f64_reinterpret_i64(0xfff8000000000000ull))),
        13830554455654793216ull,
        "copysign(1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.0, f64_reinterpret_i64(0x7ff8000000000000ull))),
        4607182418800017408ull,
        "copysign(1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, -0.0)),
        13842132293034192152ull,
        "copysign(-6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, 0.0)),
        4618760256179416344ull,
        "copysign(-6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, -0.0)),
        13842132293034192152ull,
        "copysign(6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, 0.0)),
        4618760256179416344ull,
        "copysign(6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, -5e-324)),
        13842132293034192152ull,
        "copysign(-6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, 5e-324)),
        4618760256179416344ull,
        "copysign(-6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, -5e-324)),
        13842132293034192152ull,
        "copysign(6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, 5e-324)),
        4618760256179416344ull,
        "copysign(6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, -2.2250738585072014e-308)),
        13842132293034192152ull,
        "copysign(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, 2.2250738585072014e-308)),
        4618760256179416344ull,
        "copysign(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, -2.2250738585072014e-308)),
        13842132293034192152ull,
        "copysign(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, 2.2250738585072014e-308)),
        4618760256179416344ull,
        "copysign(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, -0.5)),
        13842132293034192152ull,
        "copysign(-6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, 0.5)),
        4618760256179416344ull,
        "copysign(-6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, -0.5)),
        13842132293034192152ull,
        "copysign(6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, 0.5)),
        4618760256179416344ull,
        "copysign(6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, -1.0)),
        13842132293034192152ull,
        "copysign(-6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, 1.0)),
        4618760256179416344ull,
        "copysign(-6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, -1.0)),
        13842132293034192152ull,
        "copysign(6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, 1.0)),
        4618760256179416344ull,
        "copysign(6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, -6.283185307179586)),
        13842132293034192152ull,
        "copysign(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, 6.283185307179586)),
        4618760256179416344ull,
        "copysign(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, -6.283185307179586)),
        13842132293034192152ull,
        "copysign(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, 6.283185307179586)),
        4618760256179416344ull,
        "copysign(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, -1.7976931348623157e+308)),
        13842132293034192152ull,
        "copysign(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, 1.7976931348623157e+308)),
        4618760256179416344ull,
        "copysign(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, -1.7976931348623157e+308)),
        13842132293034192152ull,
        "copysign(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, 1.7976931348623157e+308)),
        4618760256179416344ull,
        "copysign(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, -INFINITY)),
        13842132293034192152ull,
        "copysign(-6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, INFINITY)),
        4618760256179416344ull,
        "copysign(-6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, -INFINITY)),
        13842132293034192152ull,
        "copysign(6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, INFINITY)),
        4618760256179416344ull,
        "copysign(6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))),
        13842132293034192152ull,
        "copysign(-6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))),
        4618760256179416344ull,
        "copysign(-6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))),
        13842132293034192152ull,
        "copysign(6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))),
        4618760256179416344ull,
        "copysign(6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, -0.0)),
        18442240474082181119ull,
        "copysign(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, 0.0)),
        9218868437227405311ull,
        "copysign(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, -0.0)),
        18442240474082181119ull,
        "copysign(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, 0.0)),
        9218868437227405311ull,
        "copysign(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, -5e-324)),
        18442240474082181119ull,
        "copysign(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, 5e-324)),
        9218868437227405311ull,
        "copysign(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, -5e-324)),
        18442240474082181119ull,
        "copysign(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, 5e-324)),
        9218868437227405311ull,
        "copysign(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308)),
        18442240474082181119ull,
        "copysign(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308)),
        9218868437227405311ull,
        "copysign(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308)),
        18442240474082181119ull,
        "copysign(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308)),
        9218868437227405311ull,
        "copysign(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, -0.5)),
        18442240474082181119ull,
        "copysign(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, 0.5)),
        9218868437227405311ull,
        "copysign(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, -0.5)),
        18442240474082181119ull,
        "copysign(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, 0.5)),
        9218868437227405311ull,
        "copysign(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, -1.0)),
        18442240474082181119ull,
        "copysign(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, 1.0)),
        9218868437227405311ull,
        "copysign(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, -1.0)),
        18442240474082181119ull,
        "copysign(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, 1.0)),
        9218868437227405311ull,
        "copysign(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, -6.283185307179586)),
        18442240474082181119ull,
        "copysign(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, 6.283185307179586)),
        9218868437227405311ull,
        "copysign(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, -6.283185307179586)),
        18442240474082181119ull,
        "copysign(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, 6.283185307179586)),
        9218868437227405311ull,
        "copysign(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "copysign(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "copysign(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "copysign(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "copysign(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, -INFINITY)),
        18442240474082181119ull,
        "copysign(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, INFINITY)),
        9218868437227405311ull,
        "copysign(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, -INFINITY)),
        18442240474082181119ull,
        "copysign(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, INFINITY)),
        9218868437227405311ull,
        "copysign(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))),
        18442240474082181119ull,
        "copysign(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9218868437227405311ull,
        "copysign(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))),
        18442240474082181119ull,
        "copysign(1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9218868437227405311ull,
        "copysign(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -0.0)),
        18442240474082181120ull,
        "copysign(-INFINITY, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 0.0)),
        9218868437227405312ull,
        "copysign(-INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -0.0)),
        18442240474082181120ull,
        "copysign(INFINITY, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 0.0)),
        9218868437227405312ull,
        "copysign(INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -5e-324)),
        18442240474082181120ull,
        "copysign(-INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 5e-324)),
        9218868437227405312ull,
        "copysign(-INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -5e-324)),
        18442240474082181120ull,
        "copysign(INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 5e-324)),
        9218868437227405312ull,
        "copysign(INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -2.2250738585072014e-308)),
        18442240474082181120ull,
        "copysign(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 2.2250738585072014e-308)),
        9218868437227405312ull,
        "copysign(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -2.2250738585072014e-308)),
        18442240474082181120ull,
        "copysign(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 2.2250738585072014e-308)),
        9218868437227405312ull,
        "copysign(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -0.5)),
        18442240474082181120ull,
        "copysign(-INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 0.5)),
        9218868437227405312ull,
        "copysign(-INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -0.5)),
        18442240474082181120ull,
        "copysign(INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 0.5)),
        9218868437227405312ull,
        "copysign(INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -1.0)),
        18442240474082181120ull,
        "copysign(-INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 1.0)),
        9218868437227405312ull,
        "copysign(-INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -1.0)),
        18442240474082181120ull,
        "copysign(INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 1.0)),
        9218868437227405312ull,
        "copysign(INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -6.283185307179586)),
        18442240474082181120ull,
        "copysign(-INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 6.283185307179586)),
        9218868437227405312ull,
        "copysign(-INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -6.283185307179586)),
        18442240474082181120ull,
        "copysign(INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 6.283185307179586)),
        9218868437227405312ull,
        "copysign(INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -1.7976931348623157e+308)),
        18442240474082181120ull,
        "copysign(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 1.7976931348623157e+308)),
        9218868437227405312ull,
        "copysign(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -1.7976931348623157e+308)),
        18442240474082181120ull,
        "copysign(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 1.7976931348623157e+308)),
        9218868437227405312ull,
        "copysign(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -INFINITY)),
        18442240474082181120ull,
        "copysign(-INFINITY, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, INFINITY)),
        9218868437227405312ull,
        "copysign(-INFINITY, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -INFINITY)),
        18442240474082181120ull,
        "copysign(INFINITY, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, INFINITY)),
        9218868437227405312ull,
        "copysign(INFINITY, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))),
        18442240474082181120ull,
        "copysign(-INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9218868437227405312ull,
        "copysign(-INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))),
        18442240474082181120ull,
        "copysign(INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9218868437227405312ull,
        "copysign(INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.0)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.0)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.5)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.5)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.0)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.0)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))),
        18444492273895866368ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export8_copysign(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))),
        9221120237041090560ull,
        "copysign(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, -0.0)),
        0ull,
        "abs(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, 0.0)),
        0ull,
        "abs(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, -5e-324)),
        1ull,
        "abs(-5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, 5e-324)),
        1ull,
        "abs(5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, -2.2250738585072014e-308)),
        4503599627370496ull,
        "abs(-2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, 2.2250738585072014e-308)),
        4503599627370496ull,
        "abs(2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, -0.5)),
        4602678819172646912ull,
        "abs(-0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, 0.5)),
        4602678819172646912ull,
        "abs(0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, -1.0)),
        4607182418800017408ull,
        "abs(-1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, 1.0)),
        4607182418800017408ull,
        "abs(1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, -6.283185307179586)),
        4618760256179416344ull,
        "abs(-6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, 6.283185307179586)),
        4618760256179416344ull,
        "abs(6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "abs(-1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "abs(1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, -INFINITY)),
        9218868437227405312ull,
        "abs(-INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, INFINITY)),
        9218868437227405312ull,
        "abs(INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, f64_reinterpret_i64(0xfff8000000000000ull))),
        9221120237041090560ull,
        "abs(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_abs(&instance, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9221120237041090560ull,
        "abs(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, -0.0)),
        0ull,
        "neg(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, 0.0)),
        9223372036854775808ull,
        "neg(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, -5e-324)),
        1ull,
        "neg(-5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, 5e-324)),
        9223372036854775809ull,
        "neg(5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, -2.2250738585072014e-308)),
        4503599627370496ull,
        "neg(-2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, 2.2250738585072014e-308)),
        9227875636482146304ull,
        "neg(2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, -0.5)),
        4602678819172646912ull,
        "neg(-0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, 0.5)),
        13826050856027422720ull,
        "neg(0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, -1.0)),
        4607182418800017408ull,
        "neg(-1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, 1.0)),
        13830554455654793216ull,
        "neg(1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, -6.283185307179586)),
        4618760256179416344ull,
        "neg(-6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, 6.283185307179586)),
        13842132293034192152ull,
        "neg(6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "neg(-1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "neg(1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, -INFINITY)),
        9218868437227405312ull,
        "neg(-INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, INFINITY)),
        18442240474082181120ull,
        "neg(INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, f64_reinterpret_i64(0xfff8000000000000ull))),
        9221120237041090560ull,
        "neg(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_f64X5FbitwiseX2E0Export3_neg(&instance, f64_reinterpret_i64(0x7ff8000000000000ull))),
        18444492273895866368ull,
        "neg(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
}
