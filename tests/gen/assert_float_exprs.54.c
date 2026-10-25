
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.54.h"

void test() {
    m14_floatX5FexprsX2E54Instance instance;
    m14_floatX5FexprsX2E54Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.54.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E54Export12_llvmX5Fpr27036(&instance, 4269932491u, 14942208u)),
        3407478836u,
        "llvm_pr27036(4269932491u, 14942208u)"
    );
}
