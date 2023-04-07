
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.76.h"

void test() {
    floatexprs76Instance instance;
    floatexprs76Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.76.wasm");
    assertEqualU32(
        floatexprs76_f32X2Erecoding_eq(&instance, -INFINITY, 3.0),
        1u,
        "f32.recoding_eq(-INFINITY, 3.0)"
    );
    assertEqualU32(
        floatexprs76_f32X2Erecoding_le(&instance, -INFINITY, 3.0),
        1u,
        "f32.recoding_le(-INFINITY, 3.0)"
    );
    assertEqualU32(
        floatexprs76_f32X2Erecoding_lt(&instance, -INFINITY, 3.0),
        0u,
        "f32.recoding_lt(-INFINITY, 3.0)"
    );
    assertEqualU32(
        floatexprs76_f32X2Erecoding_eq(&instance, 0.0, 1.0),
        1u,
        "f32.recoding_eq(0.0, 1.0)"
    );
    assertEqualU32(
        floatexprs76_f32X2Erecoding_le(&instance, 0.0, 1.0),
        1u,
        "f32.recoding_le(0.0, 1.0)"
    );
    assertEqualU32(
        floatexprs76_f32X2Erecoding_lt(&instance, 0.0, 1.0),
        0u,
        "f32.recoding_lt(0.0, 1.0)"
    );
    assertEqualU32(
        floatexprs76_f64X2Erecoding_eq(&instance, -INFINITY, 3.0),
        1u,
        "f64.recoding_eq(-INFINITY, 3.0)"
    );
    assertEqualU32(
        floatexprs76_f64X2Erecoding_le(&instance, -INFINITY, 3.0),
        1u,
        "f64.recoding_le(-INFINITY, 3.0)"
    );
    assertEqualU32(
        floatexprs76_f64X2Erecoding_lt(&instance, -INFINITY, 3.0),
        0u,
        "f64.recoding_lt(-INFINITY, 3.0)"
    );
    assertEqualU32(
        floatexprs76_f64X2Erecoding_eq(&instance, 0.0, 1.0),
        1u,
        "f64.recoding_eq(0.0, 1.0)"
    );
    assertEqualU32(
        floatexprs76_f64X2Erecoding_le(&instance, 0.0, 1.0),
        1u,
        "f64.recoding_le(0.0, 1.0)"
    );
    assertEqualU32(
        floatexprs76_f64X2Erecoding_lt(&instance, 0.0, 1.0),
        0u,
        "f64.recoding_lt(0.0, 1.0)"
    );
    assertEqualF32(
        floatexprs76_recoding_demote(&instance, 2.3860049081905093e-40, 1221.0),
        2.913312062965535e-37,
        "recoding_demote(2.3860049081905093e-40, 1221.0)"
    );
}
