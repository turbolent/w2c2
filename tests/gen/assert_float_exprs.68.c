
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.68.h"

void test() {
    m14_floatX5FexprsX2E68Instance instance;
    m14_floatX5FexprsX2E68Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.68.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E68Export19_f32X2EnoX5FfoldX5FaddX5Fneg(&instance, 0.0)),
        0u,
        "f32.no_fold_add_neg(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E68Export19_f32X2EnoX5FfoldX5FaddX5Fneg(&instance, -0.0)),
        0u,
        "f32.no_fold_add_neg(-0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E68Export19_f32X2EnoX5FfoldX5FaddX5Fneg(&instance, INFINITY)) & 2147483647u),
        2143289344u,
        "f32.no_fold_add_neg(INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E68Export19_f32X2EnoX5FfoldX5FaddX5Fneg(&instance, -INFINITY)) & 2147483647u),
        2143289344u,
        "f32.no_fold_add_neg(-INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E68Export19_f64X2EnoX5FfoldX5FaddX5Fneg(&instance, 0.0)),
        0ull,
        "f64.no_fold_add_neg(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E68Export19_f64X2EnoX5FfoldX5FaddX5Fneg(&instance, -0.0)),
        0ull,
        "f64.no_fold_add_neg(-0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E68Export19_f64X2EnoX5FfoldX5FaddX5Fneg(&instance, INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_add_neg(INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E68Export19_f64X2EnoX5FfoldX5FaddX5Fneg(&instance, -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_add_neg(-INFINITY)"
    );
}
