
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.53.h"

void test() {
    m14_floatX5FexprsX2E53Instance instance;
    m14_floatX5FexprsX2E53Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.53.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E53Export12_llvmX5Fpr27153(&instance, 33554434u)),
        1270874112u,
        "llvm_pr27153(33554434u)"
    );
}
