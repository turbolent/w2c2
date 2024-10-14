
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.62.h"

void test() {
    floatexprs62Instance instance;
    floatexprs62Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.62.wasm");
    floatexprs62_f64X2Esimple_x4_sum(&instance, 0u, 32u, 64u);
    assertEqualF64(
        floatexprs62_f64X2Eload(&instance, 64u),
        1e-323,
        "f64.load(64u)"
    );
    assertEqualF64(
        floatexprs62_f64X2Eload(&instance, 72u),
        0.0,
        "f64.load(72u)"
    );
    assertEqualF64(
        floatexprs62_f64X2Eload(&instance, 80u),
        5e-324,
        "f64.load(80u)"
    );
    assertEqualF64(
        floatexprs62_f64X2Eload(&instance, 88u),
        -5e-324,
        "f64.load(88u)"
    );
}
