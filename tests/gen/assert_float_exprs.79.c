
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.79.h"

void test() {
    floatexprs79Instance instance;
    floatexprs79Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.79.wasm");
    assertEqualF32(
        floatexprs79_f32X2Esqrt(&instance, 2.0),
        1.4142135381698608,
        "f32.sqrt(2.0)"
    );
    assertEqualF32(
        floatexprs79_f32X2ExkcdX5FsqrtX5F2(&instance, 3.0, 5.0, 3.1415927410125732, 7.0),
        1.4142200946807861,
        "f32.xkcd_sqrt_2(3.0, 5.0, 3.1415927410125732, 7.0)"
    );
    assertEqualF32(
        floatexprs79_f32X2Esqrt(&instance, 3.0),
        1.7320507764816284,
        "f32.sqrt(3.0)"
    );
    assertEqualF32(
        floatexprs79_f32X2ExkcdX5FsqrtX5F3(&instance, 2.0, 2.7182817459106445, 3.1415927410125732),
        1.7305119037628174,
        "f32.xkcd_sqrt_3(2.0, 2.7182817459106445, 3.1415927410125732)"
    );
    assertEqualF32(
        floatexprs79_f32X2Esqrt(&instance, 5.0),
        2.2360680103302,
        "f32.sqrt(5.0)"
    );
    assertEqualF32(
        floatexprs79_f32X2ExkcdX5FsqrtX5F5(&instance, 2.0, 2.7182817459106445, 3.0),
        2.2357587814331055,
        "f32.xkcd_sqrt_5(2.0, 2.7182817459106445, 3.0)"
    );
    assertEqualF32(
        floatexprs79_f32X2ExkcdX5FbetterX5FsqrtX5F5(&instance, 13.0, 4.0, 3.1415927410125732, 24.0),
        2.2360680103302,
        "f32.xkcd_better_sqrt_5(13.0, 4.0, 3.1415927410125732, 24.0)"
    );
    assertEqualF64(
        floatexprs79_f64X2Esqrt(&instance, 2.0),
        1.4142135623730951,
        "f64.sqrt(2.0)"
    );
    assertEqualF64(
        floatexprs79_f64X2ExkcdX5FsqrtX5F2(&instance, 3.0, 5.0, 3.141592653589793, 7.0),
        1.4142200580539208,
        "f64.xkcd_sqrt_2(3.0, 5.0, 3.141592653589793, 7.0)"
    );
    assertEqualF64(
        floatexprs79_f64X2Esqrt(&instance, 3.0),
        1.7320508075688772,
        "f64.sqrt(3.0)"
    );
    assertEqualF64(
        floatexprs79_f64X2ExkcdX5FsqrtX5F3(&instance, 2.0, 2.718281828459045, 3.141592653589793),
        1.7305119588645301,
        "f64.xkcd_sqrt_3(2.0, 2.718281828459045, 3.141592653589793)"
    );
    assertEqualF64(
        floatexprs79_f64X2Esqrt(&instance, 5.0),
        2.23606797749979,
        "f64.sqrt(5.0)"
    );
    assertEqualF64(
        floatexprs79_f64X2ExkcdX5FsqrtX5F5(&instance, 2.0, 2.718281828459045, 3.0),
        2.2357588823428847,
        "f64.xkcd_sqrt_5(2.0, 2.718281828459045, 3.0)"
    );
    assertEqualF64(
        floatexprs79_f64X2ExkcdX5FbetterX5FsqrtX5F5(&instance, 13.0, 4.0, 3.141592653589793, 24.0),
        2.2360678094452893,
        "f64.xkcd_better_sqrt_5(13.0, 4.0, 3.141592653589793, 24.0)"
    );
}
