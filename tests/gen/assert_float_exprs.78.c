
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.78.h"

void test() {
    floatexprs78Instance instance;
    floatexprs78Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.78.wasm");
    assertEqualF32(
        floatexprs78_f32X2Eno_distribute_exact(&instance, -0.0),
        0.0,
        "f32.no_distribute_exact(-0.0)"
    );
    assertEqualF64(
        floatexprs78_f64X2Eno_distribute_exact(&instance, -0.0),
        0.0,
        "f64.no_distribute_exact(-0.0)"
    );
}
