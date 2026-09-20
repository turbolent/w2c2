
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.376.h"

void test() {
    m9_constX2E376Instance instance;
    m9_constX2E376Instantiate(&instance, resolveTestImports);
    printStart("const.376.wasm");
    assertEqualF64(
        m9_constX2E376Export1_f(&instance),
        5.357543035931338e+300,
        "f()"
    );
}
