
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.43.h"

void test() {
    floatexprs43Instance instance;
    floatexprs43Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.43.wasm");
    floatexprs43_init(&instance, 0u, 15.1);
    printOK("init(0u, 15.1)");
    floatexprs43_init(&instance, 8u, 15.2);
    printOK("init(8u, 15.2)");
    floatexprs43_init(&instance, 16u, 15.3);
    printOK("init(16u, 15.3)");
    floatexprs43_init(&instance, 24u, 15.4);
    printOK("init(24u, 15.4)");
    assertEqualF64(
        floatexprs43_check(&instance, 0u),
        15.1,
        "check(0u)"
    );
    assertEqualF64(
        floatexprs43_check(&instance, 8u),
        15.2,
        "check(8u)"
    );
    assertEqualF64(
        floatexprs43_check(&instance, 16u),
        15.3,
        "check(16u)"
    );
    assertEqualF64(
        floatexprs43_check(&instance, 24u),
        15.4,
        "check(24u)"
    );
    floatexprs43_run(&instance, 32u, 3.0);
    printOK("run(32u, 3.0)");
    assertEqualF64(
        floatexprs43_check(&instance, 0u),
        5.033333333333333,
        "check(0u)"
    );
    assertEqualF64(
        floatexprs43_check(&instance, 8u),
        5.066666666666666,
        "check(8u)"
    );
    assertEqualF64(
        floatexprs43_check(&instance, 16u),
        5.1000000000000005,
        "check(16u)"
    );
    assertEqualF64(
        floatexprs43_check(&instance, 24u),
        5.133333333333334,
        "check(24u)"
    );
}
