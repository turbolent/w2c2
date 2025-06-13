
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.44.h"

void test() {
    floatexprs44Instance instance;
    floatexprs44Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.44.wasm");
    assertEqualU32(
        floatexprs44_f32X2Eult(&instance, 3.0, 2.0),
        0u,
        "f32.ult(3.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f32X2Eult(&instance, 2.0, 2.0),
        0u,
        "f32.ult(2.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f32X2Eult(&instance, 2.0, 3.0),
        1u,
        "f32.ult(2.0, 3.0)"
    );
    assertEqualU32(
        floatexprs44_f32X2Eule(&instance, 3.0, 2.0),
        0u,
        "f32.ule(3.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f32X2Eule(&instance, 2.0, 2.0),
        1u,
        "f32.ule(2.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f32X2Eule(&instance, 2.0, 3.0),
        1u,
        "f32.ule(2.0, 3.0)"
    );
    assertEqualU32(
        floatexprs44_f32X2Eugt(&instance, 3.0, 2.0),
        1u,
        "f32.ugt(3.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f32X2Eugt(&instance, 2.0, 2.0),
        0u,
        "f32.ugt(2.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f32X2Eugt(&instance, 2.0, 3.0),
        0u,
        "f32.ugt(2.0, 3.0)"
    );
    assertEqualU32(
        floatexprs44_f32X2Euge(&instance, 3.0, 2.0),
        1u,
        "f32.uge(3.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f32X2Euge(&instance, 2.0, 2.0),
        1u,
        "f32.uge(2.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f32X2Euge(&instance, 2.0, 3.0),
        0u,
        "f32.uge(2.0, 3.0)"
    );
    assertEqualU32(
        floatexprs44_f64X2Eult(&instance, 3.0, 2.0),
        0u,
        "f64.ult(3.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f64X2Eult(&instance, 2.0, 2.0),
        0u,
        "f64.ult(2.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f64X2Eult(&instance, 2.0, 3.0),
        1u,
        "f64.ult(2.0, 3.0)"
    );
    assertEqualU32(
        floatexprs44_f64X2Eule(&instance, 3.0, 2.0),
        0u,
        "f64.ule(3.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f64X2Eule(&instance, 2.0, 2.0),
        1u,
        "f64.ule(2.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f64X2Eule(&instance, 2.0, 3.0),
        1u,
        "f64.ule(2.0, 3.0)"
    );
    assertEqualU32(
        floatexprs44_f64X2Eugt(&instance, 3.0, 2.0),
        1u,
        "f64.ugt(3.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f64X2Eugt(&instance, 2.0, 2.0),
        0u,
        "f64.ugt(2.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f64X2Eugt(&instance, 2.0, 3.0),
        0u,
        "f64.ugt(2.0, 3.0)"
    );
    assertEqualU32(
        floatexprs44_f64X2Euge(&instance, 3.0, 2.0),
        1u,
        "f64.uge(3.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f64X2Euge(&instance, 2.0, 2.0),
        1u,
        "f64.uge(2.0, 2.0)"
    );
    assertEqualU32(
        floatexprs44_f64X2Euge(&instance, 2.0, 3.0),
        0u,
        "f64.uge(2.0, 3.0)"
    );
}
