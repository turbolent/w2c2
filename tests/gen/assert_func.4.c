
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func.4.h"

void test() {
    func4Instance instance;
    func4Instantiate(&instance, resolveTestImports);
    printStart("func.4.wasm");
    assertEqualU32(
        func4_f(&instance, 42u),
        0u,
        "f(42u)"
    );
    assertEqualU32(
        func4_g(&instance, 42u),
        0u,
        "g(42u)"
    );
    assertEqualU32(
        func4_p(&instance),
        42u,
        "p()"
    );
}
