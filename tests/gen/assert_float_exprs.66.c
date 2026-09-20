
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.66.h"

void test() {
    m14_floatX5FexprsX2E66Instance instance;
    m14_floatX5FexprsX2E66Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.66.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E66Export19_f32X2EnoX5FfoldX5FnegX5Fadd(&instance, -0.0, -0.0)),
        0u,
        "f32.no_fold_neg_add(-0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E66Export19_f32X2EnoX5FfoldX5FnegX5Fadd(&instance, 0.0, -0.0)),
        2147483648u,
        "f32.no_fold_neg_add(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E66Export19_f32X2EnoX5FfoldX5FnegX5Fadd(&instance, -0.0, 0.0)),
        2147483648u,
        "f32.no_fold_neg_add(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E66Export19_f32X2EnoX5FfoldX5FnegX5Fadd(&instance, 0.0, 0.0)),
        2147483648u,
        "f32.no_fold_neg_add(0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E66Export19_f64X2EnoX5FfoldX5FnegX5Fadd(&instance, -0.0, -0.0)),
        0ull,
        "f64.no_fold_neg_add(-0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E66Export19_f64X2EnoX5FfoldX5FnegX5Fadd(&instance, 0.0, -0.0)),
        9223372036854775808ull,
        "f64.no_fold_neg_add(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E66Export19_f64X2EnoX5FfoldX5FnegX5Fadd(&instance, -0.0, 0.0)),
        9223372036854775808ull,
        "f64.no_fold_neg_add(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E66Export19_f64X2EnoX5FfoldX5FnegX5Fadd(&instance, 0.0, 0.0)),
        9223372036854775808ull,
        "f64.no_fold_neg_add(0.0, 0.0)"
    );
}
