
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.60.h"

void test() {
    floatexprs60Instance instance;
    floatexprs60Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.60.wasm");
    floatexprs60_f64X2EsimpleX5Fx4X5Fsum(&instance, 0u, 32u, 64u);
    assertEqualF64(
        floatexprs60_f64X2Eload(&instance, 64u),
        1e-323,
        "f64.load(64u)"
    );
    assertEqualF64(
        floatexprs60_f64X2Eload(&instance, 72u),
        0.0,
        "f64.load(72u)"
    );
    assertEqualF64(
        floatexprs60_f64X2Eload(&instance, 80u),
        5e-324,
        "f64.load(80u)"
    );
    assertEqualF64(
        floatexprs60_f64X2Eload(&instance, 88u),
        -5e-324,
        "f64.load(88u)"
    );
}
