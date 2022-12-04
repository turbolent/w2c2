
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_f64_bitwise.0.h"

void test() {
    f64bitwise0Instance instance;
    f64bitwise0Instantiate(&instance, resolveTestImports);
    printStart("f64_bitwise.0.wasm");
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, -0.0),
        -0.0,
        "copysign(-0.0, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, 0.0),
        0.0,
        "copysign(-0.0, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, -0.0),
        -0.0,
        "copysign(0.0, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, 0.0),
        0.0,
        "copysign(0.0, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, -5e-324),
        -0.0,
        "copysign(-0.0, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, 5e-324),
        0.0,
        "copysign(-0.0, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, -5e-324),
        -0.0,
        "copysign(0.0, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, 5e-324),
        0.0,
        "copysign(0.0, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, -2.2250738585072014e-308),
        -0.0,
        "copysign(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, 2.2250738585072014e-308),
        0.0,
        "copysign(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, -2.2250738585072014e-308),
        -0.0,
        "copysign(0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, 2.2250738585072014e-308),
        0.0,
        "copysign(0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, -0.5),
        -0.0,
        "copysign(-0.0, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, 0.5),
        0.0,
        "copysign(-0.0, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, -0.5),
        -0.0,
        "copysign(0.0, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, 0.5),
        0.0,
        "copysign(0.0, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, -1.0),
        -0.0,
        "copysign(-0.0, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, 1.0),
        0.0,
        "copysign(-0.0, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, -1.0),
        -0.0,
        "copysign(0.0, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, 1.0),
        0.0,
        "copysign(0.0, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, -6.283185307179586),
        -0.0,
        "copysign(-0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, 6.283185307179586),
        0.0,
        "copysign(-0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, -6.283185307179586),
        -0.0,
        "copysign(0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, 6.283185307179586),
        0.0,
        "copysign(0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, -1.7976931348623157e+308),
        -0.0,
        "copysign(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, 1.7976931348623157e+308),
        0.0,
        "copysign(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, -1.7976931348623157e+308),
        -0.0,
        "copysign(0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, 1.7976931348623157e+308),
        0.0,
        "copysign(0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, -INFINITY),
        -0.0,
        "copysign(-0.0, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.0, INFINITY),
        0.0,
        "copysign(-0.0, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, -INFINITY),
        -0.0,
        "copysign(0.0, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.0, INFINITY),
        0.0,
        "copysign(0.0, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, -0.0),
        -5e-324,
        "copysign(-5e-324, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, 0.0),
        5e-324,
        "copysign(-5e-324, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, -0.0),
        -5e-324,
        "copysign(5e-324, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, 0.0),
        5e-324,
        "copysign(5e-324, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, -5e-324),
        -5e-324,
        "copysign(-5e-324, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, 5e-324),
        5e-324,
        "copysign(-5e-324, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, -5e-324),
        -5e-324,
        "copysign(5e-324, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, 5e-324),
        5e-324,
        "copysign(5e-324, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, -2.2250738585072014e-308),
        -5e-324,
        "copysign(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, 2.2250738585072014e-308),
        5e-324,
        "copysign(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, -2.2250738585072014e-308),
        -5e-324,
        "copysign(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, 2.2250738585072014e-308),
        5e-324,
        "copysign(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, -0.5),
        -5e-324,
        "copysign(-5e-324, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, 0.5),
        5e-324,
        "copysign(-5e-324, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, -0.5),
        -5e-324,
        "copysign(5e-324, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, 0.5),
        5e-324,
        "copysign(5e-324, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, -1.0),
        -5e-324,
        "copysign(-5e-324, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, 1.0),
        5e-324,
        "copysign(-5e-324, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, -1.0),
        -5e-324,
        "copysign(5e-324, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, 1.0),
        5e-324,
        "copysign(5e-324, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, -6.283185307179586),
        -5e-324,
        "copysign(-5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, 6.283185307179586),
        5e-324,
        "copysign(-5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, -6.283185307179586),
        -5e-324,
        "copysign(5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, 6.283185307179586),
        5e-324,
        "copysign(5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, -1.7976931348623157e+308),
        -5e-324,
        "copysign(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, 1.7976931348623157e+308),
        5e-324,
        "copysign(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, -1.7976931348623157e+308),
        -5e-324,
        "copysign(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, 1.7976931348623157e+308),
        5e-324,
        "copysign(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, -INFINITY),
        -5e-324,
        "copysign(-5e-324, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -5e-324, INFINITY),
        5e-324,
        "copysign(-5e-324, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, -INFINITY),
        -5e-324,
        "copysign(5e-324, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 5e-324, INFINITY),
        5e-324,
        "copysign(5e-324, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, -0.0),
        -2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, 0.0),
        2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, -0.0),
        -2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, 0.0),
        2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, -5e-324),
        -2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, 5e-324),
        2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, -5e-324),
        -2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, 5e-324),
        2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, -0.5),
        -2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, 0.5),
        2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, -0.5),
        -2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, 0.5),
        2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, -1.0),
        -2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, 1.0),
        2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, -1.0),
        -2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, 1.0),
        2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, -6.283185307179586),
        -2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, 6.283185307179586),
        2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, -6.283185307179586),
        -2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, 6.283185307179586),
        2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        -2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        -2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, -INFINITY),
        -2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -2.2250738585072014e-308, INFINITY),
        2.2250738585072014e-308,
        "copysign(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, -INFINITY),
        -2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 2.2250738585072014e-308, INFINITY),
        2.2250738585072014e-308,
        "copysign(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, -0.0),
        -0.5,
        "copysign(-0.5, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, 0.0),
        0.5,
        "copysign(-0.5, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, -0.0),
        -0.5,
        "copysign(0.5, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, 0.0),
        0.5,
        "copysign(0.5, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, -5e-324),
        -0.5,
        "copysign(-0.5, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, 5e-324),
        0.5,
        "copysign(-0.5, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, -5e-324),
        -0.5,
        "copysign(0.5, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, 5e-324),
        0.5,
        "copysign(0.5, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, -2.2250738585072014e-308),
        -0.5,
        "copysign(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, 2.2250738585072014e-308),
        0.5,
        "copysign(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, -2.2250738585072014e-308),
        -0.5,
        "copysign(0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, 2.2250738585072014e-308),
        0.5,
        "copysign(0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, -0.5),
        -0.5,
        "copysign(-0.5, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, 0.5),
        0.5,
        "copysign(-0.5, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, -0.5),
        -0.5,
        "copysign(0.5, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, 0.5),
        0.5,
        "copysign(0.5, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, -1.0),
        -0.5,
        "copysign(-0.5, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, 1.0),
        0.5,
        "copysign(-0.5, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, -1.0),
        -0.5,
        "copysign(0.5, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, 1.0),
        0.5,
        "copysign(0.5, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, -6.283185307179586),
        -0.5,
        "copysign(-0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, 6.283185307179586),
        0.5,
        "copysign(-0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, -6.283185307179586),
        -0.5,
        "copysign(0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, 6.283185307179586),
        0.5,
        "copysign(0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, -1.7976931348623157e+308),
        -0.5,
        "copysign(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, 1.7976931348623157e+308),
        0.5,
        "copysign(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, -1.7976931348623157e+308),
        -0.5,
        "copysign(0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, 1.7976931348623157e+308),
        0.5,
        "copysign(0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, -INFINITY),
        -0.5,
        "copysign(-0.5, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -0.5, INFINITY),
        0.5,
        "copysign(-0.5, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, -INFINITY),
        -0.5,
        "copysign(0.5, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 0.5, INFINITY),
        0.5,
        "copysign(0.5, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, -0.0),
        -1.0,
        "copysign(-1.0, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, 0.0),
        1.0,
        "copysign(-1.0, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, -0.0),
        -1.0,
        "copysign(1.0, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, 0.0),
        1.0,
        "copysign(1.0, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, -5e-324),
        -1.0,
        "copysign(-1.0, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, 5e-324),
        1.0,
        "copysign(-1.0, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, -5e-324),
        -1.0,
        "copysign(1.0, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, 5e-324),
        1.0,
        "copysign(1.0, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, -2.2250738585072014e-308),
        -1.0,
        "copysign(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, 2.2250738585072014e-308),
        1.0,
        "copysign(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, -2.2250738585072014e-308),
        -1.0,
        "copysign(1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, 2.2250738585072014e-308),
        1.0,
        "copysign(1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, -0.5),
        -1.0,
        "copysign(-1.0, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, 0.5),
        1.0,
        "copysign(-1.0, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, -0.5),
        -1.0,
        "copysign(1.0, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, 0.5),
        1.0,
        "copysign(1.0, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, -1.0),
        -1.0,
        "copysign(-1.0, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, 1.0),
        1.0,
        "copysign(-1.0, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, -1.0),
        -1.0,
        "copysign(1.0, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, 1.0),
        1.0,
        "copysign(1.0, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, -6.283185307179586),
        -1.0,
        "copysign(-1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, 6.283185307179586),
        1.0,
        "copysign(-1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, -6.283185307179586),
        -1.0,
        "copysign(1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, 6.283185307179586),
        1.0,
        "copysign(1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, -1.7976931348623157e+308),
        -1.0,
        "copysign(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, 1.7976931348623157e+308),
        1.0,
        "copysign(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, -1.7976931348623157e+308),
        -1.0,
        "copysign(1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, 1.7976931348623157e+308),
        1.0,
        "copysign(1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, -INFINITY),
        -1.0,
        "copysign(-1.0, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.0, INFINITY),
        1.0,
        "copysign(-1.0, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, -INFINITY),
        -1.0,
        "copysign(1.0, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.0, INFINITY),
        1.0,
        "copysign(1.0, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, -0.0),
        -6.283185307179586,
        "copysign(-6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, 0.0),
        6.283185307179586,
        "copysign(-6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, -0.0),
        -6.283185307179586,
        "copysign(6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, 0.0),
        6.283185307179586,
        "copysign(6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, -5e-324),
        -6.283185307179586,
        "copysign(-6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, 5e-324),
        6.283185307179586,
        "copysign(-6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, -5e-324),
        -6.283185307179586,
        "copysign(6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, 5e-324),
        6.283185307179586,
        "copysign(6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, -2.2250738585072014e-308),
        -6.283185307179586,
        "copysign(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, 2.2250738585072014e-308),
        6.283185307179586,
        "copysign(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, -2.2250738585072014e-308),
        -6.283185307179586,
        "copysign(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, 2.2250738585072014e-308),
        6.283185307179586,
        "copysign(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, -0.5),
        -6.283185307179586,
        "copysign(-6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, 0.5),
        6.283185307179586,
        "copysign(-6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, -0.5),
        -6.283185307179586,
        "copysign(6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, 0.5),
        6.283185307179586,
        "copysign(6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, -1.0),
        -6.283185307179586,
        "copysign(-6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, 1.0),
        6.283185307179586,
        "copysign(-6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, -1.0),
        -6.283185307179586,
        "copysign(6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, 1.0),
        6.283185307179586,
        "copysign(6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, -6.283185307179586),
        -6.283185307179586,
        "copysign(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, 6.283185307179586),
        6.283185307179586,
        "copysign(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, -6.283185307179586),
        -6.283185307179586,
        "copysign(6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, 6.283185307179586),
        6.283185307179586,
        "copysign(6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, -1.7976931348623157e+308),
        -6.283185307179586,
        "copysign(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, 1.7976931348623157e+308),
        6.283185307179586,
        "copysign(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, -1.7976931348623157e+308),
        -6.283185307179586,
        "copysign(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, 1.7976931348623157e+308),
        6.283185307179586,
        "copysign(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, -INFINITY),
        -6.283185307179586,
        "copysign(-6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -6.283185307179586, INFINITY),
        6.283185307179586,
        "copysign(-6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, -INFINITY),
        -6.283185307179586,
        "copysign(6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 6.283185307179586, INFINITY),
        6.283185307179586,
        "copysign(6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, -0.0),
        -1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, 0.0),
        1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, -0.0),
        -1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, 0.0),
        1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, -5e-324),
        -1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, 5e-324),
        1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, -5e-324),
        -1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, 5e-324),
        1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        -1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        -1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, -0.5),
        -1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, 0.5),
        1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, -0.5),
        -1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, 0.5),
        1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, -1.0),
        -1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, 1.0),
        1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, -1.0),
        -1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, 1.0),
        1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, -6.283185307179586),
        -1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, 6.283185307179586),
        1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, -6.283185307179586),
        -1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, 6.283185307179586),
        1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, -INFINITY),
        -1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -1.7976931348623157e+308, INFINITY),
        1.7976931348623157e+308,
        "copysign(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, -INFINITY),
        -1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, 1.7976931348623157e+308, INFINITY),
        1.7976931348623157e+308,
        "copysign(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, -0.0),
        -INFINITY,
        "copysign(-INFINITY, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, 0.0),
        INFINITY,
        "copysign(-INFINITY, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, -0.0),
        -INFINITY,
        "copysign(INFINITY, -0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, 0.0),
        INFINITY,
        "copysign(INFINITY, 0.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, -5e-324),
        -INFINITY,
        "copysign(-INFINITY, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, 5e-324),
        INFINITY,
        "copysign(-INFINITY, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, -5e-324),
        -INFINITY,
        "copysign(INFINITY, -5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, 5e-324),
        INFINITY,
        "copysign(INFINITY, 5e-324)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, -2.2250738585072014e-308),
        -INFINITY,
        "copysign(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, 2.2250738585072014e-308),
        INFINITY,
        "copysign(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, -2.2250738585072014e-308),
        -INFINITY,
        "copysign(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, 2.2250738585072014e-308),
        INFINITY,
        "copysign(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, -0.5),
        -INFINITY,
        "copysign(-INFINITY, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, 0.5),
        INFINITY,
        "copysign(-INFINITY, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, -0.5),
        -INFINITY,
        "copysign(INFINITY, -0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, 0.5),
        INFINITY,
        "copysign(INFINITY, 0.5)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, -1.0),
        -INFINITY,
        "copysign(-INFINITY, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, 1.0),
        INFINITY,
        "copysign(-INFINITY, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, -1.0),
        -INFINITY,
        "copysign(INFINITY, -1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, 1.0),
        INFINITY,
        "copysign(INFINITY, 1.0)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, -6.283185307179586),
        -INFINITY,
        "copysign(-INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, 6.283185307179586),
        INFINITY,
        "copysign(-INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, -6.283185307179586),
        -INFINITY,
        "copysign(INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, 6.283185307179586),
        INFINITY,
        "copysign(INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, -1.7976931348623157e+308),
        -INFINITY,
        "copysign(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, 1.7976931348623157e+308),
        INFINITY,
        "copysign(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, -1.7976931348623157e+308),
        -INFINITY,
        "copysign(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, 1.7976931348623157e+308),
        INFINITY,
        "copysign(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, -INFINITY),
        -INFINITY,
        "copysign(-INFINITY, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, -INFINITY, INFINITY),
        INFINITY,
        "copysign(-INFINITY, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, -INFINITY),
        -INFINITY,
        "copysign(INFINITY, -INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_copysign(&instance, INFINITY, INFINITY),
        INFINITY,
        "copysign(INFINITY, INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, -0.0),
        0.0,
        "abs(-0.0)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, 0.0),
        0.0,
        "abs(0.0)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, -5e-324),
        5e-324,
        "abs(-5e-324)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, 5e-324),
        5e-324,
        "abs(5e-324)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, -2.2250738585072014e-308),
        2.2250738585072014e-308,
        "abs(-2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "abs(2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, -0.5),
        0.5,
        "abs(-0.5)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, 0.5),
        0.5,
        "abs(0.5)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, -1.0),
        1.0,
        "abs(-1.0)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, 1.0),
        1.0,
        "abs(1.0)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, -6.283185307179586),
        6.283185307179586,
        "abs(-6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, 6.283185307179586),
        6.283185307179586,
        "abs(6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "abs(-1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "abs(1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, -INFINITY),
        INFINITY,
        "abs(-INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_abs(&instance, INFINITY),
        INFINITY,
        "abs(INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, -0.0),
        0.0,
        "neg(-0.0)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, 0.0),
        -0.0,
        "neg(0.0)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, -5e-324),
        5e-324,
        "neg(-5e-324)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, 5e-324),
        -5e-324,
        "neg(5e-324)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, -2.2250738585072014e-308),
        2.2250738585072014e-308,
        "neg(-2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, 2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "neg(2.2250738585072014e-308)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, -0.5),
        0.5,
        "neg(-0.5)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, 0.5),
        -0.5,
        "neg(0.5)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, -1.0),
        1.0,
        "neg(-1.0)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, 1.0),
        -1.0,
        "neg(1.0)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, -6.283185307179586),
        6.283185307179586,
        "neg(-6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, 6.283185307179586),
        -6.283185307179586,
        "neg(6.283185307179586)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "neg(-1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "neg(1.7976931348623157e+308)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, -INFINITY),
        INFINITY,
        "neg(-INFINITY)"
    );
    assertEqualF64(
        f64bitwise0_neg(&instance, INFINITY),
        -INFINITY,
        "neg(INFINITY)"
    );
}
