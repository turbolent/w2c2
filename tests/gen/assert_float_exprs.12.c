
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.12.h"

void test() {
    m14_floatX5FexprsX2E12Instance instance;
    m14_floatX5FexprsX2E12Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.12.wasm");
    assertEqualU32(
        m14_floatX5FexprsX2E12Export19_f32X2EnoX5FfoldX5FeqX5Fself(&instance, f32_reinterpret_i32(0x7fc00000u)),
        0u,
        "f32.no_fold_eq_self(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E12Export19_f64X2EnoX5FfoldX5FeqX5Fself(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)),
        0u,
        "f64.no_fold_eq_self(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
}
