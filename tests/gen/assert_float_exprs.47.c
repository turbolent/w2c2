
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.47.h"

void test() {
    m14_floatX5FexprsX2E47Instance instance;
    m14_floatX5FexprsX2E47Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.47.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FltX5FselectX5FtoX5Fabs(&instance, f32_reinterpret_i32(0x7fa00000u))),
        2141192192u,
        "f32.no_fold_lt_select_to_abs(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FltX5FselectX5FtoX5Fabs(&instance, f32_reinterpret_i32(0xffc00000u))),
        4290772992u,
        "f32.no_fold_lt_select_to_abs(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FltX5FselectX5FtoX5Fabs(&instance, 0.0)),
        0u,
        "f32.no_fold_lt_select_to_abs(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FltX5FselectX5FtoX5Fabs(&instance, -0.0)),
        2147483648u,
        "f32.no_fold_lt_select_to_abs(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FleX5FselectX5FtoX5Fabs(&instance, f32_reinterpret_i32(0x7fa00000u))),
        2141192192u,
        "f32.no_fold_le_select_to_abs(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FleX5FselectX5FtoX5Fabs(&instance, f32_reinterpret_i32(0xffc00000u))),
        4290772992u,
        "f32.no_fold_le_select_to_abs(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FleX5FselectX5FtoX5Fabs(&instance, 0.0)),
        2147483648u,
        "f32.no_fold_le_select_to_abs(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FleX5FselectX5FtoX5Fabs(&instance, -0.0)),
        0u,
        "f32.no_fold_le_select_to_abs(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FgtX5FselectX5FtoX5Fabs(&instance, f32_reinterpret_i32(0x7fa00000u))),
        4288675840u,
        "f32.no_fold_gt_select_to_abs(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FgtX5FselectX5FtoX5Fabs(&instance, f32_reinterpret_i32(0xffc00000u))),
        2143289344u,
        "f32.no_fold_gt_select_to_abs(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FgtX5FselectX5FtoX5Fabs(&instance, 0.0)),
        2147483648u,
        "f32.no_fold_gt_select_to_abs(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FgtX5FselectX5FtoX5Fabs(&instance, -0.0)),
        0u,
        "f32.no_fold_gt_select_to_abs(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FgeX5FselectX5FtoX5Fabs(&instance, f32_reinterpret_i32(0x7fa00000u))),
        4288675840u,
        "f32.no_fold_ge_select_to_abs(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FgeX5FselectX5FtoX5Fabs(&instance, f32_reinterpret_i32(0xffc00000u))),
        2143289344u,
        "f32.no_fold_ge_select_to_abs(f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FgeX5FselectX5FtoX5Fabs(&instance, 0.0)),
        0u,
        "f32.no_fold_ge_select_to_abs(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FgeX5FselectX5FtoX5Fabs(&instance, -0.0)),
        2147483648u,
        "f32.no_fold_ge_select_to_abs(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FltX5FselectX5FtoX5Fabs(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))),
        9219994337134247936ull,
        "f64.no_fold_lt_select_to_abs(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FltX5FselectX5FtoX5Fabs(&instance, f64_reinterpret_i64(0xfff8000000000000ull))),
        18444492273895866368ull,
        "f64.no_fold_lt_select_to_abs(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FltX5FselectX5FtoX5Fabs(&instance, 0.0)),
        0ull,
        "f64.no_fold_lt_select_to_abs(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FltX5FselectX5FtoX5Fabs(&instance, -0.0)),
        9223372036854775808ull,
        "f64.no_fold_lt_select_to_abs(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FleX5FselectX5FtoX5Fabs(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))),
        9219994337134247936ull,
        "f64.no_fold_le_select_to_abs(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FleX5FselectX5FtoX5Fabs(&instance, f64_reinterpret_i64(0xfff8000000000000ull))),
        18444492273895866368ull,
        "f64.no_fold_le_select_to_abs(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FleX5FselectX5FtoX5Fabs(&instance, 0.0)),
        9223372036854775808ull,
        "f64.no_fold_le_select_to_abs(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FleX5FselectX5FtoX5Fabs(&instance, -0.0)),
        0ull,
        "f64.no_fold_le_select_to_abs(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FgtX5FselectX5FtoX5Fabs(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))),
        18443366373989023744ull,
        "f64.no_fold_gt_select_to_abs(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FgtX5FselectX5FtoX5Fabs(&instance, f64_reinterpret_i64(0xfff8000000000000ull))),
        9221120237041090560ull,
        "f64.no_fold_gt_select_to_abs(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FgtX5FselectX5FtoX5Fabs(&instance, 0.0)),
        9223372036854775808ull,
        "f64.no_fold_gt_select_to_abs(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FgtX5FselectX5FtoX5Fabs(&instance, -0.0)),
        0ull,
        "f64.no_fold_gt_select_to_abs(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FgeX5FselectX5FtoX5Fabs(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))),
        18443366373989023744ull,
        "f64.no_fold_ge_select_to_abs(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FgeX5FselectX5FtoX5Fabs(&instance, f64_reinterpret_i64(0xfff8000000000000ull))),
        9221120237041090560ull,
        "f64.no_fold_ge_select_to_abs(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FgeX5FselectX5FtoX5Fabs(&instance, 0.0)),
        0ull,
        "f64.no_fold_ge_select_to_abs(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FgeX5FselectX5FtoX5Fabs(&instance, -0.0)),
        9223372036854775808ull,
        "f64.no_fold_ge_select_to_abs(-0.0)"
    );
}
