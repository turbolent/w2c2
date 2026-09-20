
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.52.h"

void test() {
    m14_floatX5FexprsX2E52Instance instance;
    m14_floatX5FexprsX2E52Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.52.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E52Export12_llvmX5Fpr26746(&instance, -0.0)),
        0u,
        "llvm_pr26746(-0.0)"
    );
}
