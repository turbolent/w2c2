
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.50.h"

void test() {
    m14_floatX5FexprsX2E50Instance instance;
    m14_floatX5FexprsX2E50Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.50.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E50Export9_calculate(&instance)),
        3286857379u,
        "calculate()"
    );
}
