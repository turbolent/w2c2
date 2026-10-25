
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_f32_bitwise.0.h"

void test() {
    m13_f32X5FbitwiseX2E0Instance instance;
    m13_f32X5FbitwiseX2E0Instantiate(&instance, resolveTestImports);
    printStart("f32_bitwise.0.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -0.0)),
        2147483648u,
        "copysign(-0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 0.0)),
        0u,
        "copysign(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -0.0)),
        2147483648u,
        "copysign(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 0.0)),
        0u,
        "copysign(0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -1.401298464324817e-45)),
        2147483648u,
        "copysign(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 1.401298464324817e-45)),
        0u,
        "copysign(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -1.401298464324817e-45)),
        2147483648u,
        "copysign(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 1.401298464324817e-45)),
        0u,
        "copysign(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -1.1754943508222875e-38)),
        2147483648u,
        "copysign(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 1.1754943508222875e-38)),
        0u,
        "copysign(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -1.1754943508222875e-38)),
        2147483648u,
        "copysign(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 1.1754943508222875e-38)),
        0u,
        "copysign(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -0.5)),
        2147483648u,
        "copysign(-0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 0.5)),
        0u,
        "copysign(-0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -0.5)),
        2147483648u,
        "copysign(0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 0.5)),
        0u,
        "copysign(0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -1.0)),
        2147483648u,
        "copysign(-0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 1.0)),
        0u,
        "copysign(-0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -1.0)),
        2147483648u,
        "copysign(0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 1.0)),
        0u,
        "copysign(0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -6.2831854820251465)),
        2147483648u,
        "copysign(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 6.2831854820251465)),
        0u,
        "copysign(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -6.2831854820251465)),
        2147483648u,
        "copysign(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 6.2831854820251465)),
        0u,
        "copysign(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -3.4028234663852886e+38)),
        2147483648u,
        "copysign(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, 3.4028234663852886e+38)),
        0u,
        "copysign(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -3.4028234663852886e+38)),
        2147483648u,
        "copysign(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, 3.4028234663852886e+38)),
        0u,
        "copysign(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, -INFINITY)),
        2147483648u,
        "copysign(-0.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, INFINITY)),
        0u,
        "copysign(-0.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, -INFINITY)),
        2147483648u,
        "copysign(0.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, INFINITY)),
        0u,
        "copysign(0.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, f32_reinterpret_i32(0xffc00000u))),
        2147483648u,
        "copysign(-0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.0, f32_reinterpret_i32(0x7fc00000u))),
        0u,
        "copysign(-0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, f32_reinterpret_i32(0xffc00000u))),
        2147483648u,
        "copysign(0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))),
        0u,
        "copysign(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, -0.0)),
        2147483649u,
        "copysign(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, 0.0)),
        1u,
        "copysign(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, -0.0)),
        2147483649u,
        "copysign(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, 0.0)),
        1u,
        "copysign(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, -1.401298464324817e-45)),
        2147483649u,
        "copysign(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, 1.401298464324817e-45)),
        1u,
        "copysign(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, -1.401298464324817e-45)),
        2147483649u,
        "copysign(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, 1.401298464324817e-45)),
        1u,
        "copysign(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, -1.1754943508222875e-38)),
        2147483649u,
        "copysign(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, 1.1754943508222875e-38)),
        1u,
        "copysign(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, -1.1754943508222875e-38)),
        2147483649u,
        "copysign(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, 1.1754943508222875e-38)),
        1u,
        "copysign(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, -0.5)),
        2147483649u,
        "copysign(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, 0.5)),
        1u,
        "copysign(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, -0.5)),
        2147483649u,
        "copysign(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, 0.5)),
        1u,
        "copysign(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, -1.0)),
        2147483649u,
        "copysign(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, 1.0)),
        1u,
        "copysign(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, -1.0)),
        2147483649u,
        "copysign(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, 1.0)),
        1u,
        "copysign(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, -6.2831854820251465)),
        2147483649u,
        "copysign(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, 6.2831854820251465)),
        1u,
        "copysign(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, -6.2831854820251465)),
        2147483649u,
        "copysign(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, 6.2831854820251465)),
        1u,
        "copysign(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, -3.4028234663852886e+38)),
        2147483649u,
        "copysign(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, 3.4028234663852886e+38)),
        1u,
        "copysign(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, -3.4028234663852886e+38)),
        2147483649u,
        "copysign(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, 3.4028234663852886e+38)),
        1u,
        "copysign(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, -INFINITY)),
        2147483649u,
        "copysign(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, INFINITY)),
        1u,
        "copysign(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, -INFINITY)),
        2147483649u,
        "copysign(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, INFINITY)),
        1u,
        "copysign(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))),
        2147483649u,
        "copysign(-1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))),
        1u,
        "copysign(-1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))),
        2147483649u,
        "copysign(1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))),
        1u,
        "copysign(1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, -0.0)),
        2155872256u,
        "copysign(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, 0.0)),
        8388608u,
        "copysign(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, -0.0)),
        2155872256u,
        "copysign(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, 0.0)),
        8388608u,
        "copysign(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, -1.401298464324817e-45)),
        2155872256u,
        "copysign(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, 1.401298464324817e-45)),
        8388608u,
        "copysign(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, -1.401298464324817e-45)),
        2155872256u,
        "copysign(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, 1.401298464324817e-45)),
        8388608u,
        "copysign(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38)),
        2155872256u,
        "copysign(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38)),
        8388608u,
        "copysign(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38)),
        2155872256u,
        "copysign(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38)),
        8388608u,
        "copysign(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, -0.5)),
        2155872256u,
        "copysign(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, 0.5)),
        8388608u,
        "copysign(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, -0.5)),
        2155872256u,
        "copysign(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, 0.5)),
        8388608u,
        "copysign(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, -1.0)),
        2155872256u,
        "copysign(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, 1.0)),
        8388608u,
        "copysign(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, -1.0)),
        2155872256u,
        "copysign(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, 1.0)),
        8388608u,
        "copysign(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, -6.2831854820251465)),
        2155872256u,
        "copysign(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, 6.2831854820251465)),
        8388608u,
        "copysign(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, -6.2831854820251465)),
        2155872256u,
        "copysign(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, 6.2831854820251465)),
        8388608u,
        "copysign(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38)),
        2155872256u,
        "copysign(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38)),
        8388608u,
        "copysign(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38)),
        2155872256u,
        "copysign(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38)),
        8388608u,
        "copysign(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, -INFINITY)),
        2155872256u,
        "copysign(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, INFINITY)),
        8388608u,
        "copysign(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, -INFINITY)),
        2155872256u,
        "copysign(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, INFINITY)),
        8388608u,
        "copysign(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))),
        2155872256u,
        "copysign(-1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))),
        8388608u,
        "copysign(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))),
        2155872256u,
        "copysign(1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))),
        8388608u,
        "copysign(1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -0.0)),
        3204448256u,
        "copysign(-0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 0.0)),
        1056964608u,
        "copysign(-0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -0.0)),
        3204448256u,
        "copysign(0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 0.0)),
        1056964608u,
        "copysign(0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -1.401298464324817e-45)),
        3204448256u,
        "copysign(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 1.401298464324817e-45)),
        1056964608u,
        "copysign(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -1.401298464324817e-45)),
        3204448256u,
        "copysign(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 1.401298464324817e-45)),
        1056964608u,
        "copysign(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -1.1754943508222875e-38)),
        3204448256u,
        "copysign(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 1.1754943508222875e-38)),
        1056964608u,
        "copysign(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -1.1754943508222875e-38)),
        3204448256u,
        "copysign(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 1.1754943508222875e-38)),
        1056964608u,
        "copysign(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -0.5)),
        3204448256u,
        "copysign(-0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 0.5)),
        1056964608u,
        "copysign(-0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -0.5)),
        3204448256u,
        "copysign(0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 0.5)),
        1056964608u,
        "copysign(0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -1.0)),
        3204448256u,
        "copysign(-0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 1.0)),
        1056964608u,
        "copysign(-0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -1.0)),
        3204448256u,
        "copysign(0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 1.0)),
        1056964608u,
        "copysign(0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -6.2831854820251465)),
        3204448256u,
        "copysign(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 6.2831854820251465)),
        1056964608u,
        "copysign(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -6.2831854820251465)),
        3204448256u,
        "copysign(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 6.2831854820251465)),
        1056964608u,
        "copysign(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -3.4028234663852886e+38)),
        3204448256u,
        "copysign(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, 3.4028234663852886e+38)),
        1056964608u,
        "copysign(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -3.4028234663852886e+38)),
        3204448256u,
        "copysign(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, 3.4028234663852886e+38)),
        1056964608u,
        "copysign(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, -INFINITY)),
        3204448256u,
        "copysign(-0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, INFINITY)),
        1056964608u,
        "copysign(-0.5, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, -INFINITY)),
        3204448256u,
        "copysign(0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, INFINITY)),
        1056964608u,
        "copysign(0.5, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, f32_reinterpret_i32(0xffc00000u))),
        3204448256u,
        "copysign(-0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -0.5, f32_reinterpret_i32(0x7fc00000u))),
        1056964608u,
        "copysign(-0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, f32_reinterpret_i32(0xffc00000u))),
        3204448256u,
        "copysign(0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 0.5, f32_reinterpret_i32(0x7fc00000u))),
        1056964608u,
        "copysign(0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -0.0)),
        3212836864u,
        "copysign(-1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 0.0)),
        1065353216u,
        "copysign(-1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -0.0)),
        3212836864u,
        "copysign(1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 0.0)),
        1065353216u,
        "copysign(1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -1.401298464324817e-45)),
        3212836864u,
        "copysign(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 1.401298464324817e-45)),
        1065353216u,
        "copysign(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -1.401298464324817e-45)),
        3212836864u,
        "copysign(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 1.401298464324817e-45)),
        1065353216u,
        "copysign(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -1.1754943508222875e-38)),
        3212836864u,
        "copysign(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 1.1754943508222875e-38)),
        1065353216u,
        "copysign(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -1.1754943508222875e-38)),
        3212836864u,
        "copysign(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 1.1754943508222875e-38)),
        1065353216u,
        "copysign(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -0.5)),
        3212836864u,
        "copysign(-1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 0.5)),
        1065353216u,
        "copysign(-1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -0.5)),
        3212836864u,
        "copysign(1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 0.5)),
        1065353216u,
        "copysign(1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -1.0)),
        3212836864u,
        "copysign(-1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 1.0)),
        1065353216u,
        "copysign(-1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -1.0)),
        3212836864u,
        "copysign(1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 1.0)),
        1065353216u,
        "copysign(1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -6.2831854820251465)),
        3212836864u,
        "copysign(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 6.2831854820251465)),
        1065353216u,
        "copysign(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -6.2831854820251465)),
        3212836864u,
        "copysign(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 6.2831854820251465)),
        1065353216u,
        "copysign(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -3.4028234663852886e+38)),
        3212836864u,
        "copysign(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, 3.4028234663852886e+38)),
        1065353216u,
        "copysign(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -3.4028234663852886e+38)),
        3212836864u,
        "copysign(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, 3.4028234663852886e+38)),
        1065353216u,
        "copysign(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, -INFINITY)),
        3212836864u,
        "copysign(-1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, INFINITY)),
        1065353216u,
        "copysign(-1.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, -INFINITY)),
        3212836864u,
        "copysign(1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, INFINITY)),
        1065353216u,
        "copysign(1.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, f32_reinterpret_i32(0xffc00000u))),
        3212836864u,
        "copysign(-1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -1.0, f32_reinterpret_i32(0x7fc00000u))),
        1065353216u,
        "copysign(-1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, f32_reinterpret_i32(0xffc00000u))),
        3212836864u,
        "copysign(1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 1.0, f32_reinterpret_i32(0x7fc00000u))),
        1065353216u,
        "copysign(1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, -0.0)),
        3234402267u,
        "copysign(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, 0.0)),
        1086918619u,
        "copysign(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, -0.0)),
        3234402267u,
        "copysign(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, 0.0)),
        1086918619u,
        "copysign(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, -1.401298464324817e-45)),
        3234402267u,
        "copysign(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, 1.401298464324817e-45)),
        1086918619u,
        "copysign(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, -1.401298464324817e-45)),
        3234402267u,
        "copysign(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, 1.401298464324817e-45)),
        1086918619u,
        "copysign(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, -1.1754943508222875e-38)),
        3234402267u,
        "copysign(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, 1.1754943508222875e-38)),
        1086918619u,
        "copysign(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, -1.1754943508222875e-38)),
        3234402267u,
        "copysign(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, 1.1754943508222875e-38)),
        1086918619u,
        "copysign(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, -0.5)),
        3234402267u,
        "copysign(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, 0.5)),
        1086918619u,
        "copysign(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, -0.5)),
        3234402267u,
        "copysign(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, 0.5)),
        1086918619u,
        "copysign(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, -1.0)),
        3234402267u,
        "copysign(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, 1.0)),
        1086918619u,
        "copysign(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, -1.0)),
        3234402267u,
        "copysign(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, 1.0)),
        1086918619u,
        "copysign(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, -6.2831854820251465)),
        3234402267u,
        "copysign(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, 6.2831854820251465)),
        1086918619u,
        "copysign(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, -6.2831854820251465)),
        3234402267u,
        "copysign(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, 6.2831854820251465)),
        1086918619u,
        "copysign(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, -3.4028234663852886e+38)),
        3234402267u,
        "copysign(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, 3.4028234663852886e+38)),
        1086918619u,
        "copysign(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, -3.4028234663852886e+38)),
        3234402267u,
        "copysign(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, 3.4028234663852886e+38)),
        1086918619u,
        "copysign(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, -INFINITY)),
        3234402267u,
        "copysign(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, INFINITY)),
        1086918619u,
        "copysign(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, -INFINITY)),
        3234402267u,
        "copysign(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, INFINITY)),
        1086918619u,
        "copysign(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffc00000u))),
        3234402267u,
        "copysign(-6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))),
        1086918619u,
        "copysign(-6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffc00000u))),
        3234402267u,
        "copysign(6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))),
        1086918619u,
        "copysign(6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, -0.0)),
        4286578687u,
        "copysign(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, 0.0)),
        2139095039u,
        "copysign(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, -0.0)),
        4286578687u,
        "copysign(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, 0.0)),
        2139095039u,
        "copysign(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, -1.401298464324817e-45)),
        4286578687u,
        "copysign(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, 1.401298464324817e-45)),
        2139095039u,
        "copysign(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, -1.401298464324817e-45)),
        4286578687u,
        "copysign(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, 1.401298464324817e-45)),
        2139095039u,
        "copysign(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38)),
        4286578687u,
        "copysign(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38)),
        2139095039u,
        "copysign(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38)),
        4286578687u,
        "copysign(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38)),
        2139095039u,
        "copysign(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, -0.5)),
        4286578687u,
        "copysign(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, 0.5)),
        2139095039u,
        "copysign(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, -0.5)),
        4286578687u,
        "copysign(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, 0.5)),
        2139095039u,
        "copysign(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, -1.0)),
        4286578687u,
        "copysign(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, 1.0)),
        2139095039u,
        "copysign(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, -1.0)),
        4286578687u,
        "copysign(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, 1.0)),
        2139095039u,
        "copysign(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, -6.2831854820251465)),
        4286578687u,
        "copysign(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, 6.2831854820251465)),
        2139095039u,
        "copysign(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, -6.2831854820251465)),
        4286578687u,
        "copysign(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, 6.2831854820251465)),
        2139095039u,
        "copysign(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38)),
        4286578687u,
        "copysign(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38)),
        2139095039u,
        "copysign(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38)),
        4286578687u,
        "copysign(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38)),
        2139095039u,
        "copysign(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, -INFINITY)),
        4286578687u,
        "copysign(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, INFINITY)),
        2139095039u,
        "copysign(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, -INFINITY)),
        4286578687u,
        "copysign(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, INFINITY)),
        2139095039u,
        "copysign(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))),
        4286578687u,
        "copysign(-3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))),
        2139095039u,
        "copysign(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))),
        4286578687u,
        "copysign(3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))),
        2139095039u,
        "copysign(3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -0.0)),
        4286578688u,
        "copysign(-INFINITY, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 0.0)),
        2139095040u,
        "copysign(-INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -0.0)),
        4286578688u,
        "copysign(INFINITY, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 0.0)),
        2139095040u,
        "copysign(INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -1.401298464324817e-45)),
        4286578688u,
        "copysign(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 1.401298464324817e-45)),
        2139095040u,
        "copysign(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -1.401298464324817e-45)),
        4286578688u,
        "copysign(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 1.401298464324817e-45)),
        2139095040u,
        "copysign(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -1.1754943508222875e-38)),
        4286578688u,
        "copysign(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 1.1754943508222875e-38)),
        2139095040u,
        "copysign(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -1.1754943508222875e-38)),
        4286578688u,
        "copysign(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 1.1754943508222875e-38)),
        2139095040u,
        "copysign(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -0.5)),
        4286578688u,
        "copysign(-INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 0.5)),
        2139095040u,
        "copysign(-INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -0.5)),
        4286578688u,
        "copysign(INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 0.5)),
        2139095040u,
        "copysign(INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -1.0)),
        4286578688u,
        "copysign(-INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 1.0)),
        2139095040u,
        "copysign(-INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -1.0)),
        4286578688u,
        "copysign(INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 1.0)),
        2139095040u,
        "copysign(INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -6.2831854820251465)),
        4286578688u,
        "copysign(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 6.2831854820251465)),
        2139095040u,
        "copysign(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -6.2831854820251465)),
        4286578688u,
        "copysign(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 6.2831854820251465)),
        2139095040u,
        "copysign(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -3.4028234663852886e+38)),
        4286578688u,
        "copysign(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, 3.4028234663852886e+38)),
        2139095040u,
        "copysign(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -3.4028234663852886e+38)),
        4286578688u,
        "copysign(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, 3.4028234663852886e+38)),
        2139095040u,
        "copysign(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, -INFINITY)),
        4286578688u,
        "copysign(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, INFINITY)),
        2139095040u,
        "copysign(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, -INFINITY)),
        4286578688u,
        "copysign(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, INFINITY)),
        2139095040u,
        "copysign(INFINITY, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, f32_reinterpret_i32(0xffc00000u))),
        4286578688u,
        "copysign(-INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, -INFINITY, f32_reinterpret_i32(0x7fc00000u))),
        2139095040u,
        "copysign(-INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, f32_reinterpret_i32(0xffc00000u))),
        4286578688u,
        "copysign(INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, INFINITY, f32_reinterpret_i32(0x7fc00000u))),
        2139095040u,
        "copysign(INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), -0.0)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0xffc00000u), -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), 0.0)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0xffc00000u), 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), -0.0)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), -0.5)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0xffc00000u), -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), 0.5)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0xffc00000u), 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), -0.5)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), 0.5)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), -1.0)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0xffc00000u), -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), 1.0)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0xffc00000u), 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), -1.0)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), 1.0)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), -INFINITY)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0xffc00000u), -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), INFINITY)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0xffc00000u), INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), -INFINITY)),
        4290772992u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), INFINITY)),
        2143289344u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))),
        4290772992u,
        "copysign(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))),
        2143289344u,
        "copysign(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))),
        4290772992u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export8_copysign(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))),
        2143289344u,
        "copysign(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, -0.0)),
        0u,
        "abs(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, 0.0)),
        0u,
        "abs(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, -1.401298464324817e-45)),
        1u,
        "abs(-1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, 1.401298464324817e-45)),
        1u,
        "abs(1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, -1.1754943508222875e-38)),
        8388608u,
        "abs(-1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, 1.1754943508222875e-38)),
        8388608u,
        "abs(1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, -0.5)),
        1056964608u,
        "abs(-0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, 0.5)),
        1056964608u,
        "abs(0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, -1.0)),
        1065353216u,
        "abs(-1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, 1.0)),
        1065353216u,
        "abs(1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, -6.2831854820251465)),
        1086918619u,
        "abs(-6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, 6.2831854820251465)),
        1086918619u,
        "abs(6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, -3.4028234663852886e+38)),
        2139095039u,
        "abs(-3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, 3.4028234663852886e+38)),
        2139095039u,
        "abs(3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, -INFINITY)),
        2139095040u,
        "abs(-INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, INFINITY)),
        2139095040u,
        "abs(INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, f32_reinterpret_i32(0xffc00000u))),
        2143289344u,
        "abs(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_abs(&instance, f32_reinterpret_i32(0x7fc00000u))),
        2143289344u,
        "abs(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, -0.0)),
        0u,
        "neg(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, 0.0)),
        2147483648u,
        "neg(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, -1.401298464324817e-45)),
        1u,
        "neg(-1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, 1.401298464324817e-45)),
        2147483649u,
        "neg(1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, -1.1754943508222875e-38)),
        8388608u,
        "neg(-1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, 1.1754943508222875e-38)),
        2155872256u,
        "neg(1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, -0.5)),
        1056964608u,
        "neg(-0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, 0.5)),
        3204448256u,
        "neg(0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, -1.0)),
        1065353216u,
        "neg(-1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, 1.0)),
        3212836864u,
        "neg(1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, -6.2831854820251465)),
        1086918619u,
        "neg(-6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, 6.2831854820251465)),
        3234402267u,
        "neg(6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, -3.4028234663852886e+38)),
        2139095039u,
        "neg(-3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, 3.4028234663852886e+38)),
        4286578687u,
        "neg(3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, -INFINITY)),
        2139095040u,
        "neg(-INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, INFINITY)),
        4286578688u,
        "neg(INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, f32_reinterpret_i32(0xffc00000u))),
        2143289344u,
        "neg(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_f32X5FbitwiseX2E0Export3_neg(&instance, f32_reinterpret_i32(0x7fc00000u))),
        4290772992u,
        "neg(f32_reinterpret_i32(0x7fc00000u))"
    );
}
