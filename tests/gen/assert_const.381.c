
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.381.h"

void test() {
    m9_constX2E381Instance instance;
    m9_constX2E381Instantiate(&instance, resolveTestImports);
    printStart("const.381.wasm");
    assertEqualF64(
        m9_constX2E381Export1_f(&instance),
        -5.357543035931339e+300,
        "f()"
    );
}
