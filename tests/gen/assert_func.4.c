
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func.4.h"

void test() {
    m6_funcX2E4Instance instance;
    m6_funcX2E4Instantiate(&instance, resolveTestImports);
    printStart("func.4.wasm");
    assertEqualU32(
        m6_funcX2E4Export1_f(&instance, 42u),
        0u,
        "f(42u)"
    );
    assertEqualU32(
        m6_funcX2E4Export1_g(&instance, 42u),
        0u,
        "g(42u)"
    );
    assertEqualU32(
        m6_funcX2E4Export1_p(&instance),
        42u,
        "p()"
    );
}
