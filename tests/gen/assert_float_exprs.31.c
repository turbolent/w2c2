
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.31.h"

void test() {
    m14_floatX5FexprsX2E31Instance instance;
    m14_floatX5FexprsX2E31Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.31.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E31Export19_f32X2EnoX5FfoldX5FsubX5Fadd(&instance, -676.474365234375, 403.03680419921875)),
        3291029085u,
        "f32.no_fold_sub_add(-676.474365234375, 403.03680419921875)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E31Export19_f32X2EnoX5FfoldX5FsubX5Fadd(&instance, -6.305943118406008e-34, 3.67186006875961e-29)),
        2287075328u,
        "f32.no_fold_sub_add(-6.305943118406008e-34, 3.67186006875961e-29)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E31Export19_f32X2EnoX5FfoldX5FsubX5Fadd(&instance, 83184800.0, 46216216576.0)),
        1285466624u,
        "f32.no_fold_sub_add(83184800.0, 46216216576.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E31Export19_f32X2EnoX5FfoldX5FsubX5Fadd(&instance, 2.211956963080186e-12, -1.0437929631734733e-08)),
        740007936u,
        "f32.no_fold_sub_add(2.211956963080186e-12, -1.0437929631734733e-08)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E31Export19_f32X2EnoX5FfoldX5FsubX5Fadd(&instance, 0.14944395422935486, -27393.650390625)),
        1041891328u,
        "f32.no_fold_sub_add(0.14944395422935486, -27393.650390625)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E31Export19_f64X2EnoX5FfoldX5FsubX5Fadd(&instance, 9.036598261794624e+76, -9.58186427535552e+77)),
        5758126085282503568ull,
        "f64.no_fold_sub_add(9.036598261794624e+76, -9.58186427535552e+77)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E31Export19_f64X2EnoX5FfoldX5FsubX5Fadd(&instance, 4.4230403564658815e-201, 2.6713491049366576e-195)),
        1609380455482130432ull,
        "f64.no_fold_sub_add(4.4230403564658815e-201, 2.6713491049366576e-195)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E31Export19_f64X2EnoX5FfoldX5FsubX5Fadd(&instance, 4.095348452776429e+75, -4.0501900195765687e+90)),
        5738148875223433216ull,
        "f64.no_fold_sub_add(4.095348452776429e+75, -4.0501900195765687e+90)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E31Export19_f64X2EnoX5FfoldX5FsubX5Fadd(&instance, 2.4008889207554433e-08, -0.00017253797929188484)),
        4492841470376837120ull,
        "f64.no_fold_sub_add(2.4008889207554433e-08, -0.00017253797929188484)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E31Export19_f64X2EnoX5FfoldX5FsubX5Fadd(&instance, 4.3367542918305866e-111, -3.9597706708227122e-109)),
        2955729038738127552ull,
        "f64.no_fold_sub_add(4.3367542918305866e-111, -3.9597706708227122e-109)"
    );
}
