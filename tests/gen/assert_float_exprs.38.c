
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.38.h"

void test() {
    m14_floatX5FexprsX2E38Instance instance;
    m14_floatX5FexprsX2E38Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.38.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E38Export19_noX5FdemoteX5FmixedX5Fsub(&instance, 7.869935327202668e+24, 4.0863470592574095e+18)),
        1758482618u,
        "no_demote_mixed_sub(7.869935327202668e+24, 4.0863470592574095e+18)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E38Export19_noX5FdemoteX5FmixedX5Fsub(&instance, -1535841968.9056544, 239897.28125)),
        3468107136u,
        "no_demote_mixed_sub(-1535841968.9056544, 239897.28125)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E38Export19_noX5FdemoteX5FmixedX5Fsub(&instance, -102.19459272722602, 0.0003942613839171827)),
        3268174805u,
        "no_demote_mixed_sub(-102.19459272722602, 0.0003942613839171827)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E38Export19_noX5FdemoteX5FmixedX5Fsub(&instance, 5.645470375565188e-17, 5.85107700707483e-22)),
        612510881u,
        "no_demote_mixed_sub(5.645470375565188e-17, 5.85107700707483e-22)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E38Export19_noX5FdemoteX5FmixedX5Fsub(&instance, 27090.388466832894, 63120.890625)),
        3339501185u,
        "no_demote_mixed_sub(27090.388466832894, 63120.890625)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E38Export28_noX5FdemoteX5FmixedX5FsubX5Fcommuted(&instance, 4.0863470592574095e+18, 7.869935327202668e+24)),
        3905966266u,
        "no_demote_mixed_sub_commuted(4.0863470592574095e+18, 7.869935327202668e+24)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E38Export28_noX5FdemoteX5FmixedX5FsubX5Fcommuted(&instance, 239897.28125, -1535841968.9056544)),
        1320623488u,
        "no_demote_mixed_sub_commuted(239897.28125, -1535841968.9056544)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E38Export28_noX5FdemoteX5FmixedX5FsubX5Fcommuted(&instance, 0.0003942613839171827, -102.19459272722602)),
        1120691157u,
        "no_demote_mixed_sub_commuted(0.0003942613839171827, -102.19459272722602)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E38Export28_noX5FdemoteX5FmixedX5FsubX5Fcommuted(&instance, 5.85107700707483e-22, 5.645470375565188e-17)),
        2759994529u,
        "no_demote_mixed_sub_commuted(5.85107700707483e-22, 5.645470375565188e-17)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E38Export28_noX5FdemoteX5FmixedX5FsubX5Fcommuted(&instance, 63120.890625, 27090.388466832894)),
        1192017537u,
        "no_demote_mixed_sub_commuted(63120.890625, 27090.388466832894)"
    );
}
