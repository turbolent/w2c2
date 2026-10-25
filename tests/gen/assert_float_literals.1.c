
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_literals.1.h"

void test() {
    m16_floatX5FliteralsX2E1Instance instance;
    m16_floatX5FliteralsX2E1Instantiate(&instance, resolveTestImports);
    printStart("float_literals.1.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m16_floatX5FliteralsX2E1Export10_4294967249(&instance)),
        4751297606777307136ull,
        "4294967249()"
    );
}
