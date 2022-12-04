
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.61.h"

void test() {
    floatexprs61Instance instance;
    floatexprs61Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.61.wasm");
    assertEqualF32(
        floatexprs61_f32X2EkahanX5Fsum(&instance, 0u, 256u),
        -2.1558138246206565e+31,
        "f32.kahan_sum(0u, 256u)"
    );
    assertEqualF32(
        floatexprs61_f32X2EplainX5Fsum(&instance, 0u, 256u),
        -1.6487539472071106e+31,
        "f32.plain_sum(0u, 256u)"
    );
}
