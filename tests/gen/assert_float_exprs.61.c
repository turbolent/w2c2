
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.61.h"

void test() {
    floatexprs61Instance instance;
    floatexprs61Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.61.wasm");
    floatexprs61_f32X2Esimple_x4_sum(&instance, 0u, 16u, 32u);
    assertEqualF32(
        floatexprs61_f32X2Eload(&instance, 32u),
        2.802596928649634e-45,
        "f32.load(32u)"
    );
    assertEqualF32(
        floatexprs61_f32X2Eload(&instance, 36u),
        0.0,
        "f32.load(36u)"
    );
    assertEqualF32(
        floatexprs61_f32X2Eload(&instance, 40u),
        1.401298464324817e-45,
        "f32.load(40u)"
    );
    assertEqualF32(
        floatexprs61_f32X2Eload(&instance, 44u),
        -1.401298464324817e-45,
        "f32.load(44u)"
    );
}
