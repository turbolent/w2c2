
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.11.h"

void test() {
    exports11Instance instance;
    exports11Instantiate(&instance, resolveTestImports);
    printStart("exports.11.wasm");
    assertEqualU32(
        exports11_a(&instance),
        42u,
        "a()"
    );
    assertEqualU32(
        exports11_b(&instance),
        42u,
        "b()"
    );
    assertEqualU32(
        exports11_c(&instance),
        42u,
        "c()"
    );
}
