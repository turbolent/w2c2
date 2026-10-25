
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_f32.0.h"

void test() {
    m5_f32X2E0Instance instance;
    m5_f32X2E0Instantiate(&instance, resolveTestImports);
    printStart("f32.0.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, -0.0)),
        2147483648u,
        "add(-0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, 0.0)),
        0u,
        "add(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, -0.0)),
        0u,
        "add(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, 0.0)),
        0u,
        "add(0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, -1.401298464324817e-45)),
        2147483649u,
        "add(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, 1.401298464324817e-45)),
        1u,
        "add(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, -1.401298464324817e-45)),
        2147483649u,
        "add(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, 1.401298464324817e-45)),
        1u,
        "add(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, -1.1754943508222875e-38)),
        2155872256u,
        "add(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, 1.1754943508222875e-38)),
        8388608u,
        "add(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, -1.1754943508222875e-38)),
        2155872256u,
        "add(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, 1.1754943508222875e-38)),
        8388608u,
        "add(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, -0.5)),
        3204448256u,
        "add(-0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, 0.5)),
        1056964608u,
        "add(-0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, -0.5)),
        3204448256u,
        "add(0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, 0.5)),
        1056964608u,
        "add(0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, -1.0)),
        3212836864u,
        "add(-0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, 1.0)),
        1065353216u,
        "add(-0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, -1.0)),
        3212836864u,
        "add(0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, 1.0)),
        1065353216u,
        "add(0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, -6.2831854820251465)),
        3234402267u,
        "add(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, 6.2831854820251465)),
        1086918619u,
        "add(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, -6.2831854820251465)),
        3234402267u,
        "add(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, 6.2831854820251465)),
        1086918619u,
        "add(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, -3.4028234663852886e+38)),
        4286578687u,
        "add(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, 3.4028234663852886e+38)),
        2139095039u,
        "add(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, -3.4028234663852886e+38)),
        4286578687u,
        "add(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, 3.4028234663852886e+38)),
        2139095039u,
        "add(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, -INFINITY)),
        4286578688u,
        "add(-0.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, INFINITY)),
        2139095040u,
        "add(-0.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, -INFINITY)),
        4286578688u,
        "add(0.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, INFINITY)),
        2139095040u,
        "add(0.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(-0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(-0.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(-0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(-0.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(0.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(0.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, -0.0)),
        2147483649u,
        "add(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, 0.0)),
        2147483649u,
        "add(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, -0.0)),
        1u,
        "add(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, 0.0)),
        1u,
        "add(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, -1.401298464324817e-45)),
        2147483650u,
        "add(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, 1.401298464324817e-45)),
        0u,
        "add(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, -1.401298464324817e-45)),
        0u,
        "add(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, 1.401298464324817e-45)),
        2u,
        "add(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, -1.1754943508222875e-38)),
        2155872257u,
        "add(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, 1.1754943508222875e-38)),
        8388607u,
        "add(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, -1.1754943508222875e-38)),
        2155872255u,
        "add(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, 1.1754943508222875e-38)),
        8388609u,
        "add(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, -0.5)),
        3204448256u,
        "add(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, 0.5)),
        1056964608u,
        "add(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, -0.5)),
        3204448256u,
        "add(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, 0.5)),
        1056964608u,
        "add(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, -1.0)),
        3212836864u,
        "add(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, 1.0)),
        1065353216u,
        "add(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, -1.0)),
        3212836864u,
        "add(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, 1.0)),
        1065353216u,
        "add(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, -6.2831854820251465)),
        3234402267u,
        "add(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, 6.2831854820251465)),
        1086918619u,
        "add(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, -6.2831854820251465)),
        3234402267u,
        "add(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, 6.2831854820251465)),
        1086918619u,
        "add(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, -3.4028234663852886e+38)),
        4286578687u,
        "add(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, 3.4028234663852886e+38)),
        2139095039u,
        "add(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, -3.4028234663852886e+38)),
        4286578687u,
        "add(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, 3.4028234663852886e+38)),
        2139095039u,
        "add(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, -INFINITY)),
        4286578688u,
        "add(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, INFINITY)),
        2139095040u,
        "add(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, -INFINITY)),
        4286578688u,
        "add(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, INFINITY)),
        2139095040u,
        "add(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(-1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(-1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(-1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(-1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, -0.0)),
        2155872256u,
        "add(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, 0.0)),
        2155872256u,
        "add(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, -0.0)),
        8388608u,
        "add(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, 0.0)),
        8388608u,
        "add(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, -1.401298464324817e-45)),
        2155872257u,
        "add(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, 1.401298464324817e-45)),
        2155872255u,
        "add(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, -1.401298464324817e-45)),
        8388607u,
        "add(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, 1.401298464324817e-45)),
        8388609u,
        "add(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38)),
        2164260864u,
        "add(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38)),
        0u,
        "add(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38)),
        0u,
        "add(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38)),
        16777216u,
        "add(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, -0.5)),
        3204448256u,
        "add(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, 0.5)),
        1056964608u,
        "add(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, -0.5)),
        3204448256u,
        "add(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, 0.5)),
        1056964608u,
        "add(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, -1.0)),
        3212836864u,
        "add(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, 1.0)),
        1065353216u,
        "add(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, -1.0)),
        3212836864u,
        "add(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, 1.0)),
        1065353216u,
        "add(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, -6.2831854820251465)),
        3234402267u,
        "add(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, 6.2831854820251465)),
        1086918619u,
        "add(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, -6.2831854820251465)),
        3234402267u,
        "add(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, 6.2831854820251465)),
        1086918619u,
        "add(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38)),
        4286578687u,
        "add(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38)),
        2139095039u,
        "add(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38)),
        4286578687u,
        "add(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38)),
        2139095039u,
        "add(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, -INFINITY)),
        4286578688u,
        "add(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, INFINITY)),
        2139095040u,
        "add(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, -INFINITY)),
        4286578688u,
        "add(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, INFINITY)),
        2139095040u,
        "add(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(-1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(-1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, -0.0)),
        3204448256u,
        "add(-0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, 0.0)),
        3204448256u,
        "add(-0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, -0.0)),
        1056964608u,
        "add(0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, 0.0)),
        1056964608u,
        "add(0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, -1.401298464324817e-45)),
        3204448256u,
        "add(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, 1.401298464324817e-45)),
        3204448256u,
        "add(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, -1.401298464324817e-45)),
        1056964608u,
        "add(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, 1.401298464324817e-45)),
        1056964608u,
        "add(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, -1.1754943508222875e-38)),
        3204448256u,
        "add(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, 1.1754943508222875e-38)),
        3204448256u,
        "add(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, -1.1754943508222875e-38)),
        1056964608u,
        "add(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, 1.1754943508222875e-38)),
        1056964608u,
        "add(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, -0.5)),
        3212836864u,
        "add(-0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, 0.5)),
        0u,
        "add(-0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, -0.5)),
        0u,
        "add(0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, 0.5)),
        1065353216u,
        "add(0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, -1.0)),
        3217031168u,
        "add(-0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, 1.0)),
        1056964608u,
        "add(-0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, -1.0)),
        3204448256u,
        "add(0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, 1.0)),
        1069547520u,
        "add(0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, -6.2831854820251465)),
        3235450843u,
        "add(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, 6.2831854820251465)),
        1085870043u,
        "add(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, -6.2831854820251465)),
        3233353691u,
        "add(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, 6.2831854820251465)),
        1087967195u,
        "add(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, -3.4028234663852886e+38)),
        4286578687u,
        "add(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, 3.4028234663852886e+38)),
        2139095039u,
        "add(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, -3.4028234663852886e+38)),
        4286578687u,
        "add(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, 3.4028234663852886e+38)),
        2139095039u,
        "add(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, -INFINITY)),
        4286578688u,
        "add(-0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, INFINITY)),
        2139095040u,
        "add(-0.5, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, -INFINITY)),
        4286578688u,
        "add(0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, INFINITY)),
        2139095040u,
        "add(0.5, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(-0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(-0.5, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(-0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -0.5, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(-0.5, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(0.5, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 0.5, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(0.5, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, -0.0)),
        3212836864u,
        "add(-1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, 0.0)),
        3212836864u,
        "add(-1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, -0.0)),
        1065353216u,
        "add(1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, 0.0)),
        1065353216u,
        "add(1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, -1.401298464324817e-45)),
        3212836864u,
        "add(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, 1.401298464324817e-45)),
        3212836864u,
        "add(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, -1.401298464324817e-45)),
        1065353216u,
        "add(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, 1.401298464324817e-45)),
        1065353216u,
        "add(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, -1.1754943508222875e-38)),
        3212836864u,
        "add(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, 1.1754943508222875e-38)),
        3212836864u,
        "add(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, -1.1754943508222875e-38)),
        1065353216u,
        "add(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, 1.1754943508222875e-38)),
        1065353216u,
        "add(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, -0.5)),
        3217031168u,
        "add(-1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, 0.5)),
        3204448256u,
        "add(-1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, -0.5)),
        1056964608u,
        "add(1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, 0.5)),
        1069547520u,
        "add(1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, -1.0)),
        3221225472u,
        "add(-1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, 1.0)),
        0u,
        "add(-1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, -1.0)),
        0u,
        "add(1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, 1.0)),
        1073741824u,
        "add(1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, -6.2831854820251465)),
        3236499419u,
        "add(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, 6.2831854820251465)),
        1084821467u,
        "add(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, -6.2831854820251465)),
        3232305115u,
        "add(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, 6.2831854820251465)),
        1089015771u,
        "add(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, -3.4028234663852886e+38)),
        4286578687u,
        "add(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, 3.4028234663852886e+38)),
        2139095039u,
        "add(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, -3.4028234663852886e+38)),
        4286578687u,
        "add(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, 3.4028234663852886e+38)),
        2139095039u,
        "add(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, -INFINITY)),
        4286578688u,
        "add(-1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, INFINITY)),
        2139095040u,
        "add(-1.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, -INFINITY)),
        4286578688u,
        "add(1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, INFINITY)),
        2139095040u,
        "add(1.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(-1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(-1.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(-1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -1.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(-1.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(1.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 1.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(1.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, -0.0)),
        3234402267u,
        "add(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, 0.0)),
        3234402267u,
        "add(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, -0.0)),
        1086918619u,
        "add(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, 0.0)),
        1086918619u,
        "add(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, -1.401298464324817e-45)),
        3234402267u,
        "add(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, 1.401298464324817e-45)),
        3234402267u,
        "add(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, -1.401298464324817e-45)),
        1086918619u,
        "add(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, 1.401298464324817e-45)),
        1086918619u,
        "add(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, -1.1754943508222875e-38)),
        3234402267u,
        "add(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, 1.1754943508222875e-38)),
        3234402267u,
        "add(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, -1.1754943508222875e-38)),
        1086918619u,
        "add(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, 1.1754943508222875e-38)),
        1086918619u,
        "add(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, -0.5)),
        3235450843u,
        "add(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, 0.5)),
        3233353691u,
        "add(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, -0.5)),
        1085870043u,
        "add(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, 0.5)),
        1087967195u,
        "add(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, -1.0)),
        3236499419u,
        "add(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, 1.0)),
        3232305115u,
        "add(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, -1.0)),
        1084821467u,
        "add(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, 1.0)),
        1089015771u,
        "add(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, -6.2831854820251465)),
        3242790875u,
        "add(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, 6.2831854820251465)),
        0u,
        "add(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, -6.2831854820251465)),
        0u,
        "add(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, 6.2831854820251465)),
        1095307227u,
        "add(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, -3.4028234663852886e+38)),
        4286578687u,
        "add(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, 3.4028234663852886e+38)),
        2139095039u,
        "add(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, -3.4028234663852886e+38)),
        4286578687u,
        "add(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, 3.4028234663852886e+38)),
        2139095039u,
        "add(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, -INFINITY)),
        4286578688u,
        "add(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, INFINITY)),
        2139095040u,
        "add(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, -INFINITY)),
        4286578688u,
        "add(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, INFINITY)),
        2139095040u,
        "add(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(-6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(-6.2831854820251465, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(-6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(-6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(6.2831854820251465, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, -0.0)),
        4286578687u,
        "add(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, 0.0)),
        4286578687u,
        "add(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, -0.0)),
        2139095039u,
        "add(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, 0.0)),
        2139095039u,
        "add(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, -1.401298464324817e-45)),
        4286578687u,
        "add(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, 1.401298464324817e-45)),
        4286578687u,
        "add(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, -1.401298464324817e-45)),
        2139095039u,
        "add(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, 1.401298464324817e-45)),
        2139095039u,
        "add(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38)),
        4286578687u,
        "add(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38)),
        4286578687u,
        "add(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38)),
        2139095039u,
        "add(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38)),
        2139095039u,
        "add(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, -0.5)),
        4286578687u,
        "add(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, 0.5)),
        4286578687u,
        "add(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, -0.5)),
        2139095039u,
        "add(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, 0.5)),
        2139095039u,
        "add(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, -1.0)),
        4286578687u,
        "add(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, 1.0)),
        4286578687u,
        "add(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, -1.0)),
        2139095039u,
        "add(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, 1.0)),
        2139095039u,
        "add(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, -6.2831854820251465)),
        4286578687u,
        "add(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, 6.2831854820251465)),
        4286578687u,
        "add(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, -6.2831854820251465)),
        2139095039u,
        "add(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, 6.2831854820251465)),
        2139095039u,
        "add(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38)),
        4286578688u,
        "add(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38)),
        0u,
        "add(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38)),
        0u,
        "add(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38)),
        2139095040u,
        "add(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, -INFINITY)),
        4286578688u,
        "add(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, INFINITY)),
        2139095040u,
        "add(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, -INFINITY)),
        4286578688u,
        "add(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, INFINITY)),
        2139095040u,
        "add(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(-3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(-3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, -0.0)),
        4286578688u,
        "add(-INFINITY, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, 0.0)),
        4286578688u,
        "add(-INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, -0.0)),
        2139095040u,
        "add(INFINITY, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, 0.0)),
        2139095040u,
        "add(INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, -1.401298464324817e-45)),
        4286578688u,
        "add(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, 1.401298464324817e-45)),
        4286578688u,
        "add(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, -1.401298464324817e-45)),
        2139095040u,
        "add(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, 1.401298464324817e-45)),
        2139095040u,
        "add(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, -1.1754943508222875e-38)),
        4286578688u,
        "add(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, 1.1754943508222875e-38)),
        4286578688u,
        "add(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, -1.1754943508222875e-38)),
        2139095040u,
        "add(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, 1.1754943508222875e-38)),
        2139095040u,
        "add(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, -0.5)),
        4286578688u,
        "add(-INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, 0.5)),
        4286578688u,
        "add(-INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, -0.5)),
        2139095040u,
        "add(INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, 0.5)),
        2139095040u,
        "add(INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, -1.0)),
        4286578688u,
        "add(-INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, 1.0)),
        4286578688u,
        "add(-INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, -1.0)),
        2139095040u,
        "add(INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, 1.0)),
        2139095040u,
        "add(INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, -6.2831854820251465)),
        4286578688u,
        "add(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, 6.2831854820251465)),
        4286578688u,
        "add(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, -6.2831854820251465)),
        2139095040u,
        "add(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, 6.2831854820251465)),
        2139095040u,
        "add(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, -3.4028234663852886e+38)),
        4286578688u,
        "add(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, 3.4028234663852886e+38)),
        4286578688u,
        "add(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, -3.4028234663852886e+38)),
        2139095040u,
        "add(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, 3.4028234663852886e+38)),
        2139095040u,
        "add(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, -INFINITY)),
        4286578688u,
        "add(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, INFINITY)) & 2147483647u),
        2143289344u,
        "add(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, -INFINITY)) & 2147483647u),
        2143289344u,
        "add(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, INFINITY)),
        2139095040u,
        "add(INFINITY, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(-INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(-INFINITY, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(-INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, -INFINITY, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(-INFINITY, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(INFINITY, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, INFINITY, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(INFINITY, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), -0.0)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), -0.0)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), 0.0)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), 0.0)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), -0.0)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), -0.0)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), 0.0)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), -1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), 1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), -1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), 1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), -1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), 1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), -1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), 1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), -0.5)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), -0.5)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), 0.5)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), 0.5)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), -0.5)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), -0.5)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), 0.5)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), 0.5)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), -1.0)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), -1.0)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), 1.0)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), 1.0)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), -1.0)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), -1.0)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), 1.0)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), 1.0)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), -6.2831854820251465)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), 6.2831854820251465)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), -6.2831854820251465)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), 6.2831854820251465)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), -3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), 3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), -3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), 3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), -INFINITY)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), -INFINITY)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), INFINITY)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), INFINITY)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), -INFINITY)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), -INFINITY)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), INFINITY)) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), INFINITY)) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffc00000u))) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fc00000u))) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffc00000u))) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fc00000u))) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_add(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "add(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, -0.0)),
        0u,
        "sub(-0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, 0.0)),
        2147483648u,
        "sub(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, -0.0)),
        0u,
        "sub(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, 0.0)),
        0u,
        "sub(0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, -1.401298464324817e-45)),
        1u,
        "sub(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, 1.401298464324817e-45)),
        2147483649u,
        "sub(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, -1.401298464324817e-45)),
        1u,
        "sub(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, 1.401298464324817e-45)),
        2147483649u,
        "sub(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, -1.1754943508222875e-38)),
        8388608u,
        "sub(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, 1.1754943508222875e-38)),
        2155872256u,
        "sub(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, -1.1754943508222875e-38)),
        8388608u,
        "sub(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, 1.1754943508222875e-38)),
        2155872256u,
        "sub(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, -0.5)),
        1056964608u,
        "sub(-0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, 0.5)),
        3204448256u,
        "sub(-0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, -0.5)),
        1056964608u,
        "sub(0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, 0.5)),
        3204448256u,
        "sub(0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, -1.0)),
        1065353216u,
        "sub(-0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, 1.0)),
        3212836864u,
        "sub(-0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, -1.0)),
        1065353216u,
        "sub(0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, 1.0)),
        3212836864u,
        "sub(0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, -6.2831854820251465)),
        1086918619u,
        "sub(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, 6.2831854820251465)),
        3234402267u,
        "sub(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, -6.2831854820251465)),
        1086918619u,
        "sub(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, 6.2831854820251465)),
        3234402267u,
        "sub(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, -3.4028234663852886e+38)),
        2139095039u,
        "sub(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, 3.4028234663852886e+38)),
        4286578687u,
        "sub(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, -3.4028234663852886e+38)),
        2139095039u,
        "sub(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, 3.4028234663852886e+38)),
        4286578687u,
        "sub(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, -INFINITY)),
        2139095040u,
        "sub(-0.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, INFINITY)),
        4286578688u,
        "sub(-0.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, -INFINITY)),
        2139095040u,
        "sub(0.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, INFINITY)),
        4286578688u,
        "sub(0.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(-0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(-0.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(-0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(-0.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(0.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(0.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, -0.0)),
        2147483649u,
        "sub(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, 0.0)),
        2147483649u,
        "sub(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, -0.0)),
        1u,
        "sub(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, 0.0)),
        1u,
        "sub(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, -1.401298464324817e-45)),
        0u,
        "sub(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, 1.401298464324817e-45)),
        2147483650u,
        "sub(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, -1.401298464324817e-45)),
        2u,
        "sub(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, 1.401298464324817e-45)),
        0u,
        "sub(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, -1.1754943508222875e-38)),
        8388607u,
        "sub(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, 1.1754943508222875e-38)),
        2155872257u,
        "sub(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, -1.1754943508222875e-38)),
        8388609u,
        "sub(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, 1.1754943508222875e-38)),
        2155872255u,
        "sub(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, -0.5)),
        1056964608u,
        "sub(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, 0.5)),
        3204448256u,
        "sub(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, -0.5)),
        1056964608u,
        "sub(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, 0.5)),
        3204448256u,
        "sub(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, -1.0)),
        1065353216u,
        "sub(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, 1.0)),
        3212836864u,
        "sub(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, -1.0)),
        1065353216u,
        "sub(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, 1.0)),
        3212836864u,
        "sub(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, -6.2831854820251465)),
        1086918619u,
        "sub(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, 6.2831854820251465)),
        3234402267u,
        "sub(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, -6.2831854820251465)),
        1086918619u,
        "sub(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, 6.2831854820251465)),
        3234402267u,
        "sub(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, -3.4028234663852886e+38)),
        2139095039u,
        "sub(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, 3.4028234663852886e+38)),
        4286578687u,
        "sub(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, -3.4028234663852886e+38)),
        2139095039u,
        "sub(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, 3.4028234663852886e+38)),
        4286578687u,
        "sub(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, -INFINITY)),
        2139095040u,
        "sub(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, INFINITY)),
        4286578688u,
        "sub(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, -INFINITY)),
        2139095040u,
        "sub(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, INFINITY)),
        4286578688u,
        "sub(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(-1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(-1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(-1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(-1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, -0.0)),
        2155872256u,
        "sub(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, 0.0)),
        2155872256u,
        "sub(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, -0.0)),
        8388608u,
        "sub(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, 0.0)),
        8388608u,
        "sub(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, -1.401298464324817e-45)),
        2155872255u,
        "sub(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, 1.401298464324817e-45)),
        2155872257u,
        "sub(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, -1.401298464324817e-45)),
        8388609u,
        "sub(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, 1.401298464324817e-45)),
        8388607u,
        "sub(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38)),
        0u,
        "sub(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38)),
        2164260864u,
        "sub(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38)),
        16777216u,
        "sub(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38)),
        0u,
        "sub(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, -0.5)),
        1056964608u,
        "sub(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, 0.5)),
        3204448256u,
        "sub(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, -0.5)),
        1056964608u,
        "sub(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, 0.5)),
        3204448256u,
        "sub(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, -1.0)),
        1065353216u,
        "sub(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, 1.0)),
        3212836864u,
        "sub(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, -1.0)),
        1065353216u,
        "sub(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, 1.0)),
        3212836864u,
        "sub(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, -6.2831854820251465)),
        1086918619u,
        "sub(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, 6.2831854820251465)),
        3234402267u,
        "sub(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, -6.2831854820251465)),
        1086918619u,
        "sub(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, 6.2831854820251465)),
        3234402267u,
        "sub(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38)),
        2139095039u,
        "sub(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38)),
        4286578687u,
        "sub(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38)),
        2139095039u,
        "sub(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38)),
        4286578687u,
        "sub(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, -INFINITY)),
        2139095040u,
        "sub(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, INFINITY)),
        4286578688u,
        "sub(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, -INFINITY)),
        2139095040u,
        "sub(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, INFINITY)),
        4286578688u,
        "sub(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(-1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(-1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, -0.0)),
        3204448256u,
        "sub(-0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, 0.0)),
        3204448256u,
        "sub(-0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, -0.0)),
        1056964608u,
        "sub(0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, 0.0)),
        1056964608u,
        "sub(0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, -1.401298464324817e-45)),
        3204448256u,
        "sub(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, 1.401298464324817e-45)),
        3204448256u,
        "sub(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, -1.401298464324817e-45)),
        1056964608u,
        "sub(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, 1.401298464324817e-45)),
        1056964608u,
        "sub(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, -1.1754943508222875e-38)),
        3204448256u,
        "sub(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, 1.1754943508222875e-38)),
        3204448256u,
        "sub(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, -1.1754943508222875e-38)),
        1056964608u,
        "sub(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, 1.1754943508222875e-38)),
        1056964608u,
        "sub(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, -0.5)),
        0u,
        "sub(-0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, 0.5)),
        3212836864u,
        "sub(-0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, -0.5)),
        1065353216u,
        "sub(0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, 0.5)),
        0u,
        "sub(0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, -1.0)),
        1056964608u,
        "sub(-0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, 1.0)),
        3217031168u,
        "sub(-0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, -1.0)),
        1069547520u,
        "sub(0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, 1.0)),
        3204448256u,
        "sub(0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, -6.2831854820251465)),
        1085870043u,
        "sub(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, 6.2831854820251465)),
        3235450843u,
        "sub(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, -6.2831854820251465)),
        1087967195u,
        "sub(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, 6.2831854820251465)),
        3233353691u,
        "sub(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, -3.4028234663852886e+38)),
        2139095039u,
        "sub(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, 3.4028234663852886e+38)),
        4286578687u,
        "sub(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, -3.4028234663852886e+38)),
        2139095039u,
        "sub(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, 3.4028234663852886e+38)),
        4286578687u,
        "sub(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, -INFINITY)),
        2139095040u,
        "sub(-0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, INFINITY)),
        4286578688u,
        "sub(-0.5, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, -INFINITY)),
        2139095040u,
        "sub(0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, INFINITY)),
        4286578688u,
        "sub(0.5, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(-0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(-0.5, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(-0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -0.5, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(-0.5, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(0.5, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 0.5, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(0.5, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, -0.0)),
        3212836864u,
        "sub(-1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, 0.0)),
        3212836864u,
        "sub(-1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, -0.0)),
        1065353216u,
        "sub(1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, 0.0)),
        1065353216u,
        "sub(1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, -1.401298464324817e-45)),
        3212836864u,
        "sub(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, 1.401298464324817e-45)),
        3212836864u,
        "sub(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, -1.401298464324817e-45)),
        1065353216u,
        "sub(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, 1.401298464324817e-45)),
        1065353216u,
        "sub(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, -1.1754943508222875e-38)),
        3212836864u,
        "sub(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, 1.1754943508222875e-38)),
        3212836864u,
        "sub(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, -1.1754943508222875e-38)),
        1065353216u,
        "sub(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, 1.1754943508222875e-38)),
        1065353216u,
        "sub(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, -0.5)),
        3204448256u,
        "sub(-1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, 0.5)),
        3217031168u,
        "sub(-1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, -0.5)),
        1069547520u,
        "sub(1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, 0.5)),
        1056964608u,
        "sub(1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, -1.0)),
        0u,
        "sub(-1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, 1.0)),
        3221225472u,
        "sub(-1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, -1.0)),
        1073741824u,
        "sub(1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, 1.0)),
        0u,
        "sub(1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, -6.2831854820251465)),
        1084821467u,
        "sub(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, 6.2831854820251465)),
        3236499419u,
        "sub(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, -6.2831854820251465)),
        1089015771u,
        "sub(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, 6.2831854820251465)),
        3232305115u,
        "sub(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, -3.4028234663852886e+38)),
        2139095039u,
        "sub(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, 3.4028234663852886e+38)),
        4286578687u,
        "sub(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, -3.4028234663852886e+38)),
        2139095039u,
        "sub(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, 3.4028234663852886e+38)),
        4286578687u,
        "sub(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, -INFINITY)),
        2139095040u,
        "sub(-1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, INFINITY)),
        4286578688u,
        "sub(-1.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, -INFINITY)),
        2139095040u,
        "sub(1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, INFINITY)),
        4286578688u,
        "sub(1.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(-1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(-1.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(-1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -1.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(-1.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(1.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 1.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(1.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, -0.0)),
        3234402267u,
        "sub(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, 0.0)),
        3234402267u,
        "sub(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, -0.0)),
        1086918619u,
        "sub(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, 0.0)),
        1086918619u,
        "sub(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, -1.401298464324817e-45)),
        3234402267u,
        "sub(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, 1.401298464324817e-45)),
        3234402267u,
        "sub(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, -1.401298464324817e-45)),
        1086918619u,
        "sub(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, 1.401298464324817e-45)),
        1086918619u,
        "sub(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, -1.1754943508222875e-38)),
        3234402267u,
        "sub(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, 1.1754943508222875e-38)),
        3234402267u,
        "sub(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, -1.1754943508222875e-38)),
        1086918619u,
        "sub(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, 1.1754943508222875e-38)),
        1086918619u,
        "sub(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, -0.5)),
        3233353691u,
        "sub(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, 0.5)),
        3235450843u,
        "sub(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, -0.5)),
        1087967195u,
        "sub(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, 0.5)),
        1085870043u,
        "sub(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, -1.0)),
        3232305115u,
        "sub(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, 1.0)),
        3236499419u,
        "sub(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, -1.0)),
        1089015771u,
        "sub(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, 1.0)),
        1084821467u,
        "sub(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, -6.2831854820251465)),
        0u,
        "sub(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, 6.2831854820251465)),
        3242790875u,
        "sub(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, -6.2831854820251465)),
        1095307227u,
        "sub(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, 6.2831854820251465)),
        0u,
        "sub(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, -3.4028234663852886e+38)),
        2139095039u,
        "sub(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, 3.4028234663852886e+38)),
        4286578687u,
        "sub(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, -3.4028234663852886e+38)),
        2139095039u,
        "sub(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, 3.4028234663852886e+38)),
        4286578687u,
        "sub(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, -INFINITY)),
        2139095040u,
        "sub(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, INFINITY)),
        4286578688u,
        "sub(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, -INFINITY)),
        2139095040u,
        "sub(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, INFINITY)),
        4286578688u,
        "sub(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(-6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(-6.2831854820251465, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(-6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(-6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(6.2831854820251465, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, -0.0)),
        4286578687u,
        "sub(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, 0.0)),
        4286578687u,
        "sub(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, -0.0)),
        2139095039u,
        "sub(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, 0.0)),
        2139095039u,
        "sub(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, -1.401298464324817e-45)),
        4286578687u,
        "sub(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, 1.401298464324817e-45)),
        4286578687u,
        "sub(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, -1.401298464324817e-45)),
        2139095039u,
        "sub(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, 1.401298464324817e-45)),
        2139095039u,
        "sub(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38)),
        4286578687u,
        "sub(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38)),
        4286578687u,
        "sub(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38)),
        2139095039u,
        "sub(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38)),
        2139095039u,
        "sub(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, -0.5)),
        4286578687u,
        "sub(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, 0.5)),
        4286578687u,
        "sub(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, -0.5)),
        2139095039u,
        "sub(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, 0.5)),
        2139095039u,
        "sub(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, -1.0)),
        4286578687u,
        "sub(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, 1.0)),
        4286578687u,
        "sub(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, -1.0)),
        2139095039u,
        "sub(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, 1.0)),
        2139095039u,
        "sub(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, -6.2831854820251465)),
        4286578687u,
        "sub(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, 6.2831854820251465)),
        4286578687u,
        "sub(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, -6.2831854820251465)),
        2139095039u,
        "sub(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, 6.2831854820251465)),
        2139095039u,
        "sub(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38)),
        0u,
        "sub(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38)),
        4286578688u,
        "sub(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38)),
        2139095040u,
        "sub(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38)),
        0u,
        "sub(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, -INFINITY)),
        2139095040u,
        "sub(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, INFINITY)),
        4286578688u,
        "sub(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, -INFINITY)),
        2139095040u,
        "sub(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, INFINITY)),
        4286578688u,
        "sub(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(-3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(-3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, -0.0)),
        4286578688u,
        "sub(-INFINITY, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, 0.0)),
        4286578688u,
        "sub(-INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, -0.0)),
        2139095040u,
        "sub(INFINITY, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, 0.0)),
        2139095040u,
        "sub(INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, -1.401298464324817e-45)),
        4286578688u,
        "sub(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, 1.401298464324817e-45)),
        4286578688u,
        "sub(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, -1.401298464324817e-45)),
        2139095040u,
        "sub(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, 1.401298464324817e-45)),
        2139095040u,
        "sub(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, -1.1754943508222875e-38)),
        4286578688u,
        "sub(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, 1.1754943508222875e-38)),
        4286578688u,
        "sub(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, -1.1754943508222875e-38)),
        2139095040u,
        "sub(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, 1.1754943508222875e-38)),
        2139095040u,
        "sub(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, -0.5)),
        4286578688u,
        "sub(-INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, 0.5)),
        4286578688u,
        "sub(-INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, -0.5)),
        2139095040u,
        "sub(INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, 0.5)),
        2139095040u,
        "sub(INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, -1.0)),
        4286578688u,
        "sub(-INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, 1.0)),
        4286578688u,
        "sub(-INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, -1.0)),
        2139095040u,
        "sub(INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, 1.0)),
        2139095040u,
        "sub(INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, -6.2831854820251465)),
        4286578688u,
        "sub(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, 6.2831854820251465)),
        4286578688u,
        "sub(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, -6.2831854820251465)),
        2139095040u,
        "sub(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, 6.2831854820251465)),
        2139095040u,
        "sub(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, -3.4028234663852886e+38)),
        4286578688u,
        "sub(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, 3.4028234663852886e+38)),
        4286578688u,
        "sub(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, -3.4028234663852886e+38)),
        2139095040u,
        "sub(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, 3.4028234663852886e+38)),
        2139095040u,
        "sub(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, -INFINITY)) & 2147483647u),
        2143289344u,
        "sub(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, INFINITY)),
        4286578688u,
        "sub(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, -INFINITY)),
        2139095040u,
        "sub(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, INFINITY)) & 2147483647u),
        2143289344u,
        "sub(INFINITY, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(-INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(-INFINITY, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(-INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, -INFINITY, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(-INFINITY, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(INFINITY, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, INFINITY, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(INFINITY, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), -0.0)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), -0.0)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), 0.0)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), 0.0)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), -0.0)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), -0.0)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), 0.0)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), -1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), 1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), -1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), 1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), -1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), 1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), -1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), 1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), -0.5)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), -0.5)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), 0.5)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), 0.5)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), -0.5)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), -0.5)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), 0.5)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), 0.5)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), -1.0)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), -1.0)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), 1.0)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), 1.0)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), -1.0)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), -1.0)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), 1.0)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), 1.0)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), -6.2831854820251465)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), 6.2831854820251465)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), -6.2831854820251465)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), 6.2831854820251465)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), -3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), 3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), -3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), 3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), -INFINITY)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), -INFINITY)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), INFINITY)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), INFINITY)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), -INFINITY)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), -INFINITY)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), INFINITY)) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), INFINITY)) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffc00000u))) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fc00000u))) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffc00000u))) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fc00000u))) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_sub(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sub(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, -0.0)),
        0u,
        "mul(-0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, 0.0)),
        2147483648u,
        "mul(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, -0.0)),
        2147483648u,
        "mul(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, 0.0)),
        0u,
        "mul(0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, -1.401298464324817e-45)),
        0u,
        "mul(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, 1.401298464324817e-45)),
        2147483648u,
        "mul(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, -1.401298464324817e-45)),
        2147483648u,
        "mul(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, 1.401298464324817e-45)),
        0u,
        "mul(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, -1.1754943508222875e-38)),
        0u,
        "mul(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, 1.1754943508222875e-38)),
        2147483648u,
        "mul(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, -1.1754943508222875e-38)),
        2147483648u,
        "mul(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, 1.1754943508222875e-38)),
        0u,
        "mul(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, -0.5)),
        0u,
        "mul(-0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, 0.5)),
        2147483648u,
        "mul(-0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, -0.5)),
        2147483648u,
        "mul(0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, 0.5)),
        0u,
        "mul(0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, -1.0)),
        0u,
        "mul(-0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, 1.0)),
        2147483648u,
        "mul(-0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, -1.0)),
        2147483648u,
        "mul(0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, 1.0)),
        0u,
        "mul(0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, -6.2831854820251465)),
        0u,
        "mul(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, 6.2831854820251465)),
        2147483648u,
        "mul(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, -6.2831854820251465)),
        2147483648u,
        "mul(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, 6.2831854820251465)),
        0u,
        "mul(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, -3.4028234663852886e+38)),
        0u,
        "mul(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, 3.4028234663852886e+38)),
        2147483648u,
        "mul(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, -3.4028234663852886e+38)),
        2147483648u,
        "mul(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, 3.4028234663852886e+38)),
        0u,
        "mul(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, -INFINITY)) & 2147483647u),
        2143289344u,
        "mul(-0.0, -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, INFINITY)) & 2147483647u),
        2143289344u,
        "mul(-0.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, -INFINITY)) & 2147483647u),
        2143289344u,
        "mul(0.0, -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, INFINITY)) & 2147483647u),
        2143289344u,
        "mul(0.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(-0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(-0.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(-0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(-0.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(0.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(0.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, -0.0)),
        0u,
        "mul(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, 0.0)),
        2147483648u,
        "mul(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, -0.0)),
        2147483648u,
        "mul(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, 0.0)),
        0u,
        "mul(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, -1.401298464324817e-45)),
        0u,
        "mul(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, 1.401298464324817e-45)),
        2147483648u,
        "mul(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, -1.401298464324817e-45)),
        2147483648u,
        "mul(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, 1.401298464324817e-45)),
        0u,
        "mul(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, -1.1754943508222875e-38)),
        0u,
        "mul(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, 1.1754943508222875e-38)),
        2147483648u,
        "mul(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, -1.1754943508222875e-38)),
        2147483648u,
        "mul(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, 1.1754943508222875e-38)),
        0u,
        "mul(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, -0.5)),
        0u,
        "mul(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, 0.5)),
        2147483648u,
        "mul(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, -0.5)),
        2147483648u,
        "mul(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, 0.5)),
        0u,
        "mul(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, -1.0)),
        1u,
        "mul(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, 1.0)),
        2147483649u,
        "mul(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, -1.0)),
        2147483649u,
        "mul(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, 1.0)),
        1u,
        "mul(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, -6.2831854820251465)),
        6u,
        "mul(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, 6.2831854820251465)),
        2147483654u,
        "mul(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, -6.2831854820251465)),
        2147483654u,
        "mul(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, 6.2831854820251465)),
        6u,
        "mul(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, -3.4028234663852886e+38)),
        889192447u,
        "mul(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, 3.4028234663852886e+38)),
        3036676095u,
        "mul(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, -3.4028234663852886e+38)),
        3036676095u,
        "mul(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, 3.4028234663852886e+38)),
        889192447u,
        "mul(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, -INFINITY)),
        2139095040u,
        "mul(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, INFINITY)),
        4286578688u,
        "mul(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, -INFINITY)),
        4286578688u,
        "mul(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, INFINITY)),
        2139095040u,
        "mul(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(-1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(-1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(-1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(-1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, -0.0)),
        0u,
        "mul(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, 0.0)),
        2147483648u,
        "mul(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, -0.0)),
        2147483648u,
        "mul(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, 0.0)),
        0u,
        "mul(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, -1.401298464324817e-45)),
        0u,
        "mul(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, 1.401298464324817e-45)),
        2147483648u,
        "mul(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, -1.401298464324817e-45)),
        2147483648u,
        "mul(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, 1.401298464324817e-45)),
        0u,
        "mul(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38)),
        0u,
        "mul(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38)),
        2147483648u,
        "mul(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38)),
        2147483648u,
        "mul(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38)),
        0u,
        "mul(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, -0.5)),
        4194304u,
        "mul(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, 0.5)),
        2151677952u,
        "mul(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, -0.5)),
        2151677952u,
        "mul(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, 0.5)),
        4194304u,
        "mul(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, -1.0)),
        8388608u,
        "mul(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, 1.0)),
        2155872256u,
        "mul(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, -1.0)),
        2155872256u,
        "mul(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, 1.0)),
        8388608u,
        "mul(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, -6.2831854820251465)),
        29954011u,
        "mul(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, 6.2831854820251465)),
        2177437659u,
        "mul(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, -6.2831854820251465)),
        2177437659u,
        "mul(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, 6.2831854820251465)),
        29954011u,
        "mul(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38)),
        1082130431u,
        "mul(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38)),
        3229614079u,
        "mul(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38)),
        3229614079u,
        "mul(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38)),
        1082130431u,
        "mul(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, -INFINITY)),
        2139095040u,
        "mul(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, INFINITY)),
        4286578688u,
        "mul(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, -INFINITY)),
        4286578688u,
        "mul(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, INFINITY)),
        2139095040u,
        "mul(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(-1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(-1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, -0.0)),
        0u,
        "mul(-0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, 0.0)),
        2147483648u,
        "mul(-0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, -0.0)),
        2147483648u,
        "mul(0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, 0.0)),
        0u,
        "mul(0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, -1.401298464324817e-45)),
        0u,
        "mul(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, 1.401298464324817e-45)),
        2147483648u,
        "mul(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, -1.401298464324817e-45)),
        2147483648u,
        "mul(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, 1.401298464324817e-45)),
        0u,
        "mul(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, -1.1754943508222875e-38)),
        4194304u,
        "mul(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, 1.1754943508222875e-38)),
        2151677952u,
        "mul(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, -1.1754943508222875e-38)),
        2151677952u,
        "mul(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, 1.1754943508222875e-38)),
        4194304u,
        "mul(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, -0.5)),
        1048576000u,
        "mul(-0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, 0.5)),
        3196059648u,
        "mul(-0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, -0.5)),
        3196059648u,
        "mul(0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, 0.5)),
        1048576000u,
        "mul(0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, -1.0)),
        1056964608u,
        "mul(-0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, 1.0)),
        3204448256u,
        "mul(-0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, -1.0)),
        3204448256u,
        "mul(0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, 1.0)),
        1056964608u,
        "mul(0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, -6.2831854820251465)),
        1078530011u,
        "mul(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, 6.2831854820251465)),
        3226013659u,
        "mul(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, -6.2831854820251465)),
        3226013659u,
        "mul(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, 6.2831854820251465)),
        1078530011u,
        "mul(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, -3.4028234663852886e+38)),
        2130706431u,
        "mul(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, 3.4028234663852886e+38)),
        4278190079u,
        "mul(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, -3.4028234663852886e+38)),
        4278190079u,
        "mul(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, 3.4028234663852886e+38)),
        2130706431u,
        "mul(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, -INFINITY)),
        2139095040u,
        "mul(-0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, INFINITY)),
        4286578688u,
        "mul(-0.5, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, -INFINITY)),
        4286578688u,
        "mul(0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, INFINITY)),
        2139095040u,
        "mul(0.5, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(-0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(-0.5, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(-0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -0.5, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(-0.5, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(0.5, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 0.5, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(0.5, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, -0.0)),
        0u,
        "mul(-1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, 0.0)),
        2147483648u,
        "mul(-1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, -0.0)),
        2147483648u,
        "mul(1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, 0.0)),
        0u,
        "mul(1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, -1.401298464324817e-45)),
        1u,
        "mul(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, 1.401298464324817e-45)),
        2147483649u,
        "mul(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, -1.401298464324817e-45)),
        2147483649u,
        "mul(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, 1.401298464324817e-45)),
        1u,
        "mul(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, -1.1754943508222875e-38)),
        8388608u,
        "mul(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, 1.1754943508222875e-38)),
        2155872256u,
        "mul(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, -1.1754943508222875e-38)),
        2155872256u,
        "mul(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, 1.1754943508222875e-38)),
        8388608u,
        "mul(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, -0.5)),
        1056964608u,
        "mul(-1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, 0.5)),
        3204448256u,
        "mul(-1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, -0.5)),
        3204448256u,
        "mul(1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, 0.5)),
        1056964608u,
        "mul(1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, -1.0)),
        1065353216u,
        "mul(-1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, 1.0)),
        3212836864u,
        "mul(-1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, -1.0)),
        3212836864u,
        "mul(1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, 1.0)),
        1065353216u,
        "mul(1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, -6.2831854820251465)),
        1086918619u,
        "mul(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, 6.2831854820251465)),
        3234402267u,
        "mul(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, -6.2831854820251465)),
        3234402267u,
        "mul(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, 6.2831854820251465)),
        1086918619u,
        "mul(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, -3.4028234663852886e+38)),
        2139095039u,
        "mul(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, 3.4028234663852886e+38)),
        4286578687u,
        "mul(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, -3.4028234663852886e+38)),
        4286578687u,
        "mul(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, 3.4028234663852886e+38)),
        2139095039u,
        "mul(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, -INFINITY)),
        2139095040u,
        "mul(-1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, INFINITY)),
        4286578688u,
        "mul(-1.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, -INFINITY)),
        4286578688u,
        "mul(1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, INFINITY)),
        2139095040u,
        "mul(1.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(-1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(-1.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(-1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -1.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(-1.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(1.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 1.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(1.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, -0.0)),
        0u,
        "mul(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, 0.0)),
        2147483648u,
        "mul(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, -0.0)),
        2147483648u,
        "mul(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, 0.0)),
        0u,
        "mul(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, -1.401298464324817e-45)),
        6u,
        "mul(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, 1.401298464324817e-45)),
        2147483654u,
        "mul(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, -1.401298464324817e-45)),
        2147483654u,
        "mul(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, 1.401298464324817e-45)),
        6u,
        "mul(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, -1.1754943508222875e-38)),
        29954011u,
        "mul(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, 1.1754943508222875e-38)),
        2177437659u,
        "mul(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, -1.1754943508222875e-38)),
        2177437659u,
        "mul(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, 1.1754943508222875e-38)),
        29954011u,
        "mul(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, -0.5)),
        1078530011u,
        "mul(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, 0.5)),
        3226013659u,
        "mul(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, -0.5)),
        3226013659u,
        "mul(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, 0.5)),
        1078530011u,
        "mul(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, -1.0)),
        1086918619u,
        "mul(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, 1.0)),
        3234402267u,
        "mul(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, -1.0)),
        3234402267u,
        "mul(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, 1.0)),
        1086918619u,
        "mul(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, -6.2831854820251465)),
        1109256679u,
        "mul(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, 6.2831854820251465)),
        3256740327u,
        "mul(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, -6.2831854820251465)),
        3256740327u,
        "mul(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, 6.2831854820251465)),
        1109256679u,
        "mul(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, -3.4028234663852886e+38)),
        2139095040u,
        "mul(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, 3.4028234663852886e+38)),
        4286578688u,
        "mul(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, -3.4028234663852886e+38)),
        4286578688u,
        "mul(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, 3.4028234663852886e+38)),
        2139095040u,
        "mul(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, -INFINITY)),
        2139095040u,
        "mul(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, INFINITY)),
        4286578688u,
        "mul(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, -INFINITY)),
        4286578688u,
        "mul(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, INFINITY)),
        2139095040u,
        "mul(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(-6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(-6.2831854820251465, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(-6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(-6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(6.2831854820251465, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, -0.0)),
        0u,
        "mul(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, 0.0)),
        2147483648u,
        "mul(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, -0.0)),
        2147483648u,
        "mul(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, 0.0)),
        0u,
        "mul(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, -1.401298464324817e-45)),
        889192447u,
        "mul(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, 1.401298464324817e-45)),
        3036676095u,
        "mul(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, -1.401298464324817e-45)),
        3036676095u,
        "mul(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, 1.401298464324817e-45)),
        889192447u,
        "mul(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38)),
        1082130431u,
        "mul(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38)),
        3229614079u,
        "mul(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38)),
        3229614079u,
        "mul(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38)),
        1082130431u,
        "mul(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, -0.5)),
        2130706431u,
        "mul(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, 0.5)),
        4278190079u,
        "mul(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, -0.5)),
        4278190079u,
        "mul(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, 0.5)),
        2130706431u,
        "mul(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, -1.0)),
        2139095039u,
        "mul(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, 1.0)),
        4286578687u,
        "mul(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, -1.0)),
        4286578687u,
        "mul(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, 1.0)),
        2139095039u,
        "mul(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, -6.2831854820251465)),
        2139095040u,
        "mul(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, 6.2831854820251465)),
        4286578688u,
        "mul(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, -6.2831854820251465)),
        4286578688u,
        "mul(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, 6.2831854820251465)),
        2139095040u,
        "mul(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38)),
        2139095040u,
        "mul(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38)),
        4286578688u,
        "mul(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38)),
        4286578688u,
        "mul(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38)),
        2139095040u,
        "mul(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, -INFINITY)),
        2139095040u,
        "mul(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, INFINITY)),
        4286578688u,
        "mul(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, -INFINITY)),
        4286578688u,
        "mul(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, INFINITY)),
        2139095040u,
        "mul(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(-3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(-3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, -0.0)) & 2147483647u),
        2143289344u,
        "mul(-INFINITY, -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, 0.0)) & 2147483647u),
        2143289344u,
        "mul(-INFINITY, 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, -0.0)) & 2147483647u),
        2143289344u,
        "mul(INFINITY, -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, 0.0)) & 2147483647u),
        2143289344u,
        "mul(INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, -1.401298464324817e-45)),
        2139095040u,
        "mul(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, 1.401298464324817e-45)),
        4286578688u,
        "mul(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, -1.401298464324817e-45)),
        4286578688u,
        "mul(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, 1.401298464324817e-45)),
        2139095040u,
        "mul(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, -1.1754943508222875e-38)),
        2139095040u,
        "mul(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, 1.1754943508222875e-38)),
        4286578688u,
        "mul(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, -1.1754943508222875e-38)),
        4286578688u,
        "mul(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, 1.1754943508222875e-38)),
        2139095040u,
        "mul(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, -0.5)),
        2139095040u,
        "mul(-INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, 0.5)),
        4286578688u,
        "mul(-INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, -0.5)),
        4286578688u,
        "mul(INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, 0.5)),
        2139095040u,
        "mul(INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, -1.0)),
        2139095040u,
        "mul(-INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, 1.0)),
        4286578688u,
        "mul(-INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, -1.0)),
        4286578688u,
        "mul(INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, 1.0)),
        2139095040u,
        "mul(INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, -6.2831854820251465)),
        2139095040u,
        "mul(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, 6.2831854820251465)),
        4286578688u,
        "mul(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, -6.2831854820251465)),
        4286578688u,
        "mul(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, 6.2831854820251465)),
        2139095040u,
        "mul(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, -3.4028234663852886e+38)),
        2139095040u,
        "mul(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, 3.4028234663852886e+38)),
        4286578688u,
        "mul(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, -3.4028234663852886e+38)),
        4286578688u,
        "mul(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, 3.4028234663852886e+38)),
        2139095040u,
        "mul(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, -INFINITY)),
        2139095040u,
        "mul(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, INFINITY)),
        4286578688u,
        "mul(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, -INFINITY)),
        4286578688u,
        "mul(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, INFINITY)),
        2139095040u,
        "mul(INFINITY, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(-INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(-INFINITY, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(-INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, -INFINITY, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(-INFINITY, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(INFINITY, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, INFINITY, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(INFINITY, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), -0.0)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), -0.0)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), 0.0)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), 0.0)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), -0.0)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), -0.0)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), 0.0)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), -1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), 1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), -1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), 1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), -1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), 1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), -1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), 1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), -0.5)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), -0.5)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), 0.5)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), 0.5)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), -0.5)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), -0.5)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), 0.5)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), 0.5)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), -1.0)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), -1.0)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), 1.0)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), 1.0)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), -1.0)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), -1.0)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), 1.0)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), 1.0)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), -6.2831854820251465)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), 6.2831854820251465)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), -6.2831854820251465)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), 6.2831854820251465)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), -3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), 3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), -3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), 3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), -INFINITY)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), -INFINITY)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), INFINITY)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), INFINITY)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), -INFINITY)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), -INFINITY)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), INFINITY)) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), INFINITY)) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffc00000u))) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fc00000u))) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffc00000u))) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fc00000u))) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_mul(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "mul(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, -0.0)) & 2147483647u),
        2143289344u,
        "div(-0.0, -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, 0.0)) & 2147483647u),
        2143289344u,
        "div(-0.0, 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, -0.0)) & 2147483647u),
        2143289344u,
        "div(0.0, -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, 0.0)) & 2147483647u),
        2143289344u,
        "div(0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, -1.401298464324817e-45)),
        0u,
        "div(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, 1.401298464324817e-45)),
        2147483648u,
        "div(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, -1.401298464324817e-45)),
        2147483648u,
        "div(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, 1.401298464324817e-45)),
        0u,
        "div(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, -1.1754943508222875e-38)),
        0u,
        "div(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, 1.1754943508222875e-38)),
        2147483648u,
        "div(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, -1.1754943508222875e-38)),
        2147483648u,
        "div(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, 1.1754943508222875e-38)),
        0u,
        "div(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, -0.5)),
        0u,
        "div(-0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, 0.5)),
        2147483648u,
        "div(-0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, -0.5)),
        2147483648u,
        "div(0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, 0.5)),
        0u,
        "div(0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, -1.0)),
        0u,
        "div(-0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, 1.0)),
        2147483648u,
        "div(-0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, -1.0)),
        2147483648u,
        "div(0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, 1.0)),
        0u,
        "div(0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, -6.2831854820251465)),
        0u,
        "div(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, 6.2831854820251465)),
        2147483648u,
        "div(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, -6.2831854820251465)),
        2147483648u,
        "div(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, 6.2831854820251465)),
        0u,
        "div(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, -3.4028234663852886e+38)),
        0u,
        "div(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, 3.4028234663852886e+38)),
        2147483648u,
        "div(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, -3.4028234663852886e+38)),
        2147483648u,
        "div(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, 3.4028234663852886e+38)),
        0u,
        "div(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, -INFINITY)),
        0u,
        "div(-0.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, INFINITY)),
        2147483648u,
        "div(-0.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, -INFINITY)),
        2147483648u,
        "div(0.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, INFINITY)),
        0u,
        "div(0.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(-0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(-0.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(-0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(-0.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(0.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(0.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, -0.0)),
        2139095040u,
        "div(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, 0.0)),
        4286578688u,
        "div(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, -0.0)),
        4286578688u,
        "div(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, 0.0)),
        2139095040u,
        "div(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, -1.401298464324817e-45)),
        1065353216u,
        "div(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, 1.401298464324817e-45)),
        3212836864u,
        "div(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, -1.401298464324817e-45)),
        3212836864u,
        "div(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, 1.401298464324817e-45)),
        1065353216u,
        "div(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, -1.1754943508222875e-38)),
        872415232u,
        "div(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, 1.1754943508222875e-38)),
        3019898880u,
        "div(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, -1.1754943508222875e-38)),
        3019898880u,
        "div(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, 1.1754943508222875e-38)),
        872415232u,
        "div(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, -0.5)),
        2u,
        "div(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, 0.5)),
        2147483650u,
        "div(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, -0.5)),
        2147483650u,
        "div(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, 0.5)),
        2u,
        "div(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, -1.0)),
        1u,
        "div(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, 1.0)),
        2147483649u,
        "div(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, -1.0)),
        2147483649u,
        "div(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, 1.0)),
        1u,
        "div(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, -6.2831854820251465)),
        0u,
        "div(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, 6.2831854820251465)),
        2147483648u,
        "div(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, -6.2831854820251465)),
        2147483648u,
        "div(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, 6.2831854820251465)),
        0u,
        "div(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, -3.4028234663852886e+38)),
        0u,
        "div(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, 3.4028234663852886e+38)),
        2147483648u,
        "div(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, -3.4028234663852886e+38)),
        2147483648u,
        "div(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, 3.4028234663852886e+38)),
        0u,
        "div(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, -INFINITY)),
        0u,
        "div(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, INFINITY)),
        2147483648u,
        "div(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, -INFINITY)),
        2147483648u,
        "div(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, INFINITY)),
        0u,
        "div(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(-1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(-1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(-1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(-1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, -0.0)),
        2139095040u,
        "div(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, 0.0)),
        4286578688u,
        "div(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, -0.0)),
        4286578688u,
        "div(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, 0.0)),
        2139095040u,
        "div(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, -1.401298464324817e-45)),
        1258291200u,
        "div(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, 1.401298464324817e-45)),
        3405774848u,
        "div(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, -1.401298464324817e-45)),
        3405774848u,
        "div(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, 1.401298464324817e-45)),
        1258291200u,
        "div(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38)),
        1065353216u,
        "div(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38)),
        3212836864u,
        "div(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38)),
        3212836864u,
        "div(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38)),
        1065353216u,
        "div(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, -0.5)),
        16777216u,
        "div(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, 0.5)),
        2164260864u,
        "div(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, -0.5)),
        2164260864u,
        "div(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, 0.5)),
        16777216u,
        "div(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, -1.0)),
        8388608u,
        "div(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, 1.0)),
        2155872256u,
        "div(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, -1.0)),
        2155872256u,
        "div(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, 1.0)),
        8388608u,
        "div(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, -6.2831854820251465)),
        1335088u,
        "div(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, 6.2831854820251465)),
        2148818736u,
        "div(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, -6.2831854820251465)),
        2148818736u,
        "div(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, 6.2831854820251465)),
        1335088u,
        "div(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38)),
        0u,
        "div(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38)),
        2147483648u,
        "div(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38)),
        2147483648u,
        "div(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38)),
        0u,
        "div(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, -INFINITY)),
        0u,
        "div(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, INFINITY)),
        2147483648u,
        "div(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, -INFINITY)),
        2147483648u,
        "div(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, INFINITY)),
        0u,
        "div(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(-1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(-1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, -0.0)),
        2139095040u,
        "div(-0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, 0.0)),
        4286578688u,
        "div(-0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, -0.0)),
        4286578688u,
        "div(0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, 0.0)),
        2139095040u,
        "div(0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, -1.401298464324817e-45)),
        2139095040u,
        "div(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, 1.401298464324817e-45)),
        4286578688u,
        "div(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, -1.401298464324817e-45)),
        4286578688u,
        "div(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, 1.401298464324817e-45)),
        2139095040u,
        "div(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, -1.1754943508222875e-38)),
        2113929216u,
        "div(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, 1.1754943508222875e-38)),
        4261412864u,
        "div(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, -1.1754943508222875e-38)),
        4261412864u,
        "div(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, 1.1754943508222875e-38)),
        2113929216u,
        "div(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, -0.5)),
        1065353216u,
        "div(-0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, 0.5)),
        3212836864u,
        "div(-0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, -0.5)),
        3212836864u,
        "div(0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, 0.5)),
        1065353216u,
        "div(0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, -1.0)),
        1056964608u,
        "div(-0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, 1.0)),
        3204448256u,
        "div(-0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, -1.0)),
        3204448256u,
        "div(0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, 1.0)),
        1056964608u,
        "div(0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, -6.2831854820251465)),
        1034090883u,
        "div(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, 6.2831854820251465)),
        3181574531u,
        "div(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, -6.2831854820251465)),
        3181574531u,
        "div(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, 6.2831854820251465)),
        1034090883u,
        "div(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, -3.4028234663852886e+38)),
        1048576u,
        "div(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, 3.4028234663852886e+38)),
        2148532224u,
        "div(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, -3.4028234663852886e+38)),
        2148532224u,
        "div(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, 3.4028234663852886e+38)),
        1048576u,
        "div(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, -INFINITY)),
        0u,
        "div(-0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, INFINITY)),
        2147483648u,
        "div(-0.5, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, -INFINITY)),
        2147483648u,
        "div(0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, INFINITY)),
        0u,
        "div(0.5, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(-0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(-0.5, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(-0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -0.5, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(-0.5, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(0.5, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 0.5, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(0.5, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, -0.0)),
        2139095040u,
        "div(-1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, 0.0)),
        4286578688u,
        "div(-1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, -0.0)),
        4286578688u,
        "div(1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, 0.0)),
        2139095040u,
        "div(1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, -1.401298464324817e-45)),
        2139095040u,
        "div(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, 1.401298464324817e-45)),
        4286578688u,
        "div(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, -1.401298464324817e-45)),
        4286578688u,
        "div(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, 1.401298464324817e-45)),
        2139095040u,
        "div(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, -1.1754943508222875e-38)),
        2122317824u,
        "div(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, 1.1754943508222875e-38)),
        4269801472u,
        "div(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, -1.1754943508222875e-38)),
        4269801472u,
        "div(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, 1.1754943508222875e-38)),
        2122317824u,
        "div(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, -0.5)),
        1073741824u,
        "div(-1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, 0.5)),
        3221225472u,
        "div(-1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, -0.5)),
        3221225472u,
        "div(1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, 0.5)),
        1073741824u,
        "div(1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, -1.0)),
        1065353216u,
        "div(-1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, 1.0)),
        3212836864u,
        "div(-1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, -1.0)),
        3212836864u,
        "div(1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, 1.0)),
        1065353216u,
        "div(1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, -6.2831854820251465)),
        1042479491u,
        "div(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, 6.2831854820251465)),
        3189963139u,
        "div(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, -6.2831854820251465)),
        3189963139u,
        "div(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, 6.2831854820251465)),
        1042479491u,
        "div(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, -3.4028234663852886e+38)),
        2097152u,
        "div(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, 3.4028234663852886e+38)),
        2149580800u,
        "div(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, -3.4028234663852886e+38)),
        2149580800u,
        "div(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, 3.4028234663852886e+38)),
        2097152u,
        "div(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, -INFINITY)),
        0u,
        "div(-1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, INFINITY)),
        2147483648u,
        "div(-1.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, -INFINITY)),
        2147483648u,
        "div(1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, INFINITY)),
        0u,
        "div(1.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(-1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(-1.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(-1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -1.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(-1.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(1.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 1.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(1.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, -0.0)),
        2139095040u,
        "div(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, 0.0)),
        4286578688u,
        "div(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, -0.0)),
        4286578688u,
        "div(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, 0.0)),
        2139095040u,
        "div(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, -1.401298464324817e-45)),
        2139095040u,
        "div(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, 1.401298464324817e-45)),
        4286578688u,
        "div(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, -1.401298464324817e-45)),
        4286578688u,
        "div(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, 1.401298464324817e-45)),
        2139095040u,
        "div(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, -1.1754943508222875e-38)),
        2139095040u,
        "div(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, 1.1754943508222875e-38)),
        4286578688u,
        "div(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, -1.1754943508222875e-38)),
        4286578688u,
        "div(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, 1.1754943508222875e-38)),
        2139095040u,
        "div(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, -0.5)),
        1095307227u,
        "div(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, 0.5)),
        3242790875u,
        "div(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, -0.5)),
        3242790875u,
        "div(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, 0.5)),
        1095307227u,
        "div(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, -1.0)),
        1086918619u,
        "div(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, 1.0)),
        3234402267u,
        "div(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, -1.0)),
        3234402267u,
        "div(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, 1.0)),
        1086918619u,
        "div(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, -6.2831854820251465)),
        1065353216u,
        "div(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, 6.2831854820251465)),
        3212836864u,
        "div(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, -6.2831854820251465)),
        3212836864u,
        "div(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, 6.2831854820251465)),
        1065353216u,
        "div(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, -3.4028234663852886e+38)),
        13176796u,
        "div(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, 3.4028234663852886e+38)),
        2160660444u,
        "div(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, -3.4028234663852886e+38)),
        2160660444u,
        "div(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, 3.4028234663852886e+38)),
        13176796u,
        "div(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, -INFINITY)),
        0u,
        "div(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, INFINITY)),
        2147483648u,
        "div(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, -INFINITY)),
        2147483648u,
        "div(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, INFINITY)),
        0u,
        "div(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(-6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(-6.2831854820251465, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(-6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(-6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(6.2831854820251465, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, -0.0)),
        2139095040u,
        "div(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, 0.0)),
        4286578688u,
        "div(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, -0.0)),
        4286578688u,
        "div(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, 0.0)),
        2139095040u,
        "div(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, -1.401298464324817e-45)),
        2139095040u,
        "div(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, 1.401298464324817e-45)),
        4286578688u,
        "div(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, -1.401298464324817e-45)),
        4286578688u,
        "div(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, 1.401298464324817e-45)),
        2139095040u,
        "div(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38)),
        2139095040u,
        "div(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38)),
        4286578688u,
        "div(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38)),
        4286578688u,
        "div(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38)),
        2139095040u,
        "div(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, -0.5)),
        2139095040u,
        "div(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, 0.5)),
        4286578688u,
        "div(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, -0.5)),
        4286578688u,
        "div(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, 0.5)),
        2139095040u,
        "div(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, -1.0)),
        2139095039u,
        "div(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, 1.0)),
        4286578687u,
        "div(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, -1.0)),
        4286578687u,
        "div(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, 1.0)),
        2139095039u,
        "div(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, -6.2831854820251465)),
        2116221314u,
        "div(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, 6.2831854820251465)),
        4263704962u,
        "div(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, -6.2831854820251465)),
        4263704962u,
        "div(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, 6.2831854820251465)),
        2116221314u,
        "div(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38)),
        1065353216u,
        "div(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38)),
        3212836864u,
        "div(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38)),
        3212836864u,
        "div(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38)),
        1065353216u,
        "div(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, -INFINITY)),
        0u,
        "div(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, INFINITY)),
        2147483648u,
        "div(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, -INFINITY)),
        2147483648u,
        "div(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, INFINITY)),
        0u,
        "div(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(-3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(-3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, -0.0)),
        2139095040u,
        "div(-INFINITY, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, 0.0)),
        4286578688u,
        "div(-INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, -0.0)),
        4286578688u,
        "div(INFINITY, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, 0.0)),
        2139095040u,
        "div(INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, -1.401298464324817e-45)),
        2139095040u,
        "div(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, 1.401298464324817e-45)),
        4286578688u,
        "div(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, -1.401298464324817e-45)),
        4286578688u,
        "div(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, 1.401298464324817e-45)),
        2139095040u,
        "div(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, -1.1754943508222875e-38)),
        2139095040u,
        "div(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, 1.1754943508222875e-38)),
        4286578688u,
        "div(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, -1.1754943508222875e-38)),
        4286578688u,
        "div(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, 1.1754943508222875e-38)),
        2139095040u,
        "div(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, -0.5)),
        2139095040u,
        "div(-INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, 0.5)),
        4286578688u,
        "div(-INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, -0.5)),
        4286578688u,
        "div(INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, 0.5)),
        2139095040u,
        "div(INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, -1.0)),
        2139095040u,
        "div(-INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, 1.0)),
        4286578688u,
        "div(-INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, -1.0)),
        4286578688u,
        "div(INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, 1.0)),
        2139095040u,
        "div(INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, -6.2831854820251465)),
        2139095040u,
        "div(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, 6.2831854820251465)),
        4286578688u,
        "div(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, -6.2831854820251465)),
        4286578688u,
        "div(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, 6.2831854820251465)),
        2139095040u,
        "div(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, -3.4028234663852886e+38)),
        2139095040u,
        "div(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, 3.4028234663852886e+38)),
        4286578688u,
        "div(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, -3.4028234663852886e+38)),
        4286578688u,
        "div(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, 3.4028234663852886e+38)),
        2139095040u,
        "div(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, -INFINITY)) & 2147483647u),
        2143289344u,
        "div(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, INFINITY)) & 2147483647u),
        2143289344u,
        "div(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, -INFINITY)) & 2147483647u),
        2143289344u,
        "div(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, INFINITY)) & 2147483647u),
        2143289344u,
        "div(INFINITY, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(-INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(-INFINITY, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(-INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, -INFINITY, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(-INFINITY, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(INFINITY, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, INFINITY, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(INFINITY, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), -0.0)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), -0.0)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), 0.0)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), 0.0)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), -0.0)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), -0.0)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), 0.0)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), -1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), 1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), -1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), 1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), -1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), 1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), -1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), 1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), -0.5)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), -0.5)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), 0.5)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), 0.5)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), -0.5)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), -0.5)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), 0.5)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), 0.5)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), -1.0)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), -1.0)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), 1.0)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), 1.0)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), -1.0)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), -1.0)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), 1.0)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), 1.0)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), -6.2831854820251465)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), 6.2831854820251465)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), -6.2831854820251465)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), 6.2831854820251465)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), -3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), 3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), -3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), 3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), -INFINITY)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), -INFINITY)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), INFINITY)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), INFINITY)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), -INFINITY)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), -INFINITY)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), INFINITY)) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), INFINITY)) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffc00000u))) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fc00000u))) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffc00000u))) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fc00000u))) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_div(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "div(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, -0.0)),
        2147483648u,
        "min(-0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, 0.0)),
        2147483648u,
        "min(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, -0.0)),
        2147483648u,
        "min(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, 0.0)),
        0u,
        "min(0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, -1.401298464324817e-45)),
        2147483649u,
        "min(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, 1.401298464324817e-45)),
        2147483648u,
        "min(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, -1.401298464324817e-45)),
        2147483649u,
        "min(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, 1.401298464324817e-45)),
        0u,
        "min(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, -1.1754943508222875e-38)),
        2155872256u,
        "min(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, 1.1754943508222875e-38)),
        2147483648u,
        "min(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, -1.1754943508222875e-38)),
        2155872256u,
        "min(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, 1.1754943508222875e-38)),
        0u,
        "min(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, -0.5)),
        3204448256u,
        "min(-0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, 0.5)),
        2147483648u,
        "min(-0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, -0.5)),
        3204448256u,
        "min(0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, 0.5)),
        0u,
        "min(0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, -1.0)),
        3212836864u,
        "min(-0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, 1.0)),
        2147483648u,
        "min(-0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, -1.0)),
        3212836864u,
        "min(0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, 1.0)),
        0u,
        "min(0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, -6.2831854820251465)),
        3234402267u,
        "min(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, 6.2831854820251465)),
        2147483648u,
        "min(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, -6.2831854820251465)),
        3234402267u,
        "min(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, 6.2831854820251465)),
        0u,
        "min(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, -3.4028234663852886e+38)),
        4286578687u,
        "min(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, 3.4028234663852886e+38)),
        2147483648u,
        "min(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, -3.4028234663852886e+38)),
        4286578687u,
        "min(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, 3.4028234663852886e+38)),
        0u,
        "min(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, -INFINITY)),
        4286578688u,
        "min(-0.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, INFINITY)),
        2147483648u,
        "min(-0.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, -INFINITY)),
        4286578688u,
        "min(0.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, INFINITY)),
        0u,
        "min(0.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(-0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(-0.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(-0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(-0.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(0.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(0.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, -0.0)),
        2147483649u,
        "min(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, 0.0)),
        2147483649u,
        "min(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, -0.0)),
        2147483648u,
        "min(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, 0.0)),
        0u,
        "min(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, -1.401298464324817e-45)),
        2147483649u,
        "min(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, 1.401298464324817e-45)),
        2147483649u,
        "min(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, -1.401298464324817e-45)),
        2147483649u,
        "min(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, 1.401298464324817e-45)),
        1u,
        "min(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, -1.1754943508222875e-38)),
        2155872256u,
        "min(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, 1.1754943508222875e-38)),
        2147483649u,
        "min(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, -1.1754943508222875e-38)),
        2155872256u,
        "min(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, 1.1754943508222875e-38)),
        1u,
        "min(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, -0.5)),
        3204448256u,
        "min(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, 0.5)),
        2147483649u,
        "min(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, -0.5)),
        3204448256u,
        "min(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, 0.5)),
        1u,
        "min(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, -1.0)),
        3212836864u,
        "min(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, 1.0)),
        2147483649u,
        "min(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, -1.0)),
        3212836864u,
        "min(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, 1.0)),
        1u,
        "min(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, -6.2831854820251465)),
        3234402267u,
        "min(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, 6.2831854820251465)),
        2147483649u,
        "min(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, -6.2831854820251465)),
        3234402267u,
        "min(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, 6.2831854820251465)),
        1u,
        "min(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, -3.4028234663852886e+38)),
        4286578687u,
        "min(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, 3.4028234663852886e+38)),
        2147483649u,
        "min(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, -3.4028234663852886e+38)),
        4286578687u,
        "min(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, 3.4028234663852886e+38)),
        1u,
        "min(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, -INFINITY)),
        4286578688u,
        "min(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, INFINITY)),
        2147483649u,
        "min(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, -INFINITY)),
        4286578688u,
        "min(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, INFINITY)),
        1u,
        "min(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(-1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(-1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(-1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(-1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, -0.0)),
        2155872256u,
        "min(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, 0.0)),
        2155872256u,
        "min(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, -0.0)),
        2147483648u,
        "min(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, 0.0)),
        0u,
        "min(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, -1.401298464324817e-45)),
        2155872256u,
        "min(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, 1.401298464324817e-45)),
        2155872256u,
        "min(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, -1.401298464324817e-45)),
        2147483649u,
        "min(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, 1.401298464324817e-45)),
        1u,
        "min(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38)),
        2155872256u,
        "min(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38)),
        2155872256u,
        "min(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38)),
        2155872256u,
        "min(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38)),
        8388608u,
        "min(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, -0.5)),
        3204448256u,
        "min(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, 0.5)),
        2155872256u,
        "min(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, -0.5)),
        3204448256u,
        "min(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, 0.5)),
        8388608u,
        "min(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, -1.0)),
        3212836864u,
        "min(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, 1.0)),
        2155872256u,
        "min(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, -1.0)),
        3212836864u,
        "min(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, 1.0)),
        8388608u,
        "min(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, -6.2831854820251465)),
        3234402267u,
        "min(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, 6.2831854820251465)),
        2155872256u,
        "min(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, -6.2831854820251465)),
        3234402267u,
        "min(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, 6.2831854820251465)),
        8388608u,
        "min(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38)),
        4286578687u,
        "min(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38)),
        2155872256u,
        "min(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38)),
        4286578687u,
        "min(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38)),
        8388608u,
        "min(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, -INFINITY)),
        4286578688u,
        "min(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, INFINITY)),
        2155872256u,
        "min(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, -INFINITY)),
        4286578688u,
        "min(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, INFINITY)),
        8388608u,
        "min(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(-1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(-1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, -0.0)),
        3204448256u,
        "min(-0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, 0.0)),
        3204448256u,
        "min(-0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, -0.0)),
        2147483648u,
        "min(0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, 0.0)),
        0u,
        "min(0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, -1.401298464324817e-45)),
        3204448256u,
        "min(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, 1.401298464324817e-45)),
        3204448256u,
        "min(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, -1.401298464324817e-45)),
        2147483649u,
        "min(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, 1.401298464324817e-45)),
        1u,
        "min(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, -1.1754943508222875e-38)),
        3204448256u,
        "min(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, 1.1754943508222875e-38)),
        3204448256u,
        "min(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, -1.1754943508222875e-38)),
        2155872256u,
        "min(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, 1.1754943508222875e-38)),
        8388608u,
        "min(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, -0.5)),
        3204448256u,
        "min(-0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, 0.5)),
        3204448256u,
        "min(-0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, -0.5)),
        3204448256u,
        "min(0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, 0.5)),
        1056964608u,
        "min(0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, -1.0)),
        3212836864u,
        "min(-0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, 1.0)),
        3204448256u,
        "min(-0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, -1.0)),
        3212836864u,
        "min(0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, 1.0)),
        1056964608u,
        "min(0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, -6.2831854820251465)),
        3234402267u,
        "min(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, 6.2831854820251465)),
        3204448256u,
        "min(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, -6.2831854820251465)),
        3234402267u,
        "min(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, 6.2831854820251465)),
        1056964608u,
        "min(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, -3.4028234663852886e+38)),
        4286578687u,
        "min(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, 3.4028234663852886e+38)),
        3204448256u,
        "min(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, -3.4028234663852886e+38)),
        4286578687u,
        "min(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, 3.4028234663852886e+38)),
        1056964608u,
        "min(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, -INFINITY)),
        4286578688u,
        "min(-0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, INFINITY)),
        3204448256u,
        "min(-0.5, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, -INFINITY)),
        4286578688u,
        "min(0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, INFINITY)),
        1056964608u,
        "min(0.5, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(-0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(-0.5, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(-0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -0.5, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(-0.5, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(0.5, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 0.5, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(0.5, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, -0.0)),
        3212836864u,
        "min(-1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, 0.0)),
        3212836864u,
        "min(-1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, -0.0)),
        2147483648u,
        "min(1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, 0.0)),
        0u,
        "min(1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, -1.401298464324817e-45)),
        3212836864u,
        "min(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, 1.401298464324817e-45)),
        3212836864u,
        "min(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, -1.401298464324817e-45)),
        2147483649u,
        "min(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, 1.401298464324817e-45)),
        1u,
        "min(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, -1.1754943508222875e-38)),
        3212836864u,
        "min(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, 1.1754943508222875e-38)),
        3212836864u,
        "min(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, -1.1754943508222875e-38)),
        2155872256u,
        "min(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, 1.1754943508222875e-38)),
        8388608u,
        "min(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, -0.5)),
        3212836864u,
        "min(-1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, 0.5)),
        3212836864u,
        "min(-1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, -0.5)),
        3204448256u,
        "min(1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, 0.5)),
        1056964608u,
        "min(1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, -1.0)),
        3212836864u,
        "min(-1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, 1.0)),
        3212836864u,
        "min(-1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, -1.0)),
        3212836864u,
        "min(1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, 1.0)),
        1065353216u,
        "min(1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, -6.2831854820251465)),
        3234402267u,
        "min(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, 6.2831854820251465)),
        3212836864u,
        "min(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, -6.2831854820251465)),
        3234402267u,
        "min(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, 6.2831854820251465)),
        1065353216u,
        "min(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, -3.4028234663852886e+38)),
        4286578687u,
        "min(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, 3.4028234663852886e+38)),
        3212836864u,
        "min(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, -3.4028234663852886e+38)),
        4286578687u,
        "min(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, 3.4028234663852886e+38)),
        1065353216u,
        "min(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, -INFINITY)),
        4286578688u,
        "min(-1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, INFINITY)),
        3212836864u,
        "min(-1.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, -INFINITY)),
        4286578688u,
        "min(1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, INFINITY)),
        1065353216u,
        "min(1.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(-1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(-1.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(-1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -1.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(-1.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(1.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 1.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(1.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, -0.0)),
        3234402267u,
        "min(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, 0.0)),
        3234402267u,
        "min(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, -0.0)),
        2147483648u,
        "min(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, 0.0)),
        0u,
        "min(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, -1.401298464324817e-45)),
        3234402267u,
        "min(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, 1.401298464324817e-45)),
        3234402267u,
        "min(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, -1.401298464324817e-45)),
        2147483649u,
        "min(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, 1.401298464324817e-45)),
        1u,
        "min(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, -1.1754943508222875e-38)),
        3234402267u,
        "min(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, 1.1754943508222875e-38)),
        3234402267u,
        "min(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, -1.1754943508222875e-38)),
        2155872256u,
        "min(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, 1.1754943508222875e-38)),
        8388608u,
        "min(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, -0.5)),
        3234402267u,
        "min(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, 0.5)),
        3234402267u,
        "min(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, -0.5)),
        3204448256u,
        "min(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, 0.5)),
        1056964608u,
        "min(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, -1.0)),
        3234402267u,
        "min(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, 1.0)),
        3234402267u,
        "min(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, -1.0)),
        3212836864u,
        "min(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, 1.0)),
        1065353216u,
        "min(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, -6.2831854820251465)),
        3234402267u,
        "min(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, 6.2831854820251465)),
        3234402267u,
        "min(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, -6.2831854820251465)),
        3234402267u,
        "min(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, 6.2831854820251465)),
        1086918619u,
        "min(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, -3.4028234663852886e+38)),
        4286578687u,
        "min(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, 3.4028234663852886e+38)),
        3234402267u,
        "min(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, -3.4028234663852886e+38)),
        4286578687u,
        "min(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, 3.4028234663852886e+38)),
        1086918619u,
        "min(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, -INFINITY)),
        4286578688u,
        "min(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, INFINITY)),
        3234402267u,
        "min(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, -INFINITY)),
        4286578688u,
        "min(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, INFINITY)),
        1086918619u,
        "min(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(-6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(-6.2831854820251465, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(-6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(-6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(6.2831854820251465, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, -0.0)),
        4286578687u,
        "min(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, 0.0)),
        4286578687u,
        "min(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, -0.0)),
        2147483648u,
        "min(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, 0.0)),
        0u,
        "min(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, -1.401298464324817e-45)),
        4286578687u,
        "min(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, 1.401298464324817e-45)),
        4286578687u,
        "min(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, -1.401298464324817e-45)),
        2147483649u,
        "min(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, 1.401298464324817e-45)),
        1u,
        "min(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38)),
        4286578687u,
        "min(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38)),
        4286578687u,
        "min(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38)),
        2155872256u,
        "min(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38)),
        8388608u,
        "min(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, -0.5)),
        4286578687u,
        "min(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, 0.5)),
        4286578687u,
        "min(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, -0.5)),
        3204448256u,
        "min(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, 0.5)),
        1056964608u,
        "min(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, -1.0)),
        4286578687u,
        "min(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, 1.0)),
        4286578687u,
        "min(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, -1.0)),
        3212836864u,
        "min(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, 1.0)),
        1065353216u,
        "min(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, -6.2831854820251465)),
        4286578687u,
        "min(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, 6.2831854820251465)),
        4286578687u,
        "min(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, -6.2831854820251465)),
        3234402267u,
        "min(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, 6.2831854820251465)),
        1086918619u,
        "min(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38)),
        4286578687u,
        "min(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38)),
        4286578687u,
        "min(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38)),
        4286578687u,
        "min(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38)),
        2139095039u,
        "min(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, -INFINITY)),
        4286578688u,
        "min(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, INFINITY)),
        4286578687u,
        "min(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, -INFINITY)),
        4286578688u,
        "min(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, INFINITY)),
        2139095039u,
        "min(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(-3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(-3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, -0.0)),
        4286578688u,
        "min(-INFINITY, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, 0.0)),
        4286578688u,
        "min(-INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, -0.0)),
        2147483648u,
        "min(INFINITY, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, 0.0)),
        0u,
        "min(INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, -1.401298464324817e-45)),
        4286578688u,
        "min(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, 1.401298464324817e-45)),
        4286578688u,
        "min(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, -1.401298464324817e-45)),
        2147483649u,
        "min(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, 1.401298464324817e-45)),
        1u,
        "min(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, -1.1754943508222875e-38)),
        4286578688u,
        "min(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, 1.1754943508222875e-38)),
        4286578688u,
        "min(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, -1.1754943508222875e-38)),
        2155872256u,
        "min(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, 1.1754943508222875e-38)),
        8388608u,
        "min(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, -0.5)),
        4286578688u,
        "min(-INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, 0.5)),
        4286578688u,
        "min(-INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, -0.5)),
        3204448256u,
        "min(INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, 0.5)),
        1056964608u,
        "min(INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, -1.0)),
        4286578688u,
        "min(-INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, 1.0)),
        4286578688u,
        "min(-INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, -1.0)),
        3212836864u,
        "min(INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, 1.0)),
        1065353216u,
        "min(INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, -6.2831854820251465)),
        4286578688u,
        "min(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, 6.2831854820251465)),
        4286578688u,
        "min(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, -6.2831854820251465)),
        3234402267u,
        "min(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, 6.2831854820251465)),
        1086918619u,
        "min(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, -3.4028234663852886e+38)),
        4286578688u,
        "min(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, 3.4028234663852886e+38)),
        4286578688u,
        "min(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, -3.4028234663852886e+38)),
        4286578687u,
        "min(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, 3.4028234663852886e+38)),
        2139095039u,
        "min(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, -INFINITY)),
        4286578688u,
        "min(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, INFINITY)),
        4286578688u,
        "min(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, -INFINITY)),
        4286578688u,
        "min(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, INFINITY)),
        2139095040u,
        "min(INFINITY, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(-INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(-INFINITY, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(-INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, -INFINITY, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(-INFINITY, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(INFINITY, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, INFINITY, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(INFINITY, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), -0.0)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), -0.0)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), 0.0)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), 0.0)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), -0.0)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), -0.0)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), 0.0)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), -1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), 1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), -1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), 1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), -1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), 1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), -1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), 1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), -0.5)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), -0.5)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), 0.5)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), 0.5)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), -0.5)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), -0.5)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), 0.5)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), 0.5)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), -1.0)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), -1.0)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), 1.0)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), 1.0)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), -1.0)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), -1.0)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), 1.0)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), 1.0)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), -6.2831854820251465)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), 6.2831854820251465)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), -6.2831854820251465)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), 6.2831854820251465)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), -3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), 3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), -3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), 3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), -INFINITY)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), -INFINITY)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), INFINITY)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), INFINITY)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), -INFINITY)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), -INFINITY)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), INFINITY)) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), INFINITY)) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffc00000u))) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fc00000u))) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffc00000u))) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fc00000u))) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_min(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "min(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, -0.0)),
        2147483648u,
        "max(-0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, 0.0)),
        0u,
        "max(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, -0.0)),
        0u,
        "max(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, 0.0)),
        0u,
        "max(0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, -1.401298464324817e-45)),
        2147483648u,
        "max(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, 1.401298464324817e-45)),
        1u,
        "max(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, -1.401298464324817e-45)),
        0u,
        "max(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, 1.401298464324817e-45)),
        1u,
        "max(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, -1.1754943508222875e-38)),
        2147483648u,
        "max(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, 1.1754943508222875e-38)),
        8388608u,
        "max(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, -1.1754943508222875e-38)),
        0u,
        "max(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, 1.1754943508222875e-38)),
        8388608u,
        "max(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, -0.5)),
        2147483648u,
        "max(-0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, 0.5)),
        1056964608u,
        "max(-0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, -0.5)),
        0u,
        "max(0.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, 0.5)),
        1056964608u,
        "max(0.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, -1.0)),
        2147483648u,
        "max(-0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, 1.0)),
        1065353216u,
        "max(-0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, -1.0)),
        0u,
        "max(0.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, 1.0)),
        1065353216u,
        "max(0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, -6.2831854820251465)),
        2147483648u,
        "max(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, 6.2831854820251465)),
        1086918619u,
        "max(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, -6.2831854820251465)),
        0u,
        "max(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, 6.2831854820251465)),
        1086918619u,
        "max(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, -3.4028234663852886e+38)),
        2147483648u,
        "max(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, 3.4028234663852886e+38)),
        2139095039u,
        "max(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, -3.4028234663852886e+38)),
        0u,
        "max(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, 3.4028234663852886e+38)),
        2139095039u,
        "max(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, -INFINITY)),
        2147483648u,
        "max(-0.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, INFINITY)),
        2139095040u,
        "max(-0.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, -INFINITY)),
        0u,
        "max(0.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, INFINITY)),
        2139095040u,
        "max(0.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(-0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(-0.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(-0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(-0.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(0.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(0.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(0.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, -0.0)),
        2147483648u,
        "max(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, 0.0)),
        0u,
        "max(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, -0.0)),
        1u,
        "max(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, 0.0)),
        1u,
        "max(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, -1.401298464324817e-45)),
        2147483649u,
        "max(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, 1.401298464324817e-45)),
        1u,
        "max(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, -1.401298464324817e-45)),
        1u,
        "max(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, 1.401298464324817e-45)),
        1u,
        "max(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, -1.1754943508222875e-38)),
        2147483649u,
        "max(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, 1.1754943508222875e-38)),
        8388608u,
        "max(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, -1.1754943508222875e-38)),
        1u,
        "max(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, 1.1754943508222875e-38)),
        8388608u,
        "max(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, -0.5)),
        2147483649u,
        "max(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, 0.5)),
        1056964608u,
        "max(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, -0.5)),
        1u,
        "max(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, 0.5)),
        1056964608u,
        "max(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, -1.0)),
        2147483649u,
        "max(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, 1.0)),
        1065353216u,
        "max(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, -1.0)),
        1u,
        "max(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, 1.0)),
        1065353216u,
        "max(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, -6.2831854820251465)),
        2147483649u,
        "max(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, 6.2831854820251465)),
        1086918619u,
        "max(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, -6.2831854820251465)),
        1u,
        "max(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, 6.2831854820251465)),
        1086918619u,
        "max(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, -3.4028234663852886e+38)),
        2147483649u,
        "max(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, 3.4028234663852886e+38)),
        2139095039u,
        "max(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, -3.4028234663852886e+38)),
        1u,
        "max(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, 3.4028234663852886e+38)),
        2139095039u,
        "max(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, -INFINITY)),
        2147483649u,
        "max(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, INFINITY)),
        2139095040u,
        "max(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, -INFINITY)),
        1u,
        "max(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, INFINITY)),
        2139095040u,
        "max(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(-1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(-1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(-1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(-1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(1.401298464324817e-45, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(1.401298464324817e-45, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(1.401298464324817e-45, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(1.401298464324817e-45, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, -0.0)),
        2147483648u,
        "max(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, 0.0)),
        0u,
        "max(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, -0.0)),
        8388608u,
        "max(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, 0.0)),
        8388608u,
        "max(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, -1.401298464324817e-45)),
        2147483649u,
        "max(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, 1.401298464324817e-45)),
        1u,
        "max(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, -1.401298464324817e-45)),
        8388608u,
        "max(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, 1.401298464324817e-45)),
        8388608u,
        "max(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38)),
        2155872256u,
        "max(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38)),
        8388608u,
        "max(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38)),
        8388608u,
        "max(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38)),
        8388608u,
        "max(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, -0.5)),
        2155872256u,
        "max(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, 0.5)),
        1056964608u,
        "max(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, -0.5)),
        8388608u,
        "max(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, 0.5)),
        1056964608u,
        "max(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, -1.0)),
        2155872256u,
        "max(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, 1.0)),
        1065353216u,
        "max(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, -1.0)),
        8388608u,
        "max(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, 1.0)),
        1065353216u,
        "max(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, -6.2831854820251465)),
        2155872256u,
        "max(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, 6.2831854820251465)),
        1086918619u,
        "max(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, -6.2831854820251465)),
        8388608u,
        "max(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, 6.2831854820251465)),
        1086918619u,
        "max(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38)),
        2155872256u,
        "max(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38)),
        2139095039u,
        "max(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38)),
        8388608u,
        "max(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38)),
        2139095039u,
        "max(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, -INFINITY)),
        2155872256u,
        "max(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, INFINITY)),
        2139095040u,
        "max(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, -INFINITY)),
        8388608u,
        "max(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, INFINITY)),
        2139095040u,
        "max(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(-1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(-1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(-1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(1.1754943508222875e-38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(1.1754943508222875e-38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(1.1754943508222875e-38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(1.1754943508222875e-38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, -0.0)),
        2147483648u,
        "max(-0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, 0.0)),
        0u,
        "max(-0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, -0.0)),
        1056964608u,
        "max(0.5, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, 0.0)),
        1056964608u,
        "max(0.5, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, -1.401298464324817e-45)),
        2147483649u,
        "max(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, 1.401298464324817e-45)),
        1u,
        "max(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, -1.401298464324817e-45)),
        1056964608u,
        "max(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, 1.401298464324817e-45)),
        1056964608u,
        "max(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, -1.1754943508222875e-38)),
        2155872256u,
        "max(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, 1.1754943508222875e-38)),
        8388608u,
        "max(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, -1.1754943508222875e-38)),
        1056964608u,
        "max(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, 1.1754943508222875e-38)),
        1056964608u,
        "max(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, -0.5)),
        3204448256u,
        "max(-0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, 0.5)),
        1056964608u,
        "max(-0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, -0.5)),
        1056964608u,
        "max(0.5, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, 0.5)),
        1056964608u,
        "max(0.5, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, -1.0)),
        3204448256u,
        "max(-0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, 1.0)),
        1065353216u,
        "max(-0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, -1.0)),
        1056964608u,
        "max(0.5, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, 1.0)),
        1065353216u,
        "max(0.5, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, -6.2831854820251465)),
        3204448256u,
        "max(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, 6.2831854820251465)),
        1086918619u,
        "max(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, -6.2831854820251465)),
        1056964608u,
        "max(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, 6.2831854820251465)),
        1086918619u,
        "max(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, -3.4028234663852886e+38)),
        3204448256u,
        "max(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, 3.4028234663852886e+38)),
        2139095039u,
        "max(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, -3.4028234663852886e+38)),
        1056964608u,
        "max(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, 3.4028234663852886e+38)),
        2139095039u,
        "max(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, -INFINITY)),
        3204448256u,
        "max(-0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, INFINITY)),
        2139095040u,
        "max(-0.5, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, -INFINITY)),
        1056964608u,
        "max(0.5, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, INFINITY)),
        2139095040u,
        "max(0.5, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(-0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(-0.5, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(-0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -0.5, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(-0.5, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(0.5, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(0.5, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(0.5, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 0.5, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(0.5, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, -0.0)),
        2147483648u,
        "max(-1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, 0.0)),
        0u,
        "max(-1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, -0.0)),
        1065353216u,
        "max(1.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, 0.0)),
        1065353216u,
        "max(1.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, -1.401298464324817e-45)),
        2147483649u,
        "max(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, 1.401298464324817e-45)),
        1u,
        "max(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, -1.401298464324817e-45)),
        1065353216u,
        "max(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, 1.401298464324817e-45)),
        1065353216u,
        "max(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, -1.1754943508222875e-38)),
        2155872256u,
        "max(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, 1.1754943508222875e-38)),
        8388608u,
        "max(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, -1.1754943508222875e-38)),
        1065353216u,
        "max(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, 1.1754943508222875e-38)),
        1065353216u,
        "max(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, -0.5)),
        3204448256u,
        "max(-1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, 0.5)),
        1056964608u,
        "max(-1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, -0.5)),
        1065353216u,
        "max(1.0, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, 0.5)),
        1065353216u,
        "max(1.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, -1.0)),
        3212836864u,
        "max(-1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, 1.0)),
        1065353216u,
        "max(-1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, -1.0)),
        1065353216u,
        "max(1.0, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, 1.0)),
        1065353216u,
        "max(1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, -6.2831854820251465)),
        3212836864u,
        "max(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, 6.2831854820251465)),
        1086918619u,
        "max(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, -6.2831854820251465)),
        1065353216u,
        "max(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, 6.2831854820251465)),
        1086918619u,
        "max(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, -3.4028234663852886e+38)),
        3212836864u,
        "max(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, 3.4028234663852886e+38)),
        2139095039u,
        "max(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, -3.4028234663852886e+38)),
        1065353216u,
        "max(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, 3.4028234663852886e+38)),
        2139095039u,
        "max(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, -INFINITY)),
        3212836864u,
        "max(-1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, INFINITY)),
        2139095040u,
        "max(-1.0, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, -INFINITY)),
        1065353216u,
        "max(1.0, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, INFINITY)),
        2139095040u,
        "max(1.0, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(-1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(-1.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(-1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -1.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(-1.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(1.0, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(1.0, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(1.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 1.0, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(1.0, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, -0.0)),
        2147483648u,
        "max(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, 0.0)),
        0u,
        "max(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, -0.0)),
        1086918619u,
        "max(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, 0.0)),
        1086918619u,
        "max(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, -1.401298464324817e-45)),
        2147483649u,
        "max(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, 1.401298464324817e-45)),
        1u,
        "max(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, -1.401298464324817e-45)),
        1086918619u,
        "max(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, 1.401298464324817e-45)),
        1086918619u,
        "max(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, -1.1754943508222875e-38)),
        2155872256u,
        "max(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, 1.1754943508222875e-38)),
        8388608u,
        "max(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, -1.1754943508222875e-38)),
        1086918619u,
        "max(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, 1.1754943508222875e-38)),
        1086918619u,
        "max(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, -0.5)),
        3204448256u,
        "max(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, 0.5)),
        1056964608u,
        "max(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, -0.5)),
        1086918619u,
        "max(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, 0.5)),
        1086918619u,
        "max(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, -1.0)),
        3212836864u,
        "max(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, 1.0)),
        1065353216u,
        "max(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, -1.0)),
        1086918619u,
        "max(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, 1.0)),
        1086918619u,
        "max(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, -6.2831854820251465)),
        3234402267u,
        "max(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, 6.2831854820251465)),
        1086918619u,
        "max(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, -6.2831854820251465)),
        1086918619u,
        "max(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, 6.2831854820251465)),
        1086918619u,
        "max(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, -3.4028234663852886e+38)),
        3234402267u,
        "max(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, 3.4028234663852886e+38)),
        2139095039u,
        "max(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, -3.4028234663852886e+38)),
        1086918619u,
        "max(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, 3.4028234663852886e+38)),
        2139095039u,
        "max(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, -INFINITY)),
        3234402267u,
        "max(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, INFINITY)),
        2139095040u,
        "max(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, -INFINITY)),
        1086918619u,
        "max(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, INFINITY)),
        2139095040u,
        "max(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(-6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(-6.2831854820251465, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(-6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(-6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(6.2831854820251465, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(6.2831854820251465, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(6.2831854820251465, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(6.2831854820251465, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, -0.0)),
        2147483648u,
        "max(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, 0.0)),
        0u,
        "max(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, -0.0)),
        2139095039u,
        "max(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, 0.0)),
        2139095039u,
        "max(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, -1.401298464324817e-45)),
        2147483649u,
        "max(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, 1.401298464324817e-45)),
        1u,
        "max(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, -1.401298464324817e-45)),
        2139095039u,
        "max(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, 1.401298464324817e-45)),
        2139095039u,
        "max(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38)),
        2155872256u,
        "max(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38)),
        8388608u,
        "max(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38)),
        2139095039u,
        "max(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38)),
        2139095039u,
        "max(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, -0.5)),
        3204448256u,
        "max(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, 0.5)),
        1056964608u,
        "max(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, -0.5)),
        2139095039u,
        "max(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, 0.5)),
        2139095039u,
        "max(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, -1.0)),
        3212836864u,
        "max(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, 1.0)),
        1065353216u,
        "max(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, -1.0)),
        2139095039u,
        "max(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, 1.0)),
        2139095039u,
        "max(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, -6.2831854820251465)),
        3234402267u,
        "max(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, 6.2831854820251465)),
        1086918619u,
        "max(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, -6.2831854820251465)),
        2139095039u,
        "max(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, 6.2831854820251465)),
        2139095039u,
        "max(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38)),
        4286578687u,
        "max(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38)),
        2139095039u,
        "max(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38)),
        2139095039u,
        "max(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38)),
        2139095039u,
        "max(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, -INFINITY)),
        4286578687u,
        "max(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, INFINITY)),
        2139095040u,
        "max(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, -INFINITY)),
        2139095039u,
        "max(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, INFINITY)),
        2139095040u,
        "max(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(-3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(-3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(-3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(3.4028234663852886e+38, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(3.4028234663852886e+38, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(3.4028234663852886e+38, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, 3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(3.4028234663852886e+38, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, -0.0)),
        2147483648u,
        "max(-INFINITY, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, 0.0)),
        0u,
        "max(-INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, -0.0)),
        2139095040u,
        "max(INFINITY, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, 0.0)),
        2139095040u,
        "max(INFINITY, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, -1.401298464324817e-45)),
        2147483649u,
        "max(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, 1.401298464324817e-45)),
        1u,
        "max(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, -1.401298464324817e-45)),
        2139095040u,
        "max(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, 1.401298464324817e-45)),
        2139095040u,
        "max(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, -1.1754943508222875e-38)),
        2155872256u,
        "max(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, 1.1754943508222875e-38)),
        8388608u,
        "max(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, -1.1754943508222875e-38)),
        2139095040u,
        "max(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, 1.1754943508222875e-38)),
        2139095040u,
        "max(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, -0.5)),
        3204448256u,
        "max(-INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, 0.5)),
        1056964608u,
        "max(-INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, -0.5)),
        2139095040u,
        "max(INFINITY, -0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, 0.5)),
        2139095040u,
        "max(INFINITY, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, -1.0)),
        3212836864u,
        "max(-INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, 1.0)),
        1065353216u,
        "max(-INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, -1.0)),
        2139095040u,
        "max(INFINITY, -1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, 1.0)),
        2139095040u,
        "max(INFINITY, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, -6.2831854820251465)),
        3234402267u,
        "max(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, 6.2831854820251465)),
        1086918619u,
        "max(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, -6.2831854820251465)),
        2139095040u,
        "max(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, 6.2831854820251465)),
        2139095040u,
        "max(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, -3.4028234663852886e+38)),
        4286578687u,
        "max(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, 3.4028234663852886e+38)),
        2139095039u,
        "max(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, -3.4028234663852886e+38)),
        2139095040u,
        "max(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, 3.4028234663852886e+38)),
        2139095040u,
        "max(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, -INFINITY)),
        4286578688u,
        "max(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, INFINITY)),
        2139095040u,
        "max(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, -INFINITY)),
        2139095040u,
        "max(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, INFINITY)),
        2139095040u,
        "max(INFINITY, INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(-INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(-INFINITY, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(-INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, -INFINITY, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(-INFINITY, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(INFINITY, f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(INFINITY, f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(INFINITY, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, INFINITY, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(INFINITY, f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), -0.0)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), -0.0)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), 0.0)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), 0.0)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), -0.0)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), -0.0)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), -0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), 0.0)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), 0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), -1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), 1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), -1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), -1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), 1.401298464324817e-45)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), 1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), -1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), 1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), -1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), -1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), 1.1754943508222875e-38)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), 1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), -0.5)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), -0.5)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), 0.5)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), 0.5)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), -0.5)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), -0.5)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), -0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), 0.5)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), 0.5)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), 0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), -1.0)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), -1.0)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), 1.0)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), 1.0)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), -1.0)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), -1.0)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), -1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), 1.0)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), 1.0)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), 1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), -6.2831854820251465)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), 6.2831854820251465)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), -6.2831854820251465)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), -6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), 6.2831854820251465)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), 6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), -3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), 3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), -3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), -3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), 3.4028234663852886e+38)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), 3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), -INFINITY)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), -INFINITY)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), INFINITY)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), INFINITY)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), -INFINITY)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), -INFINITY)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), -INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), INFINITY)) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), INFINITY)) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffc00000u))) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fc00000u))) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffc00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0xffa00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffc00000u))) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fc00000u))) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fc00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export3_max(&instance, f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "max(f32_reinterpret_i32(0x7fa00000u), f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, -0.0)),
        2147483648u,
        "sqrt(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, 0.0)),
        0u,
        "sqrt(0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, -1.401298464324817e-45)) & 2147483647u),
        2143289344u,
        "sqrt(-1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, 1.401298464324817e-45)),
        439682291u,
        "sqrt(1.401298464324817e-45)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, -1.1754943508222875e-38)) & 2147483647u),
        2143289344u,
        "sqrt(-1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, 1.1754943508222875e-38)),
        536870912u,
        "sqrt(1.1754943508222875e-38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, -0.5)) & 2147483647u),
        2143289344u,
        "sqrt(-0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, 0.5)),
        1060439283u,
        "sqrt(0.5)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, -1.0)) & 2147483647u),
        2143289344u,
        "sqrt(-1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, 1.0)),
        1065353216u,
        "sqrt(1.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, -6.2831854820251465)) & 2147483647u),
        2143289344u,
        "sqrt(-6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, 6.2831854820251465)),
        1075866777u,
        "sqrt(6.2831854820251465)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, -3.4028234663852886e+38)) & 2147483647u),
        2143289344u,
        "sqrt(-3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, 3.4028234663852886e+38)),
        1602224127u,
        "sqrt(3.4028234663852886e+38)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, -INFINITY)) & 2147483647u),
        2143289344u,
        "sqrt(-INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, INFINITY)),
        2139095040u,
        "sqrt(INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "sqrt(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "sqrt(f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "sqrt(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_sqrt(&instance, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "sqrt(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, -0.0)),
        2147483648u,
        "floor(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, 0.0)),
        0u,
        "floor(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, -1.401298464324817e-45)),
        3212836864u,
        "floor(-1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, 1.401298464324817e-45)),
        0u,
        "floor(1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, -1.1754943508222875e-38)),
        3212836864u,
        "floor(-1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, 1.1754943508222875e-38)),
        0u,
        "floor(1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, -0.5)),
        3212836864u,
        "floor(-0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, 0.5)),
        0u,
        "floor(0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, -1.0)),
        3212836864u,
        "floor(-1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, 1.0)),
        1065353216u,
        "floor(1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, -6.2831854820251465)),
        3235905536u,
        "floor(-6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, 6.2831854820251465)),
        1086324736u,
        "floor(6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, -3.4028234663852886e+38)),
        4286578687u,
        "floor(-3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, 3.4028234663852886e+38)),
        2139095039u,
        "floor(3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, -INFINITY)),
        4286578688u,
        "floor(-INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, INFINITY)),
        2139095040u,
        "floor(INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "floor(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "floor(f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "floor(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export5_floor(&instance, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "floor(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, -0.0)),
        2147483648u,
        "ceil(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, 0.0)),
        0u,
        "ceil(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, -1.401298464324817e-45)),
        2147483648u,
        "ceil(-1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, 1.401298464324817e-45)),
        1065353216u,
        "ceil(1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, -1.1754943508222875e-38)),
        2147483648u,
        "ceil(-1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, 1.1754943508222875e-38)),
        1065353216u,
        "ceil(1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, -0.5)),
        2147483648u,
        "ceil(-0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, 0.5)),
        1065353216u,
        "ceil(0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, -1.0)),
        3212836864u,
        "ceil(-1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, 1.0)),
        1065353216u,
        "ceil(1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, -6.2831854820251465)),
        3233808384u,
        "ceil(-6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, 6.2831854820251465)),
        1088421888u,
        "ceil(6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, -3.4028234663852886e+38)),
        4286578687u,
        "ceil(-3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, 3.4028234663852886e+38)),
        2139095039u,
        "ceil(3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, -INFINITY)),
        4286578688u,
        "ceil(-INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, INFINITY)),
        2139095040u,
        "ceil(INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "ceil(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "ceil(f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "ceil(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export4_ceil(&instance, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "ceil(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, -0.0)),
        2147483648u,
        "trunc(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, 0.0)),
        0u,
        "trunc(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, -1.401298464324817e-45)),
        2147483648u,
        "trunc(-1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, 1.401298464324817e-45)),
        0u,
        "trunc(1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, -1.1754943508222875e-38)),
        2147483648u,
        "trunc(-1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, 1.1754943508222875e-38)),
        0u,
        "trunc(1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, -0.5)),
        2147483648u,
        "trunc(-0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, 0.5)),
        0u,
        "trunc(0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, -1.0)),
        3212836864u,
        "trunc(-1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, 1.0)),
        1065353216u,
        "trunc(1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, -6.2831854820251465)),
        3233808384u,
        "trunc(-6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, 6.2831854820251465)),
        1086324736u,
        "trunc(6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, -3.4028234663852886e+38)),
        4286578687u,
        "trunc(-3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, 3.4028234663852886e+38)),
        2139095039u,
        "trunc(3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, -INFINITY)),
        4286578688u,
        "trunc(-INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, INFINITY)),
        2139095040u,
        "trunc(INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "trunc(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "trunc(f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "trunc(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export5_trunc(&instance, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "trunc(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, -0.0)),
        2147483648u,
        "nearest(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, 0.0)),
        0u,
        "nearest(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, -1.401298464324817e-45)),
        2147483648u,
        "nearest(-1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, 1.401298464324817e-45)),
        0u,
        "nearest(1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, -1.1754943508222875e-38)),
        2147483648u,
        "nearest(-1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, 1.1754943508222875e-38)),
        0u,
        "nearest(1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, -0.5)),
        2147483648u,
        "nearest(-0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, 0.5)),
        0u,
        "nearest(0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, -1.0)),
        3212836864u,
        "nearest(-1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, 1.0)),
        1065353216u,
        "nearest(1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, -6.2831854820251465)),
        3233808384u,
        "nearest(-6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, 6.2831854820251465)),
        1086324736u,
        "nearest(6.2831854820251465)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, -3.4028234663852886e+38)),
        4286578687u,
        "nearest(-3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, 3.4028234663852886e+38)),
        2139095039u,
        "nearest(3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, -INFINITY)),
        4286578688u,
        "nearest(-INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, INFINITY)),
        2139095040u,
        "nearest(INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, f32_reinterpret_i32(0xffc00000u))) & 2147483647u),
        2143289344u,
        "nearest(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, f32_reinterpret_i32(0xffa00000u))) & 2143289344u),
        2143289344u,
        "nearest(f32_reinterpret_i32(0xffa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "nearest(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m5_f32X2E0Export7_nearest(&instance, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "nearest(f32_reinterpret_i32(0x7fa00000u))"
    );
}
