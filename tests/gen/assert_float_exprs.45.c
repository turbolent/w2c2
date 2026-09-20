
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.45.h"

void test() {
    m14_floatX5FexprsX2E45Instance instance;
    m14_floatX5FexprsX2E45Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.45.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FltX5Fselect(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))),
        2143289344u,
        "f32.no_fold_lt_select(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FltX5Fselect(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)),
        0u,
        "f32.no_fold_lt_select(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FltX5Fselect(&instance, 0.0, -0.0)),
        2147483648u,
        "f32.no_fold_lt_select(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FltX5Fselect(&instance, -0.0, 0.0)),
        0u,
        "f32.no_fold_lt_select(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FleX5Fselect(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))),
        2143289344u,
        "f32.no_fold_le_select(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FleX5Fselect(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)),
        0u,
        "f32.no_fold_le_select(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FleX5Fselect(&instance, 0.0, -0.0)),
        0u,
        "f32.no_fold_le_select(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FleX5Fselect(&instance, -0.0, 0.0)),
        2147483648u,
        "f32.no_fold_le_select(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FgtX5Fselect(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))),
        2143289344u,
        "f32.no_fold_gt_select(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FgtX5Fselect(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)),
        0u,
        "f32.no_fold_gt_select(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FgtX5Fselect(&instance, 0.0, -0.0)),
        2147483648u,
        "f32.no_fold_gt_select(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FgtX5Fselect(&instance, -0.0, 0.0)),
        0u,
        "f32.no_fold_gt_select(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FgeX5Fselect(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))),
        2143289344u,
        "f32.no_fold_ge_select(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FgeX5Fselect(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)),
        0u,
        "f32.no_fold_ge_select(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FgeX5Fselect(&instance, 0.0, -0.0)),
        0u,
        "f32.no_fold_ge_select(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E45Export21_f32X2EnoX5FfoldX5FgeX5Fselect(&instance, -0.0, 0.0)),
        2147483648u,
        "f32.no_fold_ge_select(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FltX5Fselect(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9221120237041090560ull,
        "f64.no_fold_lt_select(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FltX5Fselect(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)),
        0ull,
        "f64.no_fold_lt_select(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FltX5Fselect(&instance, 0.0, -0.0)),
        9223372036854775808ull,
        "f64.no_fold_lt_select(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FltX5Fselect(&instance, -0.0, 0.0)),
        0ull,
        "f64.no_fold_lt_select(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FleX5Fselect(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9221120237041090560ull,
        "f64.no_fold_le_select(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FleX5Fselect(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)),
        0ull,
        "f64.no_fold_le_select(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FleX5Fselect(&instance, 0.0, -0.0)),
        0ull,
        "f64.no_fold_le_select(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FleX5Fselect(&instance, -0.0, 0.0)),
        9223372036854775808ull,
        "f64.no_fold_le_select(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FgtX5Fselect(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9221120237041090560ull,
        "f64.no_fold_gt_select(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FgtX5Fselect(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)),
        0ull,
        "f64.no_fold_gt_select(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FgtX5Fselect(&instance, 0.0, -0.0)),
        9223372036854775808ull,
        "f64.no_fold_gt_select(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FgtX5Fselect(&instance, -0.0, 0.0)),
        0ull,
        "f64.no_fold_gt_select(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FgeX5Fselect(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9221120237041090560ull,
        "f64.no_fold_ge_select(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FgeX5Fselect(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)),
        0ull,
        "f64.no_fold_ge_select(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FgeX5Fselect(&instance, 0.0, -0.0)),
        0ull,
        "f64.no_fold_ge_select(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E45Export21_f64X2EnoX5FfoldX5FgeX5Fselect(&instance, -0.0, 0.0)),
        9223372036854775808ull,
        "f64.no_fold_ge_select(-0.0, 0.0)"
    );
}
