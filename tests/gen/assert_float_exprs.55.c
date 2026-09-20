
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.55.h"

void test() {
    m14_floatX5FexprsX2E55Instance instance;
    m14_floatX5FexprsX2E55Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.55.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E55Export8_thepast0(&instance, 4.450147717014403e-308, 0.9999999999999999, 2.0, 0.5)),
        9007199254740991ull,
        "thepast0(4.450147717014403e-308, 0.9999999999999999, 2.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E55Export8_thepast1(&instance, 5.551115123125783e-17, 0.9999999999999999, 5.551115123125783e-17)),
        13348669295526150144ull,
        "thepast1(5.551115123125783e-17, 0.9999999999999999, 5.551115123125783e-17)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E55Export8_thepast2(&instance, 2.350988701644575e-38, 0.5, 1.0)),
        8388608u,
        "thepast2(2.350988701644575e-38, 0.5, 1.0)"
    );
}
