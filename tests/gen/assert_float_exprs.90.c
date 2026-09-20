
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.90.h"

void test() {
    m14_floatX5FexprsX2E90Instance instance;
    m14_floatX5FexprsX2E90Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.90.wasm");
    assertEqualF64(
        m14_floatX5FexprsX2E90Export19_dotX5FproductX5Fexample(&instance, 32000000.0, 1.0, -1.0, 80000000.0, 40000000.0, 1.0, -1.0, -16000000.0),
        2.0,
        "dot_product_example(32000000.0, 1.0, -1.0, 80000000.0, 40000000.0, 1.0, -1.0, -16000000.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E90Export24_withX5FbinaryX5FsumX5Fcollapse(&instance, 32000000.0, 1.0, -1.0, 80000000.0, 40000000.0, 1.0, -1.0, -16000000.0),
        2.0,
        "with_binary_sum_collapse(32000000.0, 1.0, -1.0, 80000000.0, 40000000.0, 1.0, -1.0, -16000000.0)"
    );
}
