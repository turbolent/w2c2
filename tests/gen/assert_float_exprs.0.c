
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.0.h"

void test() {
    m13_floatX5FexprsX2E0Instance instance;
    m13_floatX5FexprsX2E0Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.0.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m13_floatX5FexprsX2E0Export18_f64X2EnoX5Fcontraction(&instance, -1.5967133604096234e-31, 8.763352160827123e+199, 4.289657620489846e+160)),
        16360919150252594323ull,
        "f64.no_contraction(-1.5967133604096234e-31, 8.763352160827123e+199, 4.289657620489846e+160)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_floatX5FexprsX2E0Export18_f64X2EnoX5Fcontraction(&instance, 8341016642481988.0, 3.223424965918293e-97, 2.3310835741659086e-91)),
        3401457070760597396ull,
        "f64.no_contraction(8341016642481988.0, 3.223424965918293e-97, 2.3310835741659086e-91)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_floatX5FexprsX2E0Export18_f64X2EnoX5Fcontraction(&instance, -3.0119045290520013e-179, 5.269933643923675e+160, 6.654454781339856e-32)),
        13564076370790560102ull,
        "f64.no_contraction(-3.0119045290520013e-179, 5.269933643923675e+160, 6.654454781339856e-32)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_floatX5FexprsX2E0Export18_f64X2EnoX5Fcontraction(&instance, 3.1413936116780743e-21, -7.262766035707377e-31, 4.619684894228461e-66)),
        13072631228492738408ull,
        "f64.no_contraction(3.1413936116780743e-21, -7.262766035707377e-31, 4.619684894228461e-66)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_floatX5FexprsX2E0Export18_f64X2EnoX5Fcontraction(&instance, -1.6080464217402378e-286, -3.82103410226833e+281, 1.0541980504151345e-16)),
        4544162191519938727ull,
        "f64.no_contraction(-1.6080464217402378e-286, -3.82103410226833e+281, 1.0541980504151345e-16)"
    );
}
