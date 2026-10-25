
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.37.h"

void test() {
    m14_floatX5FexprsX2E37Instance instance;
    m14_floatX5FexprsX2E37Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.37.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E37Export19_noX5FdemoteX5FmixedX5Fadd(&instance, 4.941266527909197e-29, 1.8767182723004972e-36)),
        276467023u,
        "no_demote_mixed_add(4.941266527909197e-29, 1.8767182723004972e-36)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E37Export19_noX5FdemoteX5FmixedX5Fadd(&instance, 140851523637.69385, 401096441856.0)),
        1392270651u,
        "no_demote_mixed_add(140851523637.69385, 401096441856.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E37Export19_noX5FdemoteX5FmixedX5Fadd(&instance, 2.0831160914192852e-36, -6.050095133542437e-37)),
        66813087u,
        "no_demote_mixed_add(2.0831160914192852e-36, -6.050095133542437e-37)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E37Export19_noX5FdemoteX5FmixedX5Fadd(&instance, -1.0032827553674626e-06, 1.931291793155765e-09)),
        3045484077u,
        "no_demote_mixed_add(-1.0032827553674626e-06, 1.931291793155765e-09)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E37Export19_noX5FdemoteX5FmixedX5Fadd(&instance, -1.3840207035752711e-06, -5.202814091012642e-13)),
        3048850075u,
        "no_demote_mixed_add(-1.3840207035752711e-06, -5.202814091012642e-13)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E37Export28_noX5FdemoteX5FmixedX5FaddX5Fcommuted(&instance, 1.8767182723004972e-36, 4.941266527909197e-29)),
        276467023u,
        "no_demote_mixed_add_commuted(1.8767182723004972e-36, 4.941266527909197e-29)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E37Export28_noX5FdemoteX5FmixedX5FaddX5Fcommuted(&instance, 401096441856.0, 140851523637.69385)),
        1392270651u,
        "no_demote_mixed_add_commuted(401096441856.0, 140851523637.69385)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E37Export28_noX5FdemoteX5FmixedX5FaddX5Fcommuted(&instance, -6.050095133542437e-37, 2.0831160914192852e-36)),
        66813087u,
        "no_demote_mixed_add_commuted(-6.050095133542437e-37, 2.0831160914192852e-36)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E37Export28_noX5FdemoteX5FmixedX5FaddX5Fcommuted(&instance, 1.931291793155765e-09, -1.0032827553674626e-06)),
        3045484077u,
        "no_demote_mixed_add_commuted(1.931291793155765e-09, -1.0032827553674626e-06)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E37Export28_noX5FdemoteX5FmixedX5FaddX5Fcommuted(&instance, -5.202814091012642e-13, -1.3840207035752711e-06)),
        3048850075u,
        "no_demote_mixed_add_commuted(-5.202814091012642e-13, -1.3840207035752711e-06)"
    );
}
