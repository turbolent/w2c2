
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.13.h"

void test() {
    m14_floatX5FexprsX2E13Instance instance;
    m14_floatX5FexprsX2E13Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.13.wasm");
    assertEqualU32(
        m14_floatX5FexprsX2E13Export19_f32X2EnoX5FfoldX5FneX5Fself(&instance, f32_reinterpret_i32(0x7fc00000u)),
        1u,
        "f32.no_fold_ne_self(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E13Export19_f64X2EnoX5FfoldX5FneX5Fself(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)),
        1u,
        "f64.no_fold_ne_self(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
}
