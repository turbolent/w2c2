
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.65.h"

void test() {
    m14_floatX5FexprsX2E65Instance instance;
    m14_floatX5FexprsX2E65Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.65.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E65Export19_f32X2EnoX5FfoldX5FnegX5Fsub(&instance, -0.0, -0.0)),
        2147483648u,
        "f32.no_fold_neg_sub(-0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E65Export19_f32X2EnoX5FfoldX5FnegX5Fsub(&instance, 0.0, -0.0)),
        2147483648u,
        "f32.no_fold_neg_sub(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E65Export19_f32X2EnoX5FfoldX5FnegX5Fsub(&instance, -0.0, 0.0)),
        0u,
        "f32.no_fold_neg_sub(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E65Export19_f32X2EnoX5FfoldX5FnegX5Fsub(&instance, 0.0, 0.0)),
        2147483648u,
        "f32.no_fold_neg_sub(0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E65Export19_f64X2EnoX5FfoldX5FnegX5Fsub(&instance, -0.0, -0.0)),
        9223372036854775808ull,
        "f64.no_fold_neg_sub(-0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E65Export19_f64X2EnoX5FfoldX5FnegX5Fsub(&instance, 0.0, -0.0)),
        9223372036854775808ull,
        "f64.no_fold_neg_sub(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E65Export19_f64X2EnoX5FfoldX5FnegX5Fsub(&instance, -0.0, 0.0)),
        0ull,
        "f64.no_fold_neg_sub(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E65Export19_f64X2EnoX5FfoldX5FnegX5Fsub(&instance, 0.0, 0.0)),
        9223372036854775808ull,
        "f64.no_fold_neg_sub(0.0, 0.0)"
    );
}
