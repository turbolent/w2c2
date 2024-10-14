
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.64.h"

void test() {
    floatexprs64Instance instance;
    floatexprs64Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.64.wasm");
    assertEqualF64(
        floatexprs64_f64X2Ekahan_sum(&instance, 0u, 256u),
        4.996401743142033e+300,
        "f64.kahan_sum(0u, 256u)"
    );
    assertEqualF64(
        floatexprs64_f64X2Eplain_sum(&instance, 0u, 256u),
        4.9964017432979576e+300,
        "f64.plain_sum(0u, 256u)"
    );
}
