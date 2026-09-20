
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.49.h"

void test() {
    m14_floatX5FexprsX2E49Instance instance;
    m14_floatX5FexprsX2E49Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.49.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E49Export24_f32X2EincorrectX5Fcorrection(&instance)),
        872415232u,
        "f32.incorrect_correction()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E49Export24_f64X2EincorrectX5Fcorrection(&instance)),
        13596367275031527424ull,
        "f64.incorrect_correction()"
    );
}
