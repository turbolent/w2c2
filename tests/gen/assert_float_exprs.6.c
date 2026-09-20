
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.6.h"

void test() {
    m13_floatX5FexprsX2E6Instance instance;
    m13_floatX5FexprsX2E6Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.6.wasm");
    assertEqualU32(
        (i32_reinterpret_f32(m13_floatX5FexprsX2E6Export19_f32X2EnoX5FfoldX5FmulX5Fone(&instance, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "f32.no_fold_mul_one(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m13_floatX5FexprsX2E6Export19_f64X2EnoX5FfoldX5FmulX5Fone(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "f64.no_fold_mul_one(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
}
