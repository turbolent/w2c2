
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.55.h"

void test() {
    floatexprs55Instance instance;
    floatexprs55Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.55.wasm");
    assertEqualF64(
        floatexprs55_thepast0(&instance, 4.450147717014403e-308, 0.9999999999999999, 2.0, 0.5),
        4.4501477170144023e-308,
        "thepast0(4.450147717014403e-308, 0.9999999999999999, 2.0, 0.5)"
    );
    assertEqualF64(
        floatexprs55_thepast1(&instance, 5.551115123125783e-17, 0.9999999999999999, 5.551115123125783e-17),
        -6.162975822039155e-33,
        "thepast1(5.551115123125783e-17, 0.9999999999999999, 5.551115123125783e-17)"
    );
    assertEqualF32(
        floatexprs55_thepast2(&instance, 2.350988701644575e-38, 0.5, 1.0),
        1.1754943508222875e-38,
        "thepast2(2.350988701644575e-38, 0.5, 1.0)"
    );
}
