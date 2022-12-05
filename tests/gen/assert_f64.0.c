
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_f64.0.h"

void test() {
    f640Instance instance;
    f640Instantiate(&instance, resolveTestImports);
    printStart("f64.0.wasm");
    assertEqualF64(
        f640_add(&instance, -0.0, -0.0),
        -0.0,
        "add(-0.0, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, 0.0),
        0.0,
        "add(-0.0, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, -0.0),
        0.0,
        "add(0.0, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, 0.0),
        0.0,
        "add(0.0, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, -5e-324),
        -5e-324,
        "add(-0.0, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, 5e-324),
        5e-324,
        "add(-0.0, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, -5e-324),
        -5e-324,
        "add(0.0, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, 5e-324),
        5e-324,
        "add(0.0, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "add(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "add(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "add(0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "add(0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, -0.5),
        -0.5,
        "add(-0.0, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, 0.5),
        0.5,
        "add(-0.0, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, -0.5),
        -0.5,
        "add(0.0, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, 0.5),
        0.5,
        "add(0.0, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, -1.0),
        -1.0,
        "add(-0.0, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, 1.0),
        1.0,
        "add(-0.0, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, -1.0),
        -1.0,
        "add(0.0, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, 1.0),
        1.0,
        "add(0.0, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, -6.283185307179586),
        -6.283185307179586,
        "add(-0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, 6.283185307179586),
        6.283185307179586,
        "add(-0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, -6.283185307179586),
        -6.283185307179586,
        "add(0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, 6.283185307179586),
        6.283185307179586,
        "add(0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "add(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "add(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "add(0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "add(0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, -INFINITY),
        -INFINITY,
        "add(-0.0, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -0.0, INFINITY),
        INFINITY,
        "add(-0.0, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, -INFINITY),
        -INFINITY,
        "add(0.0, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 0.0, INFINITY),
        INFINITY,
        "add(0.0, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, -0.0),
        -5e-324,
        "add(-5e-324, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, 0.0),
        -5e-324,
        "add(-5e-324, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, -0.0),
        5e-324,
        "add(5e-324, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, 0.0),
        5e-324,
        "add(5e-324, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, -5e-324),
        -1e-323,
        "add(-5e-324, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, 5e-324),
        0.0,
        "add(-5e-324, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, -5e-324),
        0.0,
        "add(5e-324, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, 5e-324),
        1e-323,
        "add(5e-324, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, -2.2250738585072014e-308),
        -2.225073858507202e-308,
        "add(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, 2.2250738585072014e-308),
        2.225073858507201e-308,
        "add(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, -2.2250738585072014e-308),
        -2.225073858507201e-308,
        "add(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, 2.2250738585072014e-308),
        2.225073858507202e-308,
        "add(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, -0.5),
        -0.5,
        "add(-5e-324, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, 0.5),
        0.5,
        "add(-5e-324, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, -0.5),
        -0.5,
        "add(5e-324, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, 0.5),
        0.5,
        "add(5e-324, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, -1.0),
        -1.0,
        "add(-5e-324, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, 1.0),
        1.0,
        "add(-5e-324, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, -1.0),
        -1.0,
        "add(5e-324, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, 1.0),
        1.0,
        "add(5e-324, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, -6.283185307179586),
        -6.283185307179586,
        "add(-5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, 6.283185307179586),
        6.283185307179586,
        "add(-5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, -6.283185307179586),
        -6.283185307179586,
        "add(5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, 6.283185307179586),
        6.283185307179586,
        "add(5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "add(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "add(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "add(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "add(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, -INFINITY),
        -INFINITY,
        "add(-5e-324, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -5e-324, INFINITY),
        INFINITY,
        "add(-5e-324, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, -INFINITY),
        -INFINITY,
        "add(5e-324, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 5e-324, INFINITY),
        INFINITY,
        "add(5e-324, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, -0.0),
        -2.2250738585072014e-308,
        "add(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, 0.0),
        -2.2250738585072014e-308,
        "add(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, -0.0),
        2.2250738585072014e-308,
        "add(2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, 0.0),
        2.2250738585072014e-308,
        "add(2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, -5e-324),
        -2.225073858507202e-308,
        "add(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, 5e-324),
        -2.225073858507201e-308,
        "add(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, -5e-324),
        2.225073858507201e-308,
        "add(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, 5e-324),
        2.225073858507202e-308,
        "add(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        -4.450147717014403e-308,
        "add(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        0.0,
        "add(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        0.0,
        "add(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        4.450147717014403e-308,
        "add(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, -0.5),
        -0.5,
        "add(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, 0.5),
        0.5,
        "add(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, -0.5),
        -0.5,
        "add(2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, 0.5),
        0.5,
        "add(2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, -1.0),
        -1.0,
        "add(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, 1.0),
        1.0,
        "add(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, -1.0),
        -1.0,
        "add(2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, 1.0),
        1.0,
        "add(2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, -6.283185307179586),
        -6.283185307179586,
        "add(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, 6.283185307179586),
        6.283185307179586,
        "add(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, -6.283185307179586),
        -6.283185307179586,
        "add(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, 6.283185307179586),
        6.283185307179586,
        "add(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "add(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "add(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "add(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "add(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, -INFINITY),
        -INFINITY,
        "add(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -2.2250738585072014e-308, INFINITY),
        INFINITY,
        "add(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, -INFINITY),
        -INFINITY,
        "add(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 2.2250738585072014e-308, INFINITY),
        INFINITY,
        "add(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, -0.0),
        -0.5,
        "add(-0.5, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, 0.0),
        -0.5,
        "add(-0.5, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, -0.0),
        0.5,
        "add(0.5, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, 0.0),
        0.5,
        "add(0.5, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, -5e-324),
        -0.5,
        "add(-0.5, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, 5e-324),
        -0.5,
        "add(-0.5, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, -5e-324),
        0.5,
        "add(0.5, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, 5e-324),
        0.5,
        "add(0.5, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, -2.2250738585072014e-308),
        -0.5,
        "add(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, 2.2250738585072014e-308),
        -0.5,
        "add(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, -2.2250738585072014e-308),
        0.5,
        "add(0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, 2.2250738585072014e-308),
        0.5,
        "add(0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, -0.5),
        -1.0,
        "add(-0.5, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, 0.5),
        0.0,
        "add(-0.5, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, -0.5),
        0.0,
        "add(0.5, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, 0.5),
        1.0,
        "add(0.5, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, -1.0),
        -1.5,
        "add(-0.5, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, 1.0),
        0.5,
        "add(-0.5, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, -1.0),
        -0.5,
        "add(0.5, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, 1.0),
        1.5,
        "add(0.5, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, -6.283185307179586),
        -6.783185307179586,
        "add(-0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, 6.283185307179586),
        5.783185307179586,
        "add(-0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, -6.283185307179586),
        -5.783185307179586,
        "add(0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, 6.283185307179586),
        6.783185307179586,
        "add(0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "add(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "add(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "add(0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "add(0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, -INFINITY),
        -INFINITY,
        "add(-0.5, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -0.5, INFINITY),
        INFINITY,
        "add(-0.5, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, -INFINITY),
        -INFINITY,
        "add(0.5, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 0.5, INFINITY),
        INFINITY,
        "add(0.5, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, -0.0),
        -1.0,
        "add(-1.0, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, 0.0),
        -1.0,
        "add(-1.0, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, -0.0),
        1.0,
        "add(1.0, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, 0.0),
        1.0,
        "add(1.0, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, -5e-324),
        -1.0,
        "add(-1.0, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, 5e-324),
        -1.0,
        "add(-1.0, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, -5e-324),
        1.0,
        "add(1.0, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, 5e-324),
        1.0,
        "add(1.0, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, -2.2250738585072014e-308),
        -1.0,
        "add(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, 2.2250738585072014e-308),
        -1.0,
        "add(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, -2.2250738585072014e-308),
        1.0,
        "add(1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, 2.2250738585072014e-308),
        1.0,
        "add(1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, -0.5),
        -1.5,
        "add(-1.0, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, 0.5),
        -0.5,
        "add(-1.0, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, -0.5),
        0.5,
        "add(1.0, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, 0.5),
        1.5,
        "add(1.0, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, -1.0),
        -2.0,
        "add(-1.0, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, 1.0),
        0.0,
        "add(-1.0, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, -1.0),
        0.0,
        "add(1.0, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, 1.0),
        2.0,
        "add(1.0, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, -6.283185307179586),
        -7.283185307179586,
        "add(-1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, 6.283185307179586),
        5.283185307179586,
        "add(-1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, -6.283185307179586),
        -5.283185307179586,
        "add(1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, 6.283185307179586),
        7.283185307179586,
        "add(1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "add(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "add(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "add(1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "add(1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, -INFINITY),
        -INFINITY,
        "add(-1.0, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -1.0, INFINITY),
        INFINITY,
        "add(-1.0, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, -INFINITY),
        -INFINITY,
        "add(1.0, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 1.0, INFINITY),
        INFINITY,
        "add(1.0, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, -0.0),
        -6.283185307179586,
        "add(-6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, 0.0),
        -6.283185307179586,
        "add(-6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, -0.0),
        6.283185307179586,
        "add(6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, 0.0),
        6.283185307179586,
        "add(6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, -5e-324),
        -6.283185307179586,
        "add(-6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, 5e-324),
        -6.283185307179586,
        "add(-6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, -5e-324),
        6.283185307179586,
        "add(6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, 5e-324),
        6.283185307179586,
        "add(6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, -2.2250738585072014e-308),
        -6.283185307179586,
        "add(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, 2.2250738585072014e-308),
        -6.283185307179586,
        "add(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, -2.2250738585072014e-308),
        6.283185307179586,
        "add(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, 2.2250738585072014e-308),
        6.283185307179586,
        "add(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, -0.5),
        -6.783185307179586,
        "add(-6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, 0.5),
        -5.783185307179586,
        "add(-6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, -0.5),
        5.783185307179586,
        "add(6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, 0.5),
        6.783185307179586,
        "add(6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, -1.0),
        -7.283185307179586,
        "add(-6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, 1.0),
        -5.283185307179586,
        "add(-6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, -1.0),
        5.283185307179586,
        "add(6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, 1.0),
        7.283185307179586,
        "add(6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, -6.283185307179586),
        -12.566370614359172,
        "add(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, 6.283185307179586),
        0.0,
        "add(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, -6.283185307179586),
        0.0,
        "add(6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, 6.283185307179586),
        12.566370614359172,
        "add(6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "add(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "add(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "add(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "add(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, -INFINITY),
        -INFINITY,
        "add(-6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -6.283185307179586, INFINITY),
        INFINITY,
        "add(-6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, -INFINITY),
        -INFINITY,
        "add(6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 6.283185307179586, INFINITY),
        INFINITY,
        "add(6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, -0.0),
        -1.7976931348623157e+308,
        "add(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, 0.0),
        -1.7976931348623157e+308,
        "add(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, -0.0),
        1.7976931348623157e+308,
        "add(1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, 0.0),
        1.7976931348623157e+308,
        "add(1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, -5e-324),
        -1.7976931348623157e+308,
        "add(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, 5e-324),
        -1.7976931348623157e+308,
        "add(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, -5e-324),
        1.7976931348623157e+308,
        "add(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, 5e-324),
        1.7976931348623157e+308,
        "add(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        -1.7976931348623157e+308,
        "add(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        -1.7976931348623157e+308,
        "add(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        1.7976931348623157e+308,
        "add(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        1.7976931348623157e+308,
        "add(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, -0.5),
        -1.7976931348623157e+308,
        "add(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, 0.5),
        -1.7976931348623157e+308,
        "add(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, -0.5),
        1.7976931348623157e+308,
        "add(1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, 0.5),
        1.7976931348623157e+308,
        "add(1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, -1.0),
        -1.7976931348623157e+308,
        "add(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, 1.0),
        -1.7976931348623157e+308,
        "add(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, -1.0),
        1.7976931348623157e+308,
        "add(1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, 1.0),
        1.7976931348623157e+308,
        "add(1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, -6.283185307179586),
        -1.7976931348623157e+308,
        "add(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, 6.283185307179586),
        -1.7976931348623157e+308,
        "add(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, -6.283185307179586),
        1.7976931348623157e+308,
        "add(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, 6.283185307179586),
        1.7976931348623157e+308,
        "add(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        -INFINITY,
        "add(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        0.0,
        "add(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        0.0,
        "add(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        INFINITY,
        "add(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, -INFINITY),
        -INFINITY,
        "add(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -1.7976931348623157e+308, INFINITY),
        INFINITY,
        "add(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, -INFINITY),
        -INFINITY,
        "add(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, 1.7976931348623157e+308, INFINITY),
        INFINITY,
        "add(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, -0.0),
        -INFINITY,
        "add(-INFINITY, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, 0.0),
        -INFINITY,
        "add(-INFINITY, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, -0.0),
        INFINITY,
        "add(INFINITY, -0.0)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, 0.0),
        INFINITY,
        "add(INFINITY, 0.0)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, -5e-324),
        -INFINITY,
        "add(-INFINITY, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, 5e-324),
        -INFINITY,
        "add(-INFINITY, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, -5e-324),
        INFINITY,
        "add(INFINITY, -5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, 5e-324),
        INFINITY,
        "add(INFINITY, 5e-324)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, -2.2250738585072014e-308),
        -INFINITY,
        "add(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, 2.2250738585072014e-308),
        -INFINITY,
        "add(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, -2.2250738585072014e-308),
        INFINITY,
        "add(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, 2.2250738585072014e-308),
        INFINITY,
        "add(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, -0.5),
        -INFINITY,
        "add(-INFINITY, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, 0.5),
        -INFINITY,
        "add(-INFINITY, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, -0.5),
        INFINITY,
        "add(INFINITY, -0.5)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, 0.5),
        INFINITY,
        "add(INFINITY, 0.5)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, -1.0),
        -INFINITY,
        "add(-INFINITY, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, 1.0),
        -INFINITY,
        "add(-INFINITY, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, -1.0),
        INFINITY,
        "add(INFINITY, -1.0)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, 1.0),
        INFINITY,
        "add(INFINITY, 1.0)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, -6.283185307179586),
        -INFINITY,
        "add(-INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, 6.283185307179586),
        -INFINITY,
        "add(-INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, -6.283185307179586),
        INFINITY,
        "add(INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, 6.283185307179586),
        INFINITY,
        "add(INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, -1.7976931348623157e+308),
        -INFINITY,
        "add(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, 1.7976931348623157e+308),
        -INFINITY,
        "add(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, -1.7976931348623157e+308),
        INFINITY,
        "add(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, 1.7976931348623157e+308),
        INFINITY,
        "add(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_add(&instance, -INFINITY, -INFINITY),
        -INFINITY,
        "add(-INFINITY, -INFINITY)"
    );
    assertEqualF64(
        f640_add(&instance, INFINITY, INFINITY),
        INFINITY,
        "add(INFINITY, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, -0.0),
        0.0,
        "sub(-0.0, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, 0.0),
        -0.0,
        "sub(-0.0, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, -0.0),
        0.0,
        "sub(0.0, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, 0.0),
        0.0,
        "sub(0.0, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, -5e-324),
        5e-324,
        "sub(-0.0, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, 5e-324),
        -5e-324,
        "sub(-0.0, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, -5e-324),
        5e-324,
        "sub(0.0, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, 5e-324),
        -5e-324,
        "sub(0.0, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, -2.2250738585072014e-308),
        2.2250738585072014e-308,
        "sub(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, 2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "sub(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, -2.2250738585072014e-308),
        2.2250738585072014e-308,
        "sub(0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, 2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "sub(0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, -0.5),
        0.5,
        "sub(-0.0, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, 0.5),
        -0.5,
        "sub(-0.0, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, -0.5),
        0.5,
        "sub(0.0, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, 0.5),
        -0.5,
        "sub(0.0, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, -1.0),
        1.0,
        "sub(-0.0, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, 1.0),
        -1.0,
        "sub(-0.0, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, -1.0),
        1.0,
        "sub(0.0, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, 1.0),
        -1.0,
        "sub(0.0, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, -6.283185307179586),
        6.283185307179586,
        "sub(-0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, 6.283185307179586),
        -6.283185307179586,
        "sub(-0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, -6.283185307179586),
        6.283185307179586,
        "sub(0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, 6.283185307179586),
        -6.283185307179586,
        "sub(0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "sub(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "sub(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "sub(0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "sub(0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, -INFINITY),
        INFINITY,
        "sub(-0.0, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.0, INFINITY),
        -INFINITY,
        "sub(-0.0, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, -INFINITY),
        INFINITY,
        "sub(0.0, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.0, INFINITY),
        -INFINITY,
        "sub(0.0, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, -0.0),
        -5e-324,
        "sub(-5e-324, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, 0.0),
        -5e-324,
        "sub(-5e-324, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, -0.0),
        5e-324,
        "sub(5e-324, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, 0.0),
        5e-324,
        "sub(5e-324, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, -5e-324),
        0.0,
        "sub(-5e-324, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, 5e-324),
        -1e-323,
        "sub(-5e-324, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, -5e-324),
        1e-323,
        "sub(5e-324, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, 5e-324),
        0.0,
        "sub(5e-324, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, -2.2250738585072014e-308),
        2.225073858507201e-308,
        "sub(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, 2.2250738585072014e-308),
        -2.225073858507202e-308,
        "sub(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, -2.2250738585072014e-308),
        2.225073858507202e-308,
        "sub(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, 2.2250738585072014e-308),
        -2.225073858507201e-308,
        "sub(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, -0.5),
        0.5,
        "sub(-5e-324, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, 0.5),
        -0.5,
        "sub(-5e-324, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, -0.5),
        0.5,
        "sub(5e-324, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, 0.5),
        -0.5,
        "sub(5e-324, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, -1.0),
        1.0,
        "sub(-5e-324, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, 1.0),
        -1.0,
        "sub(-5e-324, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, -1.0),
        1.0,
        "sub(5e-324, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, 1.0),
        -1.0,
        "sub(5e-324, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, -6.283185307179586),
        6.283185307179586,
        "sub(-5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, 6.283185307179586),
        -6.283185307179586,
        "sub(-5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, -6.283185307179586),
        6.283185307179586,
        "sub(5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, 6.283185307179586),
        -6.283185307179586,
        "sub(5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "sub(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "sub(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "sub(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "sub(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, -INFINITY),
        INFINITY,
        "sub(-5e-324, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -5e-324, INFINITY),
        -INFINITY,
        "sub(-5e-324, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, -INFINITY),
        INFINITY,
        "sub(5e-324, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 5e-324, INFINITY),
        -INFINITY,
        "sub(5e-324, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, -0.0),
        -2.2250738585072014e-308,
        "sub(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, 0.0),
        -2.2250738585072014e-308,
        "sub(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, -0.0),
        2.2250738585072014e-308,
        "sub(2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, 0.0),
        2.2250738585072014e-308,
        "sub(2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, -5e-324),
        -2.225073858507201e-308,
        "sub(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, 5e-324),
        -2.225073858507202e-308,
        "sub(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, -5e-324),
        2.225073858507202e-308,
        "sub(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, 5e-324),
        2.225073858507201e-308,
        "sub(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        0.0,
        "sub(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        -4.450147717014403e-308,
        "sub(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        4.450147717014403e-308,
        "sub(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        0.0,
        "sub(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, -0.5),
        0.5,
        "sub(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, 0.5),
        -0.5,
        "sub(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, -0.5),
        0.5,
        "sub(2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, 0.5),
        -0.5,
        "sub(2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, -1.0),
        1.0,
        "sub(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, 1.0),
        -1.0,
        "sub(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, -1.0),
        1.0,
        "sub(2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, 1.0),
        -1.0,
        "sub(2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, -6.283185307179586),
        6.283185307179586,
        "sub(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, 6.283185307179586),
        -6.283185307179586,
        "sub(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, -6.283185307179586),
        6.283185307179586,
        "sub(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, 6.283185307179586),
        -6.283185307179586,
        "sub(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "sub(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "sub(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "sub(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "sub(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, -INFINITY),
        INFINITY,
        "sub(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -2.2250738585072014e-308, INFINITY),
        -INFINITY,
        "sub(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, -INFINITY),
        INFINITY,
        "sub(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 2.2250738585072014e-308, INFINITY),
        -INFINITY,
        "sub(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, -0.0),
        -0.5,
        "sub(-0.5, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, 0.0),
        -0.5,
        "sub(-0.5, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, -0.0),
        0.5,
        "sub(0.5, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, 0.0),
        0.5,
        "sub(0.5, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, -5e-324),
        -0.5,
        "sub(-0.5, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, 5e-324),
        -0.5,
        "sub(-0.5, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, -5e-324),
        0.5,
        "sub(0.5, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, 5e-324),
        0.5,
        "sub(0.5, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, -2.2250738585072014e-308),
        -0.5,
        "sub(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, 2.2250738585072014e-308),
        -0.5,
        "sub(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, -2.2250738585072014e-308),
        0.5,
        "sub(0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, 2.2250738585072014e-308),
        0.5,
        "sub(0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, -0.5),
        0.0,
        "sub(-0.5, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, 0.5),
        -1.0,
        "sub(-0.5, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, -0.5),
        1.0,
        "sub(0.5, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, 0.5),
        0.0,
        "sub(0.5, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, -1.0),
        0.5,
        "sub(-0.5, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, 1.0),
        -1.5,
        "sub(-0.5, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, -1.0),
        1.5,
        "sub(0.5, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, 1.0),
        -0.5,
        "sub(0.5, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, -6.283185307179586),
        5.783185307179586,
        "sub(-0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, 6.283185307179586),
        -6.783185307179586,
        "sub(-0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, -6.283185307179586),
        6.783185307179586,
        "sub(0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, 6.283185307179586),
        -5.783185307179586,
        "sub(0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "sub(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "sub(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "sub(0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "sub(0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, -INFINITY),
        INFINITY,
        "sub(-0.5, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -0.5, INFINITY),
        -INFINITY,
        "sub(-0.5, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, -INFINITY),
        INFINITY,
        "sub(0.5, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 0.5, INFINITY),
        -INFINITY,
        "sub(0.5, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, -0.0),
        -1.0,
        "sub(-1.0, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, 0.0),
        -1.0,
        "sub(-1.0, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, -0.0),
        1.0,
        "sub(1.0, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, 0.0),
        1.0,
        "sub(1.0, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, -5e-324),
        -1.0,
        "sub(-1.0, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, 5e-324),
        -1.0,
        "sub(-1.0, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, -5e-324),
        1.0,
        "sub(1.0, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, 5e-324),
        1.0,
        "sub(1.0, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, -2.2250738585072014e-308),
        -1.0,
        "sub(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, 2.2250738585072014e-308),
        -1.0,
        "sub(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, -2.2250738585072014e-308),
        1.0,
        "sub(1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, 2.2250738585072014e-308),
        1.0,
        "sub(1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, -0.5),
        -0.5,
        "sub(-1.0, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, 0.5),
        -1.5,
        "sub(-1.0, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, -0.5),
        1.5,
        "sub(1.0, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, 0.5),
        0.5,
        "sub(1.0, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, -1.0),
        0.0,
        "sub(-1.0, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, 1.0),
        -2.0,
        "sub(-1.0, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, -1.0),
        2.0,
        "sub(1.0, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, 1.0),
        0.0,
        "sub(1.0, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, -6.283185307179586),
        5.283185307179586,
        "sub(-1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, 6.283185307179586),
        -7.283185307179586,
        "sub(-1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, -6.283185307179586),
        7.283185307179586,
        "sub(1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, 6.283185307179586),
        -5.283185307179586,
        "sub(1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "sub(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "sub(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "sub(1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "sub(1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, -INFINITY),
        INFINITY,
        "sub(-1.0, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.0, INFINITY),
        -INFINITY,
        "sub(-1.0, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, -INFINITY),
        INFINITY,
        "sub(1.0, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.0, INFINITY),
        -INFINITY,
        "sub(1.0, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, -0.0),
        -6.283185307179586,
        "sub(-6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, 0.0),
        -6.283185307179586,
        "sub(-6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, -0.0),
        6.283185307179586,
        "sub(6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, 0.0),
        6.283185307179586,
        "sub(6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, -5e-324),
        -6.283185307179586,
        "sub(-6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, 5e-324),
        -6.283185307179586,
        "sub(-6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, -5e-324),
        6.283185307179586,
        "sub(6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, 5e-324),
        6.283185307179586,
        "sub(6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, -2.2250738585072014e-308),
        -6.283185307179586,
        "sub(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, 2.2250738585072014e-308),
        -6.283185307179586,
        "sub(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, -2.2250738585072014e-308),
        6.283185307179586,
        "sub(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, 2.2250738585072014e-308),
        6.283185307179586,
        "sub(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, -0.5),
        -5.783185307179586,
        "sub(-6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, 0.5),
        -6.783185307179586,
        "sub(-6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, -0.5),
        6.783185307179586,
        "sub(6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, 0.5),
        5.783185307179586,
        "sub(6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, -1.0),
        -5.283185307179586,
        "sub(-6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, 1.0),
        -7.283185307179586,
        "sub(-6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, -1.0),
        7.283185307179586,
        "sub(6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, 1.0),
        5.283185307179586,
        "sub(6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, -6.283185307179586),
        0.0,
        "sub(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, 6.283185307179586),
        -12.566370614359172,
        "sub(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, -6.283185307179586),
        12.566370614359172,
        "sub(6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, 6.283185307179586),
        0.0,
        "sub(6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "sub(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "sub(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "sub(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "sub(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, -INFINITY),
        INFINITY,
        "sub(-6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -6.283185307179586, INFINITY),
        -INFINITY,
        "sub(-6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, -INFINITY),
        INFINITY,
        "sub(6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 6.283185307179586, INFINITY),
        -INFINITY,
        "sub(6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, -0.0),
        -1.7976931348623157e+308,
        "sub(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, 0.0),
        -1.7976931348623157e+308,
        "sub(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, -0.0),
        1.7976931348623157e+308,
        "sub(1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, 0.0),
        1.7976931348623157e+308,
        "sub(1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, -5e-324),
        -1.7976931348623157e+308,
        "sub(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, 5e-324),
        -1.7976931348623157e+308,
        "sub(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, -5e-324),
        1.7976931348623157e+308,
        "sub(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, 5e-324),
        1.7976931348623157e+308,
        "sub(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        -1.7976931348623157e+308,
        "sub(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        -1.7976931348623157e+308,
        "sub(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        1.7976931348623157e+308,
        "sub(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        1.7976931348623157e+308,
        "sub(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, -0.5),
        -1.7976931348623157e+308,
        "sub(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, 0.5),
        -1.7976931348623157e+308,
        "sub(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, -0.5),
        1.7976931348623157e+308,
        "sub(1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, 0.5),
        1.7976931348623157e+308,
        "sub(1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, -1.0),
        -1.7976931348623157e+308,
        "sub(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, 1.0),
        -1.7976931348623157e+308,
        "sub(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, -1.0),
        1.7976931348623157e+308,
        "sub(1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, 1.0),
        1.7976931348623157e+308,
        "sub(1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, -6.283185307179586),
        -1.7976931348623157e+308,
        "sub(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, 6.283185307179586),
        -1.7976931348623157e+308,
        "sub(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, -6.283185307179586),
        1.7976931348623157e+308,
        "sub(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, 6.283185307179586),
        1.7976931348623157e+308,
        "sub(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        0.0,
        "sub(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        -INFINITY,
        "sub(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        INFINITY,
        "sub(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        0.0,
        "sub(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, -INFINITY),
        INFINITY,
        "sub(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -1.7976931348623157e+308, INFINITY),
        -INFINITY,
        "sub(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, -INFINITY),
        INFINITY,
        "sub(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, 1.7976931348623157e+308, INFINITY),
        -INFINITY,
        "sub(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, -0.0),
        -INFINITY,
        "sub(-INFINITY, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, 0.0),
        -INFINITY,
        "sub(-INFINITY, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, -0.0),
        INFINITY,
        "sub(INFINITY, -0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, 0.0),
        INFINITY,
        "sub(INFINITY, 0.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, -5e-324),
        -INFINITY,
        "sub(-INFINITY, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, 5e-324),
        -INFINITY,
        "sub(-INFINITY, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, -5e-324),
        INFINITY,
        "sub(INFINITY, -5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, 5e-324),
        INFINITY,
        "sub(INFINITY, 5e-324)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, -2.2250738585072014e-308),
        -INFINITY,
        "sub(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, 2.2250738585072014e-308),
        -INFINITY,
        "sub(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, -2.2250738585072014e-308),
        INFINITY,
        "sub(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, 2.2250738585072014e-308),
        INFINITY,
        "sub(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, -0.5),
        -INFINITY,
        "sub(-INFINITY, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, 0.5),
        -INFINITY,
        "sub(-INFINITY, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, -0.5),
        INFINITY,
        "sub(INFINITY, -0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, 0.5),
        INFINITY,
        "sub(INFINITY, 0.5)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, -1.0),
        -INFINITY,
        "sub(-INFINITY, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, 1.0),
        -INFINITY,
        "sub(-INFINITY, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, -1.0),
        INFINITY,
        "sub(INFINITY, -1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, 1.0),
        INFINITY,
        "sub(INFINITY, 1.0)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, -6.283185307179586),
        -INFINITY,
        "sub(-INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, 6.283185307179586),
        -INFINITY,
        "sub(-INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, -6.283185307179586),
        INFINITY,
        "sub(INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, 6.283185307179586),
        INFINITY,
        "sub(INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, -1.7976931348623157e+308),
        -INFINITY,
        "sub(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, 1.7976931348623157e+308),
        -INFINITY,
        "sub(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, -1.7976931348623157e+308),
        INFINITY,
        "sub(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, 1.7976931348623157e+308),
        INFINITY,
        "sub(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sub(&instance, -INFINITY, INFINITY),
        -INFINITY,
        "sub(-INFINITY, INFINITY)"
    );
    assertEqualF64(
        f640_sub(&instance, INFINITY, -INFINITY),
        INFINITY,
        "sub(INFINITY, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, -0.0),
        0.0,
        "mul(-0.0, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, 0.0),
        -0.0,
        "mul(-0.0, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, -0.0),
        -0.0,
        "mul(0.0, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, 0.0),
        0.0,
        "mul(0.0, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, -5e-324),
        0.0,
        "mul(-0.0, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, 5e-324),
        -0.0,
        "mul(-0.0, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, -5e-324),
        -0.0,
        "mul(0.0, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, 5e-324),
        0.0,
        "mul(0.0, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, -2.2250738585072014e-308),
        0.0,
        "mul(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, 2.2250738585072014e-308),
        -0.0,
        "mul(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, -2.2250738585072014e-308),
        -0.0,
        "mul(0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, 2.2250738585072014e-308),
        0.0,
        "mul(0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, -0.5),
        0.0,
        "mul(-0.0, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, 0.5),
        -0.0,
        "mul(-0.0, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, -0.5),
        -0.0,
        "mul(0.0, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, 0.5),
        0.0,
        "mul(0.0, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, -1.0),
        0.0,
        "mul(-0.0, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, 1.0),
        -0.0,
        "mul(-0.0, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, -1.0),
        -0.0,
        "mul(0.0, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, 1.0),
        0.0,
        "mul(0.0, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, -6.283185307179586),
        0.0,
        "mul(-0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, 6.283185307179586),
        -0.0,
        "mul(-0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, -6.283185307179586),
        -0.0,
        "mul(0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, 6.283185307179586),
        0.0,
        "mul(0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, -1.7976931348623157e+308),
        0.0,
        "mul(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.0, 1.7976931348623157e+308),
        -0.0,
        "mul(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, -1.7976931348623157e+308),
        -0.0,
        "mul(0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.0, 1.7976931348623157e+308),
        0.0,
        "mul(0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, -0.0),
        0.0,
        "mul(-5e-324, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, 0.0),
        -0.0,
        "mul(-5e-324, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, -0.0),
        -0.0,
        "mul(5e-324, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, 0.0),
        0.0,
        "mul(5e-324, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, -5e-324),
        0.0,
        "mul(-5e-324, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, 5e-324),
        -0.0,
        "mul(-5e-324, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, -5e-324),
        -0.0,
        "mul(5e-324, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, 5e-324),
        0.0,
        "mul(5e-324, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, -2.2250738585072014e-308),
        0.0,
        "mul(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, 2.2250738585072014e-308),
        -0.0,
        "mul(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, -2.2250738585072014e-308),
        -0.0,
        "mul(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, 2.2250738585072014e-308),
        0.0,
        "mul(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, -0.5),
        0.0,
        "mul(-5e-324, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, 0.5),
        -0.0,
        "mul(-5e-324, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, -0.5),
        -0.0,
        "mul(5e-324, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, 0.5),
        0.0,
        "mul(5e-324, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, -1.0),
        5e-324,
        "mul(-5e-324, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, 1.0),
        -5e-324,
        "mul(-5e-324, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, -1.0),
        -5e-324,
        "mul(5e-324, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, 1.0),
        5e-324,
        "mul(5e-324, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, -6.283185307179586),
        3e-323,
        "mul(-5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, 6.283185307179586),
        -3e-323,
        "mul(-5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, -6.283185307179586),
        -3e-323,
        "mul(5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, 6.283185307179586),
        3e-323,
        "mul(5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, -1.7976931348623157e+308),
        8.881784197001251e-16,
        "mul(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, 1.7976931348623157e+308),
        -8.881784197001251e-16,
        "mul(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, -1.7976931348623157e+308),
        -8.881784197001251e-16,
        "mul(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, 1.7976931348623157e+308),
        8.881784197001251e-16,
        "mul(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, -INFINITY),
        INFINITY,
        "mul(-5e-324, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -5e-324, INFINITY),
        -INFINITY,
        "mul(-5e-324, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, -INFINITY),
        -INFINITY,
        "mul(5e-324, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, 5e-324, INFINITY),
        INFINITY,
        "mul(5e-324, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, -0.0),
        0.0,
        "mul(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, 0.0),
        -0.0,
        "mul(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, -0.0),
        -0.0,
        "mul(2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, 0.0),
        0.0,
        "mul(2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, -5e-324),
        0.0,
        "mul(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, 5e-324),
        -0.0,
        "mul(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, -5e-324),
        -0.0,
        "mul(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, 5e-324),
        0.0,
        "mul(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        0.0,
        "mul(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        -0.0,
        "mul(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        -0.0,
        "mul(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        0.0,
        "mul(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, -0.5),
        1.1125369292536007e-308,
        "mul(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, 0.5),
        -1.1125369292536007e-308,
        "mul(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, -0.5),
        -1.1125369292536007e-308,
        "mul(2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, 0.5),
        1.1125369292536007e-308,
        "mul(2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, -1.0),
        2.2250738585072014e-308,
        "mul(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, 1.0),
        -2.2250738585072014e-308,
        "mul(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, -1.0),
        -2.2250738585072014e-308,
        "mul(2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, 1.0),
        2.2250738585072014e-308,
        "mul(2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, -6.283185307179586),
        1.3980551375161837e-307,
        "mul(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, 6.283185307179586),
        -1.3980551375161837e-307,
        "mul(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, -6.283185307179586),
        -1.3980551375161837e-307,
        "mul(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, 6.283185307179586),
        1.3980551375161837e-307,
        "mul(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        3.9999999999999996,
        "mul(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        -3.9999999999999996,
        "mul(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        -3.9999999999999996,
        "mul(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        3.9999999999999996,
        "mul(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, -INFINITY),
        INFINITY,
        "mul(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -2.2250738585072014e-308, INFINITY),
        -INFINITY,
        "mul(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, -INFINITY),
        -INFINITY,
        "mul(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, 2.2250738585072014e-308, INFINITY),
        INFINITY,
        "mul(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, -0.0),
        0.0,
        "mul(-0.5, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, 0.0),
        -0.0,
        "mul(-0.5, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, -0.0),
        -0.0,
        "mul(0.5, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, 0.0),
        0.0,
        "mul(0.5, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, -5e-324),
        0.0,
        "mul(-0.5, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, 5e-324),
        -0.0,
        "mul(-0.5, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, -5e-324),
        -0.0,
        "mul(0.5, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, 5e-324),
        0.0,
        "mul(0.5, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, -2.2250738585072014e-308),
        1.1125369292536007e-308,
        "mul(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, 2.2250738585072014e-308),
        -1.1125369292536007e-308,
        "mul(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, -2.2250738585072014e-308),
        -1.1125369292536007e-308,
        "mul(0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, 2.2250738585072014e-308),
        1.1125369292536007e-308,
        "mul(0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, -0.5),
        0.25,
        "mul(-0.5, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, 0.5),
        -0.25,
        "mul(-0.5, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, -0.5),
        -0.25,
        "mul(0.5, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, 0.5),
        0.25,
        "mul(0.5, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, -1.0),
        0.5,
        "mul(-0.5, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, 1.0),
        -0.5,
        "mul(-0.5, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, -1.0),
        -0.5,
        "mul(0.5, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, 1.0),
        0.5,
        "mul(0.5, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, -6.283185307179586),
        3.141592653589793,
        "mul(-0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, 6.283185307179586),
        -3.141592653589793,
        "mul(-0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, -6.283185307179586),
        -3.141592653589793,
        "mul(0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, 6.283185307179586),
        3.141592653589793,
        "mul(0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, -1.7976931348623157e+308),
        8.988465674311579e+307,
        "mul(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, 1.7976931348623157e+308),
        -8.988465674311579e+307,
        "mul(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, -1.7976931348623157e+308),
        -8.988465674311579e+307,
        "mul(0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, 1.7976931348623157e+308),
        8.988465674311579e+307,
        "mul(0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, -INFINITY),
        INFINITY,
        "mul(-0.5, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -0.5, INFINITY),
        -INFINITY,
        "mul(-0.5, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, -INFINITY),
        -INFINITY,
        "mul(0.5, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, 0.5, INFINITY),
        INFINITY,
        "mul(0.5, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, -0.0),
        0.0,
        "mul(-1.0, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, 0.0),
        -0.0,
        "mul(-1.0, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, -0.0),
        -0.0,
        "mul(1.0, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, 0.0),
        0.0,
        "mul(1.0, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, -5e-324),
        5e-324,
        "mul(-1.0, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, 5e-324),
        -5e-324,
        "mul(-1.0, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, -5e-324),
        -5e-324,
        "mul(1.0, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, 5e-324),
        5e-324,
        "mul(1.0, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, -2.2250738585072014e-308),
        2.2250738585072014e-308,
        "mul(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, 2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "mul(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "mul(1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "mul(1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, -0.5),
        0.5,
        "mul(-1.0, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, 0.5),
        -0.5,
        "mul(-1.0, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, -0.5),
        -0.5,
        "mul(1.0, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, 0.5),
        0.5,
        "mul(1.0, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, -1.0),
        1.0,
        "mul(-1.0, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, 1.0),
        -1.0,
        "mul(-1.0, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, -1.0),
        -1.0,
        "mul(1.0, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, 1.0),
        1.0,
        "mul(1.0, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, -6.283185307179586),
        6.283185307179586,
        "mul(-1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, 6.283185307179586),
        -6.283185307179586,
        "mul(-1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, -6.283185307179586),
        -6.283185307179586,
        "mul(1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, 6.283185307179586),
        6.283185307179586,
        "mul(1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "mul(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "mul(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "mul(1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "mul(1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, -INFINITY),
        INFINITY,
        "mul(-1.0, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.0, INFINITY),
        -INFINITY,
        "mul(-1.0, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, -INFINITY),
        -INFINITY,
        "mul(1.0, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.0, INFINITY),
        INFINITY,
        "mul(1.0, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, -0.0),
        0.0,
        "mul(-6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, 0.0),
        -0.0,
        "mul(-6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, -0.0),
        -0.0,
        "mul(6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, 0.0),
        0.0,
        "mul(6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, -5e-324),
        3e-323,
        "mul(-6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, 5e-324),
        -3e-323,
        "mul(-6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, -5e-324),
        -3e-323,
        "mul(6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, 5e-324),
        3e-323,
        "mul(6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, -2.2250738585072014e-308),
        1.3980551375161837e-307,
        "mul(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, 2.2250738585072014e-308),
        -1.3980551375161837e-307,
        "mul(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, -2.2250738585072014e-308),
        -1.3980551375161837e-307,
        "mul(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, 2.2250738585072014e-308),
        1.3980551375161837e-307,
        "mul(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, -0.5),
        3.141592653589793,
        "mul(-6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, 0.5),
        -3.141592653589793,
        "mul(-6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, -0.5),
        -3.141592653589793,
        "mul(6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, 0.5),
        3.141592653589793,
        "mul(6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, -1.0),
        6.283185307179586,
        "mul(-6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, 1.0),
        -6.283185307179586,
        "mul(-6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, -1.0),
        -6.283185307179586,
        "mul(6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, 1.0),
        6.283185307179586,
        "mul(6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, -6.283185307179586),
        39.47841760435743,
        "mul(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, 6.283185307179586),
        -39.47841760435743,
        "mul(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, -6.283185307179586),
        -39.47841760435743,
        "mul(6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, 6.283185307179586),
        39.47841760435743,
        "mul(6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, -1.7976931348623157e+308),
        INFINITY,
        "mul(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, 1.7976931348623157e+308),
        -INFINITY,
        "mul(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, -1.7976931348623157e+308),
        -INFINITY,
        "mul(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, 1.7976931348623157e+308),
        INFINITY,
        "mul(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, -INFINITY),
        INFINITY,
        "mul(-6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -6.283185307179586, INFINITY),
        -INFINITY,
        "mul(-6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, -INFINITY),
        -INFINITY,
        "mul(6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, 6.283185307179586, INFINITY),
        INFINITY,
        "mul(6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, -0.0),
        0.0,
        "mul(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, 0.0),
        -0.0,
        "mul(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, -0.0),
        -0.0,
        "mul(1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, 0.0),
        0.0,
        "mul(1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, -5e-324),
        8.881784197001251e-16,
        "mul(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, 5e-324),
        -8.881784197001251e-16,
        "mul(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, -5e-324),
        -8.881784197001251e-16,
        "mul(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, 5e-324),
        8.881784197001251e-16,
        "mul(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        3.9999999999999996,
        "mul(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        -3.9999999999999996,
        "mul(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        -3.9999999999999996,
        "mul(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        3.9999999999999996,
        "mul(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, -0.5),
        8.988465674311579e+307,
        "mul(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, 0.5),
        -8.988465674311579e+307,
        "mul(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, -0.5),
        -8.988465674311579e+307,
        "mul(1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, 0.5),
        8.988465674311579e+307,
        "mul(1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, -1.0),
        1.7976931348623157e+308,
        "mul(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, 1.0),
        -1.7976931348623157e+308,
        "mul(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, -1.0),
        -1.7976931348623157e+308,
        "mul(1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, 1.0),
        1.7976931348623157e+308,
        "mul(1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, -6.283185307179586),
        INFINITY,
        "mul(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, 6.283185307179586),
        -INFINITY,
        "mul(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, -6.283185307179586),
        -INFINITY,
        "mul(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, 6.283185307179586),
        INFINITY,
        "mul(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        INFINITY,
        "mul(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        -INFINITY,
        "mul(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        -INFINITY,
        "mul(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        INFINITY,
        "mul(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, -INFINITY),
        INFINITY,
        "mul(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -1.7976931348623157e+308, INFINITY),
        -INFINITY,
        "mul(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, -INFINITY),
        -INFINITY,
        "mul(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, 1.7976931348623157e+308, INFINITY),
        INFINITY,
        "mul(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, -5e-324),
        INFINITY,
        "mul(-INFINITY, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, 5e-324),
        -INFINITY,
        "mul(-INFINITY, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, -5e-324),
        -INFINITY,
        "mul(INFINITY, -5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, 5e-324),
        INFINITY,
        "mul(INFINITY, 5e-324)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, -2.2250738585072014e-308),
        INFINITY,
        "mul(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, 2.2250738585072014e-308),
        -INFINITY,
        "mul(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, -2.2250738585072014e-308),
        -INFINITY,
        "mul(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, 2.2250738585072014e-308),
        INFINITY,
        "mul(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, -0.5),
        INFINITY,
        "mul(-INFINITY, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, 0.5),
        -INFINITY,
        "mul(-INFINITY, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, -0.5),
        -INFINITY,
        "mul(INFINITY, -0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, 0.5),
        INFINITY,
        "mul(INFINITY, 0.5)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, -1.0),
        INFINITY,
        "mul(-INFINITY, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, 1.0),
        -INFINITY,
        "mul(-INFINITY, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, -1.0),
        -INFINITY,
        "mul(INFINITY, -1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, 1.0),
        INFINITY,
        "mul(INFINITY, 1.0)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, -6.283185307179586),
        INFINITY,
        "mul(-INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, 6.283185307179586),
        -INFINITY,
        "mul(-INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, -6.283185307179586),
        -INFINITY,
        "mul(INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, 6.283185307179586),
        INFINITY,
        "mul(INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, -1.7976931348623157e+308),
        INFINITY,
        "mul(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, 1.7976931348623157e+308),
        -INFINITY,
        "mul(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, -1.7976931348623157e+308),
        -INFINITY,
        "mul(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, 1.7976931348623157e+308),
        INFINITY,
        "mul(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, -INFINITY),
        INFINITY,
        "mul(-INFINITY, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, -INFINITY, INFINITY),
        -INFINITY,
        "mul(-INFINITY, INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, -INFINITY),
        -INFINITY,
        "mul(INFINITY, -INFINITY)"
    );
    assertEqualF64(
        f640_mul(&instance, INFINITY, INFINITY),
        INFINITY,
        "mul(INFINITY, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, -5e-324),
        0.0,
        "div(-0.0, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, 5e-324),
        -0.0,
        "div(-0.0, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, -5e-324),
        -0.0,
        "div(0.0, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, 5e-324),
        0.0,
        "div(0.0, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, -2.2250738585072014e-308),
        0.0,
        "div(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, 2.2250738585072014e-308),
        -0.0,
        "div(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, -2.2250738585072014e-308),
        -0.0,
        "div(0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, 2.2250738585072014e-308),
        0.0,
        "div(0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, -0.5),
        0.0,
        "div(-0.0, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, 0.5),
        -0.0,
        "div(-0.0, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, -0.5),
        -0.0,
        "div(0.0, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, 0.5),
        0.0,
        "div(0.0, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, -1.0),
        0.0,
        "div(-0.0, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, 1.0),
        -0.0,
        "div(-0.0, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, -1.0),
        -0.0,
        "div(0.0, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, 1.0),
        0.0,
        "div(0.0, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, -6.283185307179586),
        0.0,
        "div(-0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, 6.283185307179586),
        -0.0,
        "div(-0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, -6.283185307179586),
        -0.0,
        "div(0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, 6.283185307179586),
        0.0,
        "div(0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, -1.7976931348623157e+308),
        0.0,
        "div(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, 1.7976931348623157e+308),
        -0.0,
        "div(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, -1.7976931348623157e+308),
        -0.0,
        "div(0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, 1.7976931348623157e+308),
        0.0,
        "div(0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, -INFINITY),
        0.0,
        "div(-0.0, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -0.0, INFINITY),
        -0.0,
        "div(-0.0, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, -INFINITY),
        -0.0,
        "div(0.0, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 0.0, INFINITY),
        0.0,
        "div(0.0, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, -0.0),
        INFINITY,
        "div(-5e-324, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, 0.0),
        -INFINITY,
        "div(-5e-324, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, -0.0),
        -INFINITY,
        "div(5e-324, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, 0.0),
        INFINITY,
        "div(5e-324, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, -5e-324),
        1.0,
        "div(-5e-324, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, 5e-324),
        -1.0,
        "div(-5e-324, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, -5e-324),
        -1.0,
        "div(5e-324, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, 5e-324),
        1.0,
        "div(5e-324, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, -2.2250738585072014e-308),
        2.220446049250313e-16,
        "div(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, 2.2250738585072014e-308),
        -2.220446049250313e-16,
        "div(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, -2.2250738585072014e-308),
        -2.220446049250313e-16,
        "div(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, 2.2250738585072014e-308),
        2.220446049250313e-16,
        "div(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, -0.5),
        1e-323,
        "div(-5e-324, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, 0.5),
        -1e-323,
        "div(-5e-324, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, -0.5),
        -1e-323,
        "div(5e-324, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, 0.5),
        1e-323,
        "div(5e-324, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, -1.0),
        5e-324,
        "div(-5e-324, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, 1.0),
        -5e-324,
        "div(-5e-324, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, -1.0),
        -5e-324,
        "div(5e-324, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, 1.0),
        5e-324,
        "div(5e-324, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, -6.283185307179586),
        0.0,
        "div(-5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, 6.283185307179586),
        -0.0,
        "div(-5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, -6.283185307179586),
        -0.0,
        "div(5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, 6.283185307179586),
        0.0,
        "div(5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, -1.7976931348623157e+308),
        0.0,
        "div(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, 1.7976931348623157e+308),
        -0.0,
        "div(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, -1.7976931348623157e+308),
        -0.0,
        "div(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, 1.7976931348623157e+308),
        0.0,
        "div(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, -INFINITY),
        0.0,
        "div(-5e-324, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -5e-324, INFINITY),
        -0.0,
        "div(-5e-324, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, -INFINITY),
        -0.0,
        "div(5e-324, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 5e-324, INFINITY),
        0.0,
        "div(5e-324, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, -0.0),
        INFINITY,
        "div(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, 0.0),
        -INFINITY,
        "div(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, -0.0),
        -INFINITY,
        "div(2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, 0.0),
        INFINITY,
        "div(2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, -5e-324),
        4503599627370496.0,
        "div(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, 5e-324),
        -4503599627370496.0,
        "div(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, -5e-324),
        -4503599627370496.0,
        "div(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, 5e-324),
        4503599627370496.0,
        "div(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        1.0,
        "div(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        -1.0,
        "div(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        -1.0,
        "div(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        1.0,
        "div(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, -0.5),
        4.450147717014403e-308,
        "div(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, 0.5),
        -4.450147717014403e-308,
        "div(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, -0.5),
        -4.450147717014403e-308,
        "div(2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, 0.5),
        4.450147717014403e-308,
        "div(2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, -1.0),
        2.2250738585072014e-308,
        "div(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, 1.0),
        -2.2250738585072014e-308,
        "div(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, -1.0),
        -2.2250738585072014e-308,
        "div(2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, 1.0),
        2.2250738585072014e-308,
        "div(2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, -6.283185307179586),
        3.541315033259774e-309,
        "div(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, 6.283185307179586),
        -3.541315033259774e-309,
        "div(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, -6.283185307179586),
        -3.541315033259774e-309,
        "div(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, 6.283185307179586),
        3.541315033259774e-309,
        "div(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        0.0,
        "div(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        -0.0,
        "div(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        -0.0,
        "div(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        0.0,
        "div(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, -INFINITY),
        0.0,
        "div(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -2.2250738585072014e-308, INFINITY),
        -0.0,
        "div(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, -INFINITY),
        -0.0,
        "div(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 2.2250738585072014e-308, INFINITY),
        0.0,
        "div(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, -0.0),
        INFINITY,
        "div(-0.5, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, 0.0),
        -INFINITY,
        "div(-0.5, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, -0.0),
        -INFINITY,
        "div(0.5, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, 0.0),
        INFINITY,
        "div(0.5, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, -5e-324),
        INFINITY,
        "div(-0.5, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, 5e-324),
        -INFINITY,
        "div(-0.5, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, -5e-324),
        -INFINITY,
        "div(0.5, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, 5e-324),
        INFINITY,
        "div(0.5, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, -2.2250738585072014e-308),
        2.247116418577895e+307,
        "div(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, 2.2250738585072014e-308),
        -2.247116418577895e+307,
        "div(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, -2.2250738585072014e-308),
        -2.247116418577895e+307,
        "div(0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, 2.2250738585072014e-308),
        2.247116418577895e+307,
        "div(0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, -0.5),
        1.0,
        "div(-0.5, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, 0.5),
        -1.0,
        "div(-0.5, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, -0.5),
        -1.0,
        "div(0.5, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, 0.5),
        1.0,
        "div(0.5, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, -1.0),
        0.5,
        "div(-0.5, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, 1.0),
        -0.5,
        "div(-0.5, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, -1.0),
        -0.5,
        "div(0.5, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, 1.0),
        0.5,
        "div(0.5, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, -6.283185307179586),
        0.07957747154594767,
        "div(-0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, 6.283185307179586),
        -0.07957747154594767,
        "div(-0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, -6.283185307179586),
        -0.07957747154594767,
        "div(0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, 6.283185307179586),
        0.07957747154594767,
        "div(0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, -1.7976931348623157e+308),
        2.781342323134e-309,
        "div(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, 1.7976931348623157e+308),
        -2.781342323134e-309,
        "div(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, -1.7976931348623157e+308),
        -2.781342323134e-309,
        "div(0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, 1.7976931348623157e+308),
        2.781342323134e-309,
        "div(0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, -INFINITY),
        0.0,
        "div(-0.5, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -0.5, INFINITY),
        -0.0,
        "div(-0.5, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, -INFINITY),
        -0.0,
        "div(0.5, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 0.5, INFINITY),
        0.0,
        "div(0.5, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, -0.0),
        INFINITY,
        "div(-1.0, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, 0.0),
        -INFINITY,
        "div(-1.0, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, -0.0),
        -INFINITY,
        "div(1.0, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, 0.0),
        INFINITY,
        "div(1.0, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, -5e-324),
        INFINITY,
        "div(-1.0, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, 5e-324),
        -INFINITY,
        "div(-1.0, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, -5e-324),
        -INFINITY,
        "div(1.0, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, 5e-324),
        INFINITY,
        "div(1.0, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, -2.2250738585072014e-308),
        4.49423283715579e+307,
        "div(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, 2.2250738585072014e-308),
        -4.49423283715579e+307,
        "div(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, -2.2250738585072014e-308),
        -4.49423283715579e+307,
        "div(1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, 2.2250738585072014e-308),
        4.49423283715579e+307,
        "div(1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, -0.5),
        2.0,
        "div(-1.0, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, 0.5),
        -2.0,
        "div(-1.0, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, -0.5),
        -2.0,
        "div(1.0, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, 0.5),
        2.0,
        "div(1.0, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, -1.0),
        1.0,
        "div(-1.0, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, 1.0),
        -1.0,
        "div(-1.0, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, -1.0),
        -1.0,
        "div(1.0, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, 1.0),
        1.0,
        "div(1.0, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, -6.283185307179586),
        0.15915494309189535,
        "div(-1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, 6.283185307179586),
        -0.15915494309189535,
        "div(-1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, -6.283185307179586),
        -0.15915494309189535,
        "div(1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, 6.283185307179586),
        0.15915494309189535,
        "div(1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, -1.7976931348623157e+308),
        5.562684646268003e-309,
        "div(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, 1.7976931348623157e+308),
        -5.562684646268003e-309,
        "div(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, -1.7976931348623157e+308),
        -5.562684646268003e-309,
        "div(1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, 1.7976931348623157e+308),
        5.562684646268003e-309,
        "div(1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, -INFINITY),
        0.0,
        "div(-1.0, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -1.0, INFINITY),
        -0.0,
        "div(-1.0, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, -INFINITY),
        -0.0,
        "div(1.0, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 1.0, INFINITY),
        0.0,
        "div(1.0, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, -0.0),
        INFINITY,
        "div(-6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, 0.0),
        -INFINITY,
        "div(-6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, -0.0),
        -INFINITY,
        "div(6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, 0.0),
        INFINITY,
        "div(6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, -5e-324),
        INFINITY,
        "div(-6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, 5e-324),
        -INFINITY,
        "div(-6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, -5e-324),
        -INFINITY,
        "div(6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, 5e-324),
        INFINITY,
        "div(6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, -2.2250738585072014e-308),
        INFINITY,
        "div(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, 2.2250738585072014e-308),
        -INFINITY,
        "div(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, -2.2250738585072014e-308),
        -INFINITY,
        "div(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, 2.2250738585072014e-308),
        INFINITY,
        "div(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, -0.5),
        12.566370614359172,
        "div(-6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, 0.5),
        -12.566370614359172,
        "div(-6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, -0.5),
        -12.566370614359172,
        "div(6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, 0.5),
        12.566370614359172,
        "div(6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, -1.0),
        6.283185307179586,
        "div(-6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, 1.0),
        -6.283185307179586,
        "div(-6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, -1.0),
        -6.283185307179586,
        "div(6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, 1.0),
        6.283185307179586,
        "div(6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, -6.283185307179586),
        1.0,
        "div(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, 6.283185307179586),
        -1.0,
        "div(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, -6.283185307179586),
        -1.0,
        "div(6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, 6.283185307179586),
        1.0,
        "div(6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, -1.7976931348623157e+308),
        3.49513784379046e-308,
        "div(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, 1.7976931348623157e+308),
        -3.49513784379046e-308,
        "div(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, -1.7976931348623157e+308),
        -3.49513784379046e-308,
        "div(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, 1.7976931348623157e+308),
        3.49513784379046e-308,
        "div(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, -INFINITY),
        0.0,
        "div(-6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -6.283185307179586, INFINITY),
        -0.0,
        "div(-6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, -INFINITY),
        -0.0,
        "div(6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 6.283185307179586, INFINITY),
        0.0,
        "div(6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, -0.0),
        INFINITY,
        "div(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, 0.0),
        -INFINITY,
        "div(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, -0.0),
        -INFINITY,
        "div(1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, 0.0),
        INFINITY,
        "div(1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, -5e-324),
        INFINITY,
        "div(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, 5e-324),
        -INFINITY,
        "div(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, -5e-324),
        -INFINITY,
        "div(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, 5e-324),
        INFINITY,
        "div(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        INFINITY,
        "div(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        -INFINITY,
        "div(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        -INFINITY,
        "div(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        INFINITY,
        "div(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, -0.5),
        INFINITY,
        "div(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, 0.5),
        -INFINITY,
        "div(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, -0.5),
        -INFINITY,
        "div(1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, 0.5),
        INFINITY,
        "div(1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, -1.0),
        1.7976931348623157e+308,
        "div(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, 1.0),
        -1.7976931348623157e+308,
        "div(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, -1.0),
        -1.7976931348623157e+308,
        "div(1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, 1.0),
        1.7976931348623157e+308,
        "div(1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, -6.283185307179586),
        2.861117485757028e+307,
        "div(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, 6.283185307179586),
        -2.861117485757028e+307,
        "div(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, -6.283185307179586),
        -2.861117485757028e+307,
        "div(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, 6.283185307179586),
        2.861117485757028e+307,
        "div(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        1.0,
        "div(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        -1.0,
        "div(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        -1.0,
        "div(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        1.0,
        "div(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, -INFINITY),
        0.0,
        "div(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -1.7976931348623157e+308, INFINITY),
        -0.0,
        "div(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, -INFINITY),
        -0.0,
        "div(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, 1.7976931348623157e+308, INFINITY),
        0.0,
        "div(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, -0.0),
        INFINITY,
        "div(-INFINITY, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, 0.0),
        -INFINITY,
        "div(-INFINITY, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, -0.0),
        -INFINITY,
        "div(INFINITY, -0.0)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, 0.0),
        INFINITY,
        "div(INFINITY, 0.0)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, -5e-324),
        INFINITY,
        "div(-INFINITY, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, 5e-324),
        -INFINITY,
        "div(-INFINITY, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, -5e-324),
        -INFINITY,
        "div(INFINITY, -5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, 5e-324),
        INFINITY,
        "div(INFINITY, 5e-324)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, -2.2250738585072014e-308),
        INFINITY,
        "div(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, 2.2250738585072014e-308),
        -INFINITY,
        "div(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, -2.2250738585072014e-308),
        -INFINITY,
        "div(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, 2.2250738585072014e-308),
        INFINITY,
        "div(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, -0.5),
        INFINITY,
        "div(-INFINITY, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, 0.5),
        -INFINITY,
        "div(-INFINITY, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, -0.5),
        -INFINITY,
        "div(INFINITY, -0.5)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, 0.5),
        INFINITY,
        "div(INFINITY, 0.5)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, -1.0),
        INFINITY,
        "div(-INFINITY, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, 1.0),
        -INFINITY,
        "div(-INFINITY, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, -1.0),
        -INFINITY,
        "div(INFINITY, -1.0)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, 1.0),
        INFINITY,
        "div(INFINITY, 1.0)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, -6.283185307179586),
        INFINITY,
        "div(-INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, 6.283185307179586),
        -INFINITY,
        "div(-INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, -6.283185307179586),
        -INFINITY,
        "div(INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, 6.283185307179586),
        INFINITY,
        "div(INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, -1.7976931348623157e+308),
        INFINITY,
        "div(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, -INFINITY, 1.7976931348623157e+308),
        -INFINITY,
        "div(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, -1.7976931348623157e+308),
        -INFINITY,
        "div(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_div(&instance, INFINITY, 1.7976931348623157e+308),
        INFINITY,
        "div(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, -0.0),
        -0.0,
        "min(-0.0, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, 0.0),
        -0.0,
        "min(-0.0, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, -0.0),
        -0.0,
        "min(0.0, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, 0.0),
        0.0,
        "min(0.0, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, -5e-324),
        -5e-324,
        "min(-0.0, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, 5e-324),
        -0.0,
        "min(-0.0, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, -5e-324),
        -5e-324,
        "min(0.0, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, 5e-324),
        0.0,
        "min(0.0, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "min(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, 2.2250738585072014e-308),
        -0.0,
        "min(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "min(0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, 2.2250738585072014e-308),
        0.0,
        "min(0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, -0.5),
        -0.5,
        "min(-0.0, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, 0.5),
        -0.0,
        "min(-0.0, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, -0.5),
        -0.5,
        "min(0.0, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, 0.5),
        0.0,
        "min(0.0, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, -1.0),
        -1.0,
        "min(-0.0, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, 1.0),
        -0.0,
        "min(-0.0, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, -1.0),
        -1.0,
        "min(0.0, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, 1.0),
        0.0,
        "min(0.0, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, -6.283185307179586),
        -6.283185307179586,
        "min(-0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, 6.283185307179586),
        -0.0,
        "min(-0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, -6.283185307179586),
        -6.283185307179586,
        "min(0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, 6.283185307179586),
        0.0,
        "min(0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, 1.7976931348623157e+308),
        -0.0,
        "min(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, 1.7976931348623157e+308),
        0.0,
        "min(0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, -INFINITY),
        -INFINITY,
        "min(-0.0, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -0.0, INFINITY),
        -0.0,
        "min(-0.0, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, -INFINITY),
        -INFINITY,
        "min(0.0, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 0.0, INFINITY),
        0.0,
        "min(0.0, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, -0.0),
        -5e-324,
        "min(-5e-324, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, 0.0),
        -5e-324,
        "min(-5e-324, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, -0.0),
        -0.0,
        "min(5e-324, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, 0.0),
        0.0,
        "min(5e-324, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, -5e-324),
        -5e-324,
        "min(-5e-324, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, 5e-324),
        -5e-324,
        "min(-5e-324, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, -5e-324),
        -5e-324,
        "min(5e-324, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, 5e-324),
        5e-324,
        "min(5e-324, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "min(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, 2.2250738585072014e-308),
        -5e-324,
        "min(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "min(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, 2.2250738585072014e-308),
        5e-324,
        "min(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, -0.5),
        -0.5,
        "min(-5e-324, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, 0.5),
        -5e-324,
        "min(-5e-324, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, -0.5),
        -0.5,
        "min(5e-324, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, 0.5),
        5e-324,
        "min(5e-324, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, -1.0),
        -1.0,
        "min(-5e-324, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, 1.0),
        -5e-324,
        "min(-5e-324, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, -1.0),
        -1.0,
        "min(5e-324, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, 1.0),
        5e-324,
        "min(5e-324, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, -6.283185307179586),
        -6.283185307179586,
        "min(-5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, 6.283185307179586),
        -5e-324,
        "min(-5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, -6.283185307179586),
        -6.283185307179586,
        "min(5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, 6.283185307179586),
        5e-324,
        "min(5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, 1.7976931348623157e+308),
        -5e-324,
        "min(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, 1.7976931348623157e+308),
        5e-324,
        "min(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, -INFINITY),
        -INFINITY,
        "min(-5e-324, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -5e-324, INFINITY),
        -5e-324,
        "min(-5e-324, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, -INFINITY),
        -INFINITY,
        "min(5e-324, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 5e-324, INFINITY),
        5e-324,
        "min(5e-324, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, -0.0),
        -2.2250738585072014e-308,
        "min(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, 0.0),
        -2.2250738585072014e-308,
        "min(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, -0.0),
        -0.0,
        "min(2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, 0.0),
        0.0,
        "min(2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, -5e-324),
        -2.2250738585072014e-308,
        "min(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, 5e-324),
        -2.2250738585072014e-308,
        "min(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, -5e-324),
        -5e-324,
        "min(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, 5e-324),
        5e-324,
        "min(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "min(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "min(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "min(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "min(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, -0.5),
        -0.5,
        "min(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, 0.5),
        -2.2250738585072014e-308,
        "min(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, -0.5),
        -0.5,
        "min(2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, 0.5),
        2.2250738585072014e-308,
        "min(2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, -1.0),
        -1.0,
        "min(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, 1.0),
        -2.2250738585072014e-308,
        "min(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, -1.0),
        -1.0,
        "min(2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, 1.0),
        2.2250738585072014e-308,
        "min(2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, -6.283185307179586),
        -6.283185307179586,
        "min(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, 6.283185307179586),
        -2.2250738585072014e-308,
        "min(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, -6.283185307179586),
        -6.283185307179586,
        "min(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, 6.283185307179586),
        2.2250738585072014e-308,
        "min(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        -2.2250738585072014e-308,
        "min(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        2.2250738585072014e-308,
        "min(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, -INFINITY),
        -INFINITY,
        "min(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -2.2250738585072014e-308, INFINITY),
        -2.2250738585072014e-308,
        "min(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, -INFINITY),
        -INFINITY,
        "min(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 2.2250738585072014e-308, INFINITY),
        2.2250738585072014e-308,
        "min(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, -0.0),
        -0.5,
        "min(-0.5, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, 0.0),
        -0.5,
        "min(-0.5, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, -0.0),
        -0.0,
        "min(0.5, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, 0.0),
        0.0,
        "min(0.5, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, -5e-324),
        -0.5,
        "min(-0.5, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, 5e-324),
        -0.5,
        "min(-0.5, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, -5e-324),
        -5e-324,
        "min(0.5, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, 5e-324),
        5e-324,
        "min(0.5, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, -2.2250738585072014e-308),
        -0.5,
        "min(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, 2.2250738585072014e-308),
        -0.5,
        "min(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "min(0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "min(0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, -0.5),
        -0.5,
        "min(-0.5, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, 0.5),
        -0.5,
        "min(-0.5, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, -0.5),
        -0.5,
        "min(0.5, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, 0.5),
        0.5,
        "min(0.5, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, -1.0),
        -1.0,
        "min(-0.5, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, 1.0),
        -0.5,
        "min(-0.5, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, -1.0),
        -1.0,
        "min(0.5, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, 1.0),
        0.5,
        "min(0.5, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, -6.283185307179586),
        -6.283185307179586,
        "min(-0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, 6.283185307179586),
        -0.5,
        "min(-0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, -6.283185307179586),
        -6.283185307179586,
        "min(0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, 6.283185307179586),
        0.5,
        "min(0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, 1.7976931348623157e+308),
        -0.5,
        "min(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, 1.7976931348623157e+308),
        0.5,
        "min(0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, -INFINITY),
        -INFINITY,
        "min(-0.5, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -0.5, INFINITY),
        -0.5,
        "min(-0.5, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, -INFINITY),
        -INFINITY,
        "min(0.5, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 0.5, INFINITY),
        0.5,
        "min(0.5, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, -0.0),
        -1.0,
        "min(-1.0, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, 0.0),
        -1.0,
        "min(-1.0, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, -0.0),
        -0.0,
        "min(1.0, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, 0.0),
        0.0,
        "min(1.0, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, -5e-324),
        -1.0,
        "min(-1.0, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, 5e-324),
        -1.0,
        "min(-1.0, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, -5e-324),
        -5e-324,
        "min(1.0, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, 5e-324),
        5e-324,
        "min(1.0, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, -2.2250738585072014e-308),
        -1.0,
        "min(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, 2.2250738585072014e-308),
        -1.0,
        "min(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "min(1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "min(1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, -0.5),
        -1.0,
        "min(-1.0, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, 0.5),
        -1.0,
        "min(-1.0, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, -0.5),
        -0.5,
        "min(1.0, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, 0.5),
        0.5,
        "min(1.0, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, -1.0),
        -1.0,
        "min(-1.0, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, 1.0),
        -1.0,
        "min(-1.0, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, -1.0),
        -1.0,
        "min(1.0, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, 1.0),
        1.0,
        "min(1.0, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, -6.283185307179586),
        -6.283185307179586,
        "min(-1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, 6.283185307179586),
        -1.0,
        "min(-1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, -6.283185307179586),
        -6.283185307179586,
        "min(1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, 6.283185307179586),
        1.0,
        "min(1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, 1.7976931348623157e+308),
        -1.0,
        "min(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, 1.7976931348623157e+308),
        1.0,
        "min(1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, -INFINITY),
        -INFINITY,
        "min(-1.0, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -1.0, INFINITY),
        -1.0,
        "min(-1.0, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, -INFINITY),
        -INFINITY,
        "min(1.0, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 1.0, INFINITY),
        1.0,
        "min(1.0, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, -0.0),
        -6.283185307179586,
        "min(-6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, 0.0),
        -6.283185307179586,
        "min(-6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, -0.0),
        -0.0,
        "min(6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, 0.0),
        0.0,
        "min(6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, -5e-324),
        -6.283185307179586,
        "min(-6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, 5e-324),
        -6.283185307179586,
        "min(-6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, -5e-324),
        -5e-324,
        "min(6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, 5e-324),
        5e-324,
        "min(6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, -2.2250738585072014e-308),
        -6.283185307179586,
        "min(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, 2.2250738585072014e-308),
        -6.283185307179586,
        "min(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "min(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "min(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, -0.5),
        -6.283185307179586,
        "min(-6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, 0.5),
        -6.283185307179586,
        "min(-6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, -0.5),
        -0.5,
        "min(6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, 0.5),
        0.5,
        "min(6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, -1.0),
        -6.283185307179586,
        "min(-6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, 1.0),
        -6.283185307179586,
        "min(-6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, -1.0),
        -1.0,
        "min(6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, 1.0),
        1.0,
        "min(6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, -6.283185307179586),
        -6.283185307179586,
        "min(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, 6.283185307179586),
        -6.283185307179586,
        "min(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, -6.283185307179586),
        -6.283185307179586,
        "min(6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, 6.283185307179586),
        6.283185307179586,
        "min(6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, 1.7976931348623157e+308),
        -6.283185307179586,
        "min(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, 1.7976931348623157e+308),
        6.283185307179586,
        "min(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, -INFINITY),
        -INFINITY,
        "min(-6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -6.283185307179586, INFINITY),
        -6.283185307179586,
        "min(-6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, -INFINITY),
        -INFINITY,
        "min(6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 6.283185307179586, INFINITY),
        6.283185307179586,
        "min(6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, -0.0),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, 0.0),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, -0.0),
        -0.0,
        "min(1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, 0.0),
        0.0,
        "min(1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, -5e-324),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, 5e-324),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, -5e-324),
        -5e-324,
        "min(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, 5e-324),
        5e-324,
        "min(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "min(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "min(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, -0.5),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, 0.5),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, -0.5),
        -0.5,
        "min(1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, 0.5),
        0.5,
        "min(1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, -1.0),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, 1.0),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, -1.0),
        -1.0,
        "min(1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, 1.0),
        1.0,
        "min(1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, -6.283185307179586),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, 6.283185307179586),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, -6.283185307179586),
        -6.283185307179586,
        "min(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, 6.283185307179586),
        6.283185307179586,
        "min(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "min(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, -INFINITY),
        -INFINITY,
        "min(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -1.7976931348623157e+308, INFINITY),
        -1.7976931348623157e+308,
        "min(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, -INFINITY),
        -INFINITY,
        "min(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, 1.7976931348623157e+308, INFINITY),
        1.7976931348623157e+308,
        "min(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, -0.0),
        -INFINITY,
        "min(-INFINITY, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, 0.0),
        -INFINITY,
        "min(-INFINITY, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, -0.0),
        -0.0,
        "min(INFINITY, -0.0)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, 0.0),
        0.0,
        "min(INFINITY, 0.0)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, -5e-324),
        -INFINITY,
        "min(-INFINITY, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, 5e-324),
        -INFINITY,
        "min(-INFINITY, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, -5e-324),
        -5e-324,
        "min(INFINITY, -5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, 5e-324),
        5e-324,
        "min(INFINITY, 5e-324)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, -2.2250738585072014e-308),
        -INFINITY,
        "min(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, 2.2250738585072014e-308),
        -INFINITY,
        "min(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "min(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "min(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, -0.5),
        -INFINITY,
        "min(-INFINITY, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, 0.5),
        -INFINITY,
        "min(-INFINITY, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, -0.5),
        -0.5,
        "min(INFINITY, -0.5)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, 0.5),
        0.5,
        "min(INFINITY, 0.5)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, -1.0),
        -INFINITY,
        "min(-INFINITY, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, 1.0),
        -INFINITY,
        "min(-INFINITY, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, -1.0),
        -1.0,
        "min(INFINITY, -1.0)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, 1.0),
        1.0,
        "min(INFINITY, 1.0)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, -6.283185307179586),
        -INFINITY,
        "min(-INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, 6.283185307179586),
        -INFINITY,
        "min(-INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, -6.283185307179586),
        -6.283185307179586,
        "min(INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, 6.283185307179586),
        6.283185307179586,
        "min(INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, -1.7976931348623157e+308),
        -INFINITY,
        "min(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, 1.7976931348623157e+308),
        -INFINITY,
        "min(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "min(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "min(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, -INFINITY),
        -INFINITY,
        "min(-INFINITY, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, -INFINITY, INFINITY),
        -INFINITY,
        "min(-INFINITY, INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, -INFINITY),
        -INFINITY,
        "min(INFINITY, -INFINITY)"
    );
    assertEqualF64(
        f640_min(&instance, INFINITY, INFINITY),
        INFINITY,
        "min(INFINITY, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, -0.0),
        -0.0,
        "max(-0.0, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, 0.0),
        0.0,
        "max(-0.0, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, -0.0),
        0.0,
        "max(0.0, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, 0.0),
        0.0,
        "max(0.0, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, -5e-324),
        -0.0,
        "max(-0.0, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, 5e-324),
        5e-324,
        "max(-0.0, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, -5e-324),
        0.0,
        "max(0.0, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, 5e-324),
        5e-324,
        "max(0.0, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, -2.2250738585072014e-308),
        -0.0,
        "max(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "max(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, -2.2250738585072014e-308),
        0.0,
        "max(0.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "max(0.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, -0.5),
        -0.0,
        "max(-0.0, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, 0.5),
        0.5,
        "max(-0.0, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, -0.5),
        0.0,
        "max(0.0, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, 0.5),
        0.5,
        "max(0.0, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, -1.0),
        -0.0,
        "max(-0.0, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, 1.0),
        1.0,
        "max(-0.0, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, -1.0),
        0.0,
        "max(0.0, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, 1.0),
        1.0,
        "max(0.0, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, -6.283185307179586),
        -0.0,
        "max(-0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, 6.283185307179586),
        6.283185307179586,
        "max(-0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, -6.283185307179586),
        0.0,
        "max(0.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, 6.283185307179586),
        6.283185307179586,
        "max(0.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, -1.7976931348623157e+308),
        -0.0,
        "max(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, -1.7976931348623157e+308),
        0.0,
        "max(0.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(0.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, -INFINITY),
        -0.0,
        "max(-0.0, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -0.0, INFINITY),
        INFINITY,
        "max(-0.0, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, -INFINITY),
        0.0,
        "max(0.0, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 0.0, INFINITY),
        INFINITY,
        "max(0.0, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, -0.0),
        -0.0,
        "max(-5e-324, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, 0.0),
        0.0,
        "max(-5e-324, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, -0.0),
        5e-324,
        "max(5e-324, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, 0.0),
        5e-324,
        "max(5e-324, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, -5e-324),
        -5e-324,
        "max(-5e-324, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, 5e-324),
        5e-324,
        "max(-5e-324, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, -5e-324),
        5e-324,
        "max(5e-324, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, 5e-324),
        5e-324,
        "max(5e-324, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, -2.2250738585072014e-308),
        -5e-324,
        "max(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "max(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, -2.2250738585072014e-308),
        5e-324,
        "max(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "max(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, -0.5),
        -5e-324,
        "max(-5e-324, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, 0.5),
        0.5,
        "max(-5e-324, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, -0.5),
        5e-324,
        "max(5e-324, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, 0.5),
        0.5,
        "max(5e-324, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, -1.0),
        -5e-324,
        "max(-5e-324, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, 1.0),
        1.0,
        "max(-5e-324, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, -1.0),
        5e-324,
        "max(5e-324, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, 1.0),
        1.0,
        "max(5e-324, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, -6.283185307179586),
        -5e-324,
        "max(-5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, 6.283185307179586),
        6.283185307179586,
        "max(-5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, -6.283185307179586),
        5e-324,
        "max(5e-324, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, 6.283185307179586),
        6.283185307179586,
        "max(5e-324, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, -1.7976931348623157e+308),
        -5e-324,
        "max(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, -1.7976931348623157e+308),
        5e-324,
        "max(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, -INFINITY),
        -5e-324,
        "max(-5e-324, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -5e-324, INFINITY),
        INFINITY,
        "max(-5e-324, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, -INFINITY),
        5e-324,
        "max(5e-324, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 5e-324, INFINITY),
        INFINITY,
        "max(5e-324, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, -0.0),
        -0.0,
        "max(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, 0.0),
        0.0,
        "max(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, -0.0),
        2.2250738585072014e-308,
        "max(2.2250738585072014e-308, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, 0.0),
        2.2250738585072014e-308,
        "max(2.2250738585072014e-308, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, -5e-324),
        -5e-324,
        "max(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, 5e-324),
        5e-324,
        "max(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, -5e-324),
        2.2250738585072014e-308,
        "max(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, 5e-324),
        2.2250738585072014e-308,
        "max(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "max(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "max(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308),
        2.2250738585072014e-308,
        "max(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "max(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, -0.5),
        -2.2250738585072014e-308,
        "max(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, 0.5),
        0.5,
        "max(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, -0.5),
        2.2250738585072014e-308,
        "max(2.2250738585072014e-308, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, 0.5),
        0.5,
        "max(2.2250738585072014e-308, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, -1.0),
        -2.2250738585072014e-308,
        "max(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, 1.0),
        1.0,
        "max(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, -1.0),
        2.2250738585072014e-308,
        "max(2.2250738585072014e-308, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, 1.0),
        1.0,
        "max(2.2250738585072014e-308, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, -6.283185307179586),
        -2.2250738585072014e-308,
        "max(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, 6.283185307179586),
        6.283185307179586,
        "max(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, -6.283185307179586),
        2.2250738585072014e-308,
        "max(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, 6.283185307179586),
        6.283185307179586,
        "max(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308),
        -2.2250738585072014e-308,
        "max(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308),
        2.2250738585072014e-308,
        "max(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, -INFINITY),
        -2.2250738585072014e-308,
        "max(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -2.2250738585072014e-308, INFINITY),
        INFINITY,
        "max(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, -INFINITY),
        2.2250738585072014e-308,
        "max(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 2.2250738585072014e-308, INFINITY),
        INFINITY,
        "max(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, -0.0),
        -0.0,
        "max(-0.5, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, 0.0),
        0.0,
        "max(-0.5, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, -0.0),
        0.5,
        "max(0.5, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, 0.0),
        0.5,
        "max(0.5, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, -5e-324),
        -5e-324,
        "max(-0.5, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, 5e-324),
        5e-324,
        "max(-0.5, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, -5e-324),
        0.5,
        "max(0.5, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, 5e-324),
        0.5,
        "max(0.5, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "max(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "max(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, -2.2250738585072014e-308),
        0.5,
        "max(0.5, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, 2.2250738585072014e-308),
        0.5,
        "max(0.5, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, -0.5),
        -0.5,
        "max(-0.5, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, 0.5),
        0.5,
        "max(-0.5, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, -0.5),
        0.5,
        "max(0.5, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, 0.5),
        0.5,
        "max(0.5, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, -1.0),
        -0.5,
        "max(-0.5, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, 1.0),
        1.0,
        "max(-0.5, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, -1.0),
        0.5,
        "max(0.5, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, 1.0),
        1.0,
        "max(0.5, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, -6.283185307179586),
        -0.5,
        "max(-0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, 6.283185307179586),
        6.283185307179586,
        "max(-0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, -6.283185307179586),
        0.5,
        "max(0.5, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, 6.283185307179586),
        6.283185307179586,
        "max(0.5, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, -1.7976931348623157e+308),
        -0.5,
        "max(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, -1.7976931348623157e+308),
        0.5,
        "max(0.5, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(0.5, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, -INFINITY),
        -0.5,
        "max(-0.5, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -0.5, INFINITY),
        INFINITY,
        "max(-0.5, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, -INFINITY),
        0.5,
        "max(0.5, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 0.5, INFINITY),
        INFINITY,
        "max(0.5, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, -0.0),
        -0.0,
        "max(-1.0, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, 0.0),
        0.0,
        "max(-1.0, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, -0.0),
        1.0,
        "max(1.0, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, 0.0),
        1.0,
        "max(1.0, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, -5e-324),
        -5e-324,
        "max(-1.0, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, 5e-324),
        5e-324,
        "max(-1.0, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, -5e-324),
        1.0,
        "max(1.0, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, 5e-324),
        1.0,
        "max(1.0, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "max(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "max(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, -2.2250738585072014e-308),
        1.0,
        "max(1.0, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, 2.2250738585072014e-308),
        1.0,
        "max(1.0, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, -0.5),
        -0.5,
        "max(-1.0, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, 0.5),
        0.5,
        "max(-1.0, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, -0.5),
        1.0,
        "max(1.0, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, 0.5),
        1.0,
        "max(1.0, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, -1.0),
        -1.0,
        "max(-1.0, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, 1.0),
        1.0,
        "max(-1.0, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, -1.0),
        1.0,
        "max(1.0, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, 1.0),
        1.0,
        "max(1.0, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, -6.283185307179586),
        -1.0,
        "max(-1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, 6.283185307179586),
        6.283185307179586,
        "max(-1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, -6.283185307179586),
        1.0,
        "max(1.0, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, 6.283185307179586),
        6.283185307179586,
        "max(1.0, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, -1.7976931348623157e+308),
        -1.0,
        "max(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, -1.7976931348623157e+308),
        1.0,
        "max(1.0, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(1.0, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, -INFINITY),
        -1.0,
        "max(-1.0, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -1.0, INFINITY),
        INFINITY,
        "max(-1.0, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, -INFINITY),
        1.0,
        "max(1.0, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 1.0, INFINITY),
        INFINITY,
        "max(1.0, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, -0.0),
        -0.0,
        "max(-6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, 0.0),
        0.0,
        "max(-6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, -0.0),
        6.283185307179586,
        "max(6.283185307179586, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, 0.0),
        6.283185307179586,
        "max(6.283185307179586, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, -5e-324),
        -5e-324,
        "max(-6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, 5e-324),
        5e-324,
        "max(-6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, -5e-324),
        6.283185307179586,
        "max(6.283185307179586, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, 5e-324),
        6.283185307179586,
        "max(6.283185307179586, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "max(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "max(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, -2.2250738585072014e-308),
        6.283185307179586,
        "max(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, 2.2250738585072014e-308),
        6.283185307179586,
        "max(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, -0.5),
        -0.5,
        "max(-6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, 0.5),
        0.5,
        "max(-6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, -0.5),
        6.283185307179586,
        "max(6.283185307179586, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, 0.5),
        6.283185307179586,
        "max(6.283185307179586, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, -1.0),
        -1.0,
        "max(-6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, 1.0),
        1.0,
        "max(-6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, -1.0),
        6.283185307179586,
        "max(6.283185307179586, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, 1.0),
        6.283185307179586,
        "max(6.283185307179586, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, -6.283185307179586),
        -6.283185307179586,
        "max(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, 6.283185307179586),
        6.283185307179586,
        "max(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, -6.283185307179586),
        6.283185307179586,
        "max(6.283185307179586, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, 6.283185307179586),
        6.283185307179586,
        "max(6.283185307179586, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, -1.7976931348623157e+308),
        -6.283185307179586,
        "max(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, -1.7976931348623157e+308),
        6.283185307179586,
        "max(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, -INFINITY),
        -6.283185307179586,
        "max(-6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -6.283185307179586, INFINITY),
        INFINITY,
        "max(-6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, -INFINITY),
        6.283185307179586,
        "max(6.283185307179586, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 6.283185307179586, INFINITY),
        INFINITY,
        "max(6.283185307179586, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, -0.0),
        -0.0,
        "max(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, 0.0),
        0.0,
        "max(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, -0.0),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, 0.0),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, -5e-324),
        -5e-324,
        "max(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, 5e-324),
        5e-324,
        "max(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, -5e-324),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, 5e-324),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "max(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "max(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, -0.5),
        -0.5,
        "max(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, 0.5),
        0.5,
        "max(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, -0.5),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, 0.5),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, -1.0),
        -1.0,
        "max(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, 1.0),
        1.0,
        "max(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, -1.0),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, 1.0),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, -6.283185307179586),
        -6.283185307179586,
        "max(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, 6.283185307179586),
        6.283185307179586,
        "max(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, -6.283185307179586),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, 6.283185307179586),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "max(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, -INFINITY),
        -1.7976931348623157e+308,
        "max(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -1.7976931348623157e+308, INFINITY),
        INFINITY,
        "max(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, -INFINITY),
        1.7976931348623157e+308,
        "max(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, 1.7976931348623157e+308, INFINITY),
        INFINITY,
        "max(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, -0.0),
        -0.0,
        "max(-INFINITY, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, 0.0),
        0.0,
        "max(-INFINITY, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, -0.0),
        INFINITY,
        "max(INFINITY, -0.0)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, 0.0),
        INFINITY,
        "max(INFINITY, 0.0)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, -5e-324),
        -5e-324,
        "max(-INFINITY, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, 5e-324),
        5e-324,
        "max(-INFINITY, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, -5e-324),
        INFINITY,
        "max(INFINITY, -5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, 5e-324),
        INFINITY,
        "max(INFINITY, 5e-324)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, -2.2250738585072014e-308),
        -2.2250738585072014e-308,
        "max(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, 2.2250738585072014e-308),
        2.2250738585072014e-308,
        "max(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, -2.2250738585072014e-308),
        INFINITY,
        "max(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, 2.2250738585072014e-308),
        INFINITY,
        "max(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, -0.5),
        -0.5,
        "max(-INFINITY, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, 0.5),
        0.5,
        "max(-INFINITY, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, -0.5),
        INFINITY,
        "max(INFINITY, -0.5)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, 0.5),
        INFINITY,
        "max(INFINITY, 0.5)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, -1.0),
        -1.0,
        "max(-INFINITY, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, 1.0),
        1.0,
        "max(-INFINITY, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, -1.0),
        INFINITY,
        "max(INFINITY, -1.0)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, 1.0),
        INFINITY,
        "max(INFINITY, 1.0)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, -6.283185307179586),
        -6.283185307179586,
        "max(-INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, 6.283185307179586),
        6.283185307179586,
        "max(-INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, -6.283185307179586),
        INFINITY,
        "max(INFINITY, -6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, 6.283185307179586),
        INFINITY,
        "max(INFINITY, 6.283185307179586)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "max(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "max(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, -1.7976931348623157e+308),
        INFINITY,
        "max(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, 1.7976931348623157e+308),
        INFINITY,
        "max(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, -INFINITY),
        -INFINITY,
        "max(-INFINITY, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, -INFINITY, INFINITY),
        INFINITY,
        "max(-INFINITY, INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, -INFINITY),
        INFINITY,
        "max(INFINITY, -INFINITY)"
    );
    assertEqualF64(
        f640_max(&instance, INFINITY, INFINITY),
        INFINITY,
        "max(INFINITY, INFINITY)"
    );
    assertEqualF64(
        f640_sqrt(&instance, -0.0),
        -0.0,
        "sqrt(-0.0)"
    );
    assertEqualF64(
        f640_sqrt(&instance, 0.0),
        0.0,
        "sqrt(0.0)"
    );
    assertEqualF64(
        f640_sqrt(&instance, 5e-324),
        2.2227587494850775e-162,
        "sqrt(5e-324)"
    );
    assertEqualF64(
        f640_sqrt(&instance, 2.2250738585072014e-308),
        1.4916681462400413e-154,
        "sqrt(2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_sqrt(&instance, 0.5),
        0.7071067811865476,
        "sqrt(0.5)"
    );
    assertEqualF64(
        f640_sqrt(&instance, 1.0),
        1.0,
        "sqrt(1.0)"
    );
    assertEqualF64(
        f640_sqrt(&instance, 6.283185307179586),
        2.5066282746310002,
        "sqrt(6.283185307179586)"
    );
    assertEqualF64(
        f640_sqrt(&instance, 1.7976931348623157e+308),
        1.3407807929942596e+154,
        "sqrt(1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_sqrt(&instance, INFINITY),
        INFINITY,
        "sqrt(INFINITY)"
    );
    assertEqualF64(
        f640_floor(&instance, -0.0),
        -0.0,
        "floor(-0.0)"
    );
    assertEqualF64(
        f640_floor(&instance, 0.0),
        0.0,
        "floor(0.0)"
    );
    assertEqualF64(
        f640_floor(&instance, -5e-324),
        -1.0,
        "floor(-5e-324)"
    );
    assertEqualF64(
        f640_floor(&instance, 5e-324),
        0.0,
        "floor(5e-324)"
    );
    assertEqualF64(
        f640_floor(&instance, -2.2250738585072014e-308),
        -1.0,
        "floor(-2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_floor(&instance, 2.2250738585072014e-308),
        0.0,
        "floor(2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_floor(&instance, -0.5),
        -1.0,
        "floor(-0.5)"
    );
    assertEqualF64(
        f640_floor(&instance, 0.5),
        0.0,
        "floor(0.5)"
    );
    assertEqualF64(
        f640_floor(&instance, -1.0),
        -1.0,
        "floor(-1.0)"
    );
    assertEqualF64(
        f640_floor(&instance, 1.0),
        1.0,
        "floor(1.0)"
    );
    assertEqualF64(
        f640_floor(&instance, -6.283185307179586),
        -7.0,
        "floor(-6.283185307179586)"
    );
    assertEqualF64(
        f640_floor(&instance, 6.283185307179586),
        6.0,
        "floor(6.283185307179586)"
    );
    assertEqualF64(
        f640_floor(&instance, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "floor(-1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_floor(&instance, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "floor(1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_floor(&instance, -INFINITY),
        -INFINITY,
        "floor(-INFINITY)"
    );
    assertEqualF64(
        f640_floor(&instance, INFINITY),
        INFINITY,
        "floor(INFINITY)"
    );
    assertEqualF64(
        f640_ceil(&instance, -0.0),
        -0.0,
        "ceil(-0.0)"
    );
    assertEqualF64(
        f640_ceil(&instance, 0.0),
        0.0,
        "ceil(0.0)"
    );
    assertEqualF64(
        f640_ceil(&instance, -5e-324),
        -0.0,
        "ceil(-5e-324)"
    );
    assertEqualF64(
        f640_ceil(&instance, 5e-324),
        1.0,
        "ceil(5e-324)"
    );
    assertEqualF64(
        f640_ceil(&instance, -2.2250738585072014e-308),
        -0.0,
        "ceil(-2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_ceil(&instance, 2.2250738585072014e-308),
        1.0,
        "ceil(2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_ceil(&instance, -0.5),
        -0.0,
        "ceil(-0.5)"
    );
    assertEqualF64(
        f640_ceil(&instance, 0.5),
        1.0,
        "ceil(0.5)"
    );
    assertEqualF64(
        f640_ceil(&instance, -1.0),
        -1.0,
        "ceil(-1.0)"
    );
    assertEqualF64(
        f640_ceil(&instance, 1.0),
        1.0,
        "ceil(1.0)"
    );
    assertEqualF64(
        f640_ceil(&instance, -6.283185307179586),
        -6.0,
        "ceil(-6.283185307179586)"
    );
    assertEqualF64(
        f640_ceil(&instance, 6.283185307179586),
        7.0,
        "ceil(6.283185307179586)"
    );
    assertEqualF64(
        f640_ceil(&instance, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "ceil(-1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_ceil(&instance, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "ceil(1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_ceil(&instance, -INFINITY),
        -INFINITY,
        "ceil(-INFINITY)"
    );
    assertEqualF64(
        f640_ceil(&instance, INFINITY),
        INFINITY,
        "ceil(INFINITY)"
    );
    assertEqualF64(
        f640_trunc(&instance, -0.0),
        -0.0,
        "trunc(-0.0)"
    );
    assertEqualF64(
        f640_trunc(&instance, 0.0),
        0.0,
        "trunc(0.0)"
    );
    assertEqualF64(
        f640_trunc(&instance, -5e-324),
        -0.0,
        "trunc(-5e-324)"
    );
    assertEqualF64(
        f640_trunc(&instance, 5e-324),
        0.0,
        "trunc(5e-324)"
    );
    assertEqualF64(
        f640_trunc(&instance, -2.2250738585072014e-308),
        -0.0,
        "trunc(-2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_trunc(&instance, 2.2250738585072014e-308),
        0.0,
        "trunc(2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_trunc(&instance, -0.5),
        -0.0,
        "trunc(-0.5)"
    );
    assertEqualF64(
        f640_trunc(&instance, 0.5),
        0.0,
        "trunc(0.5)"
    );
    assertEqualF64(
        f640_trunc(&instance, -1.0),
        -1.0,
        "trunc(-1.0)"
    );
    assertEqualF64(
        f640_trunc(&instance, 1.0),
        1.0,
        "trunc(1.0)"
    );
    assertEqualF64(
        f640_trunc(&instance, -6.283185307179586),
        -6.0,
        "trunc(-6.283185307179586)"
    );
    assertEqualF64(
        f640_trunc(&instance, 6.283185307179586),
        6.0,
        "trunc(6.283185307179586)"
    );
    assertEqualF64(
        f640_trunc(&instance, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "trunc(-1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_trunc(&instance, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "trunc(1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_trunc(&instance, -INFINITY),
        -INFINITY,
        "trunc(-INFINITY)"
    );
    assertEqualF64(
        f640_trunc(&instance, INFINITY),
        INFINITY,
        "trunc(INFINITY)"
    );
    assertEqualF64(
        f640_nearest(&instance, -0.0),
        -0.0,
        "nearest(-0.0)"
    );
    assertEqualF64(
        f640_nearest(&instance, 0.0),
        0.0,
        "nearest(0.0)"
    );
    assertEqualF64(
        f640_nearest(&instance, -5e-324),
        -0.0,
        "nearest(-5e-324)"
    );
    assertEqualF64(
        f640_nearest(&instance, 5e-324),
        0.0,
        "nearest(5e-324)"
    );
    assertEqualF64(
        f640_nearest(&instance, -2.2250738585072014e-308),
        -0.0,
        "nearest(-2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_nearest(&instance, 2.2250738585072014e-308),
        0.0,
        "nearest(2.2250738585072014e-308)"
    );
    assertEqualF64(
        f640_nearest(&instance, -0.5),
        -0.0,
        "nearest(-0.5)"
    );
    assertEqualF64(
        f640_nearest(&instance, 0.5),
        0.0,
        "nearest(0.5)"
    );
    assertEqualF64(
        f640_nearest(&instance, -1.0),
        -1.0,
        "nearest(-1.0)"
    );
    assertEqualF64(
        f640_nearest(&instance, 1.0),
        1.0,
        "nearest(1.0)"
    );
    assertEqualF64(
        f640_nearest(&instance, -6.283185307179586),
        -6.0,
        "nearest(-6.283185307179586)"
    );
    assertEqualF64(
        f640_nearest(&instance, 6.283185307179586),
        6.0,
        "nearest(6.283185307179586)"
    );
    assertEqualF64(
        f640_nearest(&instance, -1.7976931348623157e+308),
        -1.7976931348623157e+308,
        "nearest(-1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_nearest(&instance, 1.7976931348623157e+308),
        1.7976931348623157e+308,
        "nearest(1.7976931348623157e+308)"
    );
    assertEqualF64(
        f640_nearest(&instance, -INFINITY),
        -INFINITY,
        "nearest(-INFINITY)"
    );
    assertEqualF64(
        f640_nearest(&instance, INFINITY),
        INFINITY,
        "nearest(INFINITY)"
    );
}
