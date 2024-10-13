
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.80.h"

void test() {
    floatexprs80Instance instance;
    floatexprs80Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.80.wasm");
    assertEqualF32(
        floatexprs80_f32X2Eno_distribute_exact(&instance, -0.0),
        0.0,
        "f32.no_distribute_exact(-0.0)"
    );
    assertEqualF64(
        floatexprs80_f64X2Eno_distribute_exact(&instance, -0.0),
        0.0,
        "f64.no_distribute_exact(-0.0)"
    );
}
