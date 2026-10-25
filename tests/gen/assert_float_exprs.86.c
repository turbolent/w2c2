
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.86.h"

void test() {
    m14_floatX5FexprsX2E86Instance instance;
    m14_floatX5FexprsX2E86Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.86.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E86Export11_f32X2Eepsilon(&instance)),
        3019898880u,
        "f32.epsilon()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E86Export11_f64X2Eepsilon(&instance)),
        4372995238176751616ull,
        "f64.epsilon()"
    );
}
