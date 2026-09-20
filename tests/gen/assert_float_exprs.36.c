
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.36.h"

void test() {
    m14_floatX5FexprsX2E36Instance instance;
    m14_floatX5FexprsX2E36Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.36.wasm");
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "no_fold_promote_demote(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, 0.0)),
        0u,
        "no_fold_promote_demote(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, -0.0)),
        2147483648u,
        "no_fold_promote_demote(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, 1.401298464324817e-45)),
        1u,
        "no_fold_promote_demote(1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, -1.401298464324817e-45)),
        2147483649u,
        "no_fold_promote_demote(-1.401298464324817e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, 1.1754942106924411e-38)),
        8388607u,
        "no_fold_promote_demote(1.1754942106924411e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, -1.1754942106924411e-38)),
        2155872255u,
        "no_fold_promote_demote(-1.1754942106924411e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, 1.1754943508222875e-38)),
        8388608u,
        "no_fold_promote_demote(1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, -1.1754943508222875e-38)),
        2155872256u,
        "no_fold_promote_demote(-1.1754943508222875e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, 3.4028234663852886e+38)),
        2139095039u,
        "no_fold_promote_demote(3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, -3.4028234663852886e+38)),
        4286578687u,
        "no_fold_promote_demote(-3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, INFINITY)),
        2139095040u,
        "no_fold_promote_demote(INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E36Export22_noX5FfoldX5FpromoteX5Fdemote(&instance, -INFINITY)),
        4286578688u,
        "no_fold_promote_demote(-INFINITY)"
    );
}
