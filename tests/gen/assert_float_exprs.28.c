
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.28.h"

void test() {
    floatexprs28Instance instance;
    floatexprs28Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.28.wasm");
    assertEqualF32(
        floatexprs28_f32X2Eno_approximate_sqrt_reciprocal(&instance, 1.8950570813004186e+18),
        7.264217560809527e-10,
        "f32.no_approximate_sqrt_reciprocal(1.8950570813004186e+18)"
    );
    assertEqualF32(
        floatexprs28_f32X2Eno_approximate_sqrt_reciprocal(&instance, 0.002565894043073058),
        19.74152183532715,
        "f32.no_approximate_sqrt_reciprocal(0.002565894043073058)"
    );
    assertEqualF32(
        floatexprs28_f32X2Eno_approximate_sqrt_reciprocal(&instance, 6.32654487022683e+20),
        3.975728427030312e-11,
        "f32.no_approximate_sqrt_reciprocal(6.32654487022683e+20)"
    );
    assertEqualF32(
        floatexprs28_f32X2Eno_approximate_sqrt_reciprocal(&instance, 14153.5390625),
        0.008405576460063457,
        "f32.no_approximate_sqrt_reciprocal(14153.5390625)"
    );
    assertEqualF32(
        floatexprs28_f32X2Eno_approximate_sqrt_reciprocal(&instance, 2.6173729982836207e+31),
        1.9546418164459933e-16,
        "f32.no_approximate_sqrt_reciprocal(2.6173729982836207e+31)"
    );
}
