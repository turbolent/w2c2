
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_f32_cmp.0.h"

void test() {
    f32cmp0Instance instance;
    f32cmp0Instantiate(&instance, resolveTestImports);
    printStart("f32_cmp.0.wasm");
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, -0.0),
        1u,
        "eq(-0.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, 0.0),
        1u,
        "eq(-0.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, -0.0),
        1u,
        "eq(0.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, 0.0),
        1u,
        "eq(0.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, -1.401298464324817e-45),
        0u,
        "eq(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, 1.401298464324817e-45),
        0u,
        "eq(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, -1.401298464324817e-45),
        0u,
        "eq(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, 1.401298464324817e-45),
        0u,
        "eq(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, -1.1754943508222875e-38),
        0u,
        "eq(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, 1.1754943508222875e-38),
        0u,
        "eq(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, -1.1754943508222875e-38),
        0u,
        "eq(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, 1.1754943508222875e-38),
        0u,
        "eq(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, -0.5),
        0u,
        "eq(-0.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, 0.5),
        0u,
        "eq(-0.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, -0.5),
        0u,
        "eq(0.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, 0.5),
        0u,
        "eq(0.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, -1.0),
        0u,
        "eq(-0.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, 1.0),
        0u,
        "eq(-0.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, -1.0),
        0u,
        "eq(0.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, 1.0),
        0u,
        "eq(0.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, -6.2831854820251465),
        0u,
        "eq(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, 6.2831854820251465),
        0u,
        "eq(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, -6.2831854820251465),
        0u,
        "eq(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, 6.2831854820251465),
        0u,
        "eq(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, -3.4028234663852886e+38),
        0u,
        "eq(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, 3.4028234663852886e+38),
        0u,
        "eq(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, -3.4028234663852886e+38),
        0u,
        "eq(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, 3.4028234663852886e+38),
        0u,
        "eq(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, -INFINITY),
        0u,
        "eq(-0.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.0, INFINITY),
        0u,
        "eq(-0.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, -INFINITY),
        0u,
        "eq(0.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.0, INFINITY),
        0u,
        "eq(0.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, -0.0),
        0u,
        "eq(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, 0.0),
        0u,
        "eq(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, -0.0),
        0u,
        "eq(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, 0.0),
        0u,
        "eq(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        1u,
        "eq(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        0u,
        "eq(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        0u,
        "eq(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        1u,
        "eq(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        0u,
        "eq(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        0u,
        "eq(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        0u,
        "eq(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        0u,
        "eq(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, -0.5),
        0u,
        "eq(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, 0.5),
        0u,
        "eq(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, -0.5),
        0u,
        "eq(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, 0.5),
        0u,
        "eq(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, -1.0),
        0u,
        "eq(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, 1.0),
        0u,
        "eq(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, -1.0),
        0u,
        "eq(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, 1.0),
        0u,
        "eq(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, -6.2831854820251465),
        0u,
        "eq(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, 6.2831854820251465),
        0u,
        "eq(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, -6.2831854820251465),
        0u,
        "eq(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, 6.2831854820251465),
        0u,
        "eq(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        0u,
        "eq(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        0u,
        "eq(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        0u,
        "eq(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        0u,
        "eq(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, -INFINITY),
        0u,
        "eq(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.401298464324817e-45, INFINITY),
        0u,
        "eq(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, -INFINITY),
        0u,
        "eq(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.401298464324817e-45, INFINITY),
        0u,
        "eq(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, -0.0),
        0u,
        "eq(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, 0.0),
        0u,
        "eq(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, -0.0),
        0u,
        "eq(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, 0.0),
        0u,
        "eq(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        0u,
        "eq(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        0u,
        "eq(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        0u,
        "eq(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        0u,
        "eq(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        1u,
        "eq(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        0u,
        "eq(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        0u,
        "eq(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        1u,
        "eq(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, -0.5),
        0u,
        "eq(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, 0.5),
        0u,
        "eq(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, -0.5),
        0u,
        "eq(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, 0.5),
        0u,
        "eq(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, -1.0),
        0u,
        "eq(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, 1.0),
        0u,
        "eq(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, -1.0),
        0u,
        "eq(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, 1.0),
        0u,
        "eq(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        0u,
        "eq(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        0u,
        "eq(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        0u,
        "eq(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        0u,
        "eq(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        0u,
        "eq(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        0u,
        "eq(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        0u,
        "eq(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        0u,
        "eq(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, -INFINITY),
        0u,
        "eq(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.1754943508222875e-38, INFINITY),
        0u,
        "eq(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, -INFINITY),
        0u,
        "eq(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.1754943508222875e-38, INFINITY),
        0u,
        "eq(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, -0.0),
        0u,
        "eq(-0.5, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, 0.0),
        0u,
        "eq(-0.5, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, -0.0),
        0u,
        "eq(0.5, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, 0.0),
        0u,
        "eq(0.5, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, -1.401298464324817e-45),
        0u,
        "eq(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, 1.401298464324817e-45),
        0u,
        "eq(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, -1.401298464324817e-45),
        0u,
        "eq(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, 1.401298464324817e-45),
        0u,
        "eq(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, -1.1754943508222875e-38),
        0u,
        "eq(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, 1.1754943508222875e-38),
        0u,
        "eq(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, -1.1754943508222875e-38),
        0u,
        "eq(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, 1.1754943508222875e-38),
        0u,
        "eq(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, -0.5),
        1u,
        "eq(-0.5, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, 0.5),
        0u,
        "eq(-0.5, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, -0.5),
        0u,
        "eq(0.5, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, 0.5),
        1u,
        "eq(0.5, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, -1.0),
        0u,
        "eq(-0.5, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, 1.0),
        0u,
        "eq(-0.5, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, -1.0),
        0u,
        "eq(0.5, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, 1.0),
        0u,
        "eq(0.5, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, -6.2831854820251465),
        0u,
        "eq(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, 6.2831854820251465),
        0u,
        "eq(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, -6.2831854820251465),
        0u,
        "eq(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, 6.2831854820251465),
        0u,
        "eq(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, -3.4028234663852886e+38),
        0u,
        "eq(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, 3.4028234663852886e+38),
        0u,
        "eq(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, -3.4028234663852886e+38),
        0u,
        "eq(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, 3.4028234663852886e+38),
        0u,
        "eq(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, -INFINITY),
        0u,
        "eq(-0.5, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -0.5, INFINITY),
        0u,
        "eq(-0.5, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, -INFINITY),
        0u,
        "eq(0.5, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 0.5, INFINITY),
        0u,
        "eq(0.5, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, -0.0),
        0u,
        "eq(-1.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, 0.0),
        0u,
        "eq(-1.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, -0.0),
        0u,
        "eq(1.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, 0.0),
        0u,
        "eq(1.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, -1.401298464324817e-45),
        0u,
        "eq(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, 1.401298464324817e-45),
        0u,
        "eq(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, -1.401298464324817e-45),
        0u,
        "eq(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, 1.401298464324817e-45),
        0u,
        "eq(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, -1.1754943508222875e-38),
        0u,
        "eq(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, 1.1754943508222875e-38),
        0u,
        "eq(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, -1.1754943508222875e-38),
        0u,
        "eq(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, 1.1754943508222875e-38),
        0u,
        "eq(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, -0.5),
        0u,
        "eq(-1.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, 0.5),
        0u,
        "eq(-1.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, -0.5),
        0u,
        "eq(1.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, 0.5),
        0u,
        "eq(1.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, -1.0),
        1u,
        "eq(-1.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, 1.0),
        0u,
        "eq(-1.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, -1.0),
        0u,
        "eq(1.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, 1.0),
        1u,
        "eq(1.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, -6.2831854820251465),
        0u,
        "eq(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, 6.2831854820251465),
        0u,
        "eq(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, -6.2831854820251465),
        0u,
        "eq(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, 6.2831854820251465),
        0u,
        "eq(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, -3.4028234663852886e+38),
        0u,
        "eq(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, 3.4028234663852886e+38),
        0u,
        "eq(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, -3.4028234663852886e+38),
        0u,
        "eq(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, 3.4028234663852886e+38),
        0u,
        "eq(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, -INFINITY),
        0u,
        "eq(-1.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -1.0, INFINITY),
        0u,
        "eq(-1.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, -INFINITY),
        0u,
        "eq(1.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 1.0, INFINITY),
        0u,
        "eq(1.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, -0.0),
        0u,
        "eq(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, 0.0),
        0u,
        "eq(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, -0.0),
        0u,
        "eq(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, 0.0),
        0u,
        "eq(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, -1.401298464324817e-45),
        0u,
        "eq(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, 1.401298464324817e-45),
        0u,
        "eq(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, -1.401298464324817e-45),
        0u,
        "eq(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, 1.401298464324817e-45),
        0u,
        "eq(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        0u,
        "eq(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        0u,
        "eq(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        0u,
        "eq(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        0u,
        "eq(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, -0.5),
        0u,
        "eq(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, 0.5),
        0u,
        "eq(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, -0.5),
        0u,
        "eq(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, 0.5),
        0u,
        "eq(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, -1.0),
        0u,
        "eq(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, 1.0),
        0u,
        "eq(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, -1.0),
        0u,
        "eq(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, 1.0),
        0u,
        "eq(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, -6.2831854820251465),
        1u,
        "eq(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, 6.2831854820251465),
        0u,
        "eq(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, -6.2831854820251465),
        0u,
        "eq(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, 6.2831854820251465),
        1u,
        "eq(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        0u,
        "eq(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        0u,
        "eq(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        0u,
        "eq(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        0u,
        "eq(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, -INFINITY),
        0u,
        "eq(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -6.2831854820251465, INFINITY),
        0u,
        "eq(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, -INFINITY),
        0u,
        "eq(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 6.2831854820251465, INFINITY),
        0u,
        "eq(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, -0.0),
        0u,
        "eq(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, 0.0),
        0u,
        "eq(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, -0.0),
        0u,
        "eq(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, 0.0),
        0u,
        "eq(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        0u,
        "eq(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        0u,
        "eq(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        0u,
        "eq(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        0u,
        "eq(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        0u,
        "eq(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        0u,
        "eq(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        0u,
        "eq(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        0u,
        "eq(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, -0.5),
        0u,
        "eq(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, 0.5),
        0u,
        "eq(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, -0.5),
        0u,
        "eq(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, 0.5),
        0u,
        "eq(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, -1.0),
        0u,
        "eq(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, 1.0),
        0u,
        "eq(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, -1.0),
        0u,
        "eq(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, 1.0),
        0u,
        "eq(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        0u,
        "eq(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        0u,
        "eq(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        0u,
        "eq(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        0u,
        "eq(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        1u,
        "eq(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        0u,
        "eq(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        0u,
        "eq(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        1u,
        "eq(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, -INFINITY),
        0u,
        "eq(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -3.4028234663852886e+38, INFINITY),
        0u,
        "eq(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, -INFINITY),
        0u,
        "eq(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, 3.4028234663852886e+38, INFINITY),
        0u,
        "eq(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, -0.0),
        0u,
        "eq(-INFINITY, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, 0.0),
        0u,
        "eq(-INFINITY, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, -0.0),
        0u,
        "eq(INFINITY, -0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, 0.0),
        0u,
        "eq(INFINITY, 0.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, -1.401298464324817e-45),
        0u,
        "eq(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, 1.401298464324817e-45),
        0u,
        "eq(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, -1.401298464324817e-45),
        0u,
        "eq(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, 1.401298464324817e-45),
        0u,
        "eq(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, -1.1754943508222875e-38),
        0u,
        "eq(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, 1.1754943508222875e-38),
        0u,
        "eq(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, -1.1754943508222875e-38),
        0u,
        "eq(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, 1.1754943508222875e-38),
        0u,
        "eq(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, -0.5),
        0u,
        "eq(-INFINITY, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, 0.5),
        0u,
        "eq(-INFINITY, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, -0.5),
        0u,
        "eq(INFINITY, -0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, 0.5),
        0u,
        "eq(INFINITY, 0.5)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, -1.0),
        0u,
        "eq(-INFINITY, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, 1.0),
        0u,
        "eq(-INFINITY, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, -1.0),
        0u,
        "eq(INFINITY, -1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, 1.0),
        0u,
        "eq(INFINITY, 1.0)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, -6.2831854820251465),
        0u,
        "eq(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, 6.2831854820251465),
        0u,
        "eq(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, -6.2831854820251465),
        0u,
        "eq(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, 6.2831854820251465),
        0u,
        "eq(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, -3.4028234663852886e+38),
        0u,
        "eq(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, 3.4028234663852886e+38),
        0u,
        "eq(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, -3.4028234663852886e+38),
        0u,
        "eq(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, 3.4028234663852886e+38),
        0u,
        "eq(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, -INFINITY),
        1u,
        "eq(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, -INFINITY, INFINITY),
        0u,
        "eq(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, -INFINITY),
        0u,
        "eq(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_eq(&instance, INFINITY, INFINITY),
        1u,
        "eq(INFINITY, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, -0.0),
        0u,
        "ne(-0.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, 0.0),
        0u,
        "ne(-0.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, -0.0),
        0u,
        "ne(0.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, 0.0),
        0u,
        "ne(0.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, -1.401298464324817e-45),
        1u,
        "ne(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, 1.401298464324817e-45),
        1u,
        "ne(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, -1.401298464324817e-45),
        1u,
        "ne(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, 1.401298464324817e-45),
        1u,
        "ne(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, -1.1754943508222875e-38),
        1u,
        "ne(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, 1.1754943508222875e-38),
        1u,
        "ne(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, -1.1754943508222875e-38),
        1u,
        "ne(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, 1.1754943508222875e-38),
        1u,
        "ne(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, -0.5),
        1u,
        "ne(-0.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, 0.5),
        1u,
        "ne(-0.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, -0.5),
        1u,
        "ne(0.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, 0.5),
        1u,
        "ne(0.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, -1.0),
        1u,
        "ne(-0.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, 1.0),
        1u,
        "ne(-0.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, -1.0),
        1u,
        "ne(0.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, 1.0),
        1u,
        "ne(0.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, -6.2831854820251465),
        1u,
        "ne(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, 6.2831854820251465),
        1u,
        "ne(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, -6.2831854820251465),
        1u,
        "ne(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, 6.2831854820251465),
        1u,
        "ne(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, -3.4028234663852886e+38),
        1u,
        "ne(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, 3.4028234663852886e+38),
        1u,
        "ne(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, -3.4028234663852886e+38),
        1u,
        "ne(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, 3.4028234663852886e+38),
        1u,
        "ne(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, -INFINITY),
        1u,
        "ne(-0.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.0, INFINITY),
        1u,
        "ne(-0.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, -INFINITY),
        1u,
        "ne(0.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.0, INFINITY),
        1u,
        "ne(0.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, -0.0),
        1u,
        "ne(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, 0.0),
        1u,
        "ne(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, -0.0),
        1u,
        "ne(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, 0.0),
        1u,
        "ne(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        0u,
        "ne(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        1u,
        "ne(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        1u,
        "ne(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        0u,
        "ne(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        1u,
        "ne(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        1u,
        "ne(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        1u,
        "ne(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        1u,
        "ne(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, -0.5),
        1u,
        "ne(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, 0.5),
        1u,
        "ne(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, -0.5),
        1u,
        "ne(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, 0.5),
        1u,
        "ne(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, -1.0),
        1u,
        "ne(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, 1.0),
        1u,
        "ne(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, -1.0),
        1u,
        "ne(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, 1.0),
        1u,
        "ne(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, -6.2831854820251465),
        1u,
        "ne(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, 6.2831854820251465),
        1u,
        "ne(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, -6.2831854820251465),
        1u,
        "ne(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, 6.2831854820251465),
        1u,
        "ne(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        1u,
        "ne(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        1u,
        "ne(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        1u,
        "ne(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        1u,
        "ne(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, -INFINITY),
        1u,
        "ne(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.401298464324817e-45, INFINITY),
        1u,
        "ne(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, -INFINITY),
        1u,
        "ne(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.401298464324817e-45, INFINITY),
        1u,
        "ne(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, -0.0),
        1u,
        "ne(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, 0.0),
        1u,
        "ne(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, -0.0),
        1u,
        "ne(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, 0.0),
        1u,
        "ne(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        1u,
        "ne(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        1u,
        "ne(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        1u,
        "ne(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        1u,
        "ne(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        0u,
        "ne(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        1u,
        "ne(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        1u,
        "ne(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        0u,
        "ne(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, -0.5),
        1u,
        "ne(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, 0.5),
        1u,
        "ne(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, -0.5),
        1u,
        "ne(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, 0.5),
        1u,
        "ne(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, -1.0),
        1u,
        "ne(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, 1.0),
        1u,
        "ne(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, -1.0),
        1u,
        "ne(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, 1.0),
        1u,
        "ne(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        1u,
        "ne(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        1u,
        "ne(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        1u,
        "ne(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        1u,
        "ne(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        1u,
        "ne(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        1u,
        "ne(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        1u,
        "ne(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        1u,
        "ne(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, -INFINITY),
        1u,
        "ne(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.1754943508222875e-38, INFINITY),
        1u,
        "ne(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, -INFINITY),
        1u,
        "ne(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.1754943508222875e-38, INFINITY),
        1u,
        "ne(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, -0.0),
        1u,
        "ne(-0.5, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, 0.0),
        1u,
        "ne(-0.5, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, -0.0),
        1u,
        "ne(0.5, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, 0.0),
        1u,
        "ne(0.5, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, -1.401298464324817e-45),
        1u,
        "ne(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, 1.401298464324817e-45),
        1u,
        "ne(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, -1.401298464324817e-45),
        1u,
        "ne(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, 1.401298464324817e-45),
        1u,
        "ne(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, -1.1754943508222875e-38),
        1u,
        "ne(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, 1.1754943508222875e-38),
        1u,
        "ne(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, -1.1754943508222875e-38),
        1u,
        "ne(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, 1.1754943508222875e-38),
        1u,
        "ne(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, -0.5),
        0u,
        "ne(-0.5, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, 0.5),
        1u,
        "ne(-0.5, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, -0.5),
        1u,
        "ne(0.5, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, 0.5),
        0u,
        "ne(0.5, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, -1.0),
        1u,
        "ne(-0.5, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, 1.0),
        1u,
        "ne(-0.5, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, -1.0),
        1u,
        "ne(0.5, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, 1.0),
        1u,
        "ne(0.5, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, -6.2831854820251465),
        1u,
        "ne(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, 6.2831854820251465),
        1u,
        "ne(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, -6.2831854820251465),
        1u,
        "ne(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, 6.2831854820251465),
        1u,
        "ne(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, -3.4028234663852886e+38),
        1u,
        "ne(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, 3.4028234663852886e+38),
        1u,
        "ne(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, -3.4028234663852886e+38),
        1u,
        "ne(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, 3.4028234663852886e+38),
        1u,
        "ne(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, -INFINITY),
        1u,
        "ne(-0.5, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -0.5, INFINITY),
        1u,
        "ne(-0.5, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, -INFINITY),
        1u,
        "ne(0.5, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 0.5, INFINITY),
        1u,
        "ne(0.5, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, -0.0),
        1u,
        "ne(-1.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, 0.0),
        1u,
        "ne(-1.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, -0.0),
        1u,
        "ne(1.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, 0.0),
        1u,
        "ne(1.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, -1.401298464324817e-45),
        1u,
        "ne(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, 1.401298464324817e-45),
        1u,
        "ne(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, -1.401298464324817e-45),
        1u,
        "ne(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, 1.401298464324817e-45),
        1u,
        "ne(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, -1.1754943508222875e-38),
        1u,
        "ne(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, 1.1754943508222875e-38),
        1u,
        "ne(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, -1.1754943508222875e-38),
        1u,
        "ne(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, 1.1754943508222875e-38),
        1u,
        "ne(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, -0.5),
        1u,
        "ne(-1.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, 0.5),
        1u,
        "ne(-1.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, -0.5),
        1u,
        "ne(1.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, 0.5),
        1u,
        "ne(1.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, -1.0),
        0u,
        "ne(-1.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, 1.0),
        1u,
        "ne(-1.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, -1.0),
        1u,
        "ne(1.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, 1.0),
        0u,
        "ne(1.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, -6.2831854820251465),
        1u,
        "ne(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, 6.2831854820251465),
        1u,
        "ne(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, -6.2831854820251465),
        1u,
        "ne(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, 6.2831854820251465),
        1u,
        "ne(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, -3.4028234663852886e+38),
        1u,
        "ne(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, 3.4028234663852886e+38),
        1u,
        "ne(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, -3.4028234663852886e+38),
        1u,
        "ne(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, 3.4028234663852886e+38),
        1u,
        "ne(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, -INFINITY),
        1u,
        "ne(-1.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -1.0, INFINITY),
        1u,
        "ne(-1.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, -INFINITY),
        1u,
        "ne(1.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 1.0, INFINITY),
        1u,
        "ne(1.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, -0.0),
        1u,
        "ne(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, 0.0),
        1u,
        "ne(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, -0.0),
        1u,
        "ne(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, 0.0),
        1u,
        "ne(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, -1.401298464324817e-45),
        1u,
        "ne(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, 1.401298464324817e-45),
        1u,
        "ne(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, -1.401298464324817e-45),
        1u,
        "ne(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, 1.401298464324817e-45),
        1u,
        "ne(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        1u,
        "ne(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        1u,
        "ne(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        1u,
        "ne(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        1u,
        "ne(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, -0.5),
        1u,
        "ne(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, 0.5),
        1u,
        "ne(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, -0.5),
        1u,
        "ne(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, 0.5),
        1u,
        "ne(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, -1.0),
        1u,
        "ne(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, 1.0),
        1u,
        "ne(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, -1.0),
        1u,
        "ne(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, 1.0),
        1u,
        "ne(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, -6.2831854820251465),
        0u,
        "ne(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, 6.2831854820251465),
        1u,
        "ne(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, -6.2831854820251465),
        1u,
        "ne(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, 6.2831854820251465),
        0u,
        "ne(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        1u,
        "ne(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        1u,
        "ne(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        1u,
        "ne(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        1u,
        "ne(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, -INFINITY),
        1u,
        "ne(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -6.2831854820251465, INFINITY),
        1u,
        "ne(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, -INFINITY),
        1u,
        "ne(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 6.2831854820251465, INFINITY),
        1u,
        "ne(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, -0.0),
        1u,
        "ne(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, 0.0),
        1u,
        "ne(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, -0.0),
        1u,
        "ne(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, 0.0),
        1u,
        "ne(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        1u,
        "ne(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        1u,
        "ne(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        1u,
        "ne(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        1u,
        "ne(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        1u,
        "ne(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        1u,
        "ne(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        1u,
        "ne(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        1u,
        "ne(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, -0.5),
        1u,
        "ne(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, 0.5),
        1u,
        "ne(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, -0.5),
        1u,
        "ne(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, 0.5),
        1u,
        "ne(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, -1.0),
        1u,
        "ne(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, 1.0),
        1u,
        "ne(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, -1.0),
        1u,
        "ne(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, 1.0),
        1u,
        "ne(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        1u,
        "ne(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        1u,
        "ne(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        1u,
        "ne(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        1u,
        "ne(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        0u,
        "ne(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        1u,
        "ne(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        1u,
        "ne(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        0u,
        "ne(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, -INFINITY),
        1u,
        "ne(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -3.4028234663852886e+38, INFINITY),
        1u,
        "ne(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, -INFINITY),
        1u,
        "ne(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, 3.4028234663852886e+38, INFINITY),
        1u,
        "ne(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, -0.0),
        1u,
        "ne(-INFINITY, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, 0.0),
        1u,
        "ne(-INFINITY, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, -0.0),
        1u,
        "ne(INFINITY, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, 0.0),
        1u,
        "ne(INFINITY, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, -1.401298464324817e-45),
        1u,
        "ne(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, 1.401298464324817e-45),
        1u,
        "ne(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, -1.401298464324817e-45),
        1u,
        "ne(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, 1.401298464324817e-45),
        1u,
        "ne(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, -1.1754943508222875e-38),
        1u,
        "ne(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, 1.1754943508222875e-38),
        1u,
        "ne(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, -1.1754943508222875e-38),
        1u,
        "ne(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, 1.1754943508222875e-38),
        1u,
        "ne(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, -0.5),
        1u,
        "ne(-INFINITY, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, 0.5),
        1u,
        "ne(-INFINITY, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, -0.5),
        1u,
        "ne(INFINITY, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, 0.5),
        1u,
        "ne(INFINITY, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, -1.0),
        1u,
        "ne(-INFINITY, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, 1.0),
        1u,
        "ne(-INFINITY, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, -1.0),
        1u,
        "ne(INFINITY, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, 1.0),
        1u,
        "ne(INFINITY, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, -6.2831854820251465),
        1u,
        "ne(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, 6.2831854820251465),
        1u,
        "ne(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, -6.2831854820251465),
        1u,
        "ne(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, 6.2831854820251465),
        1u,
        "ne(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, -3.4028234663852886e+38),
        1u,
        "ne(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, 3.4028234663852886e+38),
        1u,
        "ne(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, -3.4028234663852886e+38),
        1u,
        "ne(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, 3.4028234663852886e+38),
        1u,
        "ne(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, -INFINITY),
        0u,
        "ne(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, -INFINITY, INFINITY),
        1u,
        "ne(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, -INFINITY),
        1u,
        "ne(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ne(&instance, INFINITY, INFINITY),
        0u,
        "ne(INFINITY, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, -0.0),
        0u,
        "lt(-0.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, 0.0),
        0u,
        "lt(-0.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, -0.0),
        0u,
        "lt(0.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, 0.0),
        0u,
        "lt(0.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, -1.401298464324817e-45),
        0u,
        "lt(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, 1.401298464324817e-45),
        1u,
        "lt(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, -1.401298464324817e-45),
        0u,
        "lt(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, 1.401298464324817e-45),
        1u,
        "lt(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, -1.1754943508222875e-38),
        0u,
        "lt(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, 1.1754943508222875e-38),
        1u,
        "lt(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, -1.1754943508222875e-38),
        0u,
        "lt(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, 1.1754943508222875e-38),
        1u,
        "lt(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, -0.5),
        0u,
        "lt(-0.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, 0.5),
        1u,
        "lt(-0.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, -0.5),
        0u,
        "lt(0.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, 0.5),
        1u,
        "lt(0.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, -1.0),
        0u,
        "lt(-0.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, 1.0),
        1u,
        "lt(-0.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, -1.0),
        0u,
        "lt(0.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, 1.0),
        1u,
        "lt(0.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, -6.2831854820251465),
        0u,
        "lt(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, 6.2831854820251465),
        1u,
        "lt(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, -6.2831854820251465),
        0u,
        "lt(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, 6.2831854820251465),
        1u,
        "lt(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, -3.4028234663852886e+38),
        0u,
        "lt(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, 3.4028234663852886e+38),
        1u,
        "lt(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, -3.4028234663852886e+38),
        0u,
        "lt(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, 3.4028234663852886e+38),
        1u,
        "lt(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, -INFINITY),
        0u,
        "lt(-0.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.0, INFINITY),
        1u,
        "lt(-0.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, -INFINITY),
        0u,
        "lt(0.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.0, INFINITY),
        1u,
        "lt(0.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, -0.0),
        1u,
        "lt(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, 0.0),
        1u,
        "lt(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, -0.0),
        0u,
        "lt(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, 0.0),
        0u,
        "lt(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        0u,
        "lt(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        1u,
        "lt(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        0u,
        "lt(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        0u,
        "lt(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        0u,
        "lt(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        1u,
        "lt(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        0u,
        "lt(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        1u,
        "lt(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, -0.5),
        0u,
        "lt(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, 0.5),
        1u,
        "lt(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, -0.5),
        0u,
        "lt(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, 0.5),
        1u,
        "lt(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, -1.0),
        0u,
        "lt(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, 1.0),
        1u,
        "lt(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, -1.0),
        0u,
        "lt(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, 1.0),
        1u,
        "lt(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, -6.2831854820251465),
        0u,
        "lt(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, 6.2831854820251465),
        1u,
        "lt(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, -6.2831854820251465),
        0u,
        "lt(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, 6.2831854820251465),
        1u,
        "lt(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        0u,
        "lt(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        1u,
        "lt(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        0u,
        "lt(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        1u,
        "lt(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, -INFINITY),
        0u,
        "lt(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.401298464324817e-45, INFINITY),
        1u,
        "lt(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, -INFINITY),
        0u,
        "lt(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.401298464324817e-45, INFINITY),
        1u,
        "lt(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, -0.0),
        1u,
        "lt(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, 0.0),
        1u,
        "lt(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, -0.0),
        0u,
        "lt(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, 0.0),
        0u,
        "lt(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        1u,
        "lt(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        1u,
        "lt(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        0u,
        "lt(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        0u,
        "lt(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        0u,
        "lt(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        1u,
        "lt(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        0u,
        "lt(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        0u,
        "lt(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, -0.5),
        0u,
        "lt(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, 0.5),
        1u,
        "lt(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, -0.5),
        0u,
        "lt(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, 0.5),
        1u,
        "lt(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, -1.0),
        0u,
        "lt(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, 1.0),
        1u,
        "lt(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, -1.0),
        0u,
        "lt(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, 1.0),
        1u,
        "lt(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        0u,
        "lt(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        1u,
        "lt(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        0u,
        "lt(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        1u,
        "lt(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        0u,
        "lt(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        1u,
        "lt(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        0u,
        "lt(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        1u,
        "lt(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, -INFINITY),
        0u,
        "lt(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.1754943508222875e-38, INFINITY),
        1u,
        "lt(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, -INFINITY),
        0u,
        "lt(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.1754943508222875e-38, INFINITY),
        1u,
        "lt(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, -0.0),
        1u,
        "lt(-0.5, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, 0.0),
        1u,
        "lt(-0.5, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, -0.0),
        0u,
        "lt(0.5, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, 0.0),
        0u,
        "lt(0.5, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, -1.401298464324817e-45),
        1u,
        "lt(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, 1.401298464324817e-45),
        1u,
        "lt(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, -1.401298464324817e-45),
        0u,
        "lt(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, 1.401298464324817e-45),
        0u,
        "lt(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, -1.1754943508222875e-38),
        1u,
        "lt(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, 1.1754943508222875e-38),
        1u,
        "lt(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, -1.1754943508222875e-38),
        0u,
        "lt(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, 1.1754943508222875e-38),
        0u,
        "lt(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, -0.5),
        0u,
        "lt(-0.5, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, 0.5),
        1u,
        "lt(-0.5, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, -0.5),
        0u,
        "lt(0.5, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, 0.5),
        0u,
        "lt(0.5, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, -1.0),
        0u,
        "lt(-0.5, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, 1.0),
        1u,
        "lt(-0.5, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, -1.0),
        0u,
        "lt(0.5, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, 1.0),
        1u,
        "lt(0.5, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, -6.2831854820251465),
        0u,
        "lt(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, 6.2831854820251465),
        1u,
        "lt(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, -6.2831854820251465),
        0u,
        "lt(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, 6.2831854820251465),
        1u,
        "lt(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, -3.4028234663852886e+38),
        0u,
        "lt(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, 3.4028234663852886e+38),
        1u,
        "lt(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, -3.4028234663852886e+38),
        0u,
        "lt(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, 3.4028234663852886e+38),
        1u,
        "lt(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, -INFINITY),
        0u,
        "lt(-0.5, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -0.5, INFINITY),
        1u,
        "lt(-0.5, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, -INFINITY),
        0u,
        "lt(0.5, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 0.5, INFINITY),
        1u,
        "lt(0.5, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, -0.0),
        1u,
        "lt(-1.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, 0.0),
        1u,
        "lt(-1.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, -0.0),
        0u,
        "lt(1.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, 0.0),
        0u,
        "lt(1.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, -1.401298464324817e-45),
        1u,
        "lt(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, 1.401298464324817e-45),
        1u,
        "lt(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, -1.401298464324817e-45),
        0u,
        "lt(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, 1.401298464324817e-45),
        0u,
        "lt(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, -1.1754943508222875e-38),
        1u,
        "lt(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, 1.1754943508222875e-38),
        1u,
        "lt(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, -1.1754943508222875e-38),
        0u,
        "lt(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, 1.1754943508222875e-38),
        0u,
        "lt(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, -0.5),
        1u,
        "lt(-1.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, 0.5),
        1u,
        "lt(-1.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, -0.5),
        0u,
        "lt(1.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, 0.5),
        0u,
        "lt(1.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, -1.0),
        0u,
        "lt(-1.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, 1.0),
        1u,
        "lt(-1.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, -1.0),
        0u,
        "lt(1.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, 1.0),
        0u,
        "lt(1.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, -6.2831854820251465),
        0u,
        "lt(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, 6.2831854820251465),
        1u,
        "lt(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, -6.2831854820251465),
        0u,
        "lt(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, 6.2831854820251465),
        1u,
        "lt(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, -3.4028234663852886e+38),
        0u,
        "lt(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, 3.4028234663852886e+38),
        1u,
        "lt(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, -3.4028234663852886e+38),
        0u,
        "lt(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, 3.4028234663852886e+38),
        1u,
        "lt(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, -INFINITY),
        0u,
        "lt(-1.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -1.0, INFINITY),
        1u,
        "lt(-1.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, -INFINITY),
        0u,
        "lt(1.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 1.0, INFINITY),
        1u,
        "lt(1.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, -0.0),
        1u,
        "lt(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, 0.0),
        1u,
        "lt(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, -0.0),
        0u,
        "lt(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, 0.0),
        0u,
        "lt(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, -1.401298464324817e-45),
        1u,
        "lt(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, 1.401298464324817e-45),
        1u,
        "lt(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, -1.401298464324817e-45),
        0u,
        "lt(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, 1.401298464324817e-45),
        0u,
        "lt(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        1u,
        "lt(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        1u,
        "lt(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        0u,
        "lt(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        0u,
        "lt(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, -0.5),
        1u,
        "lt(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, 0.5),
        1u,
        "lt(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, -0.5),
        0u,
        "lt(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, 0.5),
        0u,
        "lt(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, -1.0),
        1u,
        "lt(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, 1.0),
        1u,
        "lt(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, -1.0),
        0u,
        "lt(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, 1.0),
        0u,
        "lt(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, -6.2831854820251465),
        0u,
        "lt(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, 6.2831854820251465),
        1u,
        "lt(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, -6.2831854820251465),
        0u,
        "lt(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, 6.2831854820251465),
        0u,
        "lt(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        0u,
        "lt(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        1u,
        "lt(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        0u,
        "lt(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        1u,
        "lt(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, -INFINITY),
        0u,
        "lt(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -6.2831854820251465, INFINITY),
        1u,
        "lt(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, -INFINITY),
        0u,
        "lt(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 6.2831854820251465, INFINITY),
        1u,
        "lt(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, -0.0),
        1u,
        "lt(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, 0.0),
        1u,
        "lt(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, -0.0),
        0u,
        "lt(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, 0.0),
        0u,
        "lt(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        1u,
        "lt(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        1u,
        "lt(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        0u,
        "lt(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        0u,
        "lt(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        1u,
        "lt(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        1u,
        "lt(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        0u,
        "lt(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        0u,
        "lt(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, -0.5),
        1u,
        "lt(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, 0.5),
        1u,
        "lt(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, -0.5),
        0u,
        "lt(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, 0.5),
        0u,
        "lt(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, -1.0),
        1u,
        "lt(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, 1.0),
        1u,
        "lt(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, -1.0),
        0u,
        "lt(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, 1.0),
        0u,
        "lt(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        1u,
        "lt(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        1u,
        "lt(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        0u,
        "lt(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        0u,
        "lt(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        0u,
        "lt(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        1u,
        "lt(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        0u,
        "lt(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        0u,
        "lt(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, -INFINITY),
        0u,
        "lt(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -3.4028234663852886e+38, INFINITY),
        1u,
        "lt(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, -INFINITY),
        0u,
        "lt(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, 3.4028234663852886e+38, INFINITY),
        1u,
        "lt(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, -0.0),
        1u,
        "lt(-INFINITY, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, 0.0),
        1u,
        "lt(-INFINITY, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, -0.0),
        0u,
        "lt(INFINITY, -0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, 0.0),
        0u,
        "lt(INFINITY, 0.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, -1.401298464324817e-45),
        1u,
        "lt(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, 1.401298464324817e-45),
        1u,
        "lt(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, -1.401298464324817e-45),
        0u,
        "lt(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, 1.401298464324817e-45),
        0u,
        "lt(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, -1.1754943508222875e-38),
        1u,
        "lt(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, 1.1754943508222875e-38),
        1u,
        "lt(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, -1.1754943508222875e-38),
        0u,
        "lt(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, 1.1754943508222875e-38),
        0u,
        "lt(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, -0.5),
        1u,
        "lt(-INFINITY, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, 0.5),
        1u,
        "lt(-INFINITY, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, -0.5),
        0u,
        "lt(INFINITY, -0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, 0.5),
        0u,
        "lt(INFINITY, 0.5)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, -1.0),
        1u,
        "lt(-INFINITY, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, 1.0),
        1u,
        "lt(-INFINITY, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, -1.0),
        0u,
        "lt(INFINITY, -1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, 1.0),
        0u,
        "lt(INFINITY, 1.0)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, -6.2831854820251465),
        1u,
        "lt(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, 6.2831854820251465),
        1u,
        "lt(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, -6.2831854820251465),
        0u,
        "lt(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, 6.2831854820251465),
        0u,
        "lt(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, -3.4028234663852886e+38),
        1u,
        "lt(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, 3.4028234663852886e+38),
        1u,
        "lt(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, -3.4028234663852886e+38),
        0u,
        "lt(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, 3.4028234663852886e+38),
        0u,
        "lt(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, -INFINITY),
        0u,
        "lt(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, -INFINITY, INFINITY),
        1u,
        "lt(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, -INFINITY),
        0u,
        "lt(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_lt(&instance, INFINITY, INFINITY),
        0u,
        "lt(INFINITY, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, -0.0),
        1u,
        "le(-0.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, 0.0),
        1u,
        "le(-0.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, -0.0),
        1u,
        "le(0.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, 0.0),
        1u,
        "le(0.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, -1.401298464324817e-45),
        0u,
        "le(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, 1.401298464324817e-45),
        1u,
        "le(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, -1.401298464324817e-45),
        0u,
        "le(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, 1.401298464324817e-45),
        1u,
        "le(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, -1.1754943508222875e-38),
        0u,
        "le(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, 1.1754943508222875e-38),
        1u,
        "le(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, -1.1754943508222875e-38),
        0u,
        "le(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, 1.1754943508222875e-38),
        1u,
        "le(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, -0.5),
        0u,
        "le(-0.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, 0.5),
        1u,
        "le(-0.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, -0.5),
        0u,
        "le(0.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, 0.5),
        1u,
        "le(0.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, -1.0),
        0u,
        "le(-0.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, 1.0),
        1u,
        "le(-0.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, -1.0),
        0u,
        "le(0.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, 1.0),
        1u,
        "le(0.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, -6.2831854820251465),
        0u,
        "le(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, 6.2831854820251465),
        1u,
        "le(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, -6.2831854820251465),
        0u,
        "le(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, 6.2831854820251465),
        1u,
        "le(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, -3.4028234663852886e+38),
        0u,
        "le(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, 3.4028234663852886e+38),
        1u,
        "le(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, -3.4028234663852886e+38),
        0u,
        "le(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, 3.4028234663852886e+38),
        1u,
        "le(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, -INFINITY),
        0u,
        "le(-0.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.0, INFINITY),
        1u,
        "le(-0.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, -INFINITY),
        0u,
        "le(0.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.0, INFINITY),
        1u,
        "le(0.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, -0.0),
        1u,
        "le(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, 0.0),
        1u,
        "le(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, -0.0),
        0u,
        "le(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, 0.0),
        0u,
        "le(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        1u,
        "le(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        1u,
        "le(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        0u,
        "le(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        1u,
        "le(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        0u,
        "le(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        1u,
        "le(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        0u,
        "le(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        1u,
        "le(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, -0.5),
        0u,
        "le(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, 0.5),
        1u,
        "le(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, -0.5),
        0u,
        "le(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, 0.5),
        1u,
        "le(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, -1.0),
        0u,
        "le(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, 1.0),
        1u,
        "le(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, -1.0),
        0u,
        "le(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, 1.0),
        1u,
        "le(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, -6.2831854820251465),
        0u,
        "le(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, 6.2831854820251465),
        1u,
        "le(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, -6.2831854820251465),
        0u,
        "le(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, 6.2831854820251465),
        1u,
        "le(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        0u,
        "le(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        1u,
        "le(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        0u,
        "le(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        1u,
        "le(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, -INFINITY),
        0u,
        "le(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.401298464324817e-45, INFINITY),
        1u,
        "le(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, -INFINITY),
        0u,
        "le(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.401298464324817e-45, INFINITY),
        1u,
        "le(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, -0.0),
        1u,
        "le(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, 0.0),
        1u,
        "le(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, -0.0),
        0u,
        "le(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, 0.0),
        0u,
        "le(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        1u,
        "le(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        1u,
        "le(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        0u,
        "le(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        0u,
        "le(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        1u,
        "le(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        1u,
        "le(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        0u,
        "le(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        1u,
        "le(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, -0.5),
        0u,
        "le(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, 0.5),
        1u,
        "le(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, -0.5),
        0u,
        "le(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, 0.5),
        1u,
        "le(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, -1.0),
        0u,
        "le(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, 1.0),
        1u,
        "le(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, -1.0),
        0u,
        "le(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, 1.0),
        1u,
        "le(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        0u,
        "le(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        1u,
        "le(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        0u,
        "le(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        1u,
        "le(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        0u,
        "le(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        1u,
        "le(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        0u,
        "le(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        1u,
        "le(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, -INFINITY),
        0u,
        "le(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.1754943508222875e-38, INFINITY),
        1u,
        "le(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, -INFINITY),
        0u,
        "le(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.1754943508222875e-38, INFINITY),
        1u,
        "le(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, -0.0),
        1u,
        "le(-0.5, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, 0.0),
        1u,
        "le(-0.5, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, -0.0),
        0u,
        "le(0.5, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, 0.0),
        0u,
        "le(0.5, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, -1.401298464324817e-45),
        1u,
        "le(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, 1.401298464324817e-45),
        1u,
        "le(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, -1.401298464324817e-45),
        0u,
        "le(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, 1.401298464324817e-45),
        0u,
        "le(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, -1.1754943508222875e-38),
        1u,
        "le(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, 1.1754943508222875e-38),
        1u,
        "le(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, -1.1754943508222875e-38),
        0u,
        "le(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, 1.1754943508222875e-38),
        0u,
        "le(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, -0.5),
        1u,
        "le(-0.5, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, 0.5),
        1u,
        "le(-0.5, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, -0.5),
        0u,
        "le(0.5, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, 0.5),
        1u,
        "le(0.5, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, -1.0),
        0u,
        "le(-0.5, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, 1.0),
        1u,
        "le(-0.5, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, -1.0),
        0u,
        "le(0.5, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, 1.0),
        1u,
        "le(0.5, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, -6.2831854820251465),
        0u,
        "le(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, 6.2831854820251465),
        1u,
        "le(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, -6.2831854820251465),
        0u,
        "le(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, 6.2831854820251465),
        1u,
        "le(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, -3.4028234663852886e+38),
        0u,
        "le(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, 3.4028234663852886e+38),
        1u,
        "le(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, -3.4028234663852886e+38),
        0u,
        "le(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, 3.4028234663852886e+38),
        1u,
        "le(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, -INFINITY),
        0u,
        "le(-0.5, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -0.5, INFINITY),
        1u,
        "le(-0.5, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, -INFINITY),
        0u,
        "le(0.5, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 0.5, INFINITY),
        1u,
        "le(0.5, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, -0.0),
        1u,
        "le(-1.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, 0.0),
        1u,
        "le(-1.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, -0.0),
        0u,
        "le(1.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, 0.0),
        0u,
        "le(1.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, -1.401298464324817e-45),
        1u,
        "le(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, 1.401298464324817e-45),
        1u,
        "le(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, -1.401298464324817e-45),
        0u,
        "le(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, 1.401298464324817e-45),
        0u,
        "le(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, -1.1754943508222875e-38),
        1u,
        "le(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, 1.1754943508222875e-38),
        1u,
        "le(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, -1.1754943508222875e-38),
        0u,
        "le(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, 1.1754943508222875e-38),
        0u,
        "le(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, -0.5),
        1u,
        "le(-1.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, 0.5),
        1u,
        "le(-1.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, -0.5),
        0u,
        "le(1.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, 0.5),
        0u,
        "le(1.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, -1.0),
        1u,
        "le(-1.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, 1.0),
        1u,
        "le(-1.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, -1.0),
        0u,
        "le(1.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, 1.0),
        1u,
        "le(1.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, -6.2831854820251465),
        0u,
        "le(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, 6.2831854820251465),
        1u,
        "le(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, -6.2831854820251465),
        0u,
        "le(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, 6.2831854820251465),
        1u,
        "le(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, -3.4028234663852886e+38),
        0u,
        "le(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, 3.4028234663852886e+38),
        1u,
        "le(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, -3.4028234663852886e+38),
        0u,
        "le(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, 3.4028234663852886e+38),
        1u,
        "le(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, -INFINITY),
        0u,
        "le(-1.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -1.0, INFINITY),
        1u,
        "le(-1.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, -INFINITY),
        0u,
        "le(1.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 1.0, INFINITY),
        1u,
        "le(1.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, -0.0),
        1u,
        "le(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, 0.0),
        1u,
        "le(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, -0.0),
        0u,
        "le(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, 0.0),
        0u,
        "le(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, -1.401298464324817e-45),
        1u,
        "le(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, 1.401298464324817e-45),
        1u,
        "le(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, -1.401298464324817e-45),
        0u,
        "le(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, 1.401298464324817e-45),
        0u,
        "le(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        1u,
        "le(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        1u,
        "le(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        0u,
        "le(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        0u,
        "le(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, -0.5),
        1u,
        "le(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, 0.5),
        1u,
        "le(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, -0.5),
        0u,
        "le(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, 0.5),
        0u,
        "le(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, -1.0),
        1u,
        "le(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, 1.0),
        1u,
        "le(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, -1.0),
        0u,
        "le(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, 1.0),
        0u,
        "le(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, -6.2831854820251465),
        1u,
        "le(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, 6.2831854820251465),
        1u,
        "le(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, -6.2831854820251465),
        0u,
        "le(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, 6.2831854820251465),
        1u,
        "le(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        0u,
        "le(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        1u,
        "le(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        0u,
        "le(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        1u,
        "le(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, -INFINITY),
        0u,
        "le(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -6.2831854820251465, INFINITY),
        1u,
        "le(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, -INFINITY),
        0u,
        "le(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 6.2831854820251465, INFINITY),
        1u,
        "le(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, -0.0),
        1u,
        "le(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, 0.0),
        1u,
        "le(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, -0.0),
        0u,
        "le(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, 0.0),
        0u,
        "le(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        1u,
        "le(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        1u,
        "le(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        0u,
        "le(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        0u,
        "le(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        1u,
        "le(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        1u,
        "le(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        0u,
        "le(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        0u,
        "le(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, -0.5),
        1u,
        "le(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, 0.5),
        1u,
        "le(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, -0.5),
        0u,
        "le(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, 0.5),
        0u,
        "le(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, -1.0),
        1u,
        "le(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, 1.0),
        1u,
        "le(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, -1.0),
        0u,
        "le(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, 1.0),
        0u,
        "le(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        1u,
        "le(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        1u,
        "le(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        0u,
        "le(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        0u,
        "le(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        1u,
        "le(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        1u,
        "le(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        0u,
        "le(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        1u,
        "le(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, -INFINITY),
        0u,
        "le(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -3.4028234663852886e+38, INFINITY),
        1u,
        "le(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, -INFINITY),
        0u,
        "le(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, 3.4028234663852886e+38, INFINITY),
        1u,
        "le(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, -0.0),
        1u,
        "le(-INFINITY, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, 0.0),
        1u,
        "le(-INFINITY, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, -0.0),
        0u,
        "le(INFINITY, -0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, 0.0),
        0u,
        "le(INFINITY, 0.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, -1.401298464324817e-45),
        1u,
        "le(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, 1.401298464324817e-45),
        1u,
        "le(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, -1.401298464324817e-45),
        0u,
        "le(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, 1.401298464324817e-45),
        0u,
        "le(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, -1.1754943508222875e-38),
        1u,
        "le(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, 1.1754943508222875e-38),
        1u,
        "le(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, -1.1754943508222875e-38),
        0u,
        "le(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, 1.1754943508222875e-38),
        0u,
        "le(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, -0.5),
        1u,
        "le(-INFINITY, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, 0.5),
        1u,
        "le(-INFINITY, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, -0.5),
        0u,
        "le(INFINITY, -0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, 0.5),
        0u,
        "le(INFINITY, 0.5)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, -1.0),
        1u,
        "le(-INFINITY, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, 1.0),
        1u,
        "le(-INFINITY, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, -1.0),
        0u,
        "le(INFINITY, -1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, 1.0),
        0u,
        "le(INFINITY, 1.0)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, -6.2831854820251465),
        1u,
        "le(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, 6.2831854820251465),
        1u,
        "le(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, -6.2831854820251465),
        0u,
        "le(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, 6.2831854820251465),
        0u,
        "le(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, -3.4028234663852886e+38),
        1u,
        "le(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, 3.4028234663852886e+38),
        1u,
        "le(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, -3.4028234663852886e+38),
        0u,
        "le(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, 3.4028234663852886e+38),
        0u,
        "le(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, -INFINITY),
        1u,
        "le(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, -INFINITY, INFINITY),
        1u,
        "le(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, -INFINITY),
        0u,
        "le(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_le(&instance, INFINITY, INFINITY),
        1u,
        "le(INFINITY, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, -0.0),
        0u,
        "gt(-0.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, 0.0),
        0u,
        "gt(-0.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, -0.0),
        0u,
        "gt(0.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, 0.0),
        0u,
        "gt(0.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, -1.401298464324817e-45),
        1u,
        "gt(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, 1.401298464324817e-45),
        0u,
        "gt(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, -1.401298464324817e-45),
        1u,
        "gt(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, 1.401298464324817e-45),
        0u,
        "gt(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, -1.1754943508222875e-38),
        1u,
        "gt(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, 1.1754943508222875e-38),
        0u,
        "gt(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, -1.1754943508222875e-38),
        1u,
        "gt(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, 1.1754943508222875e-38),
        0u,
        "gt(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, -0.5),
        1u,
        "gt(-0.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, 0.5),
        0u,
        "gt(-0.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, -0.5),
        1u,
        "gt(0.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, 0.5),
        0u,
        "gt(0.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, -1.0),
        1u,
        "gt(-0.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, 1.0),
        0u,
        "gt(-0.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, -1.0),
        1u,
        "gt(0.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, 1.0),
        0u,
        "gt(0.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, -6.2831854820251465),
        1u,
        "gt(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, 6.2831854820251465),
        0u,
        "gt(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, -6.2831854820251465),
        1u,
        "gt(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, 6.2831854820251465),
        0u,
        "gt(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, -3.4028234663852886e+38),
        1u,
        "gt(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, 3.4028234663852886e+38),
        0u,
        "gt(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, -3.4028234663852886e+38),
        1u,
        "gt(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, 3.4028234663852886e+38),
        0u,
        "gt(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, -INFINITY),
        1u,
        "gt(-0.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.0, INFINITY),
        0u,
        "gt(-0.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, -INFINITY),
        1u,
        "gt(0.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.0, INFINITY),
        0u,
        "gt(0.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, -0.0),
        0u,
        "gt(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, 0.0),
        0u,
        "gt(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, -0.0),
        1u,
        "gt(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, 0.0),
        1u,
        "gt(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        0u,
        "gt(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        0u,
        "gt(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        1u,
        "gt(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        0u,
        "gt(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        1u,
        "gt(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        0u,
        "gt(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        1u,
        "gt(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        0u,
        "gt(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, -0.5),
        1u,
        "gt(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, 0.5),
        0u,
        "gt(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, -0.5),
        1u,
        "gt(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, 0.5),
        0u,
        "gt(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, -1.0),
        1u,
        "gt(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, 1.0),
        0u,
        "gt(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, -1.0),
        1u,
        "gt(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, 1.0),
        0u,
        "gt(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, -6.2831854820251465),
        1u,
        "gt(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, 6.2831854820251465),
        0u,
        "gt(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, -6.2831854820251465),
        1u,
        "gt(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, 6.2831854820251465),
        0u,
        "gt(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        1u,
        "gt(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        0u,
        "gt(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        1u,
        "gt(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        0u,
        "gt(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, -INFINITY),
        1u,
        "gt(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.401298464324817e-45, INFINITY),
        0u,
        "gt(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, -INFINITY),
        1u,
        "gt(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.401298464324817e-45, INFINITY),
        0u,
        "gt(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, -0.0),
        0u,
        "gt(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, 0.0),
        0u,
        "gt(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, -0.0),
        1u,
        "gt(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, 0.0),
        1u,
        "gt(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        0u,
        "gt(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        0u,
        "gt(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        1u,
        "gt(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        1u,
        "gt(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        0u,
        "gt(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        0u,
        "gt(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        1u,
        "gt(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        0u,
        "gt(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, -0.5),
        1u,
        "gt(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, 0.5),
        0u,
        "gt(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, -0.5),
        1u,
        "gt(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, 0.5),
        0u,
        "gt(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, -1.0),
        1u,
        "gt(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, 1.0),
        0u,
        "gt(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, -1.0),
        1u,
        "gt(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, 1.0),
        0u,
        "gt(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        1u,
        "gt(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        0u,
        "gt(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        1u,
        "gt(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        0u,
        "gt(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        1u,
        "gt(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        0u,
        "gt(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        1u,
        "gt(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        0u,
        "gt(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, -INFINITY),
        1u,
        "gt(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.1754943508222875e-38, INFINITY),
        0u,
        "gt(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, -INFINITY),
        1u,
        "gt(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.1754943508222875e-38, INFINITY),
        0u,
        "gt(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, -0.0),
        0u,
        "gt(-0.5, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, 0.0),
        0u,
        "gt(-0.5, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, -0.0),
        1u,
        "gt(0.5, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, 0.0),
        1u,
        "gt(0.5, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, -1.401298464324817e-45),
        0u,
        "gt(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, 1.401298464324817e-45),
        0u,
        "gt(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, -1.401298464324817e-45),
        1u,
        "gt(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, 1.401298464324817e-45),
        1u,
        "gt(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, -1.1754943508222875e-38),
        0u,
        "gt(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, 1.1754943508222875e-38),
        0u,
        "gt(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, -1.1754943508222875e-38),
        1u,
        "gt(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, 1.1754943508222875e-38),
        1u,
        "gt(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, -0.5),
        0u,
        "gt(-0.5, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, 0.5),
        0u,
        "gt(-0.5, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, -0.5),
        1u,
        "gt(0.5, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, 0.5),
        0u,
        "gt(0.5, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, -1.0),
        1u,
        "gt(-0.5, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, 1.0),
        0u,
        "gt(-0.5, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, -1.0),
        1u,
        "gt(0.5, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, 1.0),
        0u,
        "gt(0.5, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, -6.2831854820251465),
        1u,
        "gt(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, 6.2831854820251465),
        0u,
        "gt(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, -6.2831854820251465),
        1u,
        "gt(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, 6.2831854820251465),
        0u,
        "gt(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, -3.4028234663852886e+38),
        1u,
        "gt(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, 3.4028234663852886e+38),
        0u,
        "gt(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, -3.4028234663852886e+38),
        1u,
        "gt(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, 3.4028234663852886e+38),
        0u,
        "gt(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, -INFINITY),
        1u,
        "gt(-0.5, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -0.5, INFINITY),
        0u,
        "gt(-0.5, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, -INFINITY),
        1u,
        "gt(0.5, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 0.5, INFINITY),
        0u,
        "gt(0.5, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, -0.0),
        0u,
        "gt(-1.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, 0.0),
        0u,
        "gt(-1.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, -0.0),
        1u,
        "gt(1.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, 0.0),
        1u,
        "gt(1.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, -1.401298464324817e-45),
        0u,
        "gt(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, 1.401298464324817e-45),
        0u,
        "gt(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, -1.401298464324817e-45),
        1u,
        "gt(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, 1.401298464324817e-45),
        1u,
        "gt(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, -1.1754943508222875e-38),
        0u,
        "gt(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, 1.1754943508222875e-38),
        0u,
        "gt(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, -1.1754943508222875e-38),
        1u,
        "gt(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, 1.1754943508222875e-38),
        1u,
        "gt(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, -0.5),
        0u,
        "gt(-1.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, 0.5),
        0u,
        "gt(-1.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, -0.5),
        1u,
        "gt(1.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, 0.5),
        1u,
        "gt(1.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, -1.0),
        0u,
        "gt(-1.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, 1.0),
        0u,
        "gt(-1.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, -1.0),
        1u,
        "gt(1.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, 1.0),
        0u,
        "gt(1.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, -6.2831854820251465),
        1u,
        "gt(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, 6.2831854820251465),
        0u,
        "gt(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, -6.2831854820251465),
        1u,
        "gt(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, 6.2831854820251465),
        0u,
        "gt(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, -3.4028234663852886e+38),
        1u,
        "gt(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, 3.4028234663852886e+38),
        0u,
        "gt(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, -3.4028234663852886e+38),
        1u,
        "gt(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, 3.4028234663852886e+38),
        0u,
        "gt(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, -INFINITY),
        1u,
        "gt(-1.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -1.0, INFINITY),
        0u,
        "gt(-1.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, -INFINITY),
        1u,
        "gt(1.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 1.0, INFINITY),
        0u,
        "gt(1.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, -0.0),
        0u,
        "gt(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, 0.0),
        0u,
        "gt(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, -0.0),
        1u,
        "gt(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, 0.0),
        1u,
        "gt(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, -1.401298464324817e-45),
        0u,
        "gt(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, 1.401298464324817e-45),
        0u,
        "gt(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, -1.401298464324817e-45),
        1u,
        "gt(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, 1.401298464324817e-45),
        1u,
        "gt(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        0u,
        "gt(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        0u,
        "gt(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        1u,
        "gt(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        1u,
        "gt(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, -0.5),
        0u,
        "gt(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, 0.5),
        0u,
        "gt(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, -0.5),
        1u,
        "gt(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, 0.5),
        1u,
        "gt(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, -1.0),
        0u,
        "gt(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, 1.0),
        0u,
        "gt(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, -1.0),
        1u,
        "gt(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, 1.0),
        1u,
        "gt(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, -6.2831854820251465),
        0u,
        "gt(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, 6.2831854820251465),
        0u,
        "gt(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, -6.2831854820251465),
        1u,
        "gt(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, 6.2831854820251465),
        0u,
        "gt(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        1u,
        "gt(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        0u,
        "gt(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        1u,
        "gt(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        0u,
        "gt(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, -INFINITY),
        1u,
        "gt(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -6.2831854820251465, INFINITY),
        0u,
        "gt(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, -INFINITY),
        1u,
        "gt(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 6.2831854820251465, INFINITY),
        0u,
        "gt(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, -0.0),
        0u,
        "gt(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, 0.0),
        0u,
        "gt(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, -0.0),
        1u,
        "gt(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, 0.0),
        1u,
        "gt(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        0u,
        "gt(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        0u,
        "gt(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        1u,
        "gt(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        1u,
        "gt(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        0u,
        "gt(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        0u,
        "gt(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        1u,
        "gt(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        1u,
        "gt(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, -0.5),
        0u,
        "gt(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, 0.5),
        0u,
        "gt(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, -0.5),
        1u,
        "gt(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, 0.5),
        1u,
        "gt(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, -1.0),
        0u,
        "gt(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, 1.0),
        0u,
        "gt(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, -1.0),
        1u,
        "gt(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, 1.0),
        1u,
        "gt(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        0u,
        "gt(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        0u,
        "gt(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        1u,
        "gt(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        1u,
        "gt(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        0u,
        "gt(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        0u,
        "gt(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        1u,
        "gt(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        0u,
        "gt(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, -INFINITY),
        1u,
        "gt(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -3.4028234663852886e+38, INFINITY),
        0u,
        "gt(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, -INFINITY),
        1u,
        "gt(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, 3.4028234663852886e+38, INFINITY),
        0u,
        "gt(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, -0.0),
        0u,
        "gt(-INFINITY, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, 0.0),
        0u,
        "gt(-INFINITY, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, -0.0),
        1u,
        "gt(INFINITY, -0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, 0.0),
        1u,
        "gt(INFINITY, 0.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, -1.401298464324817e-45),
        0u,
        "gt(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, 1.401298464324817e-45),
        0u,
        "gt(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, -1.401298464324817e-45),
        1u,
        "gt(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, 1.401298464324817e-45),
        1u,
        "gt(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, -1.1754943508222875e-38),
        0u,
        "gt(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, 1.1754943508222875e-38),
        0u,
        "gt(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, -1.1754943508222875e-38),
        1u,
        "gt(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, 1.1754943508222875e-38),
        1u,
        "gt(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, -0.5),
        0u,
        "gt(-INFINITY, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, 0.5),
        0u,
        "gt(-INFINITY, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, -0.5),
        1u,
        "gt(INFINITY, -0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, 0.5),
        1u,
        "gt(INFINITY, 0.5)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, -1.0),
        0u,
        "gt(-INFINITY, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, 1.0),
        0u,
        "gt(-INFINITY, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, -1.0),
        1u,
        "gt(INFINITY, -1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, 1.0),
        1u,
        "gt(INFINITY, 1.0)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, -6.2831854820251465),
        0u,
        "gt(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, 6.2831854820251465),
        0u,
        "gt(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, -6.2831854820251465),
        1u,
        "gt(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, 6.2831854820251465),
        1u,
        "gt(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, -3.4028234663852886e+38),
        0u,
        "gt(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, 3.4028234663852886e+38),
        0u,
        "gt(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, -3.4028234663852886e+38),
        1u,
        "gt(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, 3.4028234663852886e+38),
        1u,
        "gt(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, -INFINITY),
        0u,
        "gt(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, -INFINITY, INFINITY),
        0u,
        "gt(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, -INFINITY),
        1u,
        "gt(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_gt(&instance, INFINITY, INFINITY),
        0u,
        "gt(INFINITY, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, -0.0),
        1u,
        "ge(-0.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, 0.0),
        1u,
        "ge(-0.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, -0.0),
        1u,
        "ge(0.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, 0.0),
        1u,
        "ge(0.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, -1.401298464324817e-45),
        1u,
        "ge(-0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, 1.401298464324817e-45),
        0u,
        "ge(-0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, -1.401298464324817e-45),
        1u,
        "ge(0.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, 1.401298464324817e-45),
        0u,
        "ge(0.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, -1.1754943508222875e-38),
        1u,
        "ge(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, 1.1754943508222875e-38),
        0u,
        "ge(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, -1.1754943508222875e-38),
        1u,
        "ge(0.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, 1.1754943508222875e-38),
        0u,
        "ge(0.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, -0.5),
        1u,
        "ge(-0.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, 0.5),
        0u,
        "ge(-0.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, -0.5),
        1u,
        "ge(0.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, 0.5),
        0u,
        "ge(0.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, -1.0),
        1u,
        "ge(-0.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, 1.0),
        0u,
        "ge(-0.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, -1.0),
        1u,
        "ge(0.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, 1.0),
        0u,
        "ge(0.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, -6.2831854820251465),
        1u,
        "ge(-0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, 6.2831854820251465),
        0u,
        "ge(-0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, -6.2831854820251465),
        1u,
        "ge(0.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, 6.2831854820251465),
        0u,
        "ge(0.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, -3.4028234663852886e+38),
        1u,
        "ge(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, 3.4028234663852886e+38),
        0u,
        "ge(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, -3.4028234663852886e+38),
        1u,
        "ge(0.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, 3.4028234663852886e+38),
        0u,
        "ge(0.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, -INFINITY),
        1u,
        "ge(-0.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.0, INFINITY),
        0u,
        "ge(-0.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, -INFINITY),
        1u,
        "ge(0.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.0, INFINITY),
        0u,
        "ge(0.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, -0.0),
        0u,
        "ge(-1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, 0.0),
        0u,
        "ge(-1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, -0.0),
        1u,
        "ge(1.401298464324817e-45, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, 0.0),
        1u,
        "ge(1.401298464324817e-45, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        1u,
        "ge(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        0u,
        "ge(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        1u,
        "ge(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        1u,
        "ge(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        1u,
        "ge(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        0u,
        "ge(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        1u,
        "ge(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        0u,
        "ge(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, -0.5),
        1u,
        "ge(-1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, 0.5),
        0u,
        "ge(-1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, -0.5),
        1u,
        "ge(1.401298464324817e-45, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, 0.5),
        0u,
        "ge(1.401298464324817e-45, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, -1.0),
        1u,
        "ge(-1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, 1.0),
        0u,
        "ge(-1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, -1.0),
        1u,
        "ge(1.401298464324817e-45, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, 1.0),
        0u,
        "ge(1.401298464324817e-45, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, -6.2831854820251465),
        1u,
        "ge(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, 6.2831854820251465),
        0u,
        "ge(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, -6.2831854820251465),
        1u,
        "ge(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, 6.2831854820251465),
        0u,
        "ge(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        1u,
        "ge(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        0u,
        "ge(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        1u,
        "ge(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        0u,
        "ge(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, -INFINITY),
        1u,
        "ge(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.401298464324817e-45, INFINITY),
        0u,
        "ge(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, -INFINITY),
        1u,
        "ge(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.401298464324817e-45, INFINITY),
        0u,
        "ge(1.401298464324817e-45, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, -0.0),
        0u,
        "ge(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, 0.0),
        0u,
        "ge(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, -0.0),
        1u,
        "ge(1.1754943508222875e-38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, 0.0),
        1u,
        "ge(1.1754943508222875e-38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        0u,
        "ge(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        0u,
        "ge(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        1u,
        "ge(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        1u,
        "ge(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        1u,
        "ge(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        0u,
        "ge(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        1u,
        "ge(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        1u,
        "ge(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, -0.5),
        1u,
        "ge(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, 0.5),
        0u,
        "ge(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, -0.5),
        1u,
        "ge(1.1754943508222875e-38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, 0.5),
        0u,
        "ge(1.1754943508222875e-38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, -1.0),
        1u,
        "ge(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, 1.0),
        0u,
        "ge(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, -1.0),
        1u,
        "ge(1.1754943508222875e-38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, 1.0),
        0u,
        "ge(1.1754943508222875e-38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        1u,
        "ge(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        0u,
        "ge(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        1u,
        "ge(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        0u,
        "ge(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        1u,
        "ge(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        0u,
        "ge(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        1u,
        "ge(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        0u,
        "ge(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, -INFINITY),
        1u,
        "ge(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.1754943508222875e-38, INFINITY),
        0u,
        "ge(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, -INFINITY),
        1u,
        "ge(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.1754943508222875e-38, INFINITY),
        0u,
        "ge(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, -0.0),
        0u,
        "ge(-0.5, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, 0.0),
        0u,
        "ge(-0.5, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, -0.0),
        1u,
        "ge(0.5, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, 0.0),
        1u,
        "ge(0.5, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, -1.401298464324817e-45),
        0u,
        "ge(-0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, 1.401298464324817e-45),
        0u,
        "ge(-0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, -1.401298464324817e-45),
        1u,
        "ge(0.5, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, 1.401298464324817e-45),
        1u,
        "ge(0.5, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, -1.1754943508222875e-38),
        0u,
        "ge(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, 1.1754943508222875e-38),
        0u,
        "ge(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, -1.1754943508222875e-38),
        1u,
        "ge(0.5, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, 1.1754943508222875e-38),
        1u,
        "ge(0.5, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, -0.5),
        1u,
        "ge(-0.5, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, 0.5),
        0u,
        "ge(-0.5, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, -0.5),
        1u,
        "ge(0.5, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, 0.5),
        1u,
        "ge(0.5, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, -1.0),
        1u,
        "ge(-0.5, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, 1.0),
        0u,
        "ge(-0.5, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, -1.0),
        1u,
        "ge(0.5, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, 1.0),
        0u,
        "ge(0.5, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, -6.2831854820251465),
        1u,
        "ge(-0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, 6.2831854820251465),
        0u,
        "ge(-0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, -6.2831854820251465),
        1u,
        "ge(0.5, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, 6.2831854820251465),
        0u,
        "ge(0.5, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, -3.4028234663852886e+38),
        1u,
        "ge(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, 3.4028234663852886e+38),
        0u,
        "ge(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, -3.4028234663852886e+38),
        1u,
        "ge(0.5, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, 3.4028234663852886e+38),
        0u,
        "ge(0.5, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, -INFINITY),
        1u,
        "ge(-0.5, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -0.5, INFINITY),
        0u,
        "ge(-0.5, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, -INFINITY),
        1u,
        "ge(0.5, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 0.5, INFINITY),
        0u,
        "ge(0.5, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, -0.0),
        0u,
        "ge(-1.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, 0.0),
        0u,
        "ge(-1.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, -0.0),
        1u,
        "ge(1.0, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, 0.0),
        1u,
        "ge(1.0, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, -1.401298464324817e-45),
        0u,
        "ge(-1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, 1.401298464324817e-45),
        0u,
        "ge(-1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, -1.401298464324817e-45),
        1u,
        "ge(1.0, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, 1.401298464324817e-45),
        1u,
        "ge(1.0, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, -1.1754943508222875e-38),
        0u,
        "ge(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, 1.1754943508222875e-38),
        0u,
        "ge(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, -1.1754943508222875e-38),
        1u,
        "ge(1.0, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, 1.1754943508222875e-38),
        1u,
        "ge(1.0, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, -0.5),
        0u,
        "ge(-1.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, 0.5),
        0u,
        "ge(-1.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, -0.5),
        1u,
        "ge(1.0, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, 0.5),
        1u,
        "ge(1.0, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, -1.0),
        1u,
        "ge(-1.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, 1.0),
        0u,
        "ge(-1.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, -1.0),
        1u,
        "ge(1.0, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, 1.0),
        1u,
        "ge(1.0, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, -6.2831854820251465),
        1u,
        "ge(-1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, 6.2831854820251465),
        0u,
        "ge(-1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, -6.2831854820251465),
        1u,
        "ge(1.0, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, 6.2831854820251465),
        0u,
        "ge(1.0, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, -3.4028234663852886e+38),
        1u,
        "ge(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, 3.4028234663852886e+38),
        0u,
        "ge(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, -3.4028234663852886e+38),
        1u,
        "ge(1.0, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, 3.4028234663852886e+38),
        0u,
        "ge(1.0, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, -INFINITY),
        1u,
        "ge(-1.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -1.0, INFINITY),
        0u,
        "ge(-1.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, -INFINITY),
        1u,
        "ge(1.0, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 1.0, INFINITY),
        0u,
        "ge(1.0, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, -0.0),
        0u,
        "ge(-6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, 0.0),
        0u,
        "ge(-6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, -0.0),
        1u,
        "ge(6.2831854820251465, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, 0.0),
        1u,
        "ge(6.2831854820251465, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, -1.401298464324817e-45),
        0u,
        "ge(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, 1.401298464324817e-45),
        0u,
        "ge(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, -1.401298464324817e-45),
        1u,
        "ge(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, 1.401298464324817e-45),
        1u,
        "ge(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        0u,
        "ge(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        0u,
        "ge(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        1u,
        "ge(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        1u,
        "ge(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, -0.5),
        0u,
        "ge(-6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, 0.5),
        0u,
        "ge(-6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, -0.5),
        1u,
        "ge(6.2831854820251465, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, 0.5),
        1u,
        "ge(6.2831854820251465, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, -1.0),
        0u,
        "ge(-6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, 1.0),
        0u,
        "ge(-6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, -1.0),
        1u,
        "ge(6.2831854820251465, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, 1.0),
        1u,
        "ge(6.2831854820251465, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, -6.2831854820251465),
        1u,
        "ge(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, 6.2831854820251465),
        0u,
        "ge(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, -6.2831854820251465),
        1u,
        "ge(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, 6.2831854820251465),
        1u,
        "ge(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        1u,
        "ge(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        0u,
        "ge(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        1u,
        "ge(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        0u,
        "ge(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, -INFINITY),
        1u,
        "ge(-6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -6.2831854820251465, INFINITY),
        0u,
        "ge(-6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, -INFINITY),
        1u,
        "ge(6.2831854820251465, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 6.2831854820251465, INFINITY),
        0u,
        "ge(6.2831854820251465, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, -0.0),
        0u,
        "ge(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, 0.0),
        0u,
        "ge(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, -0.0),
        1u,
        "ge(3.4028234663852886e+38, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, 0.0),
        1u,
        "ge(3.4028234663852886e+38, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        0u,
        "ge(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        0u,
        "ge(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        1u,
        "ge(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        1u,
        "ge(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        0u,
        "ge(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        0u,
        "ge(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        1u,
        "ge(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        1u,
        "ge(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, -0.5),
        0u,
        "ge(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, 0.5),
        0u,
        "ge(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, -0.5),
        1u,
        "ge(3.4028234663852886e+38, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, 0.5),
        1u,
        "ge(3.4028234663852886e+38, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, -1.0),
        0u,
        "ge(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, 1.0),
        0u,
        "ge(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, -1.0),
        1u,
        "ge(3.4028234663852886e+38, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, 1.0),
        1u,
        "ge(3.4028234663852886e+38, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        0u,
        "ge(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        0u,
        "ge(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        1u,
        "ge(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        1u,
        "ge(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        1u,
        "ge(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        0u,
        "ge(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        1u,
        "ge(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        1u,
        "ge(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, -INFINITY),
        1u,
        "ge(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -3.4028234663852886e+38, INFINITY),
        0u,
        "ge(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, -INFINITY),
        1u,
        "ge(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, 3.4028234663852886e+38, INFINITY),
        0u,
        "ge(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, -0.0),
        0u,
        "ge(-INFINITY, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, 0.0),
        0u,
        "ge(-INFINITY, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, -0.0),
        1u,
        "ge(INFINITY, -0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, 0.0),
        1u,
        "ge(INFINITY, 0.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, -1.401298464324817e-45),
        0u,
        "ge(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, 1.401298464324817e-45),
        0u,
        "ge(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, -1.401298464324817e-45),
        1u,
        "ge(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, 1.401298464324817e-45),
        1u,
        "ge(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, -1.1754943508222875e-38),
        0u,
        "ge(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, 1.1754943508222875e-38),
        0u,
        "ge(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, -1.1754943508222875e-38),
        1u,
        "ge(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, 1.1754943508222875e-38),
        1u,
        "ge(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, -0.5),
        0u,
        "ge(-INFINITY, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, 0.5),
        0u,
        "ge(-INFINITY, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, -0.5),
        1u,
        "ge(INFINITY, -0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, 0.5),
        1u,
        "ge(INFINITY, 0.5)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, -1.0),
        0u,
        "ge(-INFINITY, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, 1.0),
        0u,
        "ge(-INFINITY, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, -1.0),
        1u,
        "ge(INFINITY, -1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, 1.0),
        1u,
        "ge(INFINITY, 1.0)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, -6.2831854820251465),
        0u,
        "ge(-INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, 6.2831854820251465),
        0u,
        "ge(-INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, -6.2831854820251465),
        1u,
        "ge(INFINITY, -6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, 6.2831854820251465),
        1u,
        "ge(INFINITY, 6.2831854820251465)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, -3.4028234663852886e+38),
        0u,
        "ge(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, 3.4028234663852886e+38),
        0u,
        "ge(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, -3.4028234663852886e+38),
        1u,
        "ge(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, 3.4028234663852886e+38),
        1u,
        "ge(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, -INFINITY),
        1u,
        "ge(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, -INFINITY, INFINITY),
        0u,
        "ge(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, -INFINITY),
        1u,
        "ge(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f32cmp0_ge(&instance, INFINITY, INFINITY),
        1u,
        "ge(INFINITY, INFINITY)"
    );
}
