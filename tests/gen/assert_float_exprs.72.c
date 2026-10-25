
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.72.h"

void test() {
    m14_floatX5FexprsX2E72Instance instance;
    m14_floatX5FexprsX2E72Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.72.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E72Export20_f32X2EnoX5FfoldX5FaddX5Fdivs(&instance, 377.368896484375, -0.04011818394064903, -1.3629298560546316e+38)),
        2221638875u,
        "f32.no_fold_add_divs(377.368896484375, -0.04011818394064903, -1.3629298560546316e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E72Export20_f32X2EnoX5FfoldX5FaddX5Fdivs(&instance, -1.8234023041237435e-19, -3.3970288113369237e-15, -170996707360768.0)),
        264862203u,
        "f32.no_fold_add_divs(-1.8234023041237435e-19, -3.3970288113369237e-15, -170996707360768.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E72Export20_f32X2EnoX5FfoldX5FaddX5Fdivs(&instance, -1.967263835557856e-14, 6.414098702699398e-20, -541989070176256.0)),
        272108594u,
        "f32.no_fold_add_divs(-1.967263835557856e-14, 6.414098702699398e-20, -541989070176256.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E72Export20_f32X2EnoX5FfoldX5FaddX5Fdivs(&instance, -4.038505822193515e-31, 3.848228081428171e-30, -3.4523719791292376e+26)),
        0u,
        "f32.no_fold_add_divs(-4.038505822193515e-31, 3.848228081428171e-30, -3.4523719791292376e+26)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E72Export20_f32X2EnoX5FfoldX5FaddX5Fdivs(&instance, 0.0010934415040537715, 0.2070312350988388, 1.3509783969902986e-37)),
        2073319791u,
        "f32.no_fold_add_divs(0.0010934415040537715, 0.2070312350988388, 1.3509783969902986e-37)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E72Export20_f64X2EnoX5FfoldX5FaddX5Fdivs(&instance, -4.91701943214376e+129, 6.813215632201902e+130, 2.6125410100237784e+274)),
        2458462832069881218ull,
        "f64.no_fold_add_divs(-4.91701943214376e+129, 6.813215632201902e+130, 2.6125410100237784e+274)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E72Export20_f64X2EnoX5FfoldX5FaddX5Fdivs(&instance, -1.020646795322455e+16, 63.422616671746226, -1.6024747869814892e-288)),
        9152039358940941283ull,
        "f64.no_fold_add_divs(-1.020646795322455e+16, 63.422616671746226, -1.6024747869814892e-288)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E72Export20_f64X2EnoX5FfoldX5FaddX5Fdivs(&instance, -1.5270569633109837e-291, 2.5755503329232514e-294, 5.882693916421492e+151)),
        0ull,
        "f64.no_fold_add_divs(-1.5270569633109837e-291, 2.5755503329232514e-294, 5.882693916421492e+151)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E72Export20_f64X2EnoX5FfoldX5FaddX5Fdivs(&instance, 2.666796487439464e+94, -2.1315692524936578e+99, 1.2377004518680012e-38)),
        15883525310425977300ull,
        "f64.no_fold_add_divs(2.666796487439464e+94, -2.1315692524936578e+99, 1.2377004518680012e-38)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E72Export20_f64X2EnoX5FfoldX5FaddX5Fdivs(&instance, -1.2952888377288216e-219, 5.808769259900048e-228, 1.6745741699443756e-21)),
        10866511466898347555ull,
        "f64.no_fold_add_divs(-1.2952888377288216e-219, 5.808769259900048e-228, 1.6745741699443756e-21)"
    );
}
