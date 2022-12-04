
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_f32_bitwise.0.h"

void test() {
    f32bitwise0Instance instance;
    f32bitwise0Instantiate(&instance, resolveTestImports);
    printStart("f32_bitwise.0.wasm");
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, -0.0),
        -0.0,
        "copysign(-0.0, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, 0.0),
        0.0,
        "copysign(-0.0, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, -0.0),
        -0.0,
        "copysign(0.0, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, 0.0),
        0.0,
        "copysign(0.0, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, -1.401298464324817e-45),
        -0.0,
        "copysign(-0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, 1.401298464324817e-45),
        0.0,
        "copysign(-0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, -1.401298464324817e-45),
        -0.0,
        "copysign(0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, 1.401298464324817e-45),
        0.0,
        "copysign(0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, -1.1754943508222875e-38),
        -0.0,
        "copysign(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, 1.1754943508222875e-38),
        0.0,
        "copysign(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, -1.1754943508222875e-38),
        -0.0,
        "copysign(0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, 1.1754943508222875e-38),
        0.0,
        "copysign(0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, -0.5),
        -0.0,
        "copysign(-0.0, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, 0.5),
        0.0,
        "copysign(-0.0, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, -0.5),
        -0.0,
        "copysign(0.0, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, 0.5),
        0.0,
        "copysign(0.0, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, -1.0),
        -0.0,
        "copysign(-0.0, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, 1.0),
        0.0,
        "copysign(-0.0, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, -1.0),
        -0.0,
        "copysign(0.0, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, 1.0),
        0.0,
        "copysign(0.0, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, -6.2831854820251465),
        -0.0,
        "copysign(-0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, 6.2831854820251465),
        0.0,
        "copysign(-0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, -6.2831854820251465),
        -0.0,
        "copysign(0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, 6.2831854820251465),
        0.0,
        "copysign(0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, -3.4028234663852886e+38),
        -0.0,
        "copysign(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, 3.4028234663852886e+38),
        0.0,
        "copysign(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, -3.4028234663852886e+38),
        -0.0,
        "copysign(0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, 3.4028234663852886e+38),
        0.0,
        "copysign(0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, -INFINITY),
        -0.0,
        "copysign(-0.0, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.0, INFINITY),
        0.0,
        "copysign(-0.0, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, -INFINITY),
        -0.0,
        "copysign(0.0, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.0, INFINITY),
        0.0,
        "copysign(0.0, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, -0.0),
        -1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, 0.0),
        1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, -0.0),
        -1.401298464324817e-45,
        "copysign(1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, 0.0),
        1.401298464324817e-45,
        "copysign(1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "copysign(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        1.401298464324817e-45,
        "copysign(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        -1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        -1.401298464324817e-45,
        "copysign(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        1.401298464324817e-45,
        "copysign(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, -0.5),
        -1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, 0.5),
        1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, -0.5),
        -1.401298464324817e-45,
        "copysign(1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, 0.5),
        1.401298464324817e-45,
        "copysign(1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, -1.0),
        -1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, 1.0),
        1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, -1.0),
        -1.401298464324817e-45,
        "copysign(1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, 1.0),
        1.401298464324817e-45,
        "copysign(1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, -6.2831854820251465),
        -1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, 6.2831854820251465),
        1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, -6.2831854820251465),
        -1.401298464324817e-45,
        "copysign(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, 6.2831854820251465),
        1.401298464324817e-45,
        "copysign(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        -1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        -1.401298464324817e-45,
        "copysign(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        1.401298464324817e-45,
        "copysign(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, -INFINITY),
        -1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.401298464324817e-45, INFINITY),
        1.401298464324817e-45,
        "copysign(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, -INFINITY),
        -1.401298464324817e-45,
        "copysign(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.401298464324817e-45, INFINITY),
        1.401298464324817e-45,
        "copysign(1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, -0.0),
        -1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, 0.0),
        1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, -0.0),
        -1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, 0.0),
        1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        -1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        -1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, -0.5),
        -1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, 0.5),
        1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, -0.5),
        -1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, 0.5),
        1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, -1.0),
        -1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, 1.0),
        1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, -1.0),
        -1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, 1.0),
        1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        -1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        -1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        -1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        -1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, -INFINITY),
        -1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.1754943508222875e-38, INFINITY),
        1.1754943508222875e-38,
        "copysign(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, -INFINITY),
        -1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.1754943508222875e-38, INFINITY),
        1.1754943508222875e-38,
        "copysign(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, -0.0),
        -0.5,
        "copysign(-0.5, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, 0.0),
        0.5,
        "copysign(-0.5, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, -0.0),
        -0.5,
        "copysign(0.5, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, 0.0),
        0.5,
        "copysign(0.5, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, -1.401298464324817e-45),
        -0.5,
        "copysign(-0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, 1.401298464324817e-45),
        0.5,
        "copysign(-0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, -1.401298464324817e-45),
        -0.5,
        "copysign(0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, 1.401298464324817e-45),
        0.5,
        "copysign(0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, -1.1754943508222875e-38),
        -0.5,
        "copysign(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, 1.1754943508222875e-38),
        0.5,
        "copysign(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, -1.1754943508222875e-38),
        -0.5,
        "copysign(0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, 1.1754943508222875e-38),
        0.5,
        "copysign(0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, -0.5),
        -0.5,
        "copysign(-0.5, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, 0.5),
        0.5,
        "copysign(-0.5, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, -0.5),
        -0.5,
        "copysign(0.5, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, 0.5),
        0.5,
        "copysign(0.5, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, -1.0),
        -0.5,
        "copysign(-0.5, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, 1.0),
        0.5,
        "copysign(-0.5, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, -1.0),
        -0.5,
        "copysign(0.5, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, 1.0),
        0.5,
        "copysign(0.5, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, -6.2831854820251465),
        -0.5,
        "copysign(-0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, 6.2831854820251465),
        0.5,
        "copysign(-0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, -6.2831854820251465),
        -0.5,
        "copysign(0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, 6.2831854820251465),
        0.5,
        "copysign(0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, -3.4028234663852886e+38),
        -0.5,
        "copysign(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, 3.4028234663852886e+38),
        0.5,
        "copysign(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, -3.4028234663852886e+38),
        -0.5,
        "copysign(0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, 3.4028234663852886e+38),
        0.5,
        "copysign(0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, -INFINITY),
        -0.5,
        "copysign(-0.5, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -0.5, INFINITY),
        0.5,
        "copysign(-0.5, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, -INFINITY),
        -0.5,
        "copysign(0.5, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 0.5, INFINITY),
        0.5,
        "copysign(0.5, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, -0.0),
        -1.0,
        "copysign(-1.0, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, 0.0),
        1.0,
        "copysign(-1.0, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, -0.0),
        -1.0,
        "copysign(1.0, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, 0.0),
        1.0,
        "copysign(1.0, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, -1.401298464324817e-45),
        -1.0,
        "copysign(-1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, 1.401298464324817e-45),
        1.0,
        "copysign(-1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, -1.401298464324817e-45),
        -1.0,
        "copysign(1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, 1.401298464324817e-45),
        1.0,
        "copysign(1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, -1.1754943508222875e-38),
        -1.0,
        "copysign(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, 1.1754943508222875e-38),
        1.0,
        "copysign(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, -1.1754943508222875e-38),
        -1.0,
        "copysign(1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, 1.1754943508222875e-38),
        1.0,
        "copysign(1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, -0.5),
        -1.0,
        "copysign(-1.0, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, 0.5),
        1.0,
        "copysign(-1.0, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, -0.5),
        -1.0,
        "copysign(1.0, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, 0.5),
        1.0,
        "copysign(1.0, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, -1.0),
        -1.0,
        "copysign(-1.0, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, 1.0),
        1.0,
        "copysign(-1.0, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, -1.0),
        -1.0,
        "copysign(1.0, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, 1.0),
        1.0,
        "copysign(1.0, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, -6.2831854820251465),
        -1.0,
        "copysign(-1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, 6.2831854820251465),
        1.0,
        "copysign(-1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, -6.2831854820251465),
        -1.0,
        "copysign(1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, 6.2831854820251465),
        1.0,
        "copysign(1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, -3.4028234663852886e+38),
        -1.0,
        "copysign(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, 3.4028234663852886e+38),
        1.0,
        "copysign(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, -3.4028234663852886e+38),
        -1.0,
        "copysign(1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, 3.4028234663852886e+38),
        1.0,
        "copysign(1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, -INFINITY),
        -1.0,
        "copysign(-1.0, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -1.0, INFINITY),
        1.0,
        "copysign(-1.0, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, -INFINITY),
        -1.0,
        "copysign(1.0, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 1.0, INFINITY),
        1.0,
        "copysign(1.0, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, -0.0),
        -6.2831854820251465,
        "copysign(-6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, 0.0),
        6.2831854820251465,
        "copysign(-6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, -0.0),
        -6.2831854820251465,
        "copysign(6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, 0.0),
        6.2831854820251465,
        "copysign(6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, -1.401298464324817e-45),
        -6.2831854820251465,
        "copysign(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, 1.401298464324817e-45),
        6.2831854820251465,
        "copysign(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, -1.401298464324817e-45),
        -6.2831854820251465,
        "copysign(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, 1.401298464324817e-45),
        6.2831854820251465,
        "copysign(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        -6.2831854820251465,
        "copysign(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        6.2831854820251465,
        "copysign(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        -6.2831854820251465,
        "copysign(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        6.2831854820251465,
        "copysign(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, -0.5),
        -6.2831854820251465,
        "copysign(-6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, 0.5),
        6.2831854820251465,
        "copysign(-6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, -0.5),
        -6.2831854820251465,
        "copysign(6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, 0.5),
        6.2831854820251465,
        "copysign(6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, -1.0),
        -6.2831854820251465,
        "copysign(-6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, 1.0),
        6.2831854820251465,
        "copysign(-6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, -1.0),
        -6.2831854820251465,
        "copysign(6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, 1.0),
        6.2831854820251465,
        "copysign(6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, -6.2831854820251465),
        -6.2831854820251465,
        "copysign(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, 6.2831854820251465),
        6.2831854820251465,
        "copysign(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, -6.2831854820251465),
        -6.2831854820251465,
        "copysign(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, 6.2831854820251465),
        6.2831854820251465,
        "copysign(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        -6.2831854820251465,
        "copysign(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        6.2831854820251465,
        "copysign(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        -6.2831854820251465,
        "copysign(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        6.2831854820251465,
        "copysign(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, -INFINITY),
        -6.2831854820251465,
        "copysign(-6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -6.2831854820251465, INFINITY),
        6.2831854820251465,
        "copysign(-6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, -INFINITY),
        -6.2831854820251465,
        "copysign(6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 6.2831854820251465, INFINITY),
        6.2831854820251465,
        "copysign(6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, -0.0),
        -3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, 0.0),
        3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, -0.0),
        -3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, 0.0),
        3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        -3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        -3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        -3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        -3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, -0.5),
        -3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, 0.5),
        3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, -0.5),
        -3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, 0.5),
        3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, -1.0),
        -3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, 1.0),
        3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, -1.0),
        -3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, 1.0),
        3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        -3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        -3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, -INFINITY),
        -3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -3.4028234663852886e+38, INFINITY),
        3.4028234663852886e+38,
        "copysign(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, -INFINITY),
        -3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, 3.4028234663852886e+38, INFINITY),
        3.4028234663852886e+38,
        "copysign(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, -0.0),
        -INFINITY,
        "copysign(-INFINITY, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, 0.0),
        INFINITY,
        "copysign(-INFINITY, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, -0.0),
        -INFINITY,
        "copysign(INFINITY, -0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, 0.0),
        INFINITY,
        "copysign(INFINITY, 0.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, -1.401298464324817e-45),
        -INFINITY,
        "copysign(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, 1.401298464324817e-45),
        INFINITY,
        "copysign(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, -1.401298464324817e-45),
        -INFINITY,
        "copysign(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, 1.401298464324817e-45),
        INFINITY,
        "copysign(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, -1.1754943508222875e-38),
        -INFINITY,
        "copysign(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, 1.1754943508222875e-38),
        INFINITY,
        "copysign(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, -1.1754943508222875e-38),
        -INFINITY,
        "copysign(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, 1.1754943508222875e-38),
        INFINITY,
        "copysign(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, -0.5),
        -INFINITY,
        "copysign(-INFINITY, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, 0.5),
        INFINITY,
        "copysign(-INFINITY, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, -0.5),
        -INFINITY,
        "copysign(INFINITY, -0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, 0.5),
        INFINITY,
        "copysign(INFINITY, 0.5)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, -1.0),
        -INFINITY,
        "copysign(-INFINITY, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, 1.0),
        INFINITY,
        "copysign(-INFINITY, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, -1.0),
        -INFINITY,
        "copysign(INFINITY, -1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, 1.0),
        INFINITY,
        "copysign(INFINITY, 1.0)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, -6.2831854820251465),
        -INFINITY,
        "copysign(-INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, 6.2831854820251465),
        INFINITY,
        "copysign(-INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, -6.2831854820251465),
        -INFINITY,
        "copysign(INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, 6.2831854820251465),
        INFINITY,
        "copysign(INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, -3.4028234663852886e+38),
        -INFINITY,
        "copysign(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, 3.4028234663852886e+38),
        INFINITY,
        "copysign(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, -3.4028234663852886e+38),
        -INFINITY,
        "copysign(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, 3.4028234663852886e+38),
        INFINITY,
        "copysign(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, -INFINITY),
        -INFINITY,
        "copysign(-INFINITY, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, -INFINITY, INFINITY),
        INFINITY,
        "copysign(-INFINITY, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, -INFINITY),
        -INFINITY,
        "copysign(INFINITY, -INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_copysign(&instance, INFINITY, INFINITY),
        INFINITY,
        "copysign(INFINITY, INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, -0.0),
        0.0,
        "abs(-0.0)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, 0.0),
        0.0,
        "abs(0.0)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, -1.401298464324817e-45),
        1.401298464324817e-45,
        "abs(-1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, 1.401298464324817e-45),
        1.401298464324817e-45,
        "abs(1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, -1.1754943508222875e-38),
        1.1754943508222875e-38,
        "abs(-1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "abs(1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, -0.5),
        0.5,
        "abs(-0.5)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, 0.5),
        0.5,
        "abs(0.5)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, -1.0),
        1.0,
        "abs(-1.0)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, 1.0),
        1.0,
        "abs(1.0)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, -6.2831854820251465),
        6.2831854820251465,
        "abs(-6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, 6.2831854820251465),
        6.2831854820251465,
        "abs(6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "abs(-3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "abs(3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, -INFINITY),
        INFINITY,
        "abs(-INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_abs(&instance, INFINITY),
        INFINITY,
        "abs(INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, -0.0),
        0.0,
        "neg(-0.0)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, 0.0),
        -0.0,
        "neg(0.0)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, -1.401298464324817e-45),
        1.401298464324817e-45,
        "neg(-1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, 1.401298464324817e-45),
        -1.401298464324817e-45,
        "neg(1.401298464324817e-45)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, -1.1754943508222875e-38),
        1.1754943508222875e-38,
        "neg(-1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, 1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "neg(1.1754943508222875e-38)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, -0.5),
        0.5,
        "neg(-0.5)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, 0.5),
        -0.5,
        "neg(0.5)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, -1.0),
        1.0,
        "neg(-1.0)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, 1.0),
        -1.0,
        "neg(1.0)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, -6.2831854820251465),
        6.2831854820251465,
        "neg(-6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, 6.2831854820251465),
        -6.2831854820251465,
        "neg(6.2831854820251465)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "neg(-3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "neg(3.4028234663852886e+38)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, -INFINITY),
        INFINITY,
        "neg(-INFINITY)"
    );
    assertEqualF32(
        f32bitwise0_neg(&instance, INFINITY),
        -INFINITY,
        "neg(INFINITY)"
    );
}
