
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.26.h"

void test() {
    floatexprs26Instance instance;
    floatexprs26Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.26.wasm");
    assertEqualF32(
        floatexprs26_f32X2EnoX5FapproximateX5Freciprocal(&instance, -0.0011329756816849113),
        -882.6314697265625,
        "f32.no_approximate_reciprocal(-0.0011329756816849113)"
    );
    assertEqualF32(
        floatexprs26_f32X2EnoX5FapproximateX5Freciprocal(&instance, 3.237530143903465e+38),
        3.088774304929441e-39,
        "f32.no_approximate_reciprocal(3.237530143903465e+38)"
    );
    assertEqualF32(
        floatexprs26_f32X2EnoX5FapproximateX5Freciprocal(&instance, -1.2725990163945628e-28),
        -7.857934595785829e+27,
        "f32.no_approximate_reciprocal(-1.2725990163945628e-28)"
    );
    assertEqualF32(
        floatexprs26_f32X2EnoX5FapproximateX5Freciprocal(&instance, 1.0302067914563079e+23),
        9.706789077198895e-24,
        "f32.no_approximate_reciprocal(1.0302067914563079e+23)"
    );
    assertEqualF32(
        floatexprs26_f32X2EnoX5FapproximateX5Freciprocal(&instance, -2.8443762909518046e-25),
        -3.515709324545706e+24,
        "f32.no_approximate_reciprocal(-2.8443762909518046e-25)"
    );
}
