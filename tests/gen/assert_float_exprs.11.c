
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.11.h"

void test() {
    m14_floatX5FexprsX2E11Instance instance;
    m14_floatX5FexprsX2E11Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.11.wasm");
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E11Export20_f32X2EnoX5FfoldX5Fneg1X5Fmul(&instance, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "f32.no_fold_neg1_mul(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E11Export20_f64X2EnoX5FfoldX5Fneg1X5Fmul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "f64.no_fold_neg1_mul(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
}
