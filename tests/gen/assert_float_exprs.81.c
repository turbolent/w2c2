
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.81.h"

void test() {
    m14_floatX5FexprsX2E81Instance instance;
    m14_floatX5FexprsX2E81Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.81.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E81Export8_f32X2Esqrt(&instance, 2.0)),
        1068827891u,
        "f32.sqrt(2.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E81Export15_f32X2ExkcdX5FsqrtX5F2(&instance, 3.0, 5.0, 3.1415927410125732, 7.0)),
        1068827946u,
        "f32.xkcd_sqrt_2(3.0, 5.0, 3.1415927410125732, 7.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E81Export8_f32X2Esqrt(&instance, 3.0)),
        1071494103u,
        "f32.sqrt(3.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E81Export15_f32X2ExkcdX5FsqrtX5F3(&instance, 2.0, 2.7182817459106445, 3.1415927410125732)),
        1071481194u,
        "f32.xkcd_sqrt_3(2.0, 2.7182817459106445, 3.1415927410125732)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E81Export8_f32X2Esqrt(&instance, 5.0)),
        1074731965u,
        "f32.sqrt(5.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E81Export15_f32X2ExkcdX5FsqrtX5F5(&instance, 2.0, 2.7182817459106445, 3.0)),
        1074730668u,
        "f32.xkcd_sqrt_5(2.0, 2.7182817459106445, 3.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E81Export22_f32X2ExkcdX5FbetterX5FsqrtX5F5(&instance, 13.0, 4.0, 3.1415927410125732, 24.0)),
        1074731965u,
        "f32.xkcd_better_sqrt_5(13.0, 4.0, 3.1415927410125732, 24.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E81Export8_f64X2Esqrt(&instance, 2.0)),
        4609047870845172685ull,
        "f64.sqrt(2.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E81Export15_f64X2ExkcdX5FsqrtX5F2(&instance, 3.0, 5.0, 3.141592653589793, 7.0)),
        4609047900099118431ull,
        "f64.xkcd_sqrt_2(3.0, 5.0, 3.141592653589793, 7.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E81Export8_f64X2Esqrt(&instance, 3.0)),
        4610479282544200874ull,
        "f64.sqrt(3.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E81Export15_f64X2ExkcdX5FsqrtX5F3(&instance, 2.0, 2.718281828459045, 3.141592653589793)),
        4610472352185749397ull,
        "f64.xkcd_sqrt_3(2.0, 2.718281828459045, 3.141592653589793)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E81Export8_f64X2Esqrt(&instance, 5.0)),
        4612217596255138984ull,
        "f64.sqrt(5.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E81Export15_f64X2ExkcdX5FsqrtX5F5(&instance, 2.0, 2.718281828459045, 3.0)),
        4612216900234722254ull,
        "f64.xkcd_sqrt_5(2.0, 2.718281828459045, 3.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E81Export22_f64X2ExkcdX5FbetterX5FsqrtX5F5(&instance, 13.0, 4.0, 3.141592653589793, 24.0)),
        4612217595876713891ull,
        "f64.xkcd_better_sqrt_5(13.0, 4.0, 3.141592653589793, 24.0)"
    );
}
