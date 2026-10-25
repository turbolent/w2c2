
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.78.h"

void test() {
    m14_floatX5FexprsX2E78Instance instance;
    m14_floatX5FexprsX2E78Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.78.wasm");
    assertEqualU32(
        m14_floatX5FexprsX2E78Export15_f32X2ErecodingX5Feq(&instance, -INFINITY, 3.0),
        1u,
        "f32.recoding_eq(-INFINITY, 3.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E78Export15_f32X2ErecodingX5Fle(&instance, -INFINITY, 3.0),
        1u,
        "f32.recoding_le(-INFINITY, 3.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E78Export15_f32X2ErecodingX5Flt(&instance, -INFINITY, 3.0),
        0u,
        "f32.recoding_lt(-INFINITY, 3.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E78Export15_f32X2ErecodingX5Feq(&instance, 0.0, 1.0),
        1u,
        "f32.recoding_eq(0.0, 1.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E78Export15_f32X2ErecodingX5Fle(&instance, 0.0, 1.0),
        1u,
        "f32.recoding_le(0.0, 1.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E78Export15_f32X2ErecodingX5Flt(&instance, 0.0, 1.0),
        0u,
        "f32.recoding_lt(0.0, 1.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E78Export15_f64X2ErecodingX5Feq(&instance, -INFINITY, 3.0),
        1u,
        "f64.recoding_eq(-INFINITY, 3.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E78Export15_f64X2ErecodingX5Fle(&instance, -INFINITY, 3.0),
        1u,
        "f64.recoding_le(-INFINITY, 3.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E78Export15_f64X2ErecodingX5Flt(&instance, -INFINITY, 3.0),
        0u,
        "f64.recoding_lt(-INFINITY, 3.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E78Export15_f64X2ErecodingX5Feq(&instance, 0.0, 1.0),
        1u,
        "f64.recoding_eq(0.0, 1.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E78Export15_f64X2ErecodingX5Fle(&instance, 0.0, 1.0),
        1u,
        "f64.recoding_le(0.0, 1.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E78Export15_f64X2ErecodingX5Flt(&instance, 0.0, 1.0),
        0u,
        "f64.recoding_lt(0.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E78Export15_recodingX5Fdemote(&instance, 2.3860049081905093e-40, 1221.0)),
        46548238u,
        "recoding_demote(2.3860049081905093e-40, 1221.0)"
    );
}
