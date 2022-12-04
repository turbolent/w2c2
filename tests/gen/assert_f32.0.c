
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_f32.0.h"

void test() {
    f320Instance instance;
    f320Instantiate(&instance, resolveTestImports);
    printStart("f32.0.wasm");
    assertEqualF32(
        f320_add(&instance, -0.0, -0.0),
        -0.0,
        "add(-0.0, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, 0.0),
        0.0,
        "add(-0.0, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, -0.0),
        0.0,
        "add(0.0, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, 0.0),
        0.0,
        "add(0.0, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "add(-0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, 1.401298464324817e-45),
        1.401298464324817e-45,
        "add(-0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "add(0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, 1.401298464324817e-45),
        1.401298464324817e-45,
        "add(0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "add(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "add(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "add(0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "add(0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, -0.5),
        -0.5,
        "add(-0.0, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, 0.5),
        0.5,
        "add(-0.0, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, -0.5),
        -0.5,
        "add(0.0, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, 0.5),
        0.5,
        "add(0.0, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, -1.0),
        -1.0,
        "add(-0.0, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, 1.0),
        1.0,
        "add(-0.0, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, -1.0),
        -1.0,
        "add(0.0, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, 1.0),
        1.0,
        "add(0.0, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, -6.2831854820251465),
        -6.2831854820251465,
        "add(-0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, 6.2831854820251465),
        6.2831854820251465,
        "add(-0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, -6.2831854820251465),
        -6.2831854820251465,
        "add(0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, 6.2831854820251465),
        6.2831854820251465,
        "add(0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "add(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "add(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "add(0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "add(0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, -INFINITY),
        -INFINITY,
        "add(-0.0, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -0.0, INFINITY),
        INFINITY,
        "add(-0.0, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, -INFINITY),
        -INFINITY,
        "add(0.0, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 0.0, INFINITY),
        INFINITY,
        "add(0.0, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, -0.0),
        -1.401298464324817e-45,
        "add(-1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, 0.0),
        -1.401298464324817e-45,
        "add(-1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, -0.0),
        1.401298464324817e-45,
        "add(1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, 0.0),
        1.401298464324817e-45,
        "add(1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        -2.802596928649634e-45,
        "add(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        0.0,
        "add(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        0.0,
        "add(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        2.802596928649634e-45,
        "add(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        -1.175494490952134e-38,
        "add(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        1.1754942106924411e-38,
        "add(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        -1.1754942106924411e-38,
        "add(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        1.175494490952134e-38,
        "add(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, -0.5),
        -0.5,
        "add(-1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, 0.5),
        0.5,
        "add(-1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, -0.5),
        -0.5,
        "add(1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, 0.5),
        0.5,
        "add(1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, -1.0),
        -1.0,
        "add(-1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, 1.0),
        1.0,
        "add(-1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, -1.0),
        -1.0,
        "add(1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, 1.0),
        1.0,
        "add(1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, -6.2831854820251465),
        -6.2831854820251465,
        "add(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, 6.2831854820251465),
        6.2831854820251465,
        "add(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, -6.2831854820251465),
        -6.2831854820251465,
        "add(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, 6.2831854820251465),
        6.2831854820251465,
        "add(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "add(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "add(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "add(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "add(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, -INFINITY),
        -INFINITY,
        "add(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -1.401298464324817e-45, INFINITY),
        INFINITY,
        "add(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, -INFINITY),
        -INFINITY,
        "add(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 1.401298464324817e-45, INFINITY),
        INFINITY,
        "add(1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, -0.0),
        -1.1754943508222875e-38,
        "add(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, 0.0),
        -1.1754943508222875e-38,
        "add(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, -0.0),
        1.1754943508222875e-38,
        "add(1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, 0.0),
        1.1754943508222875e-38,
        "add(1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        -1.175494490952134e-38,
        "add(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        -1.1754942106924411e-38,
        "add(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        1.1754942106924411e-38,
        "add(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        1.175494490952134e-38,
        "add(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        -2.350988701644575e-38,
        "add(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        0.0,
        "add(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        0.0,
        "add(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        2.350988701644575e-38,
        "add(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, -0.5),
        -0.5,
        "add(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, 0.5),
        0.5,
        "add(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, -0.5),
        -0.5,
        "add(1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, 0.5),
        0.5,
        "add(1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, -1.0),
        -1.0,
        "add(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, 1.0),
        1.0,
        "add(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, -1.0),
        -1.0,
        "add(1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, 1.0),
        1.0,
        "add(1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        -6.2831854820251465,
        "add(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        6.2831854820251465,
        "add(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        -6.2831854820251465,
        "add(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        6.2831854820251465,
        "add(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "add(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "add(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "add(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "add(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, -INFINITY),
        -INFINITY,
        "add(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -1.1754943508222875e-38, INFINITY),
        INFINITY,
        "add(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, -INFINITY),
        -INFINITY,
        "add(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 1.1754943508222875e-38, INFINITY),
        INFINITY,
        "add(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, -0.0),
        -0.5,
        "add(-0.5, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, 0.0),
        -0.5,
        "add(-0.5, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, -0.0),
        0.5,
        "add(0.5, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, 0.0),
        0.5,
        "add(0.5, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, -1.401298464324817e-45),
        -0.5,
        "add(-0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, 1.401298464324817e-45),
        -0.5,
        "add(-0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, -1.401298464324817e-45),
        0.5,
        "add(0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, 1.401298464324817e-45),
        0.5,
        "add(0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, -1.1754943508222875e-38),
        -0.5,
        "add(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, 1.1754943508222875e-38),
        -0.5,
        "add(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, -1.1754943508222875e-38),
        0.5,
        "add(0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, 1.1754943508222875e-38),
        0.5,
        "add(0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, -0.5),
        -1.0,
        "add(-0.5, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, 0.5),
        0.0,
        "add(-0.5, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, -0.5),
        0.0,
        "add(0.5, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, 0.5),
        1.0,
        "add(0.5, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, -1.0),
        -1.5,
        "add(-0.5, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, 1.0),
        0.5,
        "add(-0.5, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, -1.0),
        -0.5,
        "add(0.5, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, 1.0),
        1.5,
        "add(0.5, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, -6.2831854820251465),
        -6.7831854820251465,
        "add(-0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, 6.2831854820251465),
        5.7831854820251465,
        "add(-0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, -6.2831854820251465),
        -5.7831854820251465,
        "add(0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, 6.2831854820251465),
        6.7831854820251465,
        "add(0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "add(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "add(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "add(0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "add(0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, -INFINITY),
        -INFINITY,
        "add(-0.5, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -0.5, INFINITY),
        INFINITY,
        "add(-0.5, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, -INFINITY),
        -INFINITY,
        "add(0.5, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 0.5, INFINITY),
        INFINITY,
        "add(0.5, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, -0.0),
        -1.0,
        "add(-1.0, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, 0.0),
        -1.0,
        "add(-1.0, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, -0.0),
        1.0,
        "add(1.0, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, 0.0),
        1.0,
        "add(1.0, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, -1.401298464324817e-45),
        -1.0,
        "add(-1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, 1.401298464324817e-45),
        -1.0,
        "add(-1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, -1.401298464324817e-45),
        1.0,
        "add(1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, 1.401298464324817e-45),
        1.0,
        "add(1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, -1.1754943508222875e-38),
        -1.0,
        "add(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, 1.1754943508222875e-38),
        -1.0,
        "add(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, -1.1754943508222875e-38),
        1.0,
        "add(1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, 1.1754943508222875e-38),
        1.0,
        "add(1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, -0.5),
        -1.5,
        "add(-1.0, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, 0.5),
        -0.5,
        "add(-1.0, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, -0.5),
        0.5,
        "add(1.0, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, 0.5),
        1.5,
        "add(1.0, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, -1.0),
        -2.0,
        "add(-1.0, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, 1.0),
        0.0,
        "add(-1.0, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, -1.0),
        0.0,
        "add(1.0, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, 1.0),
        2.0,
        "add(1.0, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, -6.2831854820251465),
        -7.2831854820251465,
        "add(-1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, 6.2831854820251465),
        5.2831854820251465,
        "add(-1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, -6.2831854820251465),
        -5.2831854820251465,
        "add(1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, 6.2831854820251465),
        7.2831854820251465,
        "add(1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "add(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "add(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "add(1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "add(1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, -INFINITY),
        -INFINITY,
        "add(-1.0, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -1.0, INFINITY),
        INFINITY,
        "add(-1.0, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, -INFINITY),
        -INFINITY,
        "add(1.0, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 1.0, INFINITY),
        INFINITY,
        "add(1.0, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, -0.0),
        -6.2831854820251465,
        "add(-6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, 0.0),
        -6.2831854820251465,
        "add(-6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, -0.0),
        6.2831854820251465,
        "add(6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, 0.0),
        6.2831854820251465,
        "add(6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, -1.401298464324817e-45),
        -6.2831854820251465,
        "add(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, 1.401298464324817e-45),
        -6.2831854820251465,
        "add(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, -1.401298464324817e-45),
        6.2831854820251465,
        "add(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, 1.401298464324817e-45),
        6.2831854820251465,
        "add(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        -6.2831854820251465,
        "add(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        -6.2831854820251465,
        "add(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        6.2831854820251465,
        "add(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        6.2831854820251465,
        "add(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, -0.5),
        -6.7831854820251465,
        "add(-6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, 0.5),
        -5.7831854820251465,
        "add(-6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, -0.5),
        5.7831854820251465,
        "add(6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, 0.5),
        6.7831854820251465,
        "add(6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, -1.0),
        -7.2831854820251465,
        "add(-6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, 1.0),
        -5.2831854820251465,
        "add(-6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, -1.0),
        5.2831854820251465,
        "add(6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, 1.0),
        7.2831854820251465,
        "add(6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, -6.2831854820251465),
        -12.566370964050293,
        "add(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, 6.2831854820251465),
        0.0,
        "add(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, -6.2831854820251465),
        0.0,
        "add(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, 6.2831854820251465),
        12.566370964050293,
        "add(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "add(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "add(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "add(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "add(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, -INFINITY),
        -INFINITY,
        "add(-6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -6.2831854820251465, INFINITY),
        INFINITY,
        "add(-6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, -INFINITY),
        -INFINITY,
        "add(6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 6.2831854820251465, INFINITY),
        INFINITY,
        "add(6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, -0.0),
        -3.4028234663852886e+38,
        "add(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, 0.0),
        -3.4028234663852886e+38,
        "add(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, -0.0),
        3.4028234663852886e+38,
        "add(3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, 0.0),
        3.4028234663852886e+38,
        "add(3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        -3.4028234663852886e+38,
        "add(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        -3.4028234663852886e+38,
        "add(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        3.4028234663852886e+38,
        "add(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        3.4028234663852886e+38,
        "add(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        -3.4028234663852886e+38,
        "add(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        -3.4028234663852886e+38,
        "add(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        3.4028234663852886e+38,
        "add(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        3.4028234663852886e+38,
        "add(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, -0.5),
        -3.4028234663852886e+38,
        "add(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, 0.5),
        -3.4028234663852886e+38,
        "add(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, -0.5),
        3.4028234663852886e+38,
        "add(3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, 0.5),
        3.4028234663852886e+38,
        "add(3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, -1.0),
        -3.4028234663852886e+38,
        "add(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, 1.0),
        -3.4028234663852886e+38,
        "add(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, -1.0),
        3.4028234663852886e+38,
        "add(3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, 1.0),
        3.4028234663852886e+38,
        "add(3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        -3.4028234663852886e+38,
        "add(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        -3.4028234663852886e+38,
        "add(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        3.4028234663852886e+38,
        "add(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        3.4028234663852886e+38,
        "add(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        -INFINITY,
        "add(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        0.0,
        "add(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        0.0,
        "add(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        INFINITY,
        "add(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, -INFINITY),
        -INFINITY,
        "add(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -3.4028234663852886e+38, INFINITY),
        INFINITY,
        "add(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, -INFINITY),
        -INFINITY,
        "add(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, 3.4028234663852886e+38, INFINITY),
        INFINITY,
        "add(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, -0.0),
        -INFINITY,
        "add(-INFINITY, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, 0.0),
        -INFINITY,
        "add(-INFINITY, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, -0.0),
        INFINITY,
        "add(INFINITY, -0.0)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, 0.0),
        INFINITY,
        "add(INFINITY, 0.0)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, -1.401298464324817e-45),
        -INFINITY,
        "add(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, 1.401298464324817e-45),
        -INFINITY,
        "add(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, -1.401298464324817e-45),
        INFINITY,
        "add(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, 1.401298464324817e-45),
        INFINITY,
        "add(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, -1.1754943508222875e-38),
        -INFINITY,
        "add(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, 1.1754943508222875e-38),
        -INFINITY,
        "add(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, -1.1754943508222875e-38),
        INFINITY,
        "add(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, 1.1754943508222875e-38),
        INFINITY,
        "add(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, -0.5),
        -INFINITY,
        "add(-INFINITY, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, 0.5),
        -INFINITY,
        "add(-INFINITY, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, -0.5),
        INFINITY,
        "add(INFINITY, -0.5)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, 0.5),
        INFINITY,
        "add(INFINITY, 0.5)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, -1.0),
        -INFINITY,
        "add(-INFINITY, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, 1.0),
        -INFINITY,
        "add(-INFINITY, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, -1.0),
        INFINITY,
        "add(INFINITY, -1.0)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, 1.0),
        INFINITY,
        "add(INFINITY, 1.0)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, -6.2831854820251465),
        -INFINITY,
        "add(-INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, 6.2831854820251465),
        -INFINITY,
        "add(-INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, -6.2831854820251465),
        INFINITY,
        "add(INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, 6.2831854820251465),
        INFINITY,
        "add(INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, -3.4028234663852886e+38),
        -INFINITY,
        "add(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, 3.4028234663852886e+38),
        -INFINITY,
        "add(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, -3.4028234663852886e+38),
        INFINITY,
        "add(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, 3.4028234663852886e+38),
        INFINITY,
        "add(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_add(&instance, -INFINITY, -INFINITY),
        -INFINITY,
        "add(-INFINITY, -INFINITY)"
    );
    assertEqualF32(
        f320_add(&instance, INFINITY, INFINITY),
        INFINITY,
        "add(INFINITY, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, -0.0),
        0.0,
        "sub(-0.0, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, 0.0),
        -0.0,
        "sub(-0.0, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, -0.0),
        0.0,
        "sub(0.0, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, 0.0),
        0.0,
        "sub(0.0, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, -1.401298464324817e-45),
        1.401298464324817e-45,
        "sub(-0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, 1.401298464324817e-45),
        -1.401298464324817e-45,
        "sub(-0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, -1.401298464324817e-45),
        1.401298464324817e-45,
        "sub(0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, 1.401298464324817e-45),
        -1.401298464324817e-45,
        "sub(0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, -1.1754943508222875e-38),
        1.1754943508222875e-38,
        "sub(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, 1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "sub(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, -1.1754943508222875e-38),
        1.1754943508222875e-38,
        "sub(0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, 1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "sub(0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, -0.5),
        0.5,
        "sub(-0.0, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, 0.5),
        -0.5,
        "sub(-0.0, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, -0.5),
        0.5,
        "sub(0.0, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, 0.5),
        -0.5,
        "sub(0.0, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, -1.0),
        1.0,
        "sub(-0.0, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, 1.0),
        -1.0,
        "sub(-0.0, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, -1.0),
        1.0,
        "sub(0.0, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, 1.0),
        -1.0,
        "sub(0.0, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, -6.2831854820251465),
        6.2831854820251465,
        "sub(-0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, 6.2831854820251465),
        -6.2831854820251465,
        "sub(-0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, -6.2831854820251465),
        6.2831854820251465,
        "sub(0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, 6.2831854820251465),
        -6.2831854820251465,
        "sub(0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "sub(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "sub(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "sub(0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "sub(0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, -INFINITY),
        INFINITY,
        "sub(-0.0, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.0, INFINITY),
        -INFINITY,
        "sub(-0.0, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, -INFINITY),
        INFINITY,
        "sub(0.0, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.0, INFINITY),
        -INFINITY,
        "sub(0.0, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, -0.0),
        -1.401298464324817e-45,
        "sub(-1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, 0.0),
        -1.401298464324817e-45,
        "sub(-1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, -0.0),
        1.401298464324817e-45,
        "sub(1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, 0.0),
        1.401298464324817e-45,
        "sub(1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        0.0,
        "sub(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        -2.802596928649634e-45,
        "sub(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        2.802596928649634e-45,
        "sub(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        0.0,
        "sub(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        1.1754942106924411e-38,
        "sub(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        -1.175494490952134e-38,
        "sub(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        1.175494490952134e-38,
        "sub(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        -1.1754942106924411e-38,
        "sub(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, -0.5),
        0.5,
        "sub(-1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, 0.5),
        -0.5,
        "sub(-1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, -0.5),
        0.5,
        "sub(1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, 0.5),
        -0.5,
        "sub(1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, -1.0),
        1.0,
        "sub(-1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, 1.0),
        -1.0,
        "sub(-1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, -1.0),
        1.0,
        "sub(1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, 1.0),
        -1.0,
        "sub(1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, -6.2831854820251465),
        6.2831854820251465,
        "sub(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, 6.2831854820251465),
        -6.2831854820251465,
        "sub(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, -6.2831854820251465),
        6.2831854820251465,
        "sub(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, 6.2831854820251465),
        -6.2831854820251465,
        "sub(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "sub(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "sub(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "sub(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "sub(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, -INFINITY),
        INFINITY,
        "sub(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.401298464324817e-45, INFINITY),
        -INFINITY,
        "sub(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, -INFINITY),
        INFINITY,
        "sub(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.401298464324817e-45, INFINITY),
        -INFINITY,
        "sub(1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, -0.0),
        -1.1754943508222875e-38,
        "sub(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, 0.0),
        -1.1754943508222875e-38,
        "sub(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, -0.0),
        1.1754943508222875e-38,
        "sub(1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, 0.0),
        1.1754943508222875e-38,
        "sub(1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        -1.1754942106924411e-38,
        "sub(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        -1.175494490952134e-38,
        "sub(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        1.175494490952134e-38,
        "sub(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        1.1754942106924411e-38,
        "sub(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        0.0,
        "sub(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        -2.350988701644575e-38,
        "sub(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        2.350988701644575e-38,
        "sub(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        0.0,
        "sub(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, -0.5),
        0.5,
        "sub(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, 0.5),
        -0.5,
        "sub(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, -0.5),
        0.5,
        "sub(1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, 0.5),
        -0.5,
        "sub(1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, -1.0),
        1.0,
        "sub(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, 1.0),
        -1.0,
        "sub(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, -1.0),
        1.0,
        "sub(1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, 1.0),
        -1.0,
        "sub(1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        6.2831854820251465,
        "sub(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        -6.2831854820251465,
        "sub(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        6.2831854820251465,
        "sub(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        -6.2831854820251465,
        "sub(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "sub(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "sub(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "sub(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "sub(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, -INFINITY),
        INFINITY,
        "sub(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.1754943508222875e-38, INFINITY),
        -INFINITY,
        "sub(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, -INFINITY),
        INFINITY,
        "sub(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.1754943508222875e-38, INFINITY),
        -INFINITY,
        "sub(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, -0.0),
        -0.5,
        "sub(-0.5, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, 0.0),
        -0.5,
        "sub(-0.5, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, -0.0),
        0.5,
        "sub(0.5, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, 0.0),
        0.5,
        "sub(0.5, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, -1.401298464324817e-45),
        -0.5,
        "sub(-0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, 1.401298464324817e-45),
        -0.5,
        "sub(-0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, -1.401298464324817e-45),
        0.5,
        "sub(0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, 1.401298464324817e-45),
        0.5,
        "sub(0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, -1.1754943508222875e-38),
        -0.5,
        "sub(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, 1.1754943508222875e-38),
        -0.5,
        "sub(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, -1.1754943508222875e-38),
        0.5,
        "sub(0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, 1.1754943508222875e-38),
        0.5,
        "sub(0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, -0.5),
        0.0,
        "sub(-0.5, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, 0.5),
        -1.0,
        "sub(-0.5, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, -0.5),
        1.0,
        "sub(0.5, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, 0.5),
        0.0,
        "sub(0.5, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, -1.0),
        0.5,
        "sub(-0.5, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, 1.0),
        -1.5,
        "sub(-0.5, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, -1.0),
        1.5,
        "sub(0.5, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, 1.0),
        -0.5,
        "sub(0.5, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, -6.2831854820251465),
        5.7831854820251465,
        "sub(-0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, 6.2831854820251465),
        -6.7831854820251465,
        "sub(-0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, -6.2831854820251465),
        6.7831854820251465,
        "sub(0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, 6.2831854820251465),
        -5.7831854820251465,
        "sub(0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "sub(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "sub(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "sub(0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "sub(0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, -INFINITY),
        INFINITY,
        "sub(-0.5, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -0.5, INFINITY),
        -INFINITY,
        "sub(-0.5, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, -INFINITY),
        INFINITY,
        "sub(0.5, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 0.5, INFINITY),
        -INFINITY,
        "sub(0.5, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, -0.0),
        -1.0,
        "sub(-1.0, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, 0.0),
        -1.0,
        "sub(-1.0, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, -0.0),
        1.0,
        "sub(1.0, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, 0.0),
        1.0,
        "sub(1.0, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, -1.401298464324817e-45),
        -1.0,
        "sub(-1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, 1.401298464324817e-45),
        -1.0,
        "sub(-1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, -1.401298464324817e-45),
        1.0,
        "sub(1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, 1.401298464324817e-45),
        1.0,
        "sub(1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, -1.1754943508222875e-38),
        -1.0,
        "sub(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, 1.1754943508222875e-38),
        -1.0,
        "sub(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, -1.1754943508222875e-38),
        1.0,
        "sub(1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, 1.1754943508222875e-38),
        1.0,
        "sub(1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, -0.5),
        -0.5,
        "sub(-1.0, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, 0.5),
        -1.5,
        "sub(-1.0, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, -0.5),
        1.5,
        "sub(1.0, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, 0.5),
        0.5,
        "sub(1.0, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, -1.0),
        0.0,
        "sub(-1.0, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, 1.0),
        -2.0,
        "sub(-1.0, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, -1.0),
        2.0,
        "sub(1.0, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, 1.0),
        0.0,
        "sub(1.0, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, -6.2831854820251465),
        5.2831854820251465,
        "sub(-1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, 6.2831854820251465),
        -7.2831854820251465,
        "sub(-1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, -6.2831854820251465),
        7.2831854820251465,
        "sub(1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, 6.2831854820251465),
        -5.2831854820251465,
        "sub(1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "sub(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "sub(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "sub(1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "sub(1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, -INFINITY),
        INFINITY,
        "sub(-1.0, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -1.0, INFINITY),
        -INFINITY,
        "sub(-1.0, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, -INFINITY),
        INFINITY,
        "sub(1.0, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 1.0, INFINITY),
        -INFINITY,
        "sub(1.0, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, -0.0),
        -6.2831854820251465,
        "sub(-6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, 0.0),
        -6.2831854820251465,
        "sub(-6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, -0.0),
        6.2831854820251465,
        "sub(6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, 0.0),
        6.2831854820251465,
        "sub(6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, -1.401298464324817e-45),
        -6.2831854820251465,
        "sub(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, 1.401298464324817e-45),
        -6.2831854820251465,
        "sub(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, -1.401298464324817e-45),
        6.2831854820251465,
        "sub(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, 1.401298464324817e-45),
        6.2831854820251465,
        "sub(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        -6.2831854820251465,
        "sub(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        -6.2831854820251465,
        "sub(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        6.2831854820251465,
        "sub(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        6.2831854820251465,
        "sub(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, -0.5),
        -5.7831854820251465,
        "sub(-6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, 0.5),
        -6.7831854820251465,
        "sub(-6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, -0.5),
        6.7831854820251465,
        "sub(6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, 0.5),
        5.7831854820251465,
        "sub(6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, -1.0),
        -5.2831854820251465,
        "sub(-6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, 1.0),
        -7.2831854820251465,
        "sub(-6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, -1.0),
        7.2831854820251465,
        "sub(6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, 1.0),
        5.2831854820251465,
        "sub(6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, -6.2831854820251465),
        0.0,
        "sub(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, 6.2831854820251465),
        -12.566370964050293,
        "sub(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, -6.2831854820251465),
        12.566370964050293,
        "sub(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, 6.2831854820251465),
        0.0,
        "sub(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "sub(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "sub(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "sub(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "sub(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, -INFINITY),
        INFINITY,
        "sub(-6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -6.2831854820251465, INFINITY),
        -INFINITY,
        "sub(-6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, -INFINITY),
        INFINITY,
        "sub(6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 6.2831854820251465, INFINITY),
        -INFINITY,
        "sub(6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, -0.0),
        -3.4028234663852886e+38,
        "sub(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, 0.0),
        -3.4028234663852886e+38,
        "sub(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, -0.0),
        3.4028234663852886e+38,
        "sub(3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, 0.0),
        3.4028234663852886e+38,
        "sub(3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        -3.4028234663852886e+38,
        "sub(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        -3.4028234663852886e+38,
        "sub(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        3.4028234663852886e+38,
        "sub(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        3.4028234663852886e+38,
        "sub(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        -3.4028234663852886e+38,
        "sub(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        -3.4028234663852886e+38,
        "sub(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        3.4028234663852886e+38,
        "sub(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        3.4028234663852886e+38,
        "sub(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, -0.5),
        -3.4028234663852886e+38,
        "sub(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, 0.5),
        -3.4028234663852886e+38,
        "sub(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, -0.5),
        3.4028234663852886e+38,
        "sub(3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, 0.5),
        3.4028234663852886e+38,
        "sub(3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, -1.0),
        -3.4028234663852886e+38,
        "sub(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, 1.0),
        -3.4028234663852886e+38,
        "sub(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, -1.0),
        3.4028234663852886e+38,
        "sub(3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, 1.0),
        3.4028234663852886e+38,
        "sub(3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        -3.4028234663852886e+38,
        "sub(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        -3.4028234663852886e+38,
        "sub(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        3.4028234663852886e+38,
        "sub(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        3.4028234663852886e+38,
        "sub(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        0.0,
        "sub(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        -INFINITY,
        "sub(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        INFINITY,
        "sub(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        0.0,
        "sub(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, -INFINITY),
        INFINITY,
        "sub(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -3.4028234663852886e+38, INFINITY),
        -INFINITY,
        "sub(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, -INFINITY),
        INFINITY,
        "sub(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, 3.4028234663852886e+38, INFINITY),
        -INFINITY,
        "sub(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, -0.0),
        -INFINITY,
        "sub(-INFINITY, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, 0.0),
        -INFINITY,
        "sub(-INFINITY, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, -0.0),
        INFINITY,
        "sub(INFINITY, -0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, 0.0),
        INFINITY,
        "sub(INFINITY, 0.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, -1.401298464324817e-45),
        -INFINITY,
        "sub(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, 1.401298464324817e-45),
        -INFINITY,
        "sub(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, -1.401298464324817e-45),
        INFINITY,
        "sub(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, 1.401298464324817e-45),
        INFINITY,
        "sub(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, -1.1754943508222875e-38),
        -INFINITY,
        "sub(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, 1.1754943508222875e-38),
        -INFINITY,
        "sub(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, -1.1754943508222875e-38),
        INFINITY,
        "sub(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, 1.1754943508222875e-38),
        INFINITY,
        "sub(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, -0.5),
        -INFINITY,
        "sub(-INFINITY, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, 0.5),
        -INFINITY,
        "sub(-INFINITY, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, -0.5),
        INFINITY,
        "sub(INFINITY, -0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, 0.5),
        INFINITY,
        "sub(INFINITY, 0.5)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, -1.0),
        -INFINITY,
        "sub(-INFINITY, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, 1.0),
        -INFINITY,
        "sub(-INFINITY, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, -1.0),
        INFINITY,
        "sub(INFINITY, -1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, 1.0),
        INFINITY,
        "sub(INFINITY, 1.0)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, -6.2831854820251465),
        -INFINITY,
        "sub(-INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, 6.2831854820251465),
        -INFINITY,
        "sub(-INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, -6.2831854820251465),
        INFINITY,
        "sub(INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, 6.2831854820251465),
        INFINITY,
        "sub(INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, -3.4028234663852886e+38),
        -INFINITY,
        "sub(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, 3.4028234663852886e+38),
        -INFINITY,
        "sub(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, -3.4028234663852886e+38),
        INFINITY,
        "sub(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, 3.4028234663852886e+38),
        INFINITY,
        "sub(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sub(&instance, -INFINITY, INFINITY),
        -INFINITY,
        "sub(-INFINITY, INFINITY)"
    );
    assertEqualF32(
        f320_sub(&instance, INFINITY, -INFINITY),
        INFINITY,
        "sub(INFINITY, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, -0.0),
        0.0,
        "mul(-0.0, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, 0.0),
        -0.0,
        "mul(-0.0, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, -0.0),
        -0.0,
        "mul(0.0, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, 0.0),
        0.0,
        "mul(0.0, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, -1.401298464324817e-45),
        0.0,
        "mul(-0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, 1.401298464324817e-45),
        -0.0,
        "mul(-0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, -1.401298464324817e-45),
        -0.0,
        "mul(0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, 1.401298464324817e-45),
        0.0,
        "mul(0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, -1.1754943508222875e-38),
        0.0,
        "mul(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, 1.1754943508222875e-38),
        -0.0,
        "mul(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, -1.1754943508222875e-38),
        -0.0,
        "mul(0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, 1.1754943508222875e-38),
        0.0,
        "mul(0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, -0.5),
        0.0,
        "mul(-0.0, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, 0.5),
        -0.0,
        "mul(-0.0, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, -0.5),
        -0.0,
        "mul(0.0, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, 0.5),
        0.0,
        "mul(0.0, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, -1.0),
        0.0,
        "mul(-0.0, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, 1.0),
        -0.0,
        "mul(-0.0, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, -1.0),
        -0.0,
        "mul(0.0, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, 1.0),
        0.0,
        "mul(0.0, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, -6.2831854820251465),
        0.0,
        "mul(-0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, 6.2831854820251465),
        -0.0,
        "mul(-0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, -6.2831854820251465),
        -0.0,
        "mul(0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, 6.2831854820251465),
        0.0,
        "mul(0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, -3.4028234663852886e+38),
        0.0,
        "mul(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.0, 3.4028234663852886e+38),
        -0.0,
        "mul(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, -3.4028234663852886e+38),
        -0.0,
        "mul(0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.0, 3.4028234663852886e+38),
        0.0,
        "mul(0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, -0.0),
        0.0,
        "mul(-1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, 0.0),
        -0.0,
        "mul(-1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, -0.0),
        -0.0,
        "mul(1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, 0.0),
        0.0,
        "mul(1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        0.0,
        "mul(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        -0.0,
        "mul(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        -0.0,
        "mul(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        0.0,
        "mul(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        0.0,
        "mul(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        -0.0,
        "mul(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        -0.0,
        "mul(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        0.0,
        "mul(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, -0.5),
        0.0,
        "mul(-1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, 0.5),
        -0.0,
        "mul(-1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, -0.5),
        -0.0,
        "mul(1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, 0.5),
        0.0,
        "mul(1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, -1.0),
        1.401298464324817e-45,
        "mul(-1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, 1.0),
        -1.401298464324817e-45,
        "mul(-1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, -1.0),
        -1.401298464324817e-45,
        "mul(1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, 1.0),
        1.401298464324817e-45,
        "mul(1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, -6.2831854820251465),
        8.407790785948902e-45,
        "mul(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, 6.2831854820251465),
        -8.407790785948902e-45,
        "mul(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, -6.2831854820251465),
        -8.407790785948902e-45,
        "mul(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, 6.2831854820251465),
        8.407790785948902e-45,
        "mul(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        4.7683712978141557e-07,
        "mul(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        -4.7683712978141557e-07,
        "mul(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        -4.7683712978141557e-07,
        "mul(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        4.7683712978141557e-07,
        "mul(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, -INFINITY),
        INFINITY,
        "mul(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.401298464324817e-45, INFINITY),
        -INFINITY,
        "mul(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, -INFINITY),
        -INFINITY,
        "mul(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.401298464324817e-45, INFINITY),
        INFINITY,
        "mul(1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, -0.0),
        0.0,
        "mul(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, 0.0),
        -0.0,
        "mul(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, -0.0),
        -0.0,
        "mul(1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, 0.0),
        0.0,
        "mul(1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        0.0,
        "mul(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        -0.0,
        "mul(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        -0.0,
        "mul(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        0.0,
        "mul(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        0.0,
        "mul(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        -0.0,
        "mul(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        -0.0,
        "mul(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        0.0,
        "mul(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, -0.5),
        5.877471754111438e-39,
        "mul(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, 0.5),
        -5.877471754111438e-39,
        "mul(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, -0.5),
        -5.877471754111438e-39,
        "mul(1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, 0.5),
        5.877471754111438e-39,
        "mul(1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, -1.0),
        1.1754943508222875e-38,
        "mul(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, 1.0),
        -1.1754943508222875e-38,
        "mul(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, -1.0),
        -1.1754943508222875e-38,
        "mul(1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, 1.0),
        1.1754943508222875e-38,
        "mul(1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        7.385849039289171e-38,
        "mul(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        -7.385849039289171e-38,
        "mul(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        -7.385849039289171e-38,
        "mul(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        7.385849039289171e-38,
        "mul(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        3.999999761581421,
        "mul(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        -3.999999761581421,
        "mul(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        -3.999999761581421,
        "mul(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        3.999999761581421,
        "mul(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, -INFINITY),
        INFINITY,
        "mul(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.1754943508222875e-38, INFINITY),
        -INFINITY,
        "mul(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, -INFINITY),
        -INFINITY,
        "mul(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.1754943508222875e-38, INFINITY),
        INFINITY,
        "mul(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, -0.0),
        0.0,
        "mul(-0.5, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, 0.0),
        -0.0,
        "mul(-0.5, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, -0.0),
        -0.0,
        "mul(0.5, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, 0.0),
        0.0,
        "mul(0.5, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, -1.401298464324817e-45),
        0.0,
        "mul(-0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, 1.401298464324817e-45),
        -0.0,
        "mul(-0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, -1.401298464324817e-45),
        -0.0,
        "mul(0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, 1.401298464324817e-45),
        0.0,
        "mul(0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, -1.1754943508222875e-38),
        5.877471754111438e-39,
        "mul(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, 1.1754943508222875e-38),
        -5.877471754111438e-39,
        "mul(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, -1.1754943508222875e-38),
        -5.877471754111438e-39,
        "mul(0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, 1.1754943508222875e-38),
        5.877471754111438e-39,
        "mul(0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, -0.5),
        0.25,
        "mul(-0.5, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, 0.5),
        -0.25,
        "mul(-0.5, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, -0.5),
        -0.25,
        "mul(0.5, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, 0.5),
        0.25,
        "mul(0.5, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, -1.0),
        0.5,
        "mul(-0.5, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, 1.0),
        -0.5,
        "mul(-0.5, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, -1.0),
        -0.5,
        "mul(0.5, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, 1.0),
        0.5,
        "mul(0.5, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, -6.2831854820251465),
        3.1415927410125732,
        "mul(-0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, 6.2831854820251465),
        -3.1415927410125732,
        "mul(-0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, -6.2831854820251465),
        -3.1415927410125732,
        "mul(0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, 6.2831854820251465),
        3.1415927410125732,
        "mul(0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, -3.4028234663852886e+38),
        1.7014117331926443e+38,
        "mul(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, 3.4028234663852886e+38),
        -1.7014117331926443e+38,
        "mul(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, -3.4028234663852886e+38),
        -1.7014117331926443e+38,
        "mul(0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, 3.4028234663852886e+38),
        1.7014117331926443e+38,
        "mul(0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, -INFINITY),
        INFINITY,
        "mul(-0.5, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -0.5, INFINITY),
        -INFINITY,
        "mul(-0.5, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, -INFINITY),
        -INFINITY,
        "mul(0.5, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, 0.5, INFINITY),
        INFINITY,
        "mul(0.5, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, -0.0),
        0.0,
        "mul(-1.0, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, 0.0),
        -0.0,
        "mul(-1.0, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, -0.0),
        -0.0,
        "mul(1.0, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, 0.0),
        0.0,
        "mul(1.0, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, -1.401298464324817e-45),
        1.401298464324817e-45,
        "mul(-1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, 1.401298464324817e-45),
        -1.401298464324817e-45,
        "mul(-1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "mul(1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, 1.401298464324817e-45),
        1.401298464324817e-45,
        "mul(1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, -1.1754943508222875e-38),
        1.1754943508222875e-38,
        "mul(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, 1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "mul(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "mul(1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "mul(1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, -0.5),
        0.5,
        "mul(-1.0, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, 0.5),
        -0.5,
        "mul(-1.0, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, -0.5),
        -0.5,
        "mul(1.0, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, 0.5),
        0.5,
        "mul(1.0, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, -1.0),
        1.0,
        "mul(-1.0, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, 1.0),
        -1.0,
        "mul(-1.0, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, -1.0),
        -1.0,
        "mul(1.0, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, 1.0),
        1.0,
        "mul(1.0, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, -6.2831854820251465),
        6.2831854820251465,
        "mul(-1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, 6.2831854820251465),
        -6.2831854820251465,
        "mul(-1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, -6.2831854820251465),
        -6.2831854820251465,
        "mul(1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, 6.2831854820251465),
        6.2831854820251465,
        "mul(1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "mul(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "mul(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "mul(1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "mul(1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, -INFINITY),
        INFINITY,
        "mul(-1.0, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -1.0, INFINITY),
        -INFINITY,
        "mul(-1.0, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, -INFINITY),
        -INFINITY,
        "mul(1.0, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, 1.0, INFINITY),
        INFINITY,
        "mul(1.0, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, -0.0),
        0.0,
        "mul(-6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, 0.0),
        -0.0,
        "mul(-6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, -0.0),
        -0.0,
        "mul(6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, 0.0),
        0.0,
        "mul(6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, -1.401298464324817e-45),
        8.407790785948902e-45,
        "mul(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, 1.401298464324817e-45),
        -8.407790785948902e-45,
        "mul(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, -1.401298464324817e-45),
        -8.407790785948902e-45,
        "mul(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, 1.401298464324817e-45),
        8.407790785948902e-45,
        "mul(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        7.385849039289171e-38,
        "mul(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        -7.385849039289171e-38,
        "mul(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        -7.385849039289171e-38,
        "mul(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        7.385849039289171e-38,
        "mul(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, -0.5),
        3.1415927410125732,
        "mul(-6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, 0.5),
        -3.1415927410125732,
        "mul(-6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, -0.5),
        -3.1415927410125732,
        "mul(6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, 0.5),
        3.1415927410125732,
        "mul(6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, -1.0),
        6.2831854820251465,
        "mul(-6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, 1.0),
        -6.2831854820251465,
        "mul(-6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, -1.0),
        -6.2831854820251465,
        "mul(6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, 1.0),
        6.2831854820251465,
        "mul(6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, -6.2831854820251465),
        39.47842025756836,
        "mul(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, 6.2831854820251465),
        -39.47842025756836,
        "mul(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, -6.2831854820251465),
        -39.47842025756836,
        "mul(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, 6.2831854820251465),
        39.47842025756836,
        "mul(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        INFINITY,
        "mul(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        -INFINITY,
        "mul(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        -INFINITY,
        "mul(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        INFINITY,
        "mul(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, -INFINITY),
        INFINITY,
        "mul(-6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -6.2831854820251465, INFINITY),
        -INFINITY,
        "mul(-6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, -INFINITY),
        -INFINITY,
        "mul(6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, 6.2831854820251465, INFINITY),
        INFINITY,
        "mul(6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, -0.0),
        0.0,
        "mul(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, 0.0),
        -0.0,
        "mul(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, -0.0),
        -0.0,
        "mul(3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, 0.0),
        0.0,
        "mul(3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        4.7683712978141557e-07,
        "mul(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        -4.7683712978141557e-07,
        "mul(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        -4.7683712978141557e-07,
        "mul(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        4.7683712978141557e-07,
        "mul(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        3.999999761581421,
        "mul(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        -3.999999761581421,
        "mul(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        -3.999999761581421,
        "mul(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        3.999999761581421,
        "mul(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, -0.5),
        1.7014117331926443e+38,
        "mul(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, 0.5),
        -1.7014117331926443e+38,
        "mul(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, -0.5),
        -1.7014117331926443e+38,
        "mul(3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, 0.5),
        1.7014117331926443e+38,
        "mul(3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, -1.0),
        3.4028234663852886e+38,
        "mul(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, 1.0),
        -3.4028234663852886e+38,
        "mul(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, -1.0),
        -3.4028234663852886e+38,
        "mul(3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, 1.0),
        3.4028234663852886e+38,
        "mul(3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        INFINITY,
        "mul(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        -INFINITY,
        "mul(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        -INFINITY,
        "mul(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        INFINITY,
        "mul(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        INFINITY,
        "mul(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        -INFINITY,
        "mul(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        -INFINITY,
        "mul(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        INFINITY,
        "mul(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, -INFINITY),
        INFINITY,
        "mul(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -3.4028234663852886e+38, INFINITY),
        -INFINITY,
        "mul(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, -INFINITY),
        -INFINITY,
        "mul(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, 3.4028234663852886e+38, INFINITY),
        INFINITY,
        "mul(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, -1.401298464324817e-45),
        INFINITY,
        "mul(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, 1.401298464324817e-45),
        -INFINITY,
        "mul(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, -1.401298464324817e-45),
        -INFINITY,
        "mul(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, 1.401298464324817e-45),
        INFINITY,
        "mul(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, -1.1754943508222875e-38),
        INFINITY,
        "mul(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, 1.1754943508222875e-38),
        -INFINITY,
        "mul(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, -1.1754943508222875e-38),
        -INFINITY,
        "mul(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, 1.1754943508222875e-38),
        INFINITY,
        "mul(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, -0.5),
        INFINITY,
        "mul(-INFINITY, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, 0.5),
        -INFINITY,
        "mul(-INFINITY, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, -0.5),
        -INFINITY,
        "mul(INFINITY, -0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, 0.5),
        INFINITY,
        "mul(INFINITY, 0.5)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, -1.0),
        INFINITY,
        "mul(-INFINITY, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, 1.0),
        -INFINITY,
        "mul(-INFINITY, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, -1.0),
        -INFINITY,
        "mul(INFINITY, -1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, 1.0),
        INFINITY,
        "mul(INFINITY, 1.0)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, -6.2831854820251465),
        INFINITY,
        "mul(-INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, 6.2831854820251465),
        -INFINITY,
        "mul(-INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, -6.2831854820251465),
        -INFINITY,
        "mul(INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, 6.2831854820251465),
        INFINITY,
        "mul(INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, -3.4028234663852886e+38),
        INFINITY,
        "mul(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, 3.4028234663852886e+38),
        -INFINITY,
        "mul(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, -3.4028234663852886e+38),
        -INFINITY,
        "mul(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, 3.4028234663852886e+38),
        INFINITY,
        "mul(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, -INFINITY),
        INFINITY,
        "mul(-INFINITY, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, -INFINITY, INFINITY),
        -INFINITY,
        "mul(-INFINITY, INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, -INFINITY),
        -INFINITY,
        "mul(INFINITY, -INFINITY)"
    );
    assertEqualF32(
        f320_mul(&instance, INFINITY, INFINITY),
        INFINITY,
        "mul(INFINITY, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, -1.401298464324817e-45),
        0.0,
        "div(-0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, 1.401298464324817e-45),
        -0.0,
        "div(-0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, -1.401298464324817e-45),
        -0.0,
        "div(0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, 1.401298464324817e-45),
        0.0,
        "div(0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, -1.1754943508222875e-38),
        0.0,
        "div(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, 1.1754943508222875e-38),
        -0.0,
        "div(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, -1.1754943508222875e-38),
        -0.0,
        "div(0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, 1.1754943508222875e-38),
        0.0,
        "div(0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, -0.5),
        0.0,
        "div(-0.0, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, 0.5),
        -0.0,
        "div(-0.0, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, -0.5),
        -0.0,
        "div(0.0, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, 0.5),
        0.0,
        "div(0.0, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, -1.0),
        0.0,
        "div(-0.0, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, 1.0),
        -0.0,
        "div(-0.0, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, -1.0),
        -0.0,
        "div(0.0, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, 1.0),
        0.0,
        "div(0.0, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, -6.2831854820251465),
        0.0,
        "div(-0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, 6.2831854820251465),
        -0.0,
        "div(-0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, -6.2831854820251465),
        -0.0,
        "div(0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, 6.2831854820251465),
        0.0,
        "div(0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, -3.4028234663852886e+38),
        0.0,
        "div(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, 3.4028234663852886e+38),
        -0.0,
        "div(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, -3.4028234663852886e+38),
        -0.0,
        "div(0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, 3.4028234663852886e+38),
        0.0,
        "div(0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, -INFINITY),
        0.0,
        "div(-0.0, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -0.0, INFINITY),
        -0.0,
        "div(-0.0, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, -INFINITY),
        -0.0,
        "div(0.0, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 0.0, INFINITY),
        0.0,
        "div(0.0, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, -0.0),
        INFINITY,
        "div(-1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, 0.0),
        -INFINITY,
        "div(-1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, -0.0),
        -INFINITY,
        "div(1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, 0.0),
        INFINITY,
        "div(1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        1.0,
        "div(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        -1.0,
        "div(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        -1.0,
        "div(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        1.0,
        "div(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        1.1920928955078125e-07,
        "div(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        -1.1920928955078125e-07,
        "div(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        -1.1920928955078125e-07,
        "div(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        1.1920928955078125e-07,
        "div(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, -0.5),
        2.802596928649634e-45,
        "div(-1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, 0.5),
        -2.802596928649634e-45,
        "div(-1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, -0.5),
        -2.802596928649634e-45,
        "div(1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, 0.5),
        2.802596928649634e-45,
        "div(1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, -1.0),
        1.401298464324817e-45,
        "div(-1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, 1.0),
        -1.401298464324817e-45,
        "div(-1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, -1.0),
        -1.401298464324817e-45,
        "div(1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, 1.0),
        1.401298464324817e-45,
        "div(1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, -6.2831854820251465),
        0.0,
        "div(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, 6.2831854820251465),
        -0.0,
        "div(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, -6.2831854820251465),
        -0.0,
        "div(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, 6.2831854820251465),
        0.0,
        "div(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        0.0,
        "div(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        -0.0,
        "div(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        -0.0,
        "div(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        0.0,
        "div(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, -INFINITY),
        0.0,
        "div(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -1.401298464324817e-45, INFINITY),
        -0.0,
        "div(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, -INFINITY),
        -0.0,
        "div(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 1.401298464324817e-45, INFINITY),
        0.0,
        "div(1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, -0.0),
        INFINITY,
        "div(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, 0.0),
        -INFINITY,
        "div(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, -0.0),
        -INFINITY,
        "div(1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, 0.0),
        INFINITY,
        "div(1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        8388608.0,
        "div(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        -8388608.0,
        "div(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        -8388608.0,
        "div(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        8388608.0,
        "div(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        1.0,
        "div(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        -1.0,
        "div(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        -1.0,
        "div(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        1.0,
        "div(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, -0.5),
        2.350988701644575e-38,
        "div(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, 0.5),
        -2.350988701644575e-38,
        "div(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, -0.5),
        -2.350988701644575e-38,
        "div(1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, 0.5),
        2.350988701644575e-38,
        "div(1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, -1.0),
        1.1754943508222875e-38,
        "div(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, 1.0),
        -1.1754943508222875e-38,
        "div(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, -1.0),
        -1.1754943508222875e-38,
        "div(1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, 1.0),
        1.1754943508222875e-38,
        "div(1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        1.8708567641384914e-39,
        "div(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        -1.8708567641384914e-39,
        "div(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        -1.8708567641384914e-39,
        "div(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        1.8708567641384914e-39,
        "div(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        0.0,
        "div(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        -0.0,
        "div(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        -0.0,
        "div(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        0.0,
        "div(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, -INFINITY),
        0.0,
        "div(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -1.1754943508222875e-38, INFINITY),
        -0.0,
        "div(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, -INFINITY),
        -0.0,
        "div(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 1.1754943508222875e-38, INFINITY),
        0.0,
        "div(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, -0.0),
        INFINITY,
        "div(-0.5, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, 0.0),
        -INFINITY,
        "div(-0.5, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, -0.0),
        -INFINITY,
        "div(0.5, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, 0.0),
        INFINITY,
        "div(0.5, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, -1.401298464324817e-45),
        INFINITY,
        "div(-0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, 1.401298464324817e-45),
        -INFINITY,
        "div(-0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, -1.401298464324817e-45),
        -INFINITY,
        "div(0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, 1.401298464324817e-45),
        INFINITY,
        "div(0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, -1.1754943508222875e-38),
        4.253529586511731e+37,
        "div(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, 1.1754943508222875e-38),
        -4.253529586511731e+37,
        "div(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, -1.1754943508222875e-38),
        -4.253529586511731e+37,
        "div(0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, 1.1754943508222875e-38),
        4.253529586511731e+37,
        "div(0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, -0.5),
        1.0,
        "div(-0.5, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, 0.5),
        -1.0,
        "div(-0.5, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, -0.5),
        -1.0,
        "div(0.5, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, 0.5),
        1.0,
        "div(0.5, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, -1.0),
        0.5,
        "div(-0.5, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, 1.0),
        -0.5,
        "div(-0.5, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, -1.0),
        -0.5,
        "div(0.5, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, 1.0),
        0.5,
        "div(0.5, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, -6.2831854820251465),
        0.07957746833562851,
        "div(-0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, 6.2831854820251465),
        -0.07957746833562851,
        "div(-0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, -6.2831854820251465),
        -0.07957746833562851,
        "div(0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, 6.2831854820251465),
        0.07957746833562851,
        "div(0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, -3.4028234663852886e+38),
        1.4693679385278594e-39,
        "div(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, 3.4028234663852886e+38),
        -1.4693679385278594e-39,
        "div(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, -3.4028234663852886e+38),
        -1.4693679385278594e-39,
        "div(0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, 3.4028234663852886e+38),
        1.4693679385278594e-39,
        "div(0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, -INFINITY),
        0.0,
        "div(-0.5, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -0.5, INFINITY),
        -0.0,
        "div(-0.5, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, -INFINITY),
        -0.0,
        "div(0.5, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 0.5, INFINITY),
        0.0,
        "div(0.5, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, -0.0),
        INFINITY,
        "div(-1.0, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, 0.0),
        -INFINITY,
        "div(-1.0, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, -0.0),
        -INFINITY,
        "div(1.0, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, 0.0),
        INFINITY,
        "div(1.0, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, -1.401298464324817e-45),
        INFINITY,
        "div(-1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, 1.401298464324817e-45),
        -INFINITY,
        "div(-1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, -1.401298464324817e-45),
        -INFINITY,
        "div(1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, 1.401298464324817e-45),
        INFINITY,
        "div(1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, -1.1754943508222875e-38),
        8.507059173023462e+37,
        "div(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, 1.1754943508222875e-38),
        -8.507059173023462e+37,
        "div(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, -1.1754943508222875e-38),
        -8.507059173023462e+37,
        "div(1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, 1.1754943508222875e-38),
        8.507059173023462e+37,
        "div(1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, -0.5),
        2.0,
        "div(-1.0, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, 0.5),
        -2.0,
        "div(-1.0, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, -0.5),
        -2.0,
        "div(1.0, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, 0.5),
        2.0,
        "div(1.0, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, -1.0),
        1.0,
        "div(-1.0, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, 1.0),
        -1.0,
        "div(-1.0, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, -1.0),
        -1.0,
        "div(1.0, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, 1.0),
        1.0,
        "div(1.0, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, -6.2831854820251465),
        0.15915493667125702,
        "div(-1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, 6.2831854820251465),
        -0.15915493667125702,
        "div(-1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, -6.2831854820251465),
        -0.15915493667125702,
        "div(1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, 6.2831854820251465),
        0.15915493667125702,
        "div(1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, -3.4028234663852886e+38),
        2.938735877055719e-39,
        "div(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, 3.4028234663852886e+38),
        -2.938735877055719e-39,
        "div(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, -3.4028234663852886e+38),
        -2.938735877055719e-39,
        "div(1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, 3.4028234663852886e+38),
        2.938735877055719e-39,
        "div(1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, -INFINITY),
        0.0,
        "div(-1.0, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -1.0, INFINITY),
        -0.0,
        "div(-1.0, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, -INFINITY),
        -0.0,
        "div(1.0, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 1.0, INFINITY),
        0.0,
        "div(1.0, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, -0.0),
        INFINITY,
        "div(-6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, 0.0),
        -INFINITY,
        "div(-6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, -0.0),
        -INFINITY,
        "div(6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, 0.0),
        INFINITY,
        "div(6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, -1.401298464324817e-45),
        INFINITY,
        "div(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, 1.401298464324817e-45),
        -INFINITY,
        "div(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, -1.401298464324817e-45),
        -INFINITY,
        "div(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, 1.401298464324817e-45),
        INFINITY,
        "div(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        INFINITY,
        "div(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        -INFINITY,
        "div(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        -INFINITY,
        "div(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        INFINITY,
        "div(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, -0.5),
        12.566370964050293,
        "div(-6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, 0.5),
        -12.566370964050293,
        "div(-6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, -0.5),
        -12.566370964050293,
        "div(6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, 0.5),
        12.566370964050293,
        "div(6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, -1.0),
        6.2831854820251465,
        "div(-6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, 1.0),
        -6.2831854820251465,
        "div(-6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, -1.0),
        -6.2831854820251465,
        "div(6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, 1.0),
        6.2831854820251465,
        "div(6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, -6.2831854820251465),
        1.0,
        "div(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, 6.2831854820251465),
        -1.0,
        "div(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, -6.2831854820251465),
        -1.0,
        "div(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, 6.2831854820251465),
        1.0,
        "div(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        1.8464623999521392e-38,
        "div(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        -1.8464623999521392e-38,
        "div(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        -1.8464623999521392e-38,
        "div(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        1.8464623999521392e-38,
        "div(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, -INFINITY),
        0.0,
        "div(-6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -6.2831854820251465, INFINITY),
        -0.0,
        "div(-6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, -INFINITY),
        -0.0,
        "div(6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 6.2831854820251465, INFINITY),
        0.0,
        "div(6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, -0.0),
        INFINITY,
        "div(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, 0.0),
        -INFINITY,
        "div(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, -0.0),
        -INFINITY,
        "div(3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, 0.0),
        INFINITY,
        "div(3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        INFINITY,
        "div(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        -INFINITY,
        "div(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        -INFINITY,
        "div(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        INFINITY,
        "div(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        INFINITY,
        "div(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        -INFINITY,
        "div(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        -INFINITY,
        "div(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        INFINITY,
        "div(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, -0.5),
        INFINITY,
        "div(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, 0.5),
        -INFINITY,
        "div(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, -0.5),
        -INFINITY,
        "div(3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, 0.5),
        INFINITY,
        "div(3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, -1.0),
        3.4028234663852886e+38,
        "div(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, 1.0),
        -3.4028234663852886e+38,
        "div(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, -1.0),
        -3.4028234663852886e+38,
        "div(3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, 1.0),
        3.4028234663852886e+38,
        "div(3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        5.4157613487045e+37,
        "div(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        -5.4157613487045e+37,
        "div(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        -5.4157613487045e+37,
        "div(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        5.4157613487045e+37,
        "div(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        1.0,
        "div(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        -1.0,
        "div(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        -1.0,
        "div(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        1.0,
        "div(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, -INFINITY),
        0.0,
        "div(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -3.4028234663852886e+38, INFINITY),
        -0.0,
        "div(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, -INFINITY),
        -0.0,
        "div(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, 3.4028234663852886e+38, INFINITY),
        0.0,
        "div(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, -0.0),
        INFINITY,
        "div(-INFINITY, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, 0.0),
        -INFINITY,
        "div(-INFINITY, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, -0.0),
        -INFINITY,
        "div(INFINITY, -0.0)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, 0.0),
        INFINITY,
        "div(INFINITY, 0.0)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, -1.401298464324817e-45),
        INFINITY,
        "div(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, 1.401298464324817e-45),
        -INFINITY,
        "div(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, -1.401298464324817e-45),
        -INFINITY,
        "div(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, 1.401298464324817e-45),
        INFINITY,
        "div(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, -1.1754943508222875e-38),
        INFINITY,
        "div(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, 1.1754943508222875e-38),
        -INFINITY,
        "div(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, -1.1754943508222875e-38),
        -INFINITY,
        "div(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, 1.1754943508222875e-38),
        INFINITY,
        "div(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, -0.5),
        INFINITY,
        "div(-INFINITY, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, 0.5),
        -INFINITY,
        "div(-INFINITY, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, -0.5),
        -INFINITY,
        "div(INFINITY, -0.5)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, 0.5),
        INFINITY,
        "div(INFINITY, 0.5)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, -1.0),
        INFINITY,
        "div(-INFINITY, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, 1.0),
        -INFINITY,
        "div(-INFINITY, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, -1.0),
        -INFINITY,
        "div(INFINITY, -1.0)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, 1.0),
        INFINITY,
        "div(INFINITY, 1.0)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, -6.2831854820251465),
        INFINITY,
        "div(-INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, 6.2831854820251465),
        -INFINITY,
        "div(-INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, -6.2831854820251465),
        -INFINITY,
        "div(INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, 6.2831854820251465),
        INFINITY,
        "div(INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, -3.4028234663852886e+38),
        INFINITY,
        "div(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, -INFINITY, 3.4028234663852886e+38),
        -INFINITY,
        "div(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, -3.4028234663852886e+38),
        -INFINITY,
        "div(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_div(&instance, INFINITY, 3.4028234663852886e+38),
        INFINITY,
        "div(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, -0.0),
        -0.0,
        "min(-0.0, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, 0.0),
        -0.0,
        "min(-0.0, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, -0.0),
        -0.0,
        "min(0.0, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, 0.0),
        0.0,
        "min(0.0, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "min(-0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, 1.401298464324817e-45),
        -0.0,
        "min(-0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "min(0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, 1.401298464324817e-45),
        0.0,
        "min(0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "min(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, 1.1754943508222875e-38),
        -0.0,
        "min(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "min(0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, 1.1754943508222875e-38),
        0.0,
        "min(0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, -0.5),
        -0.5,
        "min(-0.0, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, 0.5),
        -0.0,
        "min(-0.0, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, -0.5),
        -0.5,
        "min(0.0, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, 0.5),
        0.0,
        "min(0.0, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, -1.0),
        -1.0,
        "min(-0.0, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, 1.0),
        -0.0,
        "min(-0.0, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, -1.0),
        -1.0,
        "min(0.0, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, 1.0),
        0.0,
        "min(0.0, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, -6.2831854820251465),
        -6.2831854820251465,
        "min(-0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, 6.2831854820251465),
        -0.0,
        "min(-0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, -6.2831854820251465),
        -6.2831854820251465,
        "min(0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, 6.2831854820251465),
        0.0,
        "min(0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, 3.4028234663852886e+38),
        -0.0,
        "min(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, 3.4028234663852886e+38),
        0.0,
        "min(0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, -INFINITY),
        -INFINITY,
        "min(-0.0, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -0.0, INFINITY),
        -0.0,
        "min(-0.0, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, -INFINITY),
        -INFINITY,
        "min(0.0, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 0.0, INFINITY),
        0.0,
        "min(0.0, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, -0.0),
        -1.401298464324817e-45,
        "min(-1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, 0.0),
        -1.401298464324817e-45,
        "min(-1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, -0.0),
        -0.0,
        "min(1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, 0.0),
        0.0,
        "min(1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "min(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        -1.401298464324817e-45,
        "min(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "min(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        1.401298464324817e-45,
        "min(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "min(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        -1.401298464324817e-45,
        "min(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "min(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        1.401298464324817e-45,
        "min(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, -0.5),
        -0.5,
        "min(-1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, 0.5),
        -1.401298464324817e-45,
        "min(-1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, -0.5),
        -0.5,
        "min(1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, 0.5),
        1.401298464324817e-45,
        "min(1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, -1.0),
        -1.0,
        "min(-1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, 1.0),
        -1.401298464324817e-45,
        "min(-1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, -1.0),
        -1.0,
        "min(1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, 1.0),
        1.401298464324817e-45,
        "min(1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, -6.2831854820251465),
        -6.2831854820251465,
        "min(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, 6.2831854820251465),
        -1.401298464324817e-45,
        "min(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, -6.2831854820251465),
        -6.2831854820251465,
        "min(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, 6.2831854820251465),
        1.401298464324817e-45,
        "min(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        -1.401298464324817e-45,
        "min(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        1.401298464324817e-45,
        "min(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, -INFINITY),
        -INFINITY,
        "min(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -1.401298464324817e-45, INFINITY),
        -1.401298464324817e-45,
        "min(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, -INFINITY),
        -INFINITY,
        "min(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 1.401298464324817e-45, INFINITY),
        1.401298464324817e-45,
        "min(1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, -0.0),
        -1.1754943508222875e-38,
        "min(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, 0.0),
        -1.1754943508222875e-38,
        "min(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, -0.0),
        -0.0,
        "min(1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, 0.0),
        0.0,
        "min(1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        -1.1754943508222875e-38,
        "min(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        -1.1754943508222875e-38,
        "min(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "min(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        1.401298464324817e-45,
        "min(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "min(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "min(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "min(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "min(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, -0.5),
        -0.5,
        "min(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, 0.5),
        -1.1754943508222875e-38,
        "min(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, -0.5),
        -0.5,
        "min(1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, 0.5),
        1.1754943508222875e-38,
        "min(1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, -1.0),
        -1.0,
        "min(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, 1.0),
        -1.1754943508222875e-38,
        "min(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, -1.0),
        -1.0,
        "min(1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, 1.0),
        1.1754943508222875e-38,
        "min(1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        -6.2831854820251465,
        "min(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        -1.1754943508222875e-38,
        "min(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        -6.2831854820251465,
        "min(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        1.1754943508222875e-38,
        "min(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        -1.1754943508222875e-38,
        "min(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        1.1754943508222875e-38,
        "min(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, -INFINITY),
        -INFINITY,
        "min(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -1.1754943508222875e-38, INFINITY),
        -1.1754943508222875e-38,
        "min(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, -INFINITY),
        -INFINITY,
        "min(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 1.1754943508222875e-38, INFINITY),
        1.1754943508222875e-38,
        "min(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, -0.0),
        -0.5,
        "min(-0.5, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, 0.0),
        -0.5,
        "min(-0.5, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, -0.0),
        -0.0,
        "min(0.5, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, 0.0),
        0.0,
        "min(0.5, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, -1.401298464324817e-45),
        -0.5,
        "min(-0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, 1.401298464324817e-45),
        -0.5,
        "min(-0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "min(0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, 1.401298464324817e-45),
        1.401298464324817e-45,
        "min(0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, -1.1754943508222875e-38),
        -0.5,
        "min(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, 1.1754943508222875e-38),
        -0.5,
        "min(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "min(0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "min(0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, -0.5),
        -0.5,
        "min(-0.5, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, 0.5),
        -0.5,
        "min(-0.5, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, -0.5),
        -0.5,
        "min(0.5, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, 0.5),
        0.5,
        "min(0.5, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, -1.0),
        -1.0,
        "min(-0.5, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, 1.0),
        -0.5,
        "min(-0.5, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, -1.0),
        -1.0,
        "min(0.5, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, 1.0),
        0.5,
        "min(0.5, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, -6.2831854820251465),
        -6.2831854820251465,
        "min(-0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, 6.2831854820251465),
        -0.5,
        "min(-0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, -6.2831854820251465),
        -6.2831854820251465,
        "min(0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, 6.2831854820251465),
        0.5,
        "min(0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, 3.4028234663852886e+38),
        -0.5,
        "min(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, 3.4028234663852886e+38),
        0.5,
        "min(0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, -INFINITY),
        -INFINITY,
        "min(-0.5, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -0.5, INFINITY),
        -0.5,
        "min(-0.5, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, -INFINITY),
        -INFINITY,
        "min(0.5, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 0.5, INFINITY),
        0.5,
        "min(0.5, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, -0.0),
        -1.0,
        "min(-1.0, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, 0.0),
        -1.0,
        "min(-1.0, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, -0.0),
        -0.0,
        "min(1.0, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, 0.0),
        0.0,
        "min(1.0, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, -1.401298464324817e-45),
        -1.0,
        "min(-1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, 1.401298464324817e-45),
        -1.0,
        "min(-1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "min(1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, 1.401298464324817e-45),
        1.401298464324817e-45,
        "min(1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, -1.1754943508222875e-38),
        -1.0,
        "min(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, 1.1754943508222875e-38),
        -1.0,
        "min(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "min(1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "min(1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, -0.5),
        -1.0,
        "min(-1.0, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, 0.5),
        -1.0,
        "min(-1.0, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, -0.5),
        -0.5,
        "min(1.0, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, 0.5),
        0.5,
        "min(1.0, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, -1.0),
        -1.0,
        "min(-1.0, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, 1.0),
        -1.0,
        "min(-1.0, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, -1.0),
        -1.0,
        "min(1.0, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, 1.0),
        1.0,
        "min(1.0, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, -6.2831854820251465),
        -6.2831854820251465,
        "min(-1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, 6.2831854820251465),
        -1.0,
        "min(-1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, -6.2831854820251465),
        -6.2831854820251465,
        "min(1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, 6.2831854820251465),
        1.0,
        "min(1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, 3.4028234663852886e+38),
        -1.0,
        "min(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, 3.4028234663852886e+38),
        1.0,
        "min(1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, -INFINITY),
        -INFINITY,
        "min(-1.0, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -1.0, INFINITY),
        -1.0,
        "min(-1.0, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, -INFINITY),
        -INFINITY,
        "min(1.0, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 1.0, INFINITY),
        1.0,
        "min(1.0, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, -0.0),
        -6.2831854820251465,
        "min(-6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, 0.0),
        -6.2831854820251465,
        "min(-6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, -0.0),
        -0.0,
        "min(6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, 0.0),
        0.0,
        "min(6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, -1.401298464324817e-45),
        -6.2831854820251465,
        "min(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, 1.401298464324817e-45),
        -6.2831854820251465,
        "min(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "min(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, 1.401298464324817e-45),
        1.401298464324817e-45,
        "min(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        -6.2831854820251465,
        "min(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        -6.2831854820251465,
        "min(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "min(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "min(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, -0.5),
        -6.2831854820251465,
        "min(-6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, 0.5),
        -6.2831854820251465,
        "min(-6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, -0.5),
        -0.5,
        "min(6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, 0.5),
        0.5,
        "min(6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, -1.0),
        -6.2831854820251465,
        "min(-6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, 1.0),
        -6.2831854820251465,
        "min(-6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, -1.0),
        -1.0,
        "min(6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, 1.0),
        1.0,
        "min(6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, -6.2831854820251465),
        -6.2831854820251465,
        "min(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, 6.2831854820251465),
        -6.2831854820251465,
        "min(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, -6.2831854820251465),
        -6.2831854820251465,
        "min(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, 6.2831854820251465),
        6.2831854820251465,
        "min(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        -6.2831854820251465,
        "min(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        6.2831854820251465,
        "min(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, -INFINITY),
        -INFINITY,
        "min(-6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -6.2831854820251465, INFINITY),
        -6.2831854820251465,
        "min(-6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, -INFINITY),
        -INFINITY,
        "min(6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 6.2831854820251465, INFINITY),
        6.2831854820251465,
        "min(6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, -0.0),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, 0.0),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, -0.0),
        -0.0,
        "min(3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, 0.0),
        0.0,
        "min(3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "min(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        1.401298464324817e-45,
        "min(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "min(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "min(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, -0.5),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, 0.5),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, -0.5),
        -0.5,
        "min(3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, 0.5),
        0.5,
        "min(3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, -1.0),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, 1.0),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, -1.0),
        -1.0,
        "min(3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, 1.0),
        1.0,
        "min(3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        -6.2831854820251465,
        "min(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        6.2831854820251465,
        "min(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "min(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, -INFINITY),
        -INFINITY,
        "min(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -3.4028234663852886e+38, INFINITY),
        -3.4028234663852886e+38,
        "min(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, -INFINITY),
        -INFINITY,
        "min(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, 3.4028234663852886e+38, INFINITY),
        3.4028234663852886e+38,
        "min(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, -0.0),
        -INFINITY,
        "min(-INFINITY, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, 0.0),
        -INFINITY,
        "min(-INFINITY, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, -0.0),
        -0.0,
        "min(INFINITY, -0.0)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, 0.0),
        0.0,
        "min(INFINITY, 0.0)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, -1.401298464324817e-45),
        -INFINITY,
        "min(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, 1.401298464324817e-45),
        -INFINITY,
        "min(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "min(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, 1.401298464324817e-45),
        1.401298464324817e-45,
        "min(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, -1.1754943508222875e-38),
        -INFINITY,
        "min(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, 1.1754943508222875e-38),
        -INFINITY,
        "min(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "min(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "min(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, -0.5),
        -INFINITY,
        "min(-INFINITY, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, 0.5),
        -INFINITY,
        "min(-INFINITY, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, -0.5),
        -0.5,
        "min(INFINITY, -0.5)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, 0.5),
        0.5,
        "min(INFINITY, 0.5)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, -1.0),
        -INFINITY,
        "min(-INFINITY, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, 1.0),
        -INFINITY,
        "min(-INFINITY, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, -1.0),
        -1.0,
        "min(INFINITY, -1.0)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, 1.0),
        1.0,
        "min(INFINITY, 1.0)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, -6.2831854820251465),
        -INFINITY,
        "min(-INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, 6.2831854820251465),
        -INFINITY,
        "min(-INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, -6.2831854820251465),
        -6.2831854820251465,
        "min(INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, 6.2831854820251465),
        6.2831854820251465,
        "min(INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, -3.4028234663852886e+38),
        -INFINITY,
        "min(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, 3.4028234663852886e+38),
        -INFINITY,
        "min(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "min(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "min(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, -INFINITY),
        -INFINITY,
        "min(-INFINITY, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, -INFINITY, INFINITY),
        -INFINITY,
        "min(-INFINITY, INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, -INFINITY),
        -INFINITY,
        "min(INFINITY, -INFINITY)"
    );
    assertEqualF32(
        f320_min(&instance, INFINITY, INFINITY),
        INFINITY,
        "min(INFINITY, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, -0.0),
        -0.0,
        "max(-0.0, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, 0.0),
        0.0,
        "max(-0.0, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, -0.0),
        0.0,
        "max(0.0, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, 0.0),
        0.0,
        "max(0.0, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, -1.401298464324817e-45),
        -0.0,
        "max(-0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, 1.401298464324817e-45),
        1.401298464324817e-45,
        "max(-0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, -1.401298464324817e-45),
        0.0,
        "max(0.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, 1.401298464324817e-45),
        1.401298464324817e-45,
        "max(0.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, -1.1754943508222875e-38),
        -0.0,
        "max(-0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "max(-0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, -1.1754943508222875e-38),
        0.0,
        "max(0.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "max(0.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, -0.5),
        -0.0,
        "max(-0.0, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, 0.5),
        0.5,
        "max(-0.0, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, -0.5),
        0.0,
        "max(0.0, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, 0.5),
        0.5,
        "max(0.0, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, -1.0),
        -0.0,
        "max(-0.0, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, 1.0),
        1.0,
        "max(-0.0, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, -1.0),
        0.0,
        "max(0.0, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, 1.0),
        1.0,
        "max(0.0, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, -6.2831854820251465),
        -0.0,
        "max(-0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, 6.2831854820251465),
        6.2831854820251465,
        "max(-0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, -6.2831854820251465),
        0.0,
        "max(0.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, 6.2831854820251465),
        6.2831854820251465,
        "max(0.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, -3.4028234663852886e+38),
        -0.0,
        "max(-0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(-0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, -3.4028234663852886e+38),
        0.0,
        "max(0.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(0.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, -INFINITY),
        -0.0,
        "max(-0.0, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -0.0, INFINITY),
        INFINITY,
        "max(-0.0, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, -INFINITY),
        0.0,
        "max(0.0, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 0.0, INFINITY),
        INFINITY,
        "max(0.0, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, -0.0),
        -0.0,
        "max(-1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, 0.0),
        0.0,
        "max(-1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, -0.0),
        1.401298464324817e-45,
        "max(1.401298464324817e-45, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, 0.0),
        1.401298464324817e-45,
        "max(1.401298464324817e-45, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "max(-1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, 1.401298464324817e-45),
        1.401298464324817e-45,
        "max(-1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, -1.401298464324817e-45),
        1.401298464324817e-45,
        "max(1.401298464324817e-45, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, 1.401298464324817e-45),
        1.401298464324817e-45,
        "max(1.401298464324817e-45, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, -1.1754943508222875e-38),
        -1.401298464324817e-45,
        "max(-1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "max(-1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, -1.1754943508222875e-38),
        1.401298464324817e-45,
        "max(1.401298464324817e-45, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "max(1.401298464324817e-45, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, -0.5),
        -1.401298464324817e-45,
        "max(-1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, 0.5),
        0.5,
        "max(-1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, -0.5),
        1.401298464324817e-45,
        "max(1.401298464324817e-45, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, 0.5),
        0.5,
        "max(1.401298464324817e-45, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, -1.0),
        -1.401298464324817e-45,
        "max(-1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, 1.0),
        1.0,
        "max(-1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, -1.0),
        1.401298464324817e-45,
        "max(1.401298464324817e-45, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, 1.0),
        1.0,
        "max(1.401298464324817e-45, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, -6.2831854820251465),
        -1.401298464324817e-45,
        "max(-1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, 6.2831854820251465),
        6.2831854820251465,
        "max(-1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, -6.2831854820251465),
        1.401298464324817e-45,
        "max(1.401298464324817e-45, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, 6.2831854820251465),
        6.2831854820251465,
        "max(1.401298464324817e-45, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, -3.4028234663852886e+38),
        -1.401298464324817e-45,
        "max(-1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(-1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, -3.4028234663852886e+38),
        1.401298464324817e-45,
        "max(1.401298464324817e-45, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(1.401298464324817e-45, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, -INFINITY),
        -1.401298464324817e-45,
        "max(-1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -1.401298464324817e-45, INFINITY),
        INFINITY,
        "max(-1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, -INFINITY),
        1.401298464324817e-45,
        "max(1.401298464324817e-45, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 1.401298464324817e-45, INFINITY),
        INFINITY,
        "max(1.401298464324817e-45, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, -0.0),
        -0.0,
        "max(-1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, 0.0),
        0.0,
        "max(-1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, -0.0),
        1.1754943508222875e-38,
        "max(1.1754943508222875e-38, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, 0.0),
        1.1754943508222875e-38,
        "max(1.1754943508222875e-38, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "max(-1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, 1.401298464324817e-45),
        1.401298464324817e-45,
        "max(-1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, -1.401298464324817e-45),
        1.1754943508222875e-38,
        "max(1.1754943508222875e-38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, 1.401298464324817e-45),
        1.1754943508222875e-38,
        "max(1.1754943508222875e-38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "max(-1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "max(-1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, -1.1754943508222875e-38),
        1.1754943508222875e-38,
        "max(1.1754943508222875e-38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "max(1.1754943508222875e-38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, -0.5),
        -1.1754943508222875e-38,
        "max(-1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, 0.5),
        0.5,
        "max(-1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, -0.5),
        1.1754943508222875e-38,
        "max(1.1754943508222875e-38, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, 0.5),
        0.5,
        "max(1.1754943508222875e-38, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, -1.0),
        -1.1754943508222875e-38,
        "max(-1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, 1.0),
        1.0,
        "max(-1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, -1.0),
        1.1754943508222875e-38,
        "max(1.1754943508222875e-38, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, 1.0),
        1.0,
        "max(1.1754943508222875e-38, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, -6.2831854820251465),
        -1.1754943508222875e-38,
        "max(-1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, 6.2831854820251465),
        6.2831854820251465,
        "max(-1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, -6.2831854820251465),
        1.1754943508222875e-38,
        "max(1.1754943508222875e-38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, 6.2831854820251465),
        6.2831854820251465,
        "max(1.1754943508222875e-38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, -3.4028234663852886e+38),
        -1.1754943508222875e-38,
        "max(-1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(-1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, -3.4028234663852886e+38),
        1.1754943508222875e-38,
        "max(1.1754943508222875e-38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(1.1754943508222875e-38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, -INFINITY),
        -1.1754943508222875e-38,
        "max(-1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -1.1754943508222875e-38, INFINITY),
        INFINITY,
        "max(-1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, -INFINITY),
        1.1754943508222875e-38,
        "max(1.1754943508222875e-38, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 1.1754943508222875e-38, INFINITY),
        INFINITY,
        "max(1.1754943508222875e-38, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, -0.0),
        -0.0,
        "max(-0.5, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, 0.0),
        0.0,
        "max(-0.5, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, -0.0),
        0.5,
        "max(0.5, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, 0.0),
        0.5,
        "max(0.5, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "max(-0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, 1.401298464324817e-45),
        1.401298464324817e-45,
        "max(-0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, -1.401298464324817e-45),
        0.5,
        "max(0.5, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, 1.401298464324817e-45),
        0.5,
        "max(0.5, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "max(-0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "max(-0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, -1.1754943508222875e-38),
        0.5,
        "max(0.5, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, 1.1754943508222875e-38),
        0.5,
        "max(0.5, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, -0.5),
        -0.5,
        "max(-0.5, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, 0.5),
        0.5,
        "max(-0.5, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, -0.5),
        0.5,
        "max(0.5, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, 0.5),
        0.5,
        "max(0.5, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, -1.0),
        -0.5,
        "max(-0.5, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, 1.0),
        1.0,
        "max(-0.5, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, -1.0),
        0.5,
        "max(0.5, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, 1.0),
        1.0,
        "max(0.5, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, -6.2831854820251465),
        -0.5,
        "max(-0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, 6.2831854820251465),
        6.2831854820251465,
        "max(-0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, -6.2831854820251465),
        0.5,
        "max(0.5, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, 6.2831854820251465),
        6.2831854820251465,
        "max(0.5, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, -3.4028234663852886e+38),
        -0.5,
        "max(-0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(-0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, -3.4028234663852886e+38),
        0.5,
        "max(0.5, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(0.5, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, -INFINITY),
        -0.5,
        "max(-0.5, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -0.5, INFINITY),
        INFINITY,
        "max(-0.5, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, -INFINITY),
        0.5,
        "max(0.5, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 0.5, INFINITY),
        INFINITY,
        "max(0.5, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, -0.0),
        -0.0,
        "max(-1.0, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, 0.0),
        0.0,
        "max(-1.0, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, -0.0),
        1.0,
        "max(1.0, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, 0.0),
        1.0,
        "max(1.0, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "max(-1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, 1.401298464324817e-45),
        1.401298464324817e-45,
        "max(-1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, -1.401298464324817e-45),
        1.0,
        "max(1.0, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, 1.401298464324817e-45),
        1.0,
        "max(1.0, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "max(-1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "max(-1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, -1.1754943508222875e-38),
        1.0,
        "max(1.0, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, 1.1754943508222875e-38),
        1.0,
        "max(1.0, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, -0.5),
        -0.5,
        "max(-1.0, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, 0.5),
        0.5,
        "max(-1.0, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, -0.5),
        1.0,
        "max(1.0, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, 0.5),
        1.0,
        "max(1.0, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, -1.0),
        -1.0,
        "max(-1.0, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, 1.0),
        1.0,
        "max(-1.0, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, -1.0),
        1.0,
        "max(1.0, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, 1.0),
        1.0,
        "max(1.0, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, -6.2831854820251465),
        -1.0,
        "max(-1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, 6.2831854820251465),
        6.2831854820251465,
        "max(-1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, -6.2831854820251465),
        1.0,
        "max(1.0, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, 6.2831854820251465),
        6.2831854820251465,
        "max(1.0, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, -3.4028234663852886e+38),
        -1.0,
        "max(-1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(-1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, -3.4028234663852886e+38),
        1.0,
        "max(1.0, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(1.0, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, -INFINITY),
        -1.0,
        "max(-1.0, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -1.0, INFINITY),
        INFINITY,
        "max(-1.0, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, -INFINITY),
        1.0,
        "max(1.0, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 1.0, INFINITY),
        INFINITY,
        "max(1.0, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, -0.0),
        -0.0,
        "max(-6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, 0.0),
        0.0,
        "max(-6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, -0.0),
        6.2831854820251465,
        "max(6.2831854820251465, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, 0.0),
        6.2831854820251465,
        "max(6.2831854820251465, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "max(-6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, 1.401298464324817e-45),
        1.401298464324817e-45,
        "max(-6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, -1.401298464324817e-45),
        6.2831854820251465,
        "max(6.2831854820251465, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, 1.401298464324817e-45),
        6.2831854820251465,
        "max(6.2831854820251465, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "max(-6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "max(-6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, -1.1754943508222875e-38),
        6.2831854820251465,
        "max(6.2831854820251465, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, 1.1754943508222875e-38),
        6.2831854820251465,
        "max(6.2831854820251465, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, -0.5),
        -0.5,
        "max(-6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, 0.5),
        0.5,
        "max(-6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, -0.5),
        6.2831854820251465,
        "max(6.2831854820251465, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, 0.5),
        6.2831854820251465,
        "max(6.2831854820251465, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, -1.0),
        -1.0,
        "max(-6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, 1.0),
        1.0,
        "max(-6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, -1.0),
        6.2831854820251465,
        "max(6.2831854820251465, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, 1.0),
        6.2831854820251465,
        "max(6.2831854820251465, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, -6.2831854820251465),
        -6.2831854820251465,
        "max(-6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, 6.2831854820251465),
        6.2831854820251465,
        "max(-6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, -6.2831854820251465),
        6.2831854820251465,
        "max(6.2831854820251465, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, 6.2831854820251465),
        6.2831854820251465,
        "max(6.2831854820251465, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, -3.4028234663852886e+38),
        -6.2831854820251465,
        "max(-6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(-6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, -3.4028234663852886e+38),
        6.2831854820251465,
        "max(6.2831854820251465, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(6.2831854820251465, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, -INFINITY),
        -6.2831854820251465,
        "max(-6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -6.2831854820251465, INFINITY),
        INFINITY,
        "max(-6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, -INFINITY),
        6.2831854820251465,
        "max(6.2831854820251465, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 6.2831854820251465, INFINITY),
        INFINITY,
        "max(6.2831854820251465, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, -0.0),
        -0.0,
        "max(-3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, 0.0),
        0.0,
        "max(-3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, -0.0),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, 0.0),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "max(-3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, 1.401298464324817e-45),
        1.401298464324817e-45,
        "max(-3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, -1.401298464324817e-45),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, 1.401298464324817e-45),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "max(-3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "max(-3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, -1.1754943508222875e-38),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, 1.1754943508222875e-38),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, -0.5),
        -0.5,
        "max(-3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, 0.5),
        0.5,
        "max(-3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, -0.5),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, 0.5),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, -1.0),
        -1.0,
        "max(-3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, 1.0),
        1.0,
        "max(-3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, -1.0),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, 1.0),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, -6.2831854820251465),
        -6.2831854820251465,
        "max(-3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, 6.2831854820251465),
        6.2831854820251465,
        "max(-3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, -6.2831854820251465),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, 6.2831854820251465),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "max(-3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(-3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, -3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, -INFINITY),
        -3.4028234663852886e+38,
        "max(-3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -3.4028234663852886e+38, INFINITY),
        INFINITY,
        "max(-3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, -INFINITY),
        3.4028234663852886e+38,
        "max(3.4028234663852886e+38, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, 3.4028234663852886e+38, INFINITY),
        INFINITY,
        "max(3.4028234663852886e+38, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, -0.0),
        -0.0,
        "max(-INFINITY, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, 0.0),
        0.0,
        "max(-INFINITY, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, -0.0),
        INFINITY,
        "max(INFINITY, -0.0)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, 0.0),
        INFINITY,
        "max(INFINITY, 0.0)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "max(-INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, 1.401298464324817e-45),
        1.401298464324817e-45,
        "max(-INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, -1.401298464324817e-45),
        INFINITY,
        "max(INFINITY, -1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, 1.401298464324817e-45),
        INFINITY,
        "max(INFINITY, 1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "max(-INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "max(-INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, -1.1754943508222875e-38),
        INFINITY,
        "max(INFINITY, -1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, 1.1754943508222875e-38),
        INFINITY,
        "max(INFINITY, 1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, -0.5),
        -0.5,
        "max(-INFINITY, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, 0.5),
        0.5,
        "max(-INFINITY, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, -0.5),
        INFINITY,
        "max(INFINITY, -0.5)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, 0.5),
        INFINITY,
        "max(INFINITY, 0.5)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, -1.0),
        -1.0,
        "max(-INFINITY, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, 1.0),
        1.0,
        "max(-INFINITY, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, -1.0),
        INFINITY,
        "max(INFINITY, -1.0)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, 1.0),
        INFINITY,
        "max(INFINITY, 1.0)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, -6.2831854820251465),
        -6.2831854820251465,
        "max(-INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, 6.2831854820251465),
        6.2831854820251465,
        "max(-INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, -6.2831854820251465),
        INFINITY,
        "max(INFINITY, -6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, 6.2831854820251465),
        INFINITY,
        "max(INFINITY, 6.2831854820251465)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "max(-INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "max(-INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, -3.4028234663852886e+38),
        INFINITY,
        "max(INFINITY, -3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, 3.4028234663852886e+38),
        INFINITY,
        "max(INFINITY, 3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, -INFINITY),
        -INFINITY,
        "max(-INFINITY, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, -INFINITY, INFINITY),
        INFINITY,
        "max(-INFINITY, INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, -INFINITY),
        INFINITY,
        "max(INFINITY, -INFINITY)"
    );
    assertEqualF32(
        f320_max(&instance, INFINITY, INFINITY),
        INFINITY,
        "max(INFINITY, INFINITY)"
    );
    assertEqualF32(
        f320_sqrt(&instance, -0.0),
        -0.0,
        "sqrt(-0.0)"
    );
    assertEqualF32(
        f320_sqrt(&instance, 0.0),
        0.0,
        "sqrt(0.0)"
    );
    assertEqualF32(
        f320_sqrt(&instance, 1.401298464324817e-45),
        3.743392066509216e-23,
        "sqrt(1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_sqrt(&instance, 1.1754943508222875e-38),
        1.0842021724855044e-19,
        "sqrt(1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_sqrt(&instance, 0.5),
        0.7071067690849304,
        "sqrt(0.5)"
    );
    assertEqualF32(
        f320_sqrt(&instance, 1.0),
        1.0,
        "sqrt(1.0)"
    );
    assertEqualF32(
        f320_sqrt(&instance, 6.2831854820251465),
        2.5066282749176025,
        "sqrt(6.2831854820251465)"
    );
    assertEqualF32(
        f320_sqrt(&instance, 3.4028234663852886e+38),
        1.8446742974197924e+19,
        "sqrt(3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_sqrt(&instance, INFINITY),
        INFINITY,
        "sqrt(INFINITY)"
    );
    assertEqualF32(
        f320_floor(&instance, -0.0),
        -0.0,
        "floor(-0.0)"
    );
    assertEqualF32(
        f320_floor(&instance, 0.0),
        0.0,
        "floor(0.0)"
    );
    assertEqualF32(
        f320_floor(&instance, -1.401298464324817e-45),
        -1.0,
        "floor(-1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_floor(&instance, 1.401298464324817e-45),
        0.0,
        "floor(1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_floor(&instance, -1.1754943508222875e-38),
        -1.0,
        "floor(-1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_floor(&instance, 1.1754943508222875e-38),
        0.0,
        "floor(1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_floor(&instance, -0.5),
        -1.0,
        "floor(-0.5)"
    );
    assertEqualF32(
        f320_floor(&instance, 0.5),
        0.0,
        "floor(0.5)"
    );
    assertEqualF32(
        f320_floor(&instance, -1.0),
        -1.0,
        "floor(-1.0)"
    );
    assertEqualF32(
        f320_floor(&instance, 1.0),
        1.0,
        "floor(1.0)"
    );
    assertEqualF32(
        f320_floor(&instance, -6.2831854820251465),
        -7.0,
        "floor(-6.2831854820251465)"
    );
    assertEqualF32(
        f320_floor(&instance, 6.2831854820251465),
        6.0,
        "floor(6.2831854820251465)"
    );
    assertEqualF32(
        f320_floor(&instance, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "floor(-3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_floor(&instance, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "floor(3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_floor(&instance, -INFINITY),
        -INFINITY,
        "floor(-INFINITY)"
    );
    assertEqualF32(
        f320_floor(&instance, INFINITY),
        INFINITY,
        "floor(INFINITY)"
    );
    assertEqualF32(
        f320_ceil(&instance, -0.0),
        -0.0,
        "ceil(-0.0)"
    );
    assertEqualF32(
        f320_ceil(&instance, 0.0),
        0.0,
        "ceil(0.0)"
    );
    assertEqualF32(
        f320_ceil(&instance, -1.401298464324817e-45),
        -0.0,
        "ceil(-1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_ceil(&instance, 1.401298464324817e-45),
        1.0,
        "ceil(1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_ceil(&instance, -1.1754943508222875e-38),
        -0.0,
        "ceil(-1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_ceil(&instance, 1.1754943508222875e-38),
        1.0,
        "ceil(1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_ceil(&instance, -0.5),
        -0.0,
        "ceil(-0.5)"
    );
    assertEqualF32(
        f320_ceil(&instance, 0.5),
        1.0,
        "ceil(0.5)"
    );
    assertEqualF32(
        f320_ceil(&instance, -1.0),
        -1.0,
        "ceil(-1.0)"
    );
    assertEqualF32(
        f320_ceil(&instance, 1.0),
        1.0,
        "ceil(1.0)"
    );
    assertEqualF32(
        f320_ceil(&instance, -6.2831854820251465),
        -6.0,
        "ceil(-6.2831854820251465)"
    );
    assertEqualF32(
        f320_ceil(&instance, 6.2831854820251465),
        7.0,
        "ceil(6.2831854820251465)"
    );
    assertEqualF32(
        f320_ceil(&instance, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "ceil(-3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_ceil(&instance, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "ceil(3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_ceil(&instance, -INFINITY),
        -INFINITY,
        "ceil(-INFINITY)"
    );
    assertEqualF32(
        f320_ceil(&instance, INFINITY),
        INFINITY,
        "ceil(INFINITY)"
    );
    assertEqualF32(
        f320_trunc(&instance, -0.0),
        -0.0,
        "trunc(-0.0)"
    );
    assertEqualF32(
        f320_trunc(&instance, 0.0),
        0.0,
        "trunc(0.0)"
    );
    assertEqualF32(
        f320_trunc(&instance, -1.401298464324817e-45),
        -0.0,
        "trunc(-1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_trunc(&instance, 1.401298464324817e-45),
        0.0,
        "trunc(1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_trunc(&instance, -1.1754943508222875e-38),
        -0.0,
        "trunc(-1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_trunc(&instance, 1.1754943508222875e-38),
        0.0,
        "trunc(1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_trunc(&instance, -0.5),
        -0.0,
        "trunc(-0.5)"
    );
    assertEqualF32(
        f320_trunc(&instance, 0.5),
        0.0,
        "trunc(0.5)"
    );
    assertEqualF32(
        f320_trunc(&instance, -1.0),
        -1.0,
        "trunc(-1.0)"
    );
    assertEqualF32(
        f320_trunc(&instance, 1.0),
        1.0,
        "trunc(1.0)"
    );
    assertEqualF32(
        f320_trunc(&instance, -6.2831854820251465),
        -6.0,
        "trunc(-6.2831854820251465)"
    );
    assertEqualF32(
        f320_trunc(&instance, 6.2831854820251465),
        6.0,
        "trunc(6.2831854820251465)"
    );
    assertEqualF32(
        f320_trunc(&instance, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "trunc(-3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_trunc(&instance, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "trunc(3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_trunc(&instance, -INFINITY),
        -INFINITY,
        "trunc(-INFINITY)"
    );
    assertEqualF32(
        f320_trunc(&instance, INFINITY),
        INFINITY,
        "trunc(INFINITY)"
    );
    assertEqualF32(
        f320_nearest(&instance, -0.0),
        -0.0,
        "nearest(-0.0)"
    );
    assertEqualF32(
        f320_nearest(&instance, 0.0),
        0.0,
        "nearest(0.0)"
    );
    assertEqualF32(
        f320_nearest(&instance, -1.401298464324817e-45),
        -0.0,
        "nearest(-1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_nearest(&instance, 1.401298464324817e-45),
        0.0,
        "nearest(1.401298464324817e-45)"
    );
    assertEqualF32(
        f320_nearest(&instance, -1.1754943508222875e-38),
        -0.0,
        "nearest(-1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_nearest(&instance, 1.1754943508222875e-38),
        0.0,
        "nearest(1.1754943508222875e-38)"
    );
    assertEqualF32(
        f320_nearest(&instance, -0.5),
        -0.0,
        "nearest(-0.5)"
    );
    assertEqualF32(
        f320_nearest(&instance, 0.5),
        0.0,
        "nearest(0.5)"
    );
    assertEqualF32(
        f320_nearest(&instance, -1.0),
        -1.0,
        "nearest(-1.0)"
    );
    assertEqualF32(
        f320_nearest(&instance, 1.0),
        1.0,
        "nearest(1.0)"
    );
    assertEqualF32(
        f320_nearest(&instance, -6.2831854820251465),
        -6.0,
        "nearest(-6.2831854820251465)"
    );
    assertEqualF32(
        f320_nearest(&instance, 6.2831854820251465),
        6.0,
        "nearest(6.2831854820251465)"
    );
    assertEqualF32(
        f320_nearest(&instance, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "nearest(-3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_nearest(&instance, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "nearest(3.4028234663852886e+38)"
    );
    assertEqualF32(
        f320_nearest(&instance, -INFINITY),
        -INFINITY,
        "nearest(-INFINITY)"
    );
    assertEqualF32(
        f320_nearest(&instance, INFINITY),
        INFINITY,
        "nearest(INFINITY)"
    );
}
