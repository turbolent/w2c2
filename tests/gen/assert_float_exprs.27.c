
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.27.h"

void test() {
    m14_floatX5FexprsX2E27Instance instance;
    m14_floatX5FexprsX2E27Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.27.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E27Export34_f32X2EnoX5FapproximateX5FreciprocalX5Fsqrt(&instance, 1.6117864692650336e-13)),
        1243088746u,
        "f32.no_approximate_reciprocal_sqrt(1.6117864692650336e-13)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E27Export34_f32X2EnoX5FapproximateX5FreciprocalX5Fsqrt(&instance, 0.007449136581271887)),
        1094279611u,
        "f32.no_approximate_reciprocal_sqrt(0.007449136581271887)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E27Export34_f32X2EnoX5FapproximateX5FreciprocalX5Fsqrt(&instance, 2.339817041277766e-20)),
        1338168541u,
        "f32.no_approximate_reciprocal_sqrt(2.339817041277766e-20)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E27Export34_f32X2EnoX5FapproximateX5FreciprocalX5Fsqrt(&instance, 1.1123504325754804e-13)),
        1245118689u,
        "f32.no_approximate_reciprocal_sqrt(1.1123504325754804e-13)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E27Export34_f32X2EnoX5FapproximateX5FreciprocalX5Fsqrt(&instance, 1.7653063085045715e-26)),
        1423641701u,
        "f32.no_approximate_reciprocal_sqrt(1.7653063085045715e-26)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E27Export27_f64X2EnoX5FfuseX5FreciprocalX5Fsqrt(&instance, 4.472459252766337e+267)),
        2604695339663988000ull,
        "f64.no_fuse_reciprocal_sqrt(4.472459252766337e+267)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E27Export27_f64X2EnoX5FfuseX5FreciprocalX5Fsqrt(&instance, 4.752392260007119e+93)),
        3906084647186679832ull,
        "f64.no_fuse_reciprocal_sqrt(4.752392260007119e+93)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E27Export27_f64X2EnoX5FfuseX5FreciprocalX5Fsqrt(&instance, 2.9014415885392436e+31)),
        4371518865190387497ull,
        "f64.no_fuse_reciprocal_sqrt(2.9014415885392436e+31)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E27Export27_f64X2EnoX5FfuseX5FreciprocalX5Fsqrt(&instance, 1.3966125076974778e+201)),
        3102407657946187309ull,
        "f64.no_fuse_reciprocal_sqrt(1.3966125076974778e+201)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E27Export27_f64X2EnoX5FfuseX5FreciprocalX5Fsqrt(&instance, 1.5159641544070443e+44)),
        4276321761661248681ull,
        "f64.no_fuse_reciprocal_sqrt(1.5159641544070443e+44)"
    );
}
