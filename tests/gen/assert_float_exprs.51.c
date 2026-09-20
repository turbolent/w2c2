
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.51.h"

void test() {
    m14_floatX5FexprsX2E51Instance instance;
    m14_floatX5FexprsX2E51Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.51.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E51Export9_calculate(&instance)),
        13870293918930799763ull,
        "calculate()"
    );
}
