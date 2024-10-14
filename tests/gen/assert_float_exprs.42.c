
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.42.h"

void test() {
    floatexprs42Instance instance;
    floatexprs42Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.42.wasm");
    floatexprs42_init(&instance, 0u, 15.100000381469727);
    printOK("init(0u, 15.100000381469727)");
    floatexprs42_init(&instance, 4u, 15.199999809265137);
    printOK("init(4u, 15.199999809265137)");
    floatexprs42_init(&instance, 8u, 15.300000190734863);
    printOK("init(8u, 15.300000190734863)");
    floatexprs42_init(&instance, 12u, 15.399999618530273);
    printOK("init(12u, 15.399999618530273)");
    assertEqualF32(
        floatexprs42_check(&instance, 0u),
        15.100000381469727,
        "check(0u)"
    );
    assertEqualF32(
        floatexprs42_check(&instance, 4u),
        15.199999809265137,
        "check(4u)"
    );
    assertEqualF32(
        floatexprs42_check(&instance, 8u),
        15.300000190734863,
        "check(8u)"
    );
    assertEqualF32(
        floatexprs42_check(&instance, 12u),
        15.399999618530273,
        "check(12u)"
    );
    floatexprs42_run(&instance, 16u, 3.0);
    printOK("run(16u, 3.0)");
    assertEqualF32(
        floatexprs42_check(&instance, 0u),
        5.0333333015441895,
        "check(0u)"
    );
    assertEqualF32(
        floatexprs42_check(&instance, 4u),
        5.066666603088379,
        "check(4u)"
    );
    assertEqualF32(
        floatexprs42_check(&instance, 8u),
        5.099999904632568,
        "check(8u)"
    );
    assertEqualF32(
        floatexprs42_check(&instance, 12u),
        5.133333206176758,
        "check(12u)"
    );
}
