
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.28.h"

void test() {
    m14_floatX5FexprsX2E28Instance instance;
    m14_floatX5FexprsX2E28Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.28.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E28Export34_f32X2EnoX5FapproximateX5FsqrtX5Freciprocal(&instance, 1.8950570813004186e+18)),
        810003811u,
        "f32.no_approximate_sqrt_reciprocal(1.8950570813004186e+18)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E28Export34_f32X2EnoX5FapproximateX5FsqrtX5Freciprocal(&instance, 0.002565894043073058)),
        1100869283u,
        "f32.no_approximate_sqrt_reciprocal(0.002565894043073058)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E28Export34_f32X2EnoX5FapproximateX5FsqrtX5Freciprocal(&instance, 6.32654487022683e+20)),
        774822585u,
        "f32.no_approximate_sqrt_reciprocal(6.32654487022683e+20)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E28Export34_f32X2EnoX5FapproximateX5FsqrtX5Freciprocal(&instance, 14153.5390625)),
        1007269771u,
        "f32.no_approximate_sqrt_reciprocal(14153.5390625)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E28Export34_f32X2EnoX5FapproximateX5FsqrtX5Freciprocal(&instance, 2.6173729982836207e+31)),
        627137240u,
        "f32.no_approximate_sqrt_reciprocal(2.6173729982836207e+31)"
    );
}
