
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_f64_cmp.0.h"

void test() {
    f64cmp0Instance instance;
    f64cmp0Instantiate(&instance, resolveTestImports);
    printStart("f64_cmp.0.wasm");
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, -0.0),
        1u,
        "eq(-0.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, 0.0),
        1u,
        "eq(-0.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, -0.0),
        1u,
        "eq(0.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, 0.0),
        1u,
        "eq(0.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, -5e-324),
        0u,
        "eq(-0.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, 5e-324),
        0u,
        "eq(-0.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, -5e-324),
        0u,
        "eq(0.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, 5e-324),
        0u,
        "eq(0.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, -2.2250738585072014e-308),
        0u,
        "eq(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, 2.2250738585072014e-308),
        0u,
        "eq(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, -2.2250738585072014e-308),
        0u,
        "eq(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, 2.2250738585072014e-308),
        0u,
        "eq(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, -0.5),
        0u,
        "eq(-0.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, 0.5),
        0u,
        "eq(-0.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, -0.5),
        0u,
        "eq(0.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, 0.5),
        0u,
        "eq(0.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, -1.0),
        0u,
        "eq(-0.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, 1.0),
        0u,
        "eq(-0.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, -1.0),
        0u,
        "eq(0.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, 1.0),
        0u,
        "eq(0.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, -6.283185307179586),
        0u,
        "eq(-0.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, 6.283185307179586),
        0u,
        "eq(-0.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, -6.283185307179586),
        0u,
        "eq(0.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, 6.283185307179586),
        0u,
        "eq(0.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, -1.7976931348623157e+308),
        0u,
        "eq(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, 1.7976931348623157e+308),
        0u,
        "eq(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, -1.7976931348623157e+308),
        0u,
        "eq(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, 1.7976931348623157e+308),
        0u,
        "eq(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, -INFINITY),
        0u,
        "eq(-0.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.0, INFINITY),
        0u,
        "eq(-0.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, -INFINITY),
        0u,
        "eq(0.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.0, INFINITY),
        0u,
        "eq(0.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, -0.0),
        0u,
        "eq(-5e-324, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, 0.0),
        0u,
        "eq(-5e-324, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, -0.0),
        0u,
        "eq(5e-324, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, 0.0),
        0u,
        "eq(5e-324, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, -5e-324),
        1u,
        "eq(-5e-324, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, 5e-324),
        0u,
        "eq(-5e-324, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, -5e-324),
        0u,
        "eq(5e-324, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, 5e-324),
        1u,
        "eq(5e-324, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, -2.2250738585072014e-308),
        0u,
        "eq(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, 2.2250738585072014e-308),
        0u,
        "eq(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, -2.2250738585072014e-308),
        0u,
        "eq(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, 2.2250738585072014e-308),
        0u,
        "eq(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, -0.5),
        0u,
        "eq(-5e-324, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, 0.5),
        0u,
        "eq(-5e-324, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, -0.5),
        0u,
        "eq(5e-324, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, 0.5),
        0u,
        "eq(5e-324, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, -1.0),
        0u,
        "eq(-5e-324, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, 1.0),
        0u,
        "eq(-5e-324, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, -1.0),
        0u,
        "eq(5e-324, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, 1.0),
        0u,
        "eq(5e-324, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, -6.283185307179586),
        0u,
        "eq(-5e-324, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, 6.283185307179586),
        0u,
        "eq(-5e-324, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, -6.283185307179586),
        0u,
        "eq(5e-324, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, 6.283185307179586),
        0u,
        "eq(5e-324, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, -1.7976931348623157e+308),
        0u,
        "eq(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, 1.7976931348623157e+308),
        0u,
        "eq(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, -1.7976931348623157e+308),
        0u,
        "eq(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, 1.7976931348623157e+308),
        0u,
        "eq(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, -INFINITY),
        0u,
        "eq(-5e-324, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -5e-324, INFINITY),
        0u,
        "eq(-5e-324, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, -INFINITY),
        0u,
        "eq(5e-324, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 5e-324, INFINITY),
        0u,
        "eq(5e-324, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, -0.0),
        0u,
        "eq(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, 0.0),
        0u,
        "eq(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, -0.0),
        0u,
        "eq(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, 0.0),
        0u,
        "eq(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, -5e-324),
        0u,
        "eq(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, 5e-324),
        0u,
        "eq(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, -5e-324),
        0u,
        "eq(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, 5e-324),
        0u,
        "eq(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        1u,
        "eq(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        0u,
        "eq(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        0u,
        "eq(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        1u,
        "eq(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, -0.5),
        0u,
        "eq(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, 0.5),
        0u,
        "eq(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, -0.5),
        0u,
        "eq(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, 0.5),
        0u,
        "eq(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, -1.0),
        0u,
        "eq(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, 1.0),
        0u,
        "eq(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, -1.0),
        0u,
        "eq(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, 1.0),
        0u,
        "eq(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, -6.283185307179586),
        0u,
        "eq(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, 6.283185307179586),
        0u,
        "eq(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, -6.283185307179586),
        0u,
        "eq(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, 6.283185307179586),
        0u,
        "eq(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        0u,
        "eq(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        0u,
        "eq(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        0u,
        "eq(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        0u,
        "eq(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, -INFINITY),
        0u,
        "eq(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -2.2250738585072014e-308, INFINITY),
        0u,
        "eq(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, -INFINITY),
        0u,
        "eq(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 2.2250738585072014e-308, INFINITY),
        0u,
        "eq(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, -0.0),
        0u,
        "eq(-0.5, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, 0.0),
        0u,
        "eq(-0.5, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, -0.0),
        0u,
        "eq(0.5, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, 0.0),
        0u,
        "eq(0.5, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, -5e-324),
        0u,
        "eq(-0.5, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, 5e-324),
        0u,
        "eq(-0.5, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, -5e-324),
        0u,
        "eq(0.5, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, 5e-324),
        0u,
        "eq(0.5, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, -2.2250738585072014e-308),
        0u,
        "eq(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, 2.2250738585072014e-308),
        0u,
        "eq(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, -2.2250738585072014e-308),
        0u,
        "eq(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, 2.2250738585072014e-308),
        0u,
        "eq(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, -0.5),
        1u,
        "eq(-0.5, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, 0.5),
        0u,
        "eq(-0.5, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, -0.5),
        0u,
        "eq(0.5, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, 0.5),
        1u,
        "eq(0.5, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, -1.0),
        0u,
        "eq(-0.5, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, 1.0),
        0u,
        "eq(-0.5, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, -1.0),
        0u,
        "eq(0.5, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, 1.0),
        0u,
        "eq(0.5, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, -6.283185307179586),
        0u,
        "eq(-0.5, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, 6.283185307179586),
        0u,
        "eq(-0.5, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, -6.283185307179586),
        0u,
        "eq(0.5, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, 6.283185307179586),
        0u,
        "eq(0.5, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, -1.7976931348623157e+308),
        0u,
        "eq(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, 1.7976931348623157e+308),
        0u,
        "eq(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, -1.7976931348623157e+308),
        0u,
        "eq(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, 1.7976931348623157e+308),
        0u,
        "eq(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, -INFINITY),
        0u,
        "eq(-0.5, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -0.5, INFINITY),
        0u,
        "eq(-0.5, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, -INFINITY),
        0u,
        "eq(0.5, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 0.5, INFINITY),
        0u,
        "eq(0.5, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, -0.0),
        0u,
        "eq(-1.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, 0.0),
        0u,
        "eq(-1.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, -0.0),
        0u,
        "eq(1.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, 0.0),
        0u,
        "eq(1.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, -5e-324),
        0u,
        "eq(-1.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, 5e-324),
        0u,
        "eq(-1.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, -5e-324),
        0u,
        "eq(1.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, 5e-324),
        0u,
        "eq(1.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, -2.2250738585072014e-308),
        0u,
        "eq(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, 2.2250738585072014e-308),
        0u,
        "eq(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, -2.2250738585072014e-308),
        0u,
        "eq(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, 2.2250738585072014e-308),
        0u,
        "eq(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, -0.5),
        0u,
        "eq(-1.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, 0.5),
        0u,
        "eq(-1.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, -0.5),
        0u,
        "eq(1.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, 0.5),
        0u,
        "eq(1.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, -1.0),
        1u,
        "eq(-1.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, 1.0),
        0u,
        "eq(-1.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, -1.0),
        0u,
        "eq(1.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, 1.0),
        1u,
        "eq(1.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, -6.283185307179586),
        0u,
        "eq(-1.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, 6.283185307179586),
        0u,
        "eq(-1.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, -6.283185307179586),
        0u,
        "eq(1.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, 6.283185307179586),
        0u,
        "eq(1.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, -1.7976931348623157e+308),
        0u,
        "eq(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, 1.7976931348623157e+308),
        0u,
        "eq(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, -1.7976931348623157e+308),
        0u,
        "eq(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, 1.7976931348623157e+308),
        0u,
        "eq(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, -INFINITY),
        0u,
        "eq(-1.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.0, INFINITY),
        0u,
        "eq(-1.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, -INFINITY),
        0u,
        "eq(1.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.0, INFINITY),
        0u,
        "eq(1.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, -0.0),
        0u,
        "eq(-6.283185307179586, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, 0.0),
        0u,
        "eq(-6.283185307179586, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, -0.0),
        0u,
        "eq(6.283185307179586, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, 0.0),
        0u,
        "eq(6.283185307179586, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, -5e-324),
        0u,
        "eq(-6.283185307179586, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, 5e-324),
        0u,
        "eq(-6.283185307179586, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, -5e-324),
        0u,
        "eq(6.283185307179586, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, 5e-324),
        0u,
        "eq(6.283185307179586, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, -2.2250738585072014e-308),
        0u,
        "eq(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, 2.2250738585072014e-308),
        0u,
        "eq(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, -2.2250738585072014e-308),
        0u,
        "eq(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, 2.2250738585072014e-308),
        0u,
        "eq(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, -0.5),
        0u,
        "eq(-6.283185307179586, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, 0.5),
        0u,
        "eq(-6.283185307179586, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, -0.5),
        0u,
        "eq(6.283185307179586, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, 0.5),
        0u,
        "eq(6.283185307179586, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, -1.0),
        0u,
        "eq(-6.283185307179586, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, 1.0),
        0u,
        "eq(-6.283185307179586, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, -1.0),
        0u,
        "eq(6.283185307179586, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, 1.0),
        0u,
        "eq(6.283185307179586, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, -6.283185307179586),
        1u,
        "eq(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, 6.283185307179586),
        0u,
        "eq(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, -6.283185307179586),
        0u,
        "eq(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, 6.283185307179586),
        1u,
        "eq(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, -1.7976931348623157e+308),
        0u,
        "eq(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, 1.7976931348623157e+308),
        0u,
        "eq(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, -1.7976931348623157e+308),
        0u,
        "eq(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, 1.7976931348623157e+308),
        0u,
        "eq(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, -INFINITY),
        0u,
        "eq(-6.283185307179586, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -6.283185307179586, INFINITY),
        0u,
        "eq(-6.283185307179586, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, -INFINITY),
        0u,
        "eq(6.283185307179586, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 6.283185307179586, INFINITY),
        0u,
        "eq(6.283185307179586, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, -0.0),
        0u,
        "eq(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, 0.0),
        0u,
        "eq(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, -0.0),
        0u,
        "eq(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, 0.0),
        0u,
        "eq(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, -5e-324),
        0u,
        "eq(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, 5e-324),
        0u,
        "eq(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, -5e-324),
        0u,
        "eq(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, 5e-324),
        0u,
        "eq(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        0u,
        "eq(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        0u,
        "eq(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        0u,
        "eq(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        0u,
        "eq(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, -0.5),
        0u,
        "eq(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, 0.5),
        0u,
        "eq(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, -0.5),
        0u,
        "eq(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, 0.5),
        0u,
        "eq(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, -1.0),
        0u,
        "eq(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, 1.0),
        0u,
        "eq(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, -1.0),
        0u,
        "eq(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, 1.0),
        0u,
        "eq(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, -6.283185307179586),
        0u,
        "eq(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, 6.283185307179586),
        0u,
        "eq(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, -6.283185307179586),
        0u,
        "eq(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, 6.283185307179586),
        0u,
        "eq(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        1u,
        "eq(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        0u,
        "eq(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        0u,
        "eq(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        1u,
        "eq(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, -INFINITY),
        0u,
        "eq(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -1.7976931348623157e+308, INFINITY),
        0u,
        "eq(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, -INFINITY),
        0u,
        "eq(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, 1.7976931348623157e+308, INFINITY),
        0u,
        "eq(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, -0.0),
        0u,
        "eq(-INFINITY, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, 0.0),
        0u,
        "eq(-INFINITY, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, -0.0),
        0u,
        "eq(INFINITY, -0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, 0.0),
        0u,
        "eq(INFINITY, 0.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, -5e-324),
        0u,
        "eq(-INFINITY, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, 5e-324),
        0u,
        "eq(-INFINITY, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, -5e-324),
        0u,
        "eq(INFINITY, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, 5e-324),
        0u,
        "eq(INFINITY, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, -2.2250738585072014e-308),
        0u,
        "eq(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, 2.2250738585072014e-308),
        0u,
        "eq(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, -2.2250738585072014e-308),
        0u,
        "eq(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, 2.2250738585072014e-308),
        0u,
        "eq(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, -0.5),
        0u,
        "eq(-INFINITY, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, 0.5),
        0u,
        "eq(-INFINITY, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, -0.5),
        0u,
        "eq(INFINITY, -0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, 0.5),
        0u,
        "eq(INFINITY, 0.5)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, -1.0),
        0u,
        "eq(-INFINITY, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, 1.0),
        0u,
        "eq(-INFINITY, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, -1.0),
        0u,
        "eq(INFINITY, -1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, 1.0),
        0u,
        "eq(INFINITY, 1.0)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, -6.283185307179586),
        0u,
        "eq(-INFINITY, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, 6.283185307179586),
        0u,
        "eq(-INFINITY, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, -6.283185307179586),
        0u,
        "eq(INFINITY, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, 6.283185307179586),
        0u,
        "eq(INFINITY, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, -1.7976931348623157e+308),
        0u,
        "eq(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, 1.7976931348623157e+308),
        0u,
        "eq(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, -1.7976931348623157e+308),
        0u,
        "eq(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, 1.7976931348623157e+308),
        0u,
        "eq(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, -INFINITY),
        1u,
        "eq(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, -INFINITY, INFINITY),
        0u,
        "eq(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, -INFINITY),
        0u,
        "eq(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_eq(&instance, INFINITY, INFINITY),
        1u,
        "eq(INFINITY, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, -0.0),
        0u,
        "ne(-0.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, 0.0),
        0u,
        "ne(-0.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, -0.0),
        0u,
        "ne(0.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, 0.0),
        0u,
        "ne(0.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, -5e-324),
        1u,
        "ne(-0.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, 5e-324),
        1u,
        "ne(-0.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, -5e-324),
        1u,
        "ne(0.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, 5e-324),
        1u,
        "ne(0.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, -2.2250738585072014e-308),
        1u,
        "ne(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, 2.2250738585072014e-308),
        1u,
        "ne(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, -2.2250738585072014e-308),
        1u,
        "ne(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, 2.2250738585072014e-308),
        1u,
        "ne(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, -0.5),
        1u,
        "ne(-0.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, 0.5),
        1u,
        "ne(-0.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, -0.5),
        1u,
        "ne(0.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, 0.5),
        1u,
        "ne(0.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, -1.0),
        1u,
        "ne(-0.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, 1.0),
        1u,
        "ne(-0.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, -1.0),
        1u,
        "ne(0.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, 1.0),
        1u,
        "ne(0.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, -6.283185307179586),
        1u,
        "ne(-0.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, 6.283185307179586),
        1u,
        "ne(-0.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, -6.283185307179586),
        1u,
        "ne(0.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, 6.283185307179586),
        1u,
        "ne(0.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, -1.7976931348623157e+308),
        1u,
        "ne(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, 1.7976931348623157e+308),
        1u,
        "ne(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, -1.7976931348623157e+308),
        1u,
        "ne(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, 1.7976931348623157e+308),
        1u,
        "ne(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, -INFINITY),
        1u,
        "ne(-0.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.0, INFINITY),
        1u,
        "ne(-0.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, -INFINITY),
        1u,
        "ne(0.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.0, INFINITY),
        1u,
        "ne(0.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, -0.0),
        1u,
        "ne(-5e-324, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, 0.0),
        1u,
        "ne(-5e-324, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, -0.0),
        1u,
        "ne(5e-324, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, 0.0),
        1u,
        "ne(5e-324, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, -5e-324),
        0u,
        "ne(-5e-324, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, 5e-324),
        1u,
        "ne(-5e-324, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, -5e-324),
        1u,
        "ne(5e-324, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, 5e-324),
        0u,
        "ne(5e-324, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, -2.2250738585072014e-308),
        1u,
        "ne(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, 2.2250738585072014e-308),
        1u,
        "ne(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, -2.2250738585072014e-308),
        1u,
        "ne(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, 2.2250738585072014e-308),
        1u,
        "ne(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, -0.5),
        1u,
        "ne(-5e-324, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, 0.5),
        1u,
        "ne(-5e-324, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, -0.5),
        1u,
        "ne(5e-324, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, 0.5),
        1u,
        "ne(5e-324, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, -1.0),
        1u,
        "ne(-5e-324, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, 1.0),
        1u,
        "ne(-5e-324, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, -1.0),
        1u,
        "ne(5e-324, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, 1.0),
        1u,
        "ne(5e-324, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, -6.283185307179586),
        1u,
        "ne(-5e-324, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, 6.283185307179586),
        1u,
        "ne(-5e-324, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, -6.283185307179586),
        1u,
        "ne(5e-324, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, 6.283185307179586),
        1u,
        "ne(5e-324, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, -1.7976931348623157e+308),
        1u,
        "ne(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, 1.7976931348623157e+308),
        1u,
        "ne(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, -1.7976931348623157e+308),
        1u,
        "ne(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, 1.7976931348623157e+308),
        1u,
        "ne(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, -INFINITY),
        1u,
        "ne(-5e-324, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -5e-324, INFINITY),
        1u,
        "ne(-5e-324, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, -INFINITY),
        1u,
        "ne(5e-324, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 5e-324, INFINITY),
        1u,
        "ne(5e-324, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, -0.0),
        1u,
        "ne(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, 0.0),
        1u,
        "ne(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, -0.0),
        1u,
        "ne(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, 0.0),
        1u,
        "ne(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, -5e-324),
        1u,
        "ne(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, 5e-324),
        1u,
        "ne(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, -5e-324),
        1u,
        "ne(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, 5e-324),
        1u,
        "ne(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        0u,
        "ne(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        1u,
        "ne(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        1u,
        "ne(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        0u,
        "ne(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, -0.5),
        1u,
        "ne(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, 0.5),
        1u,
        "ne(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, -0.5),
        1u,
        "ne(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, 0.5),
        1u,
        "ne(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, -1.0),
        1u,
        "ne(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, 1.0),
        1u,
        "ne(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, -1.0),
        1u,
        "ne(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, 1.0),
        1u,
        "ne(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, -6.283185307179586),
        1u,
        "ne(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, 6.283185307179586),
        1u,
        "ne(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, -6.283185307179586),
        1u,
        "ne(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, 6.283185307179586),
        1u,
        "ne(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        1u,
        "ne(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        1u,
        "ne(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        1u,
        "ne(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        1u,
        "ne(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, -INFINITY),
        1u,
        "ne(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -2.2250738585072014e-308, INFINITY),
        1u,
        "ne(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, -INFINITY),
        1u,
        "ne(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 2.2250738585072014e-308, INFINITY),
        1u,
        "ne(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, -0.0),
        1u,
        "ne(-0.5, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, 0.0),
        1u,
        "ne(-0.5, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, -0.0),
        1u,
        "ne(0.5, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, 0.0),
        1u,
        "ne(0.5, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, -5e-324),
        1u,
        "ne(-0.5, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, 5e-324),
        1u,
        "ne(-0.5, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, -5e-324),
        1u,
        "ne(0.5, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, 5e-324),
        1u,
        "ne(0.5, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, -2.2250738585072014e-308),
        1u,
        "ne(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, 2.2250738585072014e-308),
        1u,
        "ne(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, -2.2250738585072014e-308),
        1u,
        "ne(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, 2.2250738585072014e-308),
        1u,
        "ne(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, -0.5),
        0u,
        "ne(-0.5, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, 0.5),
        1u,
        "ne(-0.5, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, -0.5),
        1u,
        "ne(0.5, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, 0.5),
        0u,
        "ne(0.5, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, -1.0),
        1u,
        "ne(-0.5, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, 1.0),
        1u,
        "ne(-0.5, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, -1.0),
        1u,
        "ne(0.5, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, 1.0),
        1u,
        "ne(0.5, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, -6.283185307179586),
        1u,
        "ne(-0.5, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, 6.283185307179586),
        1u,
        "ne(-0.5, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, -6.283185307179586),
        1u,
        "ne(0.5, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, 6.283185307179586),
        1u,
        "ne(0.5, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, -1.7976931348623157e+308),
        1u,
        "ne(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, 1.7976931348623157e+308),
        1u,
        "ne(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, -1.7976931348623157e+308),
        1u,
        "ne(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, 1.7976931348623157e+308),
        1u,
        "ne(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, -INFINITY),
        1u,
        "ne(-0.5, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -0.5, INFINITY),
        1u,
        "ne(-0.5, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, -INFINITY),
        1u,
        "ne(0.5, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 0.5, INFINITY),
        1u,
        "ne(0.5, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, -0.0),
        1u,
        "ne(-1.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, 0.0),
        1u,
        "ne(-1.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, -0.0),
        1u,
        "ne(1.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, 0.0),
        1u,
        "ne(1.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, -5e-324),
        1u,
        "ne(-1.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, 5e-324),
        1u,
        "ne(-1.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, -5e-324),
        1u,
        "ne(1.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, 5e-324),
        1u,
        "ne(1.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, -2.2250738585072014e-308),
        1u,
        "ne(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, 2.2250738585072014e-308),
        1u,
        "ne(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, -2.2250738585072014e-308),
        1u,
        "ne(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, 2.2250738585072014e-308),
        1u,
        "ne(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, -0.5),
        1u,
        "ne(-1.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, 0.5),
        1u,
        "ne(-1.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, -0.5),
        1u,
        "ne(1.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, 0.5),
        1u,
        "ne(1.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, -1.0),
        0u,
        "ne(-1.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, 1.0),
        1u,
        "ne(-1.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, -1.0),
        1u,
        "ne(1.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, 1.0),
        0u,
        "ne(1.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, -6.283185307179586),
        1u,
        "ne(-1.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, 6.283185307179586),
        1u,
        "ne(-1.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, -6.283185307179586),
        1u,
        "ne(1.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, 6.283185307179586),
        1u,
        "ne(1.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, -1.7976931348623157e+308),
        1u,
        "ne(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, 1.7976931348623157e+308),
        1u,
        "ne(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, -1.7976931348623157e+308),
        1u,
        "ne(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, 1.7976931348623157e+308),
        1u,
        "ne(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, -INFINITY),
        1u,
        "ne(-1.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.0, INFINITY),
        1u,
        "ne(-1.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, -INFINITY),
        1u,
        "ne(1.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.0, INFINITY),
        1u,
        "ne(1.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, -0.0),
        1u,
        "ne(-6.283185307179586, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, 0.0),
        1u,
        "ne(-6.283185307179586, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, -0.0),
        1u,
        "ne(6.283185307179586, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, 0.0),
        1u,
        "ne(6.283185307179586, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, -5e-324),
        1u,
        "ne(-6.283185307179586, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, 5e-324),
        1u,
        "ne(-6.283185307179586, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, -5e-324),
        1u,
        "ne(6.283185307179586, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, 5e-324),
        1u,
        "ne(6.283185307179586, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, -2.2250738585072014e-308),
        1u,
        "ne(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, 2.2250738585072014e-308),
        1u,
        "ne(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, -2.2250738585072014e-308),
        1u,
        "ne(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, 2.2250738585072014e-308),
        1u,
        "ne(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, -0.5),
        1u,
        "ne(-6.283185307179586, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, 0.5),
        1u,
        "ne(-6.283185307179586, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, -0.5),
        1u,
        "ne(6.283185307179586, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, 0.5),
        1u,
        "ne(6.283185307179586, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, -1.0),
        1u,
        "ne(-6.283185307179586, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, 1.0),
        1u,
        "ne(-6.283185307179586, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, -1.0),
        1u,
        "ne(6.283185307179586, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, 1.0),
        1u,
        "ne(6.283185307179586, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, -6.283185307179586),
        0u,
        "ne(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, 6.283185307179586),
        1u,
        "ne(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, -6.283185307179586),
        1u,
        "ne(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, 6.283185307179586),
        0u,
        "ne(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, -1.7976931348623157e+308),
        1u,
        "ne(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, 1.7976931348623157e+308),
        1u,
        "ne(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, -1.7976931348623157e+308),
        1u,
        "ne(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, 1.7976931348623157e+308),
        1u,
        "ne(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, -INFINITY),
        1u,
        "ne(-6.283185307179586, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -6.283185307179586, INFINITY),
        1u,
        "ne(-6.283185307179586, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, -INFINITY),
        1u,
        "ne(6.283185307179586, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 6.283185307179586, INFINITY),
        1u,
        "ne(6.283185307179586, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, -0.0),
        1u,
        "ne(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, 0.0),
        1u,
        "ne(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, -0.0),
        1u,
        "ne(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, 0.0),
        1u,
        "ne(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, -5e-324),
        1u,
        "ne(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, 5e-324),
        1u,
        "ne(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, -5e-324),
        1u,
        "ne(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, 5e-324),
        1u,
        "ne(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        1u,
        "ne(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        1u,
        "ne(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        1u,
        "ne(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        1u,
        "ne(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, -0.5),
        1u,
        "ne(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, 0.5),
        1u,
        "ne(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, -0.5),
        1u,
        "ne(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, 0.5),
        1u,
        "ne(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, -1.0),
        1u,
        "ne(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, 1.0),
        1u,
        "ne(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, -1.0),
        1u,
        "ne(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, 1.0),
        1u,
        "ne(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, -6.283185307179586),
        1u,
        "ne(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, 6.283185307179586),
        1u,
        "ne(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, -6.283185307179586),
        1u,
        "ne(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, 6.283185307179586),
        1u,
        "ne(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        0u,
        "ne(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        1u,
        "ne(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        1u,
        "ne(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        0u,
        "ne(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, -INFINITY),
        1u,
        "ne(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -1.7976931348623157e+308, INFINITY),
        1u,
        "ne(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, -INFINITY),
        1u,
        "ne(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, 1.7976931348623157e+308, INFINITY),
        1u,
        "ne(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, -0.0),
        1u,
        "ne(-INFINITY, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, 0.0),
        1u,
        "ne(-INFINITY, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, -0.0),
        1u,
        "ne(INFINITY, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, 0.0),
        1u,
        "ne(INFINITY, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, -5e-324),
        1u,
        "ne(-INFINITY, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, 5e-324),
        1u,
        "ne(-INFINITY, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, -5e-324),
        1u,
        "ne(INFINITY, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, 5e-324),
        1u,
        "ne(INFINITY, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, -2.2250738585072014e-308),
        1u,
        "ne(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, 2.2250738585072014e-308),
        1u,
        "ne(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, -2.2250738585072014e-308),
        1u,
        "ne(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, 2.2250738585072014e-308),
        1u,
        "ne(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, -0.5),
        1u,
        "ne(-INFINITY, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, 0.5),
        1u,
        "ne(-INFINITY, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, -0.5),
        1u,
        "ne(INFINITY, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, 0.5),
        1u,
        "ne(INFINITY, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, -1.0),
        1u,
        "ne(-INFINITY, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, 1.0),
        1u,
        "ne(-INFINITY, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, -1.0),
        1u,
        "ne(INFINITY, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, 1.0),
        1u,
        "ne(INFINITY, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, -6.283185307179586),
        1u,
        "ne(-INFINITY, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, 6.283185307179586),
        1u,
        "ne(-INFINITY, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, -6.283185307179586),
        1u,
        "ne(INFINITY, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, 6.283185307179586),
        1u,
        "ne(INFINITY, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, -1.7976931348623157e+308),
        1u,
        "ne(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, 1.7976931348623157e+308),
        1u,
        "ne(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, -1.7976931348623157e+308),
        1u,
        "ne(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, 1.7976931348623157e+308),
        1u,
        "ne(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, -INFINITY),
        0u,
        "ne(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, -INFINITY, INFINITY),
        1u,
        "ne(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, -INFINITY),
        1u,
        "ne(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ne(&instance, INFINITY, INFINITY),
        0u,
        "ne(INFINITY, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, -0.0),
        0u,
        "lt(-0.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, 0.0),
        0u,
        "lt(-0.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, -0.0),
        0u,
        "lt(0.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, 0.0),
        0u,
        "lt(0.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, -5e-324),
        0u,
        "lt(-0.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, 5e-324),
        1u,
        "lt(-0.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, -5e-324),
        0u,
        "lt(0.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, 5e-324),
        1u,
        "lt(0.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, -2.2250738585072014e-308),
        0u,
        "lt(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, 2.2250738585072014e-308),
        1u,
        "lt(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, -2.2250738585072014e-308),
        0u,
        "lt(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, 2.2250738585072014e-308),
        1u,
        "lt(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, -0.5),
        0u,
        "lt(-0.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, 0.5),
        1u,
        "lt(-0.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, -0.5),
        0u,
        "lt(0.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, 0.5),
        1u,
        "lt(0.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, -1.0),
        0u,
        "lt(-0.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, 1.0),
        1u,
        "lt(-0.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, -1.0),
        0u,
        "lt(0.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, 1.0),
        1u,
        "lt(0.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, -6.283185307179586),
        0u,
        "lt(-0.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, 6.283185307179586),
        1u,
        "lt(-0.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, -6.283185307179586),
        0u,
        "lt(0.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, 6.283185307179586),
        1u,
        "lt(0.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, -1.7976931348623157e+308),
        0u,
        "lt(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, 1.7976931348623157e+308),
        1u,
        "lt(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, -1.7976931348623157e+308),
        0u,
        "lt(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, 1.7976931348623157e+308),
        1u,
        "lt(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, -INFINITY),
        0u,
        "lt(-0.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.0, INFINITY),
        1u,
        "lt(-0.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, -INFINITY),
        0u,
        "lt(0.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.0, INFINITY),
        1u,
        "lt(0.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, -0.0),
        1u,
        "lt(-5e-324, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, 0.0),
        1u,
        "lt(-5e-324, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, -0.0),
        0u,
        "lt(5e-324, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, 0.0),
        0u,
        "lt(5e-324, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, -5e-324),
        0u,
        "lt(-5e-324, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, 5e-324),
        1u,
        "lt(-5e-324, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, -5e-324),
        0u,
        "lt(5e-324, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, 5e-324),
        0u,
        "lt(5e-324, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, -2.2250738585072014e-308),
        0u,
        "lt(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, 2.2250738585072014e-308),
        1u,
        "lt(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, -2.2250738585072014e-308),
        0u,
        "lt(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, 2.2250738585072014e-308),
        1u,
        "lt(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, -0.5),
        0u,
        "lt(-5e-324, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, 0.5),
        1u,
        "lt(-5e-324, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, -0.5),
        0u,
        "lt(5e-324, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, 0.5),
        1u,
        "lt(5e-324, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, -1.0),
        0u,
        "lt(-5e-324, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, 1.0),
        1u,
        "lt(-5e-324, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, -1.0),
        0u,
        "lt(5e-324, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, 1.0),
        1u,
        "lt(5e-324, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, -6.283185307179586),
        0u,
        "lt(-5e-324, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, 6.283185307179586),
        1u,
        "lt(-5e-324, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, -6.283185307179586),
        0u,
        "lt(5e-324, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, 6.283185307179586),
        1u,
        "lt(5e-324, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, -1.7976931348623157e+308),
        0u,
        "lt(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, 1.7976931348623157e+308),
        1u,
        "lt(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, -1.7976931348623157e+308),
        0u,
        "lt(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, 1.7976931348623157e+308),
        1u,
        "lt(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, -INFINITY),
        0u,
        "lt(-5e-324, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -5e-324, INFINITY),
        1u,
        "lt(-5e-324, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, -INFINITY),
        0u,
        "lt(5e-324, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 5e-324, INFINITY),
        1u,
        "lt(5e-324, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, -0.0),
        1u,
        "lt(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, 0.0),
        1u,
        "lt(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, -0.0),
        0u,
        "lt(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, 0.0),
        0u,
        "lt(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, -5e-324),
        1u,
        "lt(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, 5e-324),
        1u,
        "lt(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, -5e-324),
        0u,
        "lt(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, 5e-324),
        0u,
        "lt(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        0u,
        "lt(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        1u,
        "lt(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        0u,
        "lt(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        0u,
        "lt(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, -0.5),
        0u,
        "lt(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, 0.5),
        1u,
        "lt(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, -0.5),
        0u,
        "lt(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, 0.5),
        1u,
        "lt(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, -1.0),
        0u,
        "lt(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, 1.0),
        1u,
        "lt(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, -1.0),
        0u,
        "lt(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, 1.0),
        1u,
        "lt(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, -6.283185307179586),
        0u,
        "lt(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, 6.283185307179586),
        1u,
        "lt(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, -6.283185307179586),
        0u,
        "lt(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, 6.283185307179586),
        1u,
        "lt(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        0u,
        "lt(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        1u,
        "lt(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        0u,
        "lt(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        1u,
        "lt(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, -INFINITY),
        0u,
        "lt(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -2.2250738585072014e-308, INFINITY),
        1u,
        "lt(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, -INFINITY),
        0u,
        "lt(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 2.2250738585072014e-308, INFINITY),
        1u,
        "lt(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, -0.0),
        1u,
        "lt(-0.5, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, 0.0),
        1u,
        "lt(-0.5, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, -0.0),
        0u,
        "lt(0.5, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, 0.0),
        0u,
        "lt(0.5, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, -5e-324),
        1u,
        "lt(-0.5, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, 5e-324),
        1u,
        "lt(-0.5, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, -5e-324),
        0u,
        "lt(0.5, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, 5e-324),
        0u,
        "lt(0.5, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, -2.2250738585072014e-308),
        1u,
        "lt(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, 2.2250738585072014e-308),
        1u,
        "lt(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, -2.2250738585072014e-308),
        0u,
        "lt(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, 2.2250738585072014e-308),
        0u,
        "lt(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, -0.5),
        0u,
        "lt(-0.5, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, 0.5),
        1u,
        "lt(-0.5, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, -0.5),
        0u,
        "lt(0.5, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, 0.5),
        0u,
        "lt(0.5, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, -1.0),
        0u,
        "lt(-0.5, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, 1.0),
        1u,
        "lt(-0.5, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, -1.0),
        0u,
        "lt(0.5, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, 1.0),
        1u,
        "lt(0.5, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, -6.283185307179586),
        0u,
        "lt(-0.5, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, 6.283185307179586),
        1u,
        "lt(-0.5, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, -6.283185307179586),
        0u,
        "lt(0.5, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, 6.283185307179586),
        1u,
        "lt(0.5, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, -1.7976931348623157e+308),
        0u,
        "lt(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, 1.7976931348623157e+308),
        1u,
        "lt(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, -1.7976931348623157e+308),
        0u,
        "lt(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, 1.7976931348623157e+308),
        1u,
        "lt(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, -INFINITY),
        0u,
        "lt(-0.5, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -0.5, INFINITY),
        1u,
        "lt(-0.5, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, -INFINITY),
        0u,
        "lt(0.5, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 0.5, INFINITY),
        1u,
        "lt(0.5, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, -0.0),
        1u,
        "lt(-1.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, 0.0),
        1u,
        "lt(-1.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, -0.0),
        0u,
        "lt(1.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, 0.0),
        0u,
        "lt(1.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, -5e-324),
        1u,
        "lt(-1.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, 5e-324),
        1u,
        "lt(-1.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, -5e-324),
        0u,
        "lt(1.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, 5e-324),
        0u,
        "lt(1.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, -2.2250738585072014e-308),
        1u,
        "lt(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, 2.2250738585072014e-308),
        1u,
        "lt(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, -2.2250738585072014e-308),
        0u,
        "lt(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, 2.2250738585072014e-308),
        0u,
        "lt(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, -0.5),
        1u,
        "lt(-1.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, 0.5),
        1u,
        "lt(-1.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, -0.5),
        0u,
        "lt(1.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, 0.5),
        0u,
        "lt(1.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, -1.0),
        0u,
        "lt(-1.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, 1.0),
        1u,
        "lt(-1.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, -1.0),
        0u,
        "lt(1.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, 1.0),
        0u,
        "lt(1.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, -6.283185307179586),
        0u,
        "lt(-1.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, 6.283185307179586),
        1u,
        "lt(-1.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, -6.283185307179586),
        0u,
        "lt(1.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, 6.283185307179586),
        1u,
        "lt(1.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, -1.7976931348623157e+308),
        0u,
        "lt(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, 1.7976931348623157e+308),
        1u,
        "lt(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, -1.7976931348623157e+308),
        0u,
        "lt(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, 1.7976931348623157e+308),
        1u,
        "lt(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, -INFINITY),
        0u,
        "lt(-1.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.0, INFINITY),
        1u,
        "lt(-1.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, -INFINITY),
        0u,
        "lt(1.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.0, INFINITY),
        1u,
        "lt(1.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, -0.0),
        1u,
        "lt(-6.283185307179586, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, 0.0),
        1u,
        "lt(-6.283185307179586, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, -0.0),
        0u,
        "lt(6.283185307179586, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, 0.0),
        0u,
        "lt(6.283185307179586, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, -5e-324),
        1u,
        "lt(-6.283185307179586, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, 5e-324),
        1u,
        "lt(-6.283185307179586, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, -5e-324),
        0u,
        "lt(6.283185307179586, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, 5e-324),
        0u,
        "lt(6.283185307179586, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, -2.2250738585072014e-308),
        1u,
        "lt(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, 2.2250738585072014e-308),
        1u,
        "lt(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, -2.2250738585072014e-308),
        0u,
        "lt(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, 2.2250738585072014e-308),
        0u,
        "lt(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, -0.5),
        1u,
        "lt(-6.283185307179586, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, 0.5),
        1u,
        "lt(-6.283185307179586, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, -0.5),
        0u,
        "lt(6.283185307179586, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, 0.5),
        0u,
        "lt(6.283185307179586, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, -1.0),
        1u,
        "lt(-6.283185307179586, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, 1.0),
        1u,
        "lt(-6.283185307179586, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, -1.0),
        0u,
        "lt(6.283185307179586, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, 1.0),
        0u,
        "lt(6.283185307179586, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, -6.283185307179586),
        0u,
        "lt(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, 6.283185307179586),
        1u,
        "lt(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, -6.283185307179586),
        0u,
        "lt(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, 6.283185307179586),
        0u,
        "lt(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, -1.7976931348623157e+308),
        0u,
        "lt(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, 1.7976931348623157e+308),
        1u,
        "lt(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, -1.7976931348623157e+308),
        0u,
        "lt(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, 1.7976931348623157e+308),
        1u,
        "lt(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, -INFINITY),
        0u,
        "lt(-6.283185307179586, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -6.283185307179586, INFINITY),
        1u,
        "lt(-6.283185307179586, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, -INFINITY),
        0u,
        "lt(6.283185307179586, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 6.283185307179586, INFINITY),
        1u,
        "lt(6.283185307179586, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, -0.0),
        1u,
        "lt(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, 0.0),
        1u,
        "lt(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, -0.0),
        0u,
        "lt(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, 0.0),
        0u,
        "lt(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, -5e-324),
        1u,
        "lt(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, 5e-324),
        1u,
        "lt(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, -5e-324),
        0u,
        "lt(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, 5e-324),
        0u,
        "lt(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        1u,
        "lt(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        1u,
        "lt(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        0u,
        "lt(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        0u,
        "lt(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, -0.5),
        1u,
        "lt(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, 0.5),
        1u,
        "lt(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, -0.5),
        0u,
        "lt(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, 0.5),
        0u,
        "lt(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, -1.0),
        1u,
        "lt(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, 1.0),
        1u,
        "lt(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, -1.0),
        0u,
        "lt(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, 1.0),
        0u,
        "lt(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, -6.283185307179586),
        1u,
        "lt(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, 6.283185307179586),
        1u,
        "lt(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, -6.283185307179586),
        0u,
        "lt(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, 6.283185307179586),
        0u,
        "lt(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        0u,
        "lt(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        1u,
        "lt(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        0u,
        "lt(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        0u,
        "lt(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, -INFINITY),
        0u,
        "lt(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -1.7976931348623157e+308, INFINITY),
        1u,
        "lt(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, -INFINITY),
        0u,
        "lt(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, 1.7976931348623157e+308, INFINITY),
        1u,
        "lt(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, -0.0),
        1u,
        "lt(-INFINITY, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, 0.0),
        1u,
        "lt(-INFINITY, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, -0.0),
        0u,
        "lt(INFINITY, -0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, 0.0),
        0u,
        "lt(INFINITY, 0.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, -5e-324),
        1u,
        "lt(-INFINITY, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, 5e-324),
        1u,
        "lt(-INFINITY, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, -5e-324),
        0u,
        "lt(INFINITY, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, 5e-324),
        0u,
        "lt(INFINITY, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, -2.2250738585072014e-308),
        1u,
        "lt(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, 2.2250738585072014e-308),
        1u,
        "lt(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, -2.2250738585072014e-308),
        0u,
        "lt(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, 2.2250738585072014e-308),
        0u,
        "lt(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, -0.5),
        1u,
        "lt(-INFINITY, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, 0.5),
        1u,
        "lt(-INFINITY, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, -0.5),
        0u,
        "lt(INFINITY, -0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, 0.5),
        0u,
        "lt(INFINITY, 0.5)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, -1.0),
        1u,
        "lt(-INFINITY, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, 1.0),
        1u,
        "lt(-INFINITY, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, -1.0),
        0u,
        "lt(INFINITY, -1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, 1.0),
        0u,
        "lt(INFINITY, 1.0)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, -6.283185307179586),
        1u,
        "lt(-INFINITY, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, 6.283185307179586),
        1u,
        "lt(-INFINITY, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, -6.283185307179586),
        0u,
        "lt(INFINITY, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, 6.283185307179586),
        0u,
        "lt(INFINITY, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, -1.7976931348623157e+308),
        1u,
        "lt(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, 1.7976931348623157e+308),
        1u,
        "lt(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, -1.7976931348623157e+308),
        0u,
        "lt(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, 1.7976931348623157e+308),
        0u,
        "lt(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, -INFINITY),
        0u,
        "lt(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, -INFINITY, INFINITY),
        1u,
        "lt(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, -INFINITY),
        0u,
        "lt(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_lt(&instance, INFINITY, INFINITY),
        0u,
        "lt(INFINITY, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, -0.0),
        1u,
        "le(-0.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, 0.0),
        1u,
        "le(-0.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, -0.0),
        1u,
        "le(0.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, 0.0),
        1u,
        "le(0.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, -5e-324),
        0u,
        "le(-0.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, 5e-324),
        1u,
        "le(-0.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, -5e-324),
        0u,
        "le(0.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, 5e-324),
        1u,
        "le(0.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, -2.2250738585072014e-308),
        0u,
        "le(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, 2.2250738585072014e-308),
        1u,
        "le(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, -2.2250738585072014e-308),
        0u,
        "le(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, 2.2250738585072014e-308),
        1u,
        "le(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, -0.5),
        0u,
        "le(-0.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, 0.5),
        1u,
        "le(-0.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, -0.5),
        0u,
        "le(0.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, 0.5),
        1u,
        "le(0.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, -1.0),
        0u,
        "le(-0.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, 1.0),
        1u,
        "le(-0.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, -1.0),
        0u,
        "le(0.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, 1.0),
        1u,
        "le(0.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, -6.283185307179586),
        0u,
        "le(-0.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, 6.283185307179586),
        1u,
        "le(-0.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, -6.283185307179586),
        0u,
        "le(0.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, 6.283185307179586),
        1u,
        "le(0.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, -1.7976931348623157e+308),
        0u,
        "le(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, 1.7976931348623157e+308),
        1u,
        "le(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, -1.7976931348623157e+308),
        0u,
        "le(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, 1.7976931348623157e+308),
        1u,
        "le(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, -INFINITY),
        0u,
        "le(-0.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.0, INFINITY),
        1u,
        "le(-0.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, -INFINITY),
        0u,
        "le(0.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.0, INFINITY),
        1u,
        "le(0.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, -0.0),
        1u,
        "le(-5e-324, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, 0.0),
        1u,
        "le(-5e-324, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, -0.0),
        0u,
        "le(5e-324, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, 0.0),
        0u,
        "le(5e-324, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, -5e-324),
        1u,
        "le(-5e-324, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, 5e-324),
        1u,
        "le(-5e-324, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, -5e-324),
        0u,
        "le(5e-324, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, 5e-324),
        1u,
        "le(5e-324, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, -2.2250738585072014e-308),
        0u,
        "le(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, 2.2250738585072014e-308),
        1u,
        "le(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, -2.2250738585072014e-308),
        0u,
        "le(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, 2.2250738585072014e-308),
        1u,
        "le(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, -0.5),
        0u,
        "le(-5e-324, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, 0.5),
        1u,
        "le(-5e-324, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, -0.5),
        0u,
        "le(5e-324, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, 0.5),
        1u,
        "le(5e-324, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, -1.0),
        0u,
        "le(-5e-324, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, 1.0),
        1u,
        "le(-5e-324, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, -1.0),
        0u,
        "le(5e-324, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, 1.0),
        1u,
        "le(5e-324, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, -6.283185307179586),
        0u,
        "le(-5e-324, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, 6.283185307179586),
        1u,
        "le(-5e-324, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, -6.283185307179586),
        0u,
        "le(5e-324, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, 6.283185307179586),
        1u,
        "le(5e-324, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, -1.7976931348623157e+308),
        0u,
        "le(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, 1.7976931348623157e+308),
        1u,
        "le(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, -1.7976931348623157e+308),
        0u,
        "le(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, 1.7976931348623157e+308),
        1u,
        "le(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, -INFINITY),
        0u,
        "le(-5e-324, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -5e-324, INFINITY),
        1u,
        "le(-5e-324, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, -INFINITY),
        0u,
        "le(5e-324, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 5e-324, INFINITY),
        1u,
        "le(5e-324, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, -0.0),
        1u,
        "le(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, 0.0),
        1u,
        "le(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, -0.0),
        0u,
        "le(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, 0.0),
        0u,
        "le(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, -5e-324),
        1u,
        "le(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, 5e-324),
        1u,
        "le(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, -5e-324),
        0u,
        "le(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, 5e-324),
        0u,
        "le(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        1u,
        "le(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        1u,
        "le(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        0u,
        "le(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        1u,
        "le(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, -0.5),
        0u,
        "le(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, 0.5),
        1u,
        "le(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, -0.5),
        0u,
        "le(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, 0.5),
        1u,
        "le(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, -1.0),
        0u,
        "le(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, 1.0),
        1u,
        "le(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, -1.0),
        0u,
        "le(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, 1.0),
        1u,
        "le(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, -6.283185307179586),
        0u,
        "le(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, 6.283185307179586),
        1u,
        "le(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, -6.283185307179586),
        0u,
        "le(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, 6.283185307179586),
        1u,
        "le(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        0u,
        "le(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        1u,
        "le(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        0u,
        "le(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        1u,
        "le(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, -INFINITY),
        0u,
        "le(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -2.2250738585072014e-308, INFINITY),
        1u,
        "le(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, -INFINITY),
        0u,
        "le(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 2.2250738585072014e-308, INFINITY),
        1u,
        "le(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, -0.0),
        1u,
        "le(-0.5, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, 0.0),
        1u,
        "le(-0.5, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, -0.0),
        0u,
        "le(0.5, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, 0.0),
        0u,
        "le(0.5, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, -5e-324),
        1u,
        "le(-0.5, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, 5e-324),
        1u,
        "le(-0.5, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, -5e-324),
        0u,
        "le(0.5, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, 5e-324),
        0u,
        "le(0.5, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, -2.2250738585072014e-308),
        1u,
        "le(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, 2.2250738585072014e-308),
        1u,
        "le(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, -2.2250738585072014e-308),
        0u,
        "le(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, 2.2250738585072014e-308),
        0u,
        "le(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, -0.5),
        1u,
        "le(-0.5, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, 0.5),
        1u,
        "le(-0.5, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, -0.5),
        0u,
        "le(0.5, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, 0.5),
        1u,
        "le(0.5, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, -1.0),
        0u,
        "le(-0.5, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, 1.0),
        1u,
        "le(-0.5, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, -1.0),
        0u,
        "le(0.5, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, 1.0),
        1u,
        "le(0.5, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, -6.283185307179586),
        0u,
        "le(-0.5, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, 6.283185307179586),
        1u,
        "le(-0.5, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, -6.283185307179586),
        0u,
        "le(0.5, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, 6.283185307179586),
        1u,
        "le(0.5, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, -1.7976931348623157e+308),
        0u,
        "le(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, 1.7976931348623157e+308),
        1u,
        "le(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, -1.7976931348623157e+308),
        0u,
        "le(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, 1.7976931348623157e+308),
        1u,
        "le(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, -INFINITY),
        0u,
        "le(-0.5, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -0.5, INFINITY),
        1u,
        "le(-0.5, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, -INFINITY),
        0u,
        "le(0.5, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 0.5, INFINITY),
        1u,
        "le(0.5, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, -0.0),
        1u,
        "le(-1.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, 0.0),
        1u,
        "le(-1.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, -0.0),
        0u,
        "le(1.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, 0.0),
        0u,
        "le(1.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, -5e-324),
        1u,
        "le(-1.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, 5e-324),
        1u,
        "le(-1.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, -5e-324),
        0u,
        "le(1.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, 5e-324),
        0u,
        "le(1.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, -2.2250738585072014e-308),
        1u,
        "le(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, 2.2250738585072014e-308),
        1u,
        "le(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, -2.2250738585072014e-308),
        0u,
        "le(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, 2.2250738585072014e-308),
        0u,
        "le(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, -0.5),
        1u,
        "le(-1.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, 0.5),
        1u,
        "le(-1.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, -0.5),
        0u,
        "le(1.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, 0.5),
        0u,
        "le(1.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, -1.0),
        1u,
        "le(-1.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, 1.0),
        1u,
        "le(-1.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, -1.0),
        0u,
        "le(1.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, 1.0),
        1u,
        "le(1.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, -6.283185307179586),
        0u,
        "le(-1.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, 6.283185307179586),
        1u,
        "le(-1.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, -6.283185307179586),
        0u,
        "le(1.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, 6.283185307179586),
        1u,
        "le(1.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, -1.7976931348623157e+308),
        0u,
        "le(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, 1.7976931348623157e+308),
        1u,
        "le(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, -1.7976931348623157e+308),
        0u,
        "le(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, 1.7976931348623157e+308),
        1u,
        "le(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, -INFINITY),
        0u,
        "le(-1.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.0, INFINITY),
        1u,
        "le(-1.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, -INFINITY),
        0u,
        "le(1.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.0, INFINITY),
        1u,
        "le(1.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, -0.0),
        1u,
        "le(-6.283185307179586, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, 0.0),
        1u,
        "le(-6.283185307179586, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, -0.0),
        0u,
        "le(6.283185307179586, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, 0.0),
        0u,
        "le(6.283185307179586, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, -5e-324),
        1u,
        "le(-6.283185307179586, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, 5e-324),
        1u,
        "le(-6.283185307179586, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, -5e-324),
        0u,
        "le(6.283185307179586, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, 5e-324),
        0u,
        "le(6.283185307179586, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, -2.2250738585072014e-308),
        1u,
        "le(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, 2.2250738585072014e-308),
        1u,
        "le(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, -2.2250738585072014e-308),
        0u,
        "le(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, 2.2250738585072014e-308),
        0u,
        "le(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, -0.5),
        1u,
        "le(-6.283185307179586, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, 0.5),
        1u,
        "le(-6.283185307179586, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, -0.5),
        0u,
        "le(6.283185307179586, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, 0.5),
        0u,
        "le(6.283185307179586, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, -1.0),
        1u,
        "le(-6.283185307179586, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, 1.0),
        1u,
        "le(-6.283185307179586, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, -1.0),
        0u,
        "le(6.283185307179586, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, 1.0),
        0u,
        "le(6.283185307179586, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, -6.283185307179586),
        1u,
        "le(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, 6.283185307179586),
        1u,
        "le(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, -6.283185307179586),
        0u,
        "le(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, 6.283185307179586),
        1u,
        "le(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, -1.7976931348623157e+308),
        0u,
        "le(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, 1.7976931348623157e+308),
        1u,
        "le(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, -1.7976931348623157e+308),
        0u,
        "le(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, 1.7976931348623157e+308),
        1u,
        "le(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, -INFINITY),
        0u,
        "le(-6.283185307179586, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -6.283185307179586, INFINITY),
        1u,
        "le(-6.283185307179586, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, -INFINITY),
        0u,
        "le(6.283185307179586, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 6.283185307179586, INFINITY),
        1u,
        "le(6.283185307179586, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, -0.0),
        1u,
        "le(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, 0.0),
        1u,
        "le(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, -0.0),
        0u,
        "le(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, 0.0),
        0u,
        "le(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, -5e-324),
        1u,
        "le(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, 5e-324),
        1u,
        "le(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, -5e-324),
        0u,
        "le(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, 5e-324),
        0u,
        "le(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        1u,
        "le(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        1u,
        "le(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        0u,
        "le(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        0u,
        "le(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, -0.5),
        1u,
        "le(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, 0.5),
        1u,
        "le(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, -0.5),
        0u,
        "le(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, 0.5),
        0u,
        "le(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, -1.0),
        1u,
        "le(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, 1.0),
        1u,
        "le(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, -1.0),
        0u,
        "le(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, 1.0),
        0u,
        "le(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, -6.283185307179586),
        1u,
        "le(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, 6.283185307179586),
        1u,
        "le(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, -6.283185307179586),
        0u,
        "le(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, 6.283185307179586),
        0u,
        "le(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        1u,
        "le(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        1u,
        "le(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        0u,
        "le(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        1u,
        "le(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, -INFINITY),
        0u,
        "le(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -1.7976931348623157e+308, INFINITY),
        1u,
        "le(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, -INFINITY),
        0u,
        "le(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, 1.7976931348623157e+308, INFINITY),
        1u,
        "le(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, -0.0),
        1u,
        "le(-INFINITY, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, 0.0),
        1u,
        "le(-INFINITY, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, -0.0),
        0u,
        "le(INFINITY, -0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, 0.0),
        0u,
        "le(INFINITY, 0.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, -5e-324),
        1u,
        "le(-INFINITY, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, 5e-324),
        1u,
        "le(-INFINITY, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, -5e-324),
        0u,
        "le(INFINITY, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, 5e-324),
        0u,
        "le(INFINITY, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, -2.2250738585072014e-308),
        1u,
        "le(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, 2.2250738585072014e-308),
        1u,
        "le(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, -2.2250738585072014e-308),
        0u,
        "le(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, 2.2250738585072014e-308),
        0u,
        "le(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, -0.5),
        1u,
        "le(-INFINITY, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, 0.5),
        1u,
        "le(-INFINITY, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, -0.5),
        0u,
        "le(INFINITY, -0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, 0.5),
        0u,
        "le(INFINITY, 0.5)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, -1.0),
        1u,
        "le(-INFINITY, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, 1.0),
        1u,
        "le(-INFINITY, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, -1.0),
        0u,
        "le(INFINITY, -1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, 1.0),
        0u,
        "le(INFINITY, 1.0)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, -6.283185307179586),
        1u,
        "le(-INFINITY, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, 6.283185307179586),
        1u,
        "le(-INFINITY, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, -6.283185307179586),
        0u,
        "le(INFINITY, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, 6.283185307179586),
        0u,
        "le(INFINITY, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, -1.7976931348623157e+308),
        1u,
        "le(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, 1.7976931348623157e+308),
        1u,
        "le(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, -1.7976931348623157e+308),
        0u,
        "le(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, 1.7976931348623157e+308),
        0u,
        "le(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, -INFINITY),
        1u,
        "le(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, -INFINITY, INFINITY),
        1u,
        "le(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, -INFINITY),
        0u,
        "le(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_le(&instance, INFINITY, INFINITY),
        1u,
        "le(INFINITY, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, -0.0),
        0u,
        "gt(-0.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, 0.0),
        0u,
        "gt(-0.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, -0.0),
        0u,
        "gt(0.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, 0.0),
        0u,
        "gt(0.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, -5e-324),
        1u,
        "gt(-0.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, 5e-324),
        0u,
        "gt(-0.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, -5e-324),
        1u,
        "gt(0.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, 5e-324),
        0u,
        "gt(0.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, -2.2250738585072014e-308),
        1u,
        "gt(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, 2.2250738585072014e-308),
        0u,
        "gt(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, -2.2250738585072014e-308),
        1u,
        "gt(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, 2.2250738585072014e-308),
        0u,
        "gt(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, -0.5),
        1u,
        "gt(-0.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, 0.5),
        0u,
        "gt(-0.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, -0.5),
        1u,
        "gt(0.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, 0.5),
        0u,
        "gt(0.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, -1.0),
        1u,
        "gt(-0.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, 1.0),
        0u,
        "gt(-0.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, -1.0),
        1u,
        "gt(0.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, 1.0),
        0u,
        "gt(0.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, -6.283185307179586),
        1u,
        "gt(-0.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, 6.283185307179586),
        0u,
        "gt(-0.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, -6.283185307179586),
        1u,
        "gt(0.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, 6.283185307179586),
        0u,
        "gt(0.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, -1.7976931348623157e+308),
        1u,
        "gt(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, 1.7976931348623157e+308),
        0u,
        "gt(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, -1.7976931348623157e+308),
        1u,
        "gt(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, 1.7976931348623157e+308),
        0u,
        "gt(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, -INFINITY),
        1u,
        "gt(-0.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.0, INFINITY),
        0u,
        "gt(-0.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, -INFINITY),
        1u,
        "gt(0.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.0, INFINITY),
        0u,
        "gt(0.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, -0.0),
        0u,
        "gt(-5e-324, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, 0.0),
        0u,
        "gt(-5e-324, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, -0.0),
        1u,
        "gt(5e-324, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, 0.0),
        1u,
        "gt(5e-324, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, -5e-324),
        0u,
        "gt(-5e-324, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, 5e-324),
        0u,
        "gt(-5e-324, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, -5e-324),
        1u,
        "gt(5e-324, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, 5e-324),
        0u,
        "gt(5e-324, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, -2.2250738585072014e-308),
        1u,
        "gt(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, 2.2250738585072014e-308),
        0u,
        "gt(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, -2.2250738585072014e-308),
        1u,
        "gt(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, 2.2250738585072014e-308),
        0u,
        "gt(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, -0.5),
        1u,
        "gt(-5e-324, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, 0.5),
        0u,
        "gt(-5e-324, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, -0.5),
        1u,
        "gt(5e-324, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, 0.5),
        0u,
        "gt(5e-324, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, -1.0),
        1u,
        "gt(-5e-324, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, 1.0),
        0u,
        "gt(-5e-324, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, -1.0),
        1u,
        "gt(5e-324, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, 1.0),
        0u,
        "gt(5e-324, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, -6.283185307179586),
        1u,
        "gt(-5e-324, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, 6.283185307179586),
        0u,
        "gt(-5e-324, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, -6.283185307179586),
        1u,
        "gt(5e-324, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, 6.283185307179586),
        0u,
        "gt(5e-324, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, -1.7976931348623157e+308),
        1u,
        "gt(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, 1.7976931348623157e+308),
        0u,
        "gt(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, -1.7976931348623157e+308),
        1u,
        "gt(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, 1.7976931348623157e+308),
        0u,
        "gt(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, -INFINITY),
        1u,
        "gt(-5e-324, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -5e-324, INFINITY),
        0u,
        "gt(-5e-324, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, -INFINITY),
        1u,
        "gt(5e-324, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 5e-324, INFINITY),
        0u,
        "gt(5e-324, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, -0.0),
        0u,
        "gt(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, 0.0),
        0u,
        "gt(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, -0.0),
        1u,
        "gt(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, 0.0),
        1u,
        "gt(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, -5e-324),
        0u,
        "gt(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, 5e-324),
        0u,
        "gt(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, -5e-324),
        1u,
        "gt(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, 5e-324),
        1u,
        "gt(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        0u,
        "gt(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        0u,
        "gt(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        1u,
        "gt(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        0u,
        "gt(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, -0.5),
        1u,
        "gt(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, 0.5),
        0u,
        "gt(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, -0.5),
        1u,
        "gt(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, 0.5),
        0u,
        "gt(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, -1.0),
        1u,
        "gt(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, 1.0),
        0u,
        "gt(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, -1.0),
        1u,
        "gt(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, 1.0),
        0u,
        "gt(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, -6.283185307179586),
        1u,
        "gt(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, 6.283185307179586),
        0u,
        "gt(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, -6.283185307179586),
        1u,
        "gt(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, 6.283185307179586),
        0u,
        "gt(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        1u,
        "gt(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        0u,
        "gt(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        1u,
        "gt(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        0u,
        "gt(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, -INFINITY),
        1u,
        "gt(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -2.2250738585072014e-308, INFINITY),
        0u,
        "gt(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, -INFINITY),
        1u,
        "gt(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 2.2250738585072014e-308, INFINITY),
        0u,
        "gt(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, -0.0),
        0u,
        "gt(-0.5, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, 0.0),
        0u,
        "gt(-0.5, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, -0.0),
        1u,
        "gt(0.5, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, 0.0),
        1u,
        "gt(0.5, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, -5e-324),
        0u,
        "gt(-0.5, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, 5e-324),
        0u,
        "gt(-0.5, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, -5e-324),
        1u,
        "gt(0.5, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, 5e-324),
        1u,
        "gt(0.5, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, -2.2250738585072014e-308),
        0u,
        "gt(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, 2.2250738585072014e-308),
        0u,
        "gt(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, -2.2250738585072014e-308),
        1u,
        "gt(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, 2.2250738585072014e-308),
        1u,
        "gt(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, -0.5),
        0u,
        "gt(-0.5, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, 0.5),
        0u,
        "gt(-0.5, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, -0.5),
        1u,
        "gt(0.5, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, 0.5),
        0u,
        "gt(0.5, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, -1.0),
        1u,
        "gt(-0.5, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, 1.0),
        0u,
        "gt(-0.5, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, -1.0),
        1u,
        "gt(0.5, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, 1.0),
        0u,
        "gt(0.5, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, -6.283185307179586),
        1u,
        "gt(-0.5, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, 6.283185307179586),
        0u,
        "gt(-0.5, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, -6.283185307179586),
        1u,
        "gt(0.5, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, 6.283185307179586),
        0u,
        "gt(0.5, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, -1.7976931348623157e+308),
        1u,
        "gt(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, 1.7976931348623157e+308),
        0u,
        "gt(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, -1.7976931348623157e+308),
        1u,
        "gt(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, 1.7976931348623157e+308),
        0u,
        "gt(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, -INFINITY),
        1u,
        "gt(-0.5, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -0.5, INFINITY),
        0u,
        "gt(-0.5, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, -INFINITY),
        1u,
        "gt(0.5, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 0.5, INFINITY),
        0u,
        "gt(0.5, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, -0.0),
        0u,
        "gt(-1.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, 0.0),
        0u,
        "gt(-1.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, -0.0),
        1u,
        "gt(1.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, 0.0),
        1u,
        "gt(1.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, -5e-324),
        0u,
        "gt(-1.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, 5e-324),
        0u,
        "gt(-1.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, -5e-324),
        1u,
        "gt(1.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, 5e-324),
        1u,
        "gt(1.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, -2.2250738585072014e-308),
        0u,
        "gt(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, 2.2250738585072014e-308),
        0u,
        "gt(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, -2.2250738585072014e-308),
        1u,
        "gt(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, 2.2250738585072014e-308),
        1u,
        "gt(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, -0.5),
        0u,
        "gt(-1.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, 0.5),
        0u,
        "gt(-1.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, -0.5),
        1u,
        "gt(1.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, 0.5),
        1u,
        "gt(1.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, -1.0),
        0u,
        "gt(-1.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, 1.0),
        0u,
        "gt(-1.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, -1.0),
        1u,
        "gt(1.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, 1.0),
        0u,
        "gt(1.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, -6.283185307179586),
        1u,
        "gt(-1.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, 6.283185307179586),
        0u,
        "gt(-1.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, -6.283185307179586),
        1u,
        "gt(1.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, 6.283185307179586),
        0u,
        "gt(1.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, -1.7976931348623157e+308),
        1u,
        "gt(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, 1.7976931348623157e+308),
        0u,
        "gt(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, -1.7976931348623157e+308),
        1u,
        "gt(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, 1.7976931348623157e+308),
        0u,
        "gt(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, -INFINITY),
        1u,
        "gt(-1.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.0, INFINITY),
        0u,
        "gt(-1.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, -INFINITY),
        1u,
        "gt(1.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.0, INFINITY),
        0u,
        "gt(1.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, -0.0),
        0u,
        "gt(-6.283185307179586, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, 0.0),
        0u,
        "gt(-6.283185307179586, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, -0.0),
        1u,
        "gt(6.283185307179586, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, 0.0),
        1u,
        "gt(6.283185307179586, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, -5e-324),
        0u,
        "gt(-6.283185307179586, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, 5e-324),
        0u,
        "gt(-6.283185307179586, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, -5e-324),
        1u,
        "gt(6.283185307179586, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, 5e-324),
        1u,
        "gt(6.283185307179586, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, -2.2250738585072014e-308),
        0u,
        "gt(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, 2.2250738585072014e-308),
        0u,
        "gt(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, -2.2250738585072014e-308),
        1u,
        "gt(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, 2.2250738585072014e-308),
        1u,
        "gt(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, -0.5),
        0u,
        "gt(-6.283185307179586, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, 0.5),
        0u,
        "gt(-6.283185307179586, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, -0.5),
        1u,
        "gt(6.283185307179586, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, 0.5),
        1u,
        "gt(6.283185307179586, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, -1.0),
        0u,
        "gt(-6.283185307179586, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, 1.0),
        0u,
        "gt(-6.283185307179586, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, -1.0),
        1u,
        "gt(6.283185307179586, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, 1.0),
        1u,
        "gt(6.283185307179586, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, -6.283185307179586),
        0u,
        "gt(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, 6.283185307179586),
        0u,
        "gt(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, -6.283185307179586),
        1u,
        "gt(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, 6.283185307179586),
        0u,
        "gt(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, -1.7976931348623157e+308),
        1u,
        "gt(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, 1.7976931348623157e+308),
        0u,
        "gt(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, -1.7976931348623157e+308),
        1u,
        "gt(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, 1.7976931348623157e+308),
        0u,
        "gt(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, -INFINITY),
        1u,
        "gt(-6.283185307179586, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -6.283185307179586, INFINITY),
        0u,
        "gt(-6.283185307179586, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, -INFINITY),
        1u,
        "gt(6.283185307179586, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 6.283185307179586, INFINITY),
        0u,
        "gt(6.283185307179586, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, -0.0),
        0u,
        "gt(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, 0.0),
        0u,
        "gt(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, -0.0),
        1u,
        "gt(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, 0.0),
        1u,
        "gt(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, -5e-324),
        0u,
        "gt(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, 5e-324),
        0u,
        "gt(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, -5e-324),
        1u,
        "gt(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, 5e-324),
        1u,
        "gt(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        0u,
        "gt(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        0u,
        "gt(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        1u,
        "gt(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        1u,
        "gt(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, -0.5),
        0u,
        "gt(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, 0.5),
        0u,
        "gt(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, -0.5),
        1u,
        "gt(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, 0.5),
        1u,
        "gt(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, -1.0),
        0u,
        "gt(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, 1.0),
        0u,
        "gt(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, -1.0),
        1u,
        "gt(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, 1.0),
        1u,
        "gt(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, -6.283185307179586),
        0u,
        "gt(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, 6.283185307179586),
        0u,
        "gt(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, -6.283185307179586),
        1u,
        "gt(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, 6.283185307179586),
        1u,
        "gt(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        0u,
        "gt(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        0u,
        "gt(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        1u,
        "gt(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        0u,
        "gt(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, -INFINITY),
        1u,
        "gt(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -1.7976931348623157e+308, INFINITY),
        0u,
        "gt(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, -INFINITY),
        1u,
        "gt(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, 1.7976931348623157e+308, INFINITY),
        0u,
        "gt(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, -0.0),
        0u,
        "gt(-INFINITY, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, 0.0),
        0u,
        "gt(-INFINITY, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, -0.0),
        1u,
        "gt(INFINITY, -0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, 0.0),
        1u,
        "gt(INFINITY, 0.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, -5e-324),
        0u,
        "gt(-INFINITY, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, 5e-324),
        0u,
        "gt(-INFINITY, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, -5e-324),
        1u,
        "gt(INFINITY, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, 5e-324),
        1u,
        "gt(INFINITY, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, -2.2250738585072014e-308),
        0u,
        "gt(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, 2.2250738585072014e-308),
        0u,
        "gt(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, -2.2250738585072014e-308),
        1u,
        "gt(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, 2.2250738585072014e-308),
        1u,
        "gt(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, -0.5),
        0u,
        "gt(-INFINITY, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, 0.5),
        0u,
        "gt(-INFINITY, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, -0.5),
        1u,
        "gt(INFINITY, -0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, 0.5),
        1u,
        "gt(INFINITY, 0.5)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, -1.0),
        0u,
        "gt(-INFINITY, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, 1.0),
        0u,
        "gt(-INFINITY, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, -1.0),
        1u,
        "gt(INFINITY, -1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, 1.0),
        1u,
        "gt(INFINITY, 1.0)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, -6.283185307179586),
        0u,
        "gt(-INFINITY, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, 6.283185307179586),
        0u,
        "gt(-INFINITY, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, -6.283185307179586),
        1u,
        "gt(INFINITY, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, 6.283185307179586),
        1u,
        "gt(INFINITY, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, -1.7976931348623157e+308),
        0u,
        "gt(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, 1.7976931348623157e+308),
        0u,
        "gt(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, -1.7976931348623157e+308),
        1u,
        "gt(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, 1.7976931348623157e+308),
        1u,
        "gt(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, -INFINITY),
        0u,
        "gt(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, -INFINITY, INFINITY),
        0u,
        "gt(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, -INFINITY),
        1u,
        "gt(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_gt(&instance, INFINITY, INFINITY),
        0u,
        "gt(INFINITY, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, -0.0),
        1u,
        "ge(-0.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, 0.0),
        1u,
        "ge(-0.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, -0.0),
        1u,
        "ge(0.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, 0.0),
        1u,
        "ge(0.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, -5e-324),
        1u,
        "ge(-0.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, 5e-324),
        0u,
        "ge(-0.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, -5e-324),
        1u,
        "ge(0.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, 5e-324),
        0u,
        "ge(0.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, -2.2250738585072014e-308),
        1u,
        "ge(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, 2.2250738585072014e-308),
        0u,
        "ge(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, -2.2250738585072014e-308),
        1u,
        "ge(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, 2.2250738585072014e-308),
        0u,
        "ge(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, -0.5),
        1u,
        "ge(-0.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, 0.5),
        0u,
        "ge(-0.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, -0.5),
        1u,
        "ge(0.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, 0.5),
        0u,
        "ge(0.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, -1.0),
        1u,
        "ge(-0.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, 1.0),
        0u,
        "ge(-0.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, -1.0),
        1u,
        "ge(0.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, 1.0),
        0u,
        "ge(0.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, -6.283185307179586),
        1u,
        "ge(-0.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, 6.283185307179586),
        0u,
        "ge(-0.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, -6.283185307179586),
        1u,
        "ge(0.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, 6.283185307179586),
        0u,
        "ge(0.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, -1.7976931348623157e+308),
        1u,
        "ge(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, 1.7976931348623157e+308),
        0u,
        "ge(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, -1.7976931348623157e+308),
        1u,
        "ge(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, 1.7976931348623157e+308),
        0u,
        "ge(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, -INFINITY),
        1u,
        "ge(-0.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.0, INFINITY),
        0u,
        "ge(-0.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, -INFINITY),
        1u,
        "ge(0.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.0, INFINITY),
        0u,
        "ge(0.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, -0.0),
        0u,
        "ge(-5e-324, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, 0.0),
        0u,
        "ge(-5e-324, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, -0.0),
        1u,
        "ge(5e-324, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, 0.0),
        1u,
        "ge(5e-324, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, -5e-324),
        1u,
        "ge(-5e-324, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, 5e-324),
        0u,
        "ge(-5e-324, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, -5e-324),
        1u,
        "ge(5e-324, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, 5e-324),
        1u,
        "ge(5e-324, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, -2.2250738585072014e-308),
        1u,
        "ge(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, 2.2250738585072014e-308),
        0u,
        "ge(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, -2.2250738585072014e-308),
        1u,
        "ge(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, 2.2250738585072014e-308),
        0u,
        "ge(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, -0.5),
        1u,
        "ge(-5e-324, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, 0.5),
        0u,
        "ge(-5e-324, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, -0.5),
        1u,
        "ge(5e-324, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, 0.5),
        0u,
        "ge(5e-324, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, -1.0),
        1u,
        "ge(-5e-324, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, 1.0),
        0u,
        "ge(-5e-324, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, -1.0),
        1u,
        "ge(5e-324, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, 1.0),
        0u,
        "ge(5e-324, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, -6.283185307179586),
        1u,
        "ge(-5e-324, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, 6.283185307179586),
        0u,
        "ge(-5e-324, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, -6.283185307179586),
        1u,
        "ge(5e-324, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, 6.283185307179586),
        0u,
        "ge(5e-324, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, -1.7976931348623157e+308),
        1u,
        "ge(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, 1.7976931348623157e+308),
        0u,
        "ge(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, -1.7976931348623157e+308),
        1u,
        "ge(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, 1.7976931348623157e+308),
        0u,
        "ge(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, -INFINITY),
        1u,
        "ge(-5e-324, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -5e-324, INFINITY),
        0u,
        "ge(-5e-324, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, -INFINITY),
        1u,
        "ge(5e-324, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 5e-324, INFINITY),
        0u,
        "ge(5e-324, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, -0.0),
        0u,
        "ge(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, 0.0),
        0u,
        "ge(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, -0.0),
        1u,
        "ge(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, 0.0),
        1u,
        "ge(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, -5e-324),
        0u,
        "ge(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, 5e-324),
        0u,
        "ge(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, -5e-324),
        1u,
        "ge(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, 5e-324),
        1u,
        "ge(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        1u,
        "ge(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        0u,
        "ge(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        1u,
        "ge(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        1u,
        "ge(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, -0.5),
        1u,
        "ge(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, 0.5),
        0u,
        "ge(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, -0.5),
        1u,
        "ge(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, 0.5),
        0u,
        "ge(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, -1.0),
        1u,
        "ge(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, 1.0),
        0u,
        "ge(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, -1.0),
        1u,
        "ge(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, 1.0),
        0u,
        "ge(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, -6.283185307179586),
        1u,
        "ge(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, 6.283185307179586),
        0u,
        "ge(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, -6.283185307179586),
        1u,
        "ge(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, 6.283185307179586),
        0u,
        "ge(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        1u,
        "ge(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        0u,
        "ge(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        1u,
        "ge(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        0u,
        "ge(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, -INFINITY),
        1u,
        "ge(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -2.2250738585072014e-308, INFINITY),
        0u,
        "ge(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, -INFINITY),
        1u,
        "ge(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 2.2250738585072014e-308, INFINITY),
        0u,
        "ge(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, -0.0),
        0u,
        "ge(-0.5, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, 0.0),
        0u,
        "ge(-0.5, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, -0.0),
        1u,
        "ge(0.5, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, 0.0),
        1u,
        "ge(0.5, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, -5e-324),
        0u,
        "ge(-0.5, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, 5e-324),
        0u,
        "ge(-0.5, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, -5e-324),
        1u,
        "ge(0.5, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, 5e-324),
        1u,
        "ge(0.5, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, -2.2250738585072014e-308),
        0u,
        "ge(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, 2.2250738585072014e-308),
        0u,
        "ge(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, -2.2250738585072014e-308),
        1u,
        "ge(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, 2.2250738585072014e-308),
        1u,
        "ge(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, -0.5),
        1u,
        "ge(-0.5, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, 0.5),
        0u,
        "ge(-0.5, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, -0.5),
        1u,
        "ge(0.5, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, 0.5),
        1u,
        "ge(0.5, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, -1.0),
        1u,
        "ge(-0.5, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, 1.0),
        0u,
        "ge(-0.5, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, -1.0),
        1u,
        "ge(0.5, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, 1.0),
        0u,
        "ge(0.5, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, -6.283185307179586),
        1u,
        "ge(-0.5, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, 6.283185307179586),
        0u,
        "ge(-0.5, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, -6.283185307179586),
        1u,
        "ge(0.5, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, 6.283185307179586),
        0u,
        "ge(0.5, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, -1.7976931348623157e+308),
        1u,
        "ge(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, 1.7976931348623157e+308),
        0u,
        "ge(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, -1.7976931348623157e+308),
        1u,
        "ge(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, 1.7976931348623157e+308),
        0u,
        "ge(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, -INFINITY),
        1u,
        "ge(-0.5, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -0.5, INFINITY),
        0u,
        "ge(-0.5, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, -INFINITY),
        1u,
        "ge(0.5, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 0.5, INFINITY),
        0u,
        "ge(0.5, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, -0.0),
        0u,
        "ge(-1.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, 0.0),
        0u,
        "ge(-1.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, -0.0),
        1u,
        "ge(1.0, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, 0.0),
        1u,
        "ge(1.0, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, -5e-324),
        0u,
        "ge(-1.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, 5e-324),
        0u,
        "ge(-1.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, -5e-324),
        1u,
        "ge(1.0, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, 5e-324),
        1u,
        "ge(1.0, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, -2.2250738585072014e-308),
        0u,
        "ge(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, 2.2250738585072014e-308),
        0u,
        "ge(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, -2.2250738585072014e-308),
        1u,
        "ge(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, 2.2250738585072014e-308),
        1u,
        "ge(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, -0.5),
        0u,
        "ge(-1.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, 0.5),
        0u,
        "ge(-1.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, -0.5),
        1u,
        "ge(1.0, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, 0.5),
        1u,
        "ge(1.0, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, -1.0),
        1u,
        "ge(-1.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, 1.0),
        0u,
        "ge(-1.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, -1.0),
        1u,
        "ge(1.0, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, 1.0),
        1u,
        "ge(1.0, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, -6.283185307179586),
        1u,
        "ge(-1.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, 6.283185307179586),
        0u,
        "ge(-1.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, -6.283185307179586),
        1u,
        "ge(1.0, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, 6.283185307179586),
        0u,
        "ge(1.0, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, -1.7976931348623157e+308),
        1u,
        "ge(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, 1.7976931348623157e+308),
        0u,
        "ge(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, -1.7976931348623157e+308),
        1u,
        "ge(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, 1.7976931348623157e+308),
        0u,
        "ge(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, -INFINITY),
        1u,
        "ge(-1.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.0, INFINITY),
        0u,
        "ge(-1.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, -INFINITY),
        1u,
        "ge(1.0, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.0, INFINITY),
        0u,
        "ge(1.0, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, -0.0),
        0u,
        "ge(-6.283185307179586, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, 0.0),
        0u,
        "ge(-6.283185307179586, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, -0.0),
        1u,
        "ge(6.283185307179586, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, 0.0),
        1u,
        "ge(6.283185307179586, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, -5e-324),
        0u,
        "ge(-6.283185307179586, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, 5e-324),
        0u,
        "ge(-6.283185307179586, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, -5e-324),
        1u,
        "ge(6.283185307179586, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, 5e-324),
        1u,
        "ge(6.283185307179586, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, -2.2250738585072014e-308),
        0u,
        "ge(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, 2.2250738585072014e-308),
        0u,
        "ge(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, -2.2250738585072014e-308),
        1u,
        "ge(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, 2.2250738585072014e-308),
        1u,
        "ge(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, -0.5),
        0u,
        "ge(-6.283185307179586, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, 0.5),
        0u,
        "ge(-6.283185307179586, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, -0.5),
        1u,
        "ge(6.283185307179586, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, 0.5),
        1u,
        "ge(6.283185307179586, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, -1.0),
        0u,
        "ge(-6.283185307179586, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, 1.0),
        0u,
        "ge(-6.283185307179586, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, -1.0),
        1u,
        "ge(6.283185307179586, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, 1.0),
        1u,
        "ge(6.283185307179586, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, -6.283185307179586),
        1u,
        "ge(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, 6.283185307179586),
        0u,
        "ge(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, -6.283185307179586),
        1u,
        "ge(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, 6.283185307179586),
        1u,
        "ge(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, -1.7976931348623157e+308),
        1u,
        "ge(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, 1.7976931348623157e+308),
        0u,
        "ge(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, -1.7976931348623157e+308),
        1u,
        "ge(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, 1.7976931348623157e+308),
        0u,
        "ge(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, -INFINITY),
        1u,
        "ge(-6.283185307179586, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -6.283185307179586, INFINITY),
        0u,
        "ge(-6.283185307179586, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, -INFINITY),
        1u,
        "ge(6.283185307179586, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 6.283185307179586, INFINITY),
        0u,
        "ge(6.283185307179586, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, -0.0),
        0u,
        "ge(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, 0.0),
        0u,
        "ge(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, -0.0),
        1u,
        "ge(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, 0.0),
        1u,
        "ge(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, -5e-324),
        0u,
        "ge(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, 5e-324),
        0u,
        "ge(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, -5e-324),
        1u,
        "ge(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, 5e-324),
        1u,
        "ge(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        0u,
        "ge(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        0u,
        "ge(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        1u,
        "ge(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        1u,
        "ge(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, -0.5),
        0u,
        "ge(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, 0.5),
        0u,
        "ge(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, -0.5),
        1u,
        "ge(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, 0.5),
        1u,
        "ge(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, -1.0),
        0u,
        "ge(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, 1.0),
        0u,
        "ge(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, -1.0),
        1u,
        "ge(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, 1.0),
        1u,
        "ge(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, -6.283185307179586),
        0u,
        "ge(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, 6.283185307179586),
        0u,
        "ge(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, -6.283185307179586),
        1u,
        "ge(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, 6.283185307179586),
        1u,
        "ge(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        1u,
        "ge(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        0u,
        "ge(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        1u,
        "ge(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        1u,
        "ge(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, -INFINITY),
        1u,
        "ge(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -1.7976931348623157e+308, INFINITY),
        0u,
        "ge(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, -INFINITY),
        1u,
        "ge(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, 1.7976931348623157e+308, INFINITY),
        0u,
        "ge(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, -0.0),
        0u,
        "ge(-INFINITY, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, 0.0),
        0u,
        "ge(-INFINITY, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, -0.0),
        1u,
        "ge(INFINITY, -0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, 0.0),
        1u,
        "ge(INFINITY, 0.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, -5e-324),
        0u,
        "ge(-INFINITY, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, 5e-324),
        0u,
        "ge(-INFINITY, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, -5e-324),
        1u,
        "ge(INFINITY, -5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, 5e-324),
        1u,
        "ge(INFINITY, 5e-324)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, -2.2250738585072014e-308),
        0u,
        "ge(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, 2.2250738585072014e-308),
        0u,
        "ge(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, -2.2250738585072014e-308),
        1u,
        "ge(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, 2.2250738585072014e-308),
        1u,
        "ge(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, -0.5),
        0u,
        "ge(-INFINITY, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, 0.5),
        0u,
        "ge(-INFINITY, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, -0.5),
        1u,
        "ge(INFINITY, -0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, 0.5),
        1u,
        "ge(INFINITY, 0.5)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, -1.0),
        0u,
        "ge(-INFINITY, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, 1.0),
        0u,
        "ge(-INFINITY, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, -1.0),
        1u,
        "ge(INFINITY, -1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, 1.0),
        1u,
        "ge(INFINITY, 1.0)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, -6.283185307179586),
        0u,
        "ge(-INFINITY, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, 6.283185307179586),
        0u,
        "ge(-INFINITY, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, -6.283185307179586),
        1u,
        "ge(INFINITY, -6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, 6.283185307179586),
        1u,
        "ge(INFINITY, 6.283185307179586)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, -1.7976931348623157e+308),
        0u,
        "ge(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, 1.7976931348623157e+308),
        0u,
        "ge(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, -1.7976931348623157e+308),
        1u,
        "ge(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, 1.7976931348623157e+308),
        1u,
        "ge(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, -INFINITY),
        1u,
        "ge(-INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, -INFINITY, INFINITY),
        0u,
        "ge(-INFINITY, INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, -INFINITY),
        1u,
        "ge(INFINITY, -INFINITY)"
    );
    assertEqualU32(
        f64cmp0_ge(&instance, INFINITY, INFINITY),
        1u,
        "ge(INFINITY, INFINITY)"
    );
}
