
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.46.h"

void test() {
    m14_floatX5FexprsX2E46Instance instance;
    m14_floatX5FexprsX2E46Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.46.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FltX5Fif(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))),
        2143289344u,
        "f32.no_fold_lt_if(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FltX5Fif(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)),
        0u,
        "f32.no_fold_lt_if(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FltX5Fif(&instance, 0.0, -0.0)),
        2147483648u,
        "f32.no_fold_lt_if(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FltX5Fif(&instance, -0.0, 0.0)),
        0u,
        "f32.no_fold_lt_if(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FleX5Fif(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))),
        2143289344u,
        "f32.no_fold_le_if(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FleX5Fif(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)),
        0u,
        "f32.no_fold_le_if(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FleX5Fif(&instance, 0.0, -0.0)),
        0u,
        "f32.no_fold_le_if(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FleX5Fif(&instance, -0.0, 0.0)),
        2147483648u,
        "f32.no_fold_le_if(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FgtX5Fif(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))),
        2143289344u,
        "f32.no_fold_gt_if(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FgtX5Fif(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)),
        0u,
        "f32.no_fold_gt_if(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FgtX5Fif(&instance, 0.0, -0.0)),
        2147483648u,
        "f32.no_fold_gt_if(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FgtX5Fif(&instance, -0.0, 0.0)),
        0u,
        "f32.no_fold_gt_if(-0.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FgeX5Fif(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u))),
        2143289344u,
        "f32.no_fold_ge_if(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FgeX5Fif(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0)),
        0u,
        "f32.no_fold_ge_if(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FgeX5Fif(&instance, 0.0, -0.0)),
        0u,
        "f32.no_fold_ge_if(0.0, -0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FgeX5Fif(&instance, -0.0, 0.0)),
        2147483648u,
        "f32.no_fold_ge_if(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FltX5Fif(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9221120237041090560ull,
        "f64.no_fold_lt_if(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FltX5Fif(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)),
        0ull,
        "f64.no_fold_lt_if(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FltX5Fif(&instance, 0.0, -0.0)),
        9223372036854775808ull,
        "f64.no_fold_lt_if(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FltX5Fif(&instance, -0.0, 0.0)),
        0ull,
        "f64.no_fold_lt_if(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FleX5Fif(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9221120237041090560ull,
        "f64.no_fold_le_if(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FleX5Fif(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)),
        0ull,
        "f64.no_fold_le_if(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FleX5Fif(&instance, 0.0, -0.0)),
        0ull,
        "f64.no_fold_le_if(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FleX5Fif(&instance, -0.0, 0.0)),
        9223372036854775808ull,
        "f64.no_fold_le_if(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FgtX5Fif(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9221120237041090560ull,
        "f64.no_fold_gt_if(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FgtX5Fif(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)),
        0ull,
        "f64.no_fold_gt_if(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FgtX5Fif(&instance, 0.0, -0.0)),
        9223372036854775808ull,
        "f64.no_fold_gt_if(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FgtX5Fif(&instance, -0.0, 0.0)),
        0ull,
        "f64.no_fold_gt_if(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FgeX5Fif(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))),
        9221120237041090560ull,
        "f64.no_fold_ge_if(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FgeX5Fif(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)),
        0ull,
        "f64.no_fold_ge_if(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FgeX5Fif(&instance, 0.0, -0.0)),
        0ull,
        "f64.no_fold_ge_if(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FgeX5Fif(&instance, -0.0, 0.0)),
        9223372036854775808ull,
        "f64.no_fold_ge_if(-0.0, 0.0)"
    );
}
