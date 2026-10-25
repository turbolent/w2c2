
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.26.h"

void test() {
    m14_floatX5FexprsX2E26Instance instance;
    m14_floatX5FexprsX2E26Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.26.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E26Export29_f32X2EnoX5FapproximateX5Freciprocal(&instance, -0.0011329756816849113)),
        3294406762u,
        "f32.no_approximate_reciprocal(-0.0011329756816849113)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E26Export29_f32X2EnoX5FapproximateX5Freciprocal(&instance, 3.237530143903465e+38)),
        2204223u,
        "f32.no_approximate_reciprocal(3.237530143903465e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E26Export29_f32X2EnoX5FapproximateX5Freciprocal(&instance, -1.2725990163945628e-28)),
        3989512051u,
        "f32.no_approximate_reciprocal(-1.2725990163945628e-28)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E26Export29_f32X2EnoX5FapproximateX5Freciprocal(&instance, 1.0302067914563079e+23)),
        423346609u,
        "f32.no_approximate_reciprocal(1.0302067914563079e+23)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E26Export29_f32X2EnoX5FapproximateX5Freciprocal(&instance, -2.8443762909518046e-25)),
        3896123071u,
        "f32.no_approximate_reciprocal(-2.8443762909518046e-25)"
    );
}
